#include "clock.h"
#include "gpio.h"


void initClock(void){
    RCC_t *rcc = RCC;
    FLASH_TypeDef *flash = FLASH;
    PWR_TypeDef *pwr = PWR;


    rcc->CR |= (1 << 16); //Enable HSE
    while(!(rcc->CR & (1 << 17))); //Wait for HSE to be ready
    rcc->APB1ENR |= (1 << 28); //Enable PWR clock
    pwr->CR |= (1 << 14); //VOS Always corresponds to reset value
    
    //Configure the FLASH PREFETCH and the LATENCY Related Settings
    flash->ACR |= (1 << 9) | (1 << 10) | (1 << 8) | (0x00000005U);

    //Configure the PRESCALERS HCLK, PCLK1, PCLK2
    rcc->CFGR |= (0x00000000U); //AHB Prescaler (divided by 1[no division])
    rcc->CFGR |= (0x00001400U); //APB1 Prescaler (divided by 4)
    rcc->CFGR |= (0x00008000U); //APB2 Prescaler (divided by 2)

    //configure the main PLL
    rcc->PLLCFGR |= (PLL_M < 0) | (PLL_N < 6) | (PLL_P < 16) | (1 << 22);
    rcc->CR |= (1 << 24); //Enable the main PLL
    while(!(rcc->CR & (1 << 25))); //Wait for PLL to be ready
    rcc->CFGR |= (0x00000002U); //select clock source
    while((rcc->CFGR & (3U << 2)) != 0x00000008U); //Wait for PLL to be CLK
}
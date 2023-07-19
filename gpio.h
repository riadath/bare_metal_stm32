#ifndef __STM32_GPIO_H
#define __STM32_GPIO_H

#include <stdint.h>
#include <stdbool.h>


typedef struct {
  volatile uint32_t MODER;
  volatile uint32_t OTYPER; 
  volatile uint32_t OSPEEDR;
  volatile uint32_t PUPDR;
  volatile uint32_t IDR;
  volatile uint32_t ODR;
  volatile uint32_t BSRR;
  volatile uint32_t LCKR;
  volatile uint32_t AFRL[2];
}GPIO_STRUCT;


typedef struct{
  uint32_t volatile CR; /* Offset: 0x00 (R/W) Clock Control Register */
  uint32_t volatile PLLCFGR; /* Offset: 0x04 (R/W) PLL Configuration Register */
  uint32_t volatile CFGR; /* Offset: 0x08 (R/W) Clock Configuration Register */
  uint32_t volatile CIR; /* Offset: 0x0C (R/W) Clock Interrupt Register */
  uint32_t volatile AHB1RSTR; /* Offset: 0x10 (R/W) AHB1 Peripheral Reset Register */
  uint32_t volatile AHB2RSTR; /* Offset: 0x14 (R/W) AHB2 Peripheral Reset Register */
  uint32_t volatile AHB3RSTR; /* Offset: 0x18 (R/W) AHB3 Peripheral Reset Register */
  uint32_t volatile reserved0;
  uint32_t volatile APB1RSTR; /* Offset: 0x20 (R/W) APB1 Peripheral Reset Register */
  uint32_t volatile APB2RSTR; /* Offset: 0x24 (R/W) APB2 Peripheral Reset Register */
  uint32_t reserved1[2];
  uint32_t volatile AHB1ENR; /* Offset: 0x30 (R/W) AHB1 Peripheral Clock Enable Register */
  uint32_t volatile AHB2ENR; /* Offset: 0x34 (R/W) AHB2 Peripheral Clock Enable Register */
  uint32_t volatile AHB3ENR; /* Offset: 0x38 (R/W) AHB3 Peripheral Clock Enable Register */
  uint32_t reserved2;
  uint32_t volatile APB1ENR; /* Offset: 0x40 (R/W) APB1 Peripheral Clock Enable Register */
  uint32_t volatile APB2ENR; /* Offset: 0x44 (R/W) APB1 Peripheral Clock Enable Register */
  uint32_t reserved3[2];
  uint32_t volatile AHB1LPENR; /* Offset: 0x50 (R/W) AHB1 Peripheral Clock Enable Lower Power Mode Register */
  uint32_t volatile AHB2LPENR; /* Offset: 0x54 (R/W) AHB2 Peripheral Clock Enable Lower Power Mode Register */
  uint32_t volatile AHB3LPENR; /* Offset: 0x58 (R/W) AHB3 Peripheral Clock Enable Lower Power Mode Register */
  uint32_t reserved4;
  uint32_t volatile APB1LPENR; /* Offset: 0x60 (R/W) APB1 Peripheral Clock Enable Lower Power Mode Register */
  uint32_t volatile APB2LPENR; /* Offset: 0x64 (R/W) APB2 Peripheral Clock Enable Lower Power Mode Register */
  uint32_t reserved5[2];
  uint32_t volatile BDCR; /* Offset: 0x70 (R/W) Backup Domain Control Register */
  uint32_t volatile CSR; /* Offset: 0x74 (R/W) Clock Control & Status Register */
  uint32_t reserved6[2];
  uint32_t volatile SSCGR; /* Offset: 0x80 (R/W) Spread Spectrum Clock Generation Register */
  uint32_t volatile PLLI2SCFGR; /* Offset: 0x84 (R/W) PLLI2S Configuration Register */
  uint32_t volatile PLLSAICFGR; /* Offset: 0x88 (R/W) PLLSAI Configuration Register */
  uint32_t volatile DCKCFGR; /* Offset: 0x8C (R/W) Dedicated Clocks Configuration Register */
  uint32_t volatile CKGATENR; /* Offset: 0x90 (R/W) Clocks Gated Enabled Register */
  uint32_t volatile DCKCFGR2; /* Offset: 0x94 (R/W) Dedicated Clocks Configuration Register 2 */
}RCC_t;

#define RCC ((RCC_t *)0x40023800)
#define GPIO(n) ((GPIO_STRUCT*) (0x40020000 + (n * 0x400)))
#define GPIOA_OFFSET 0x0;

enum GPIOx{GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOF,GPIOG,GPIOH};
enum PIN_STATE{GPIO_PIN_RESET,GPIO_PIN_SET};
enum GPIO_MODE{INPUT,OUTPUT,ALTERNATE,ANALOG};


void GPIO_Init(enum GPIOx gpiox, uint8_t pin,enum GPIO_MODE mode);
void GPIO_WritePin(enum GPIOx gpiox,uint8_t pin,enum PIN_STATE state);
bool GPIO_InputStatus(enum GPIOx gpiox,uint8_t pin);

#endif
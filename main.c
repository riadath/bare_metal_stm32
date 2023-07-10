#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
  n = 0, for GPIOA
  n = 1, for GPIOB
  ....
  n = 7, for GPIOH
*/
#define GPIO(n) ((struct GPIO_STRUCT *) (0x40020000 + (n * 0x400)))
#define GPIOA_OFFSET 0x0
#define AHB1_OFFSET 0x30


struct GPIO_STRUCT {
  volatile uint32_t MODER;
  volatile uint32_t OTYPER; 
  volatile uint32_t OSPEEDR;
  volatile uint32_t PUPDR;
  volatile uint32_t IDR;
  volatile uint32_t ODR;
  volatile uint32_t BSRR;
  volatile uint32_t LCKR;
  volatile uint32_t AFRL[2];
};



static inline void GPIO_Init(uint8_t gpio_no, uint8_t pin,uint8_t mode)
{
  struct GPIO_STRUCT* gpio = GPIO(gpio_no);
  gpio->MODER &= ~(3U << (pin * 2));
  gpio->MODER |= ((mode) << (pin * 2));
}

static inline void GPIO_WritePin(uint8_t gpio_no,uint8_t pin,bool state){
  struct GPIO_STRUCT *gpio = GPIO(gpio_no);

  if(state == true){
    gpio->BSRR |= (0x1U << pin);
  }else{
    gpio->BSRR |= (0x1U << (pin + 16));
  }
}

static inline void shitty_delay(volatile uint32_t count) {
  while (count--) asm("nop");
}


int main()
{
  volatile uint32_t *RCC_AHB1ENR = (uint32_t*)(0x40023800 + AHB1_OFFSET);
  *RCC_AHB1ENR |= (1 << GPIOA_OFFSET); //enable GPIOA

  GPIO_Init(0,5,1);
  GPIO_Init(0,6,1);
  GPIO_Init(0,7,1);

  while(1){
    GPIO_WritePin(0,5,true);
    GPIO_WritePin(0,7,true);
    GPIO_WritePin(0,6,true);

    shitty_delay(999999);

    GPIO_WritePin(0,5,false);
    GPIO_WritePin(0,7,false);
    GPIO_WritePin(0,6,false);

    shitty_delay(999999);
  }
  
  return 0;
}

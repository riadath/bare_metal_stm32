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
  gpio->MODER &= ~(0x3 << (pin * 2));
  gpio->MODER |= ((mode & 3) << (pin * 2));
}

static inline GPIO_WritePin(uint8_t gpio_no,uint8_t pin,bool state){
  struct GPIO_STRUCT *gpio = GPIO(gpio_no);

  if(state == true){
    gpio->BSRR |= (0x1U << pin);
  }else{
    gpio->BSRR |= (0x1U << (pin + 16));
  }
}

void shitty_delay(){
  for (int i = 0;i < 1e9;i++);
}

int main()
{
  GPIO_Init(0,5,1);

  while(1){
    GPIO_WritePin(0,5,true);
    shitty_delay();
    GPIO_WritePin(0,5,false);
    shitty_delay();
  }
  
  return 0;
}

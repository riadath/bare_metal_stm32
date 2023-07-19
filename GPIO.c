#include "GPIO.h"

static inline void GPIO_Init(enum GPIOx gpiox, uint8_t pin,enum GPIO_MODE mode)
{
  GPIO_STRUCT* gpio = GPIO(gpiox);
  gpio->MODER &= ~(3U << (pin * 2));
  gpio->MODER |= ((mode) << (pin * 2));
}

static inline void GPIO_WritePin(enum GPIOx gpiox,uint8_t pin,enum PIN_STATE state){
  GPIO_STRUCT *gpio = GPIO(gpiox);
  if(state == GPIO_PIN_SET){
    gpio->BSRR |= (0x1U << pin);
  }else if (state == GPIO_PIN_RESET){
    gpio->BSRR |= (0x1U << (pin + 16));
  }
}

static inline bool GPIO_InputStatus(enum GPIOx gpiox,uint8_t pin){
  GPIO_STRUCT *gpio = GPIO(gpiox);
  if(gpio->IDR & (1U << pin)){
    return true;
  }else{
    return false;
  }
}

static inline void shitty_delay(volatile uint32_t count) {
  while (count--) asm("nop");
}


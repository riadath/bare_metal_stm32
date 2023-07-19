#include <stdint.h>
#include <stdbool.h>
#include "GPIO.h"

int main()
{
  RCC_t* rcc = RCC;
  rcc->AHB1ENR |= 1 << GPIOA_OFFSET;

  GPIO_Init(GPIOA,1,OUTPUT); // initialize gpio pin 5 in output mode.
  GPIO_Init(GPIOA,4,INPUT); // initialize gpio pin 6 in input mode.
  
  while(1){
    if(GPIO_InputStatus(GPIOA,4)){
      GPIO_WritePin(GPIOA,1,GPIO_PIN_SET);
    }else{
      GPIO_WritePin(GPIOA,1,GPIO_PIN_RESET);
    }
  }
  
  return 0;
}

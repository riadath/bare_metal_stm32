#include "stm32_startup.h"

void Default_Handler(void){
  while(1);
}

void Reset_Handler(void){
  uint32_t size = (uint32_t)&_edata - (uint32_t)&_sdata; 
    
  uint8_t *dest = (uint8_t*)&_sdata; //sram
  uint8_t *src = (uint8_t*)&_etext; //flash

  for(uint32_t i = 0;i < size;i++){
      *dest++ = *src++;    
  }
  size = (uint32_t)&_ebss - (uint32_t)&_sbss;
  dest = (uint8_t*)&_sbss;

  for(uint32_t i = 0;i < size;i++){
      *dest++ = 0;
  }
  
  main();
}













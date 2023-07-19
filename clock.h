#ifndef __STM32_CLOCK_H
#define __STM32_CLOCK_H

#include <stdint.h>

#define PLL_M 4
#define PLL_N 180
#define PLL_P 0



typedef struct
{
  uint32_t ACR;      /*!< FLASH access control register,   Address offset: 0x00 */
  uint32_t KEYR;     /*!< FLASH key register,              Address offset: 0x04 */
  uint32_t OPTKEYR;  /*!< FLASH option key register,       Address offset: 0x08 */
  uint32_t SR;       /*!< FLASH status register,           Address offset: 0x0C */
  uint32_t CR;       /*!< FLASH control register,          Address offset: 0x10 */
  uint32_t OPTCR;    /*!< FLASH option control register ,  Address offset: 0x14 */
  uint32_t OPTCR1;   /*!< FLASH option control register 1, Address offset: 0x18 */
} FLASH_TypeDef;

typedef struct
{
  uint32_t CR;   /*!< PWR power control register,        Address offset: 0x00 */
  uint32_t CSR;  /*!< PWR power control/status register, Address offset: 0x04 */
} PWR_TypeDef;

#define FLASH ((FLASH_TypeDef*) 0x40023C00)
#define PWR ((PWR_TypeDef*) 0x40007000)

void initClock(void);
#endif
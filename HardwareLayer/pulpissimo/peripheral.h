#ifndef __PULPISSIMO_PERIPHERAL_H
#define __PULPISSIMO_PERIPHERAL_H

#include <stdint.h>
#include "core.h"

/** @addtogroup Peripheral_registers_structures
  * @{
  */

/**
  * @brief GPIO
  */
typedef struct {
    __IO volatile uint32_t PADDIR;                // GPIO pad direction configuration register
    __IO volatile uint32_t GPIOEN;                // GPIO enable register
    __I  volatile uint32_t PADIN;                 // GPIO pad input value register
    __IO volatile uint32_t PADOUT;                // GPIO pad output value register
    __IO volatile uint32_t PADOUTSET;             // GPIO pad output set register
    __IO volatile uint32_t PADOUTCLR;             // GPIO pad output clear register
    __IO volatile uint32_t INTEN;                 // GPIO pad interrupt enable configuration register
    __IO volatile uint32_t INTTYPE0;              // GPIO pad interrupt type gpio 0 to 15 register
    __IO volatile uint32_t INTTYPE1;              // GPIO pad interrupt type gpio 16 to 31 register
    __I  volatile uint32_t INTSTATUS;             // GPIO pad interrupt status register
    __IO volatile uint32_t PADCFG0;               // GPIO pad pin 0 to 7 configuration register
    __IO volatile uint32_t PADCFG1;               // GPIO pad pin 8 to 15 configuration register
    __IO volatile uint32_t PADCFG2;               // GPIO pad pin 16 to 23 configuration register
    __IO volatile uint32_t PADCFG3;               // GPIO pad pin 24 to 31 configuration register
} GPIO_TypeDef;

/** 
  * @brief SoC Control
  */

typedef struct
{
  __I  uint32_t INFO;
  __IO uint32_t BOOT_ADR;
  __IO uint32_t FETCH_ENABLE;
       uint32_t RESERVED1;
  __IO uint32_t PAD_MUX[4];
  __IO uint32_t PAD_CFG[16];
       uint32_t RESERVED2[5];
  __IO uint32_t JTAG_REG;
       uint32_t RESERVED3[10];
  __IO uint32_t CORE_STATUS0;
       uint32_t RESERVED4[7];
  __I  uint32_t CORE_STATUS1;
       uint32_t RESERVED5;
  __IO uint32_t FLL_CLOCK_SELECT;
} SOCCTRL_TypeDef;


/** 
  * @}
  */
#endif // __PULPISSIMO_GPIO_H

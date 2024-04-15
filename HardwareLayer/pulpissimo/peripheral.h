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
    volatile uint32_t PADDIR;                // GPIO pad direction configuration register
    volatile uint32_t GPIOEN;                // GPIO enable register
    volatile uint32_t PADIN;                 // GPIO pad input value register
    volatile uint32_t PADOUT;                // GPIO pad output value register
    volatile uint32_t PADOUTSET;             // GPIO pad output set register
    volatile uint32_t PADOUTCLR;             // GPIO pad output clear register
    volatile uint32_t INTEN;                 // GPIO pad interrupt enable configuration register
    volatile uint32_t INTTYPE0;              // GPIO pad interrupt type gpio 0 to 15 register
    volatile uint32_t INTTYPE1;              // GPIO pad interrupt type gpio 16 to 31 register
    volatile uint32_t INTSTATUS;             // GPIO pad interrupt status register
    volatile uint32_t PADCFG0;               // GPIO pad pin 0 to 7 configuration register
    volatile uint32_t PADCFG1;               // GPIO pad pin 8 to 15 configuration register
    volatile uint32_t PADCFG2;               // GPIO pad pin 16 to 23 configuration register
    volatile uint32_t PADCFG3;               // GPIO pad pin 24 to 31 configuration register
} GPIO_TypeDef;


#endif // __PULPISSIMO_GPIO_H

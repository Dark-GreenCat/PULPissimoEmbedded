#include <stdint.h>

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
    volatile uint32_t PADDIR_32_63;          // GPIO pad direction configuration register
    volatile uint32_t GPIOEN_32_63;          // GPIO enable register
    volatile uint32_t PADIN_32_63;           // GPIO pad input value register
    volatile uint32_t PADOUT_32_63;          // GPIO pad output value register
    volatile uint32_t PADOUTSET_32_63;       // GPIO pad output set register
    volatile uint32_t PADOUTCLR_32_63;       // GPIO pad output clear register
    volatile uint32_t INTEN_32_63;           // GPIO pad interrupt enable configuration register
    volatile uint32_t INTTYPE_32_47;         // GPIO pad interrupt type gpio 32 to 47 register
    volatile uint32_t INTTYPE_48_63;         // GPIO pad interrupt type gpio 48 to 63 register
    volatile uint32_t INTSTATUS_32_63;       // GPIO pad interrupt status register
    volatile uint32_t PADCFG_32_39;          // GPIO pad pin 32 to 39 configuration register
    volatile uint32_t PADCFG_40_47;          // GPIO pad pin 40 to 47 configuration register
    volatile uint32_t PADCFG_48_55;          // GPIO pad pin 48 to 55 configuration register
    volatile uint32_t PADCFG_56_63;          // GPIO pad pin 56 to 63 configuration register
} GPIO_TypeDef;

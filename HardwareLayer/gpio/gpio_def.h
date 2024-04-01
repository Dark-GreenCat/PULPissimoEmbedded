#ifndef __GPIO_DEF_H
#define __GPIO_DEF_H

#include <stdint.h>

#define GPIO_PIN_0   0
#define GPIO_PIN_1   1
#define GPIO_PIN_2   2
#define GPIO_PIN_3   3
#define GPIO_PIN_4   4
#define GPIO_PIN_5   5
#define GPIO_PIN_6   6
#define GPIO_PIN_7   7
#define GPIO_PIN_8   8
#define GPIO_PIN_9   9
#define GPIO_PIN_10  10
#define GPIO_PIN_11  11
#define GPIO_PIN_12  12
#define GPIO_PIN_13  13
#define GPIO_PIN_14  14
#define GPIO_PIN_15  15
#define GPIO_PIN_16  16
#define GPIO_PIN_17  17
#define GPIO_PIN_18  18
#define GPIO_PIN_19  19
#define GPIO_PIN_20  20
#define GPIO_PIN_21  21
#define GPIO_PIN_22  22
#define GPIO_PIN_23  23
#define GPIO_PIN_24  24
#define GPIO_PIN_25  25
#define GPIO_PIN_26  26
#define GPIO_PIN_27  27
#define GPIO_PIN_28  28
#define GPIO_PIN_29  29
#define GPIO_PIN_30  30
#define GPIO_PIN_31  31
#define GPIO_PIN_32  32
#define GPIO_PIN_33  33
#define GPIO_PIN_34  34
#define GPIO_PIN_35  35
#define GPIO_PIN_36  36
#define GPIO_PIN_37  37
#define GPIO_PIN_38  38
#define GPIO_PIN_39  39
#define GPIO_PIN_40  40
#define GPIO_PIN_41  41
#define GPIO_PIN_42  42
#define GPIO_PIN_43  43
#define GPIO_PIN_44  44
#define GPIO_PIN_45  45
#define GPIO_PIN_46  46
#define GPIO_PIN_47  47
#define GPIO_PIN_48  48
#define GPIO_PIN_49  49
#define GPIO_PIN_50  50
#define GPIO_PIN_51  51
#define GPIO_PIN_52  52
#define GPIO_PIN_53  53
#define GPIO_PIN_54  54
#define GPIO_PIN_55  55
#define GPIO_PIN_56  56
#define GPIO_PIN_57  57
#define GPIO_PIN_58  58
#define GPIO_PIN_59  59
#define GPIO_PIN_60  60
#define GPIO_PIN_61  61
#define GPIO_PIN_62  62
#define GPIO_PIN_63  63

typedef enum {
  GPIO_PIN_RESET = 0,
  GPIO_PIN_SET
} GPIO_PinState;

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

#endif

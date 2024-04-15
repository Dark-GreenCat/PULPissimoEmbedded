#ifndef __PULPISSIMO_MEMORY_MAP_H__
#define __PULPISSIMO_MEMORY_MAP_H__

/** @addtogroup Soc peripheral_memory_map
  * @{
  */


#define SOC_PERIPHERALS_BASE    0x1A100000

#define FLL_OFFSET              0x00000000
#define GPIO_OFFSET             0x00001000
#define UDMA_OFFSET             0x00002000
#define SOC_CONTROL_OFFSET      0x00004000
#define ADVANCED_TIMER_OFFSET   0x00005000
#define SOC_EVENT_GEN_OFFSET    0x00006000
#define EVENT_INT_UNIT_OFFSET   0x00009000
#define TIMER_OFFSET            0x0000B000
#define HWPE_OFFSET             0x0000C000
#define STDOUT_OFFSET           0x0000F000
#define DEBUG_UNIT_OFFSET       0x00010000

#define FLL_BASE                (SOC_PERIPHERALS_BASE + FLL_OFFSET)
#define GPIO_BASE               (SOC_PERIPHERALS_BASE + GPIO_OFFSET)
#define UDMA_BASE               (SOC_PERIPHERALS_BASE + UDMA_OFFSET)
#define SOC_CONTROL_BASE        (SOC_PERIPHERALS_BASE + SOC_CONTROL_OFFSET)
#define ADVANCED_TIMER_BASE     (SOC_PERIPHERALS_BASE + ADVANCED_TIMER_OFFSET)
#define SOC_EVENT_GEN_BASE      (SOC_PERIPHERALS_BASE + SOC_EVENT_GEN_OFFSET)
#define EVENT_INT_UNIT_BASE     (SOC_PERIPHERALS_BASE + EVENT_INT_UNIT_OFFSET)
#define TIMER_BASE              (SOC_PERIPHERALS_BASE + TIMER_OFFSET)
#define HWPE_BASE               (SOC_PERIPHERALS_BASE + HWPE_OFFSET)
#define STDOUT_BASE             (SOC_PERIPHERALS_BASE + STDOUT_OFFSET)
#define DEBUG_UNIT_BASE         (SOC_PERIPHERALS_BASE + DEBUG_UNIT_OFFSET)


/*!< APB peripherals */
#define GPIOL_BASE              (GPIO_BASE + 0x00000000UL)
#define GPIOH_BASE              (GPIO_BASE + 0x00000038UL)

/*!< uDMA peripherals */

/**
  * @}
  */

/** @addtogroup Peripheral_declaration
  * @{
  */  
#define GPIOL               ((GPIO_TypeDef *) GPIOL_BASE)
#define GPIOH               ((GPIO_TypeDef *) GPIOH_BASE)
/**
  * @}
  */
#endif

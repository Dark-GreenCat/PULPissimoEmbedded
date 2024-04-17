#ifndef __GPIO_HCL_DEF_H
#define __GPIO_HCL_DEF_H

/* Includes ------------------------------------------------------------------*/
#include "../pulpissimo/pulpissimo.h"
#include "soc_control/soc_control_hcl_def.h"


/** @addtogroup PULPissimo_HCL_Driver
  * @{
  */

/** @addtogroup GPIO
  * @{
  */ 

/* Exported types ------------------------------------------------------------*/ 

/** @defgroup GPIO_Exported_Types GPIO Exported Types
  * @{
  */
/** 
  * @brief   GPIO Init structure definition  
  */
typedef struct
{
  uint32_t Pin;       /*!< Specifies the GPIO pins to be configured. This parameter can be any value of @ref GPIO_pins */
  uint32_t Mode;      /*!< Specifies the operating mode for the selected pins. This parameter can be a value of @ref GPIO_mode */
  uint32_t Pull;      /*!< Specifies the Pull-up or Pull-Down activation for the selected pins. This parameter can be a value of @ref GPIO_pull */
}GPIO_InitTypeDef;

/**
  * @brief  GPIO handle Structure definition
  */
typedef struct {
    GPIO_TypeDef* Instance; /*!< GPIO registers base address        */
    uint8_t Pin;
} GPIO_HandleTypeDef;
/** 
  * @brief  GPIO Bit SET and Bit RESET enumeration 
  */
typedef enum
{
  GPIO_PIN_RESET = 0U,
  GPIO_PIN_SET
}GPIO_PinState;
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup GPIO_Exported_Constants GPIO Exported Constants
  * @{
  */
/** @defgroup GPIO_pins GPIO pins
  * @{
  */
#define GPIO_PIN_0                 ((uint32_t)0x00000001U)  /* Pin 0 selected    */
#define GPIO_PIN_1                 ((uint32_t)0x00000002U)  /* Pin 1 selected    */
#define GPIO_PIN_2                 ((uint32_t)0x00000004U)  /* Pin 2 selected    */
#define GPIO_PIN_3                 ((uint32_t)0x00000008U)  /* Pin 3 selected    */
#define GPIO_PIN_4                 ((uint32_t)0x00000010U)  /* Pin 4 selected    */
#define GPIO_PIN_5                 ((uint32_t)0x00000020U)  /* Pin 5 selected    */
#define GPIO_PIN_6                 ((uint32_t)0x00000040U)  /* Pin 6 selected    */
#define GPIO_PIN_7                 ((uint32_t)0x00000080U)  /* Pin 7 selected    */
#define GPIO_PIN_8                 ((uint32_t)0x00000100U)  /* Pin 8 selected    */
#define GPIO_PIN_9                 ((uint32_t)0x00000200U)  /* Pin 9 selected    */
#define GPIO_PIN_10                ((uint32_t)0x00000400U)  /* Pin 10 selected   */
#define GPIO_PIN_11                ((uint32_t)0x00000800U)  /* Pin 11 selected   */
#define GPIO_PIN_12                ((uint32_t)0x00001000U)  /* Pin 12 selected   */
#define GPIO_PIN_13                ((uint32_t)0x00002000U)  /* Pin 13 selected   */
#define GPIO_PIN_14                ((uint32_t)0x00004000U)  /* Pin 14 selected   */
#define GPIO_PIN_15                ((uint32_t)0x00008000U)  /* Pin 15 selected   */
#define GPIO_PIN_16                ((uint32_t)0x00010000U)  /* Pin 16 selected   */
#define GPIO_PIN_17                ((uint32_t)0x00020000U)  /* Pin 17 selected   */
#define GPIO_PIN_18                ((uint32_t)0x00040000U)  /* Pin 18 selected   */
#define GPIO_PIN_19                ((uint32_t)0x00080000U)  /* Pin 19 selected   */
#define GPIO_PIN_20                ((uint32_t)0x00100000U)  /* Pin 20 selected   */
#define GPIO_PIN_21                ((uint32_t)0x00200000U)  /* Pin 21 selected   */
#define GPIO_PIN_22                ((uint32_t)0x00400000U)  /* Pin 22 selected   */
#define GPIO_PIN_23                ((uint32_t)0x00800000U)  /* Pin 23 selected   */
#define GPIO_PIN_24                ((uint32_t)0x01000000U)  /* Pin 24 selected   */
#define GPIO_PIN_25                ((uint32_t)0x02000000U)  /* Pin 25 selected   */
#define GPIO_PIN_26                ((uint32_t)0x04000000U)  /* Pin 26 selected   */
#define GPIO_PIN_27                ((uint32_t)0x08000000U)  /* Pin 27 selected   */
#define GPIO_PIN_28                ((uint32_t)0x10000000U)  /* Pin 28 selected   */
#define GPIO_PIN_29                ((uint32_t)0x20000000U)  /* Pin 29 selected   */
#define GPIO_PIN_30                ((uint32_t)0x40000000U)  /* Pin 30 selected   */
#define GPIO_PIN_31                ((uint32_t)0x80000000U)  /* Pin 31 selected   */
#define GPIO_PIN_All               ((uint32_t)0xFFFFFFFFU)  /* All pins selected */

#define GPIO_PIN_MASK              (0xFFFFFFFFU) /* PIN mask for assert test */
#define GPIO_PIN_NUMBER(GPIO_PIN_x) (__builtin_ctz((GPIO_PIN_x)))
/**
  * @}
  */

/** @defgroup GPIO_mode GPIO mode
  * @brief GPIO Configuration Mode
  *        Elements values convention: 0x00W0000Z
  *           - W  : EXTI trigger detection on 2 bits
  *           - Z  : GPIO mode (Input, Output) on 1 bits
  * @{
  */ 
#define  GPIO_MODE_INPUT            MODE_INPUT                                                  /*!< Input Floating Mode                   */
#define  GPIO_MODE_OUTPUT           MODE_OUTPUT                                   /*!< Output Push Pull Mode                 */

#define  GPIO_MODE_IT_RISING                    (MODE_INPUT | TRIGGER_RISING)                     /*!< External Interrupt Mode with Rising edge trigger detection          */
#define  GPIO_MODE_IT_FALLING                   (MODE_INPUT | TRIGGER_FALLING)                    /*!< External Interrupt Mode with Falling edge trigger detection         */
#define  GPIO_MODE_IT_RISING_FALLING            (MODE_INPUT | TRIGGER_RISING | TRIGGER_FALLING)   /*!< External Interrupt Mode with Rising/Falling edge trigger detection  */

/**
  * @}
  */

 /** @defgroup GPIO_pull GPIO pull
   * @brief GPIO Pull-Up or Pull-Down Activation
   * @{
   */  
#define  GPIO_PULL_Msk      (0x00000001U)
#define  GPIO_PULLDOWN      (0x00000000U)   /*!< Pull-up activation                  */
#define  GPIO_PULLUP        (0x00000001U)   /*!< Pull-down activation                */
/**
  * @}
  */

 /** @defgroup GPIO_pad_mux GPIO pad mux
   * @brief GPIO with coresponding PAD_MUX value
   * @{
   */  
#define GPIOL_PIN_0_PADMUX_Pos                 SOCCTRL_PAD_MUX_0_PADMUX0_Pos
#define GPIOL_PIN_0_PADMUX_Msk                 SOCCTRL_PAD_MUX_0_PADMUX0_Msk
#define GPIOL_PIN_1_PADMUX_Pos                 SOCCTRL_PAD_MUX_0_PADMUX1_Pos
#define GPIOL_PIN_1_PADMUX_Msk                 SOCCTRL_PAD_MUX_0_PADMUX1_Msk
#define GPIOL_PIN_2_PADMUX_Pos                 SOCCTRL_PAD_MUX_0_PADMUX2_Pos
#define GPIOL_PIN_2_PADMUX_Msk                 SOCCTRL_PAD_MUX_0_PADMUX2_Msk
#define GPIOL_PIN_3_PADMUX_Pos                 SOCCTRL_PAD_MUX_0_PADMUX3_Pos
#define GPIOL_PIN_3_PADMUX_Msk                 SOCCTRL_PAD_MUX_0_PADMUX3_Msk
#define GPIOL_PIN_4_PADMUX_Pos                 SOCCTRL_PAD_MUX_0_PADMUX4_Pos
#define GPIOL_PIN_4_PADMUX_Msk                 SOCCTRL_PAD_MUX_0_PADMUX4_Msk
#define GPIOL_PIN_5_PADMUX_Pos                 SOCCTRL_PAD_MUX_0_PADMUX5_Pos
#define GPIOL_PIN_5_PADMUX_Msk                 SOCCTRL_PAD_MUX_0_PADMUX5_Msk
#define GPIOL_PIN_6_PADMUX_Pos                 SOCCTRL_PAD_MUX_0_PADMUX6_Pos
#define GPIOL_PIN_6_PADMUX_Msk                 SOCCTRL_PAD_MUX_0_PADMUX6_Msk
#define GPIOL_PIN_7_PADMUX_Pos                 SOCCTRL_PAD_MUX_0_PADMUX7_Pos
#define GPIOL_PIN_7_PADMUX_Msk                 SOCCTRL_PAD_MUX_0_PADMUX7_Msk
#define GPIOL_PIN_8_PADMUX_Pos                 SOCCTRL_PAD_MUX_0_PADMUX8_Pos
#define GPIOL_PIN_8_PADMUX_Msk                 SOCCTRL_PAD_MUX_0_PADMUX8_Msk
#define GPIOL_PIN_9_PADMUX_Pos                 SOCCTRL_PAD_MUX_0_PADMUX9_Pos
#define GPIOL_PIN_9_PADMUX_Msk                 SOCCTRL_PAD_MUX_0_PADMUX9_Msk
#define GPIOL_PIN_10_PADMUX_Pos                SOCCTRL_PAD_MUX_0_PADMUX10_Pos
#define GPIOL_PIN_10_PADMUX_Msk                SOCCTRL_PAD_MUX_0_PADMUX10_Msk
#define GPIOL_PIN_11_PADMUX_Pos                SOCCTRL_PAD_MUX_0_PADMUX11_Pos
#define GPIOL_PIN_11_PADMUX_Msk                SOCCTRL_PAD_MUX_0_PADMUX11_Msk
#define GPIOL_PIN_12_PADMUX_Pos                SOCCTRL_PAD_MUX_0_PADMUX12_Pos
#define GPIOL_PIN_12_PADMUX_Msk                SOCCTRL_PAD_MUX_0_PADMUX12_Msk
#define GPIOL_PIN_13_PADMUX_Pos                SOCCTRL_PAD_MUX_0_PADMUX13_Pos
#define GPIOL_PIN_13_PADMUX_Msk                SOCCTRL_PAD_MUX_0_PADMUX13_Msk
#define GPIOL_PIN_14_PADMUX_Pos                SOCCTRL_PAD_MUX_0_PADMUX14_Pos
#define GPIOL_PIN_14_PADMUX_Msk                SOCCTRL_PAD_MUX_0_PADMUX14_Msk
#define GPIOL_PIN_15_PADMUX_Pos                SOCCTRL_PAD_MUX_0_PADMUX15_Pos
#define GPIOL_PIN_15_PADMUX_Msk                SOCCTRL_PAD_MUX_0_PADMUX15_Msk
#define GPIOL_PIN_16_PADMUX_Pos                SOCCTRL_PAD_MUX_1_PADMUX16_Pos
#define GPIOL_PIN_16_PADMUX_Msk                SOCCTRL_PAD_MUX_1_PADMUX16_Msk
#define GPIOL_PIN_17_PADMUX_Pos                SOCCTRL_PAD_MUX_1_PADMUX17_Pos
#define GPIOL_PIN_17_PADMUX_Msk                SOCCTRL_PAD_MUX_1_PADMUX17_Msk
#define GPIOL_PIN_18_PADMUX_Pos                SOCCTRL_PAD_MUX_1_PADMUX18_Pos
#define GPIOL_PIN_18_PADMUX_Msk                SOCCTRL_PAD_MUX_1_PADMUX18_Msk
#define GPIOL_PIN_19_PADMUX_Pos                SOCCTRL_PAD_MUX_1_PADMUX19_Pos
#define GPIOL_PIN_19_PADMUX_Msk                SOCCTRL_PAD_MUX_1_PADMUX19_Msk
#define GPIOL_PIN_20_PADMUX_Pos                SOCCTRL_PAD_MUX_1_PADMUX20_Pos
#define GPIOL_PIN_20_PADMUX_Msk                SOCCTRL_PAD_MUX_1_PADMUX20_Msk
#define GPIOL_PIN_21_PADMUX_Pos                SOCCTRL_PAD_MUX_1_PADMUX21_Pos
#define GPIOL_PIN_21_PADMUX_Msk                SOCCTRL_PAD_MUX_1_PADMUX21_Msk
#define GPIOL_PIN_22_PADMUX_Pos                SOCCTRL_PAD_MUX_1_PADMUX22_Pos
#define GPIOL_PIN_22_PADMUX_Msk                SOCCTRL_PAD_MUX_1_PADMUX22_Msk
#define GPIOL_PIN_23_PADMUX_Pos                SOCCTRL_PAD_MUX_1_PADMUX23_Pos
#define GPIOL_PIN_23_PADMUX_Msk                SOCCTRL_PAD_MUX_1_PADMUX23_Msk
#define GPIOL_PIN_24_PADMUX_Pos                SOCCTRL_PAD_MUX_1_PADMUX24_Pos
#define GPIOL_PIN_24_PADMUX_Msk                SOCCTRL_PAD_MUX_1_PADMUX24_Msk
#define GPIOL_PIN_25_PADMUX_Pos                SOCCTRL_PAD_MUX_1_PADMUX25_Pos
#define GPIOL_PIN_25_PADMUX_Msk                SOCCTRL_PAD_MUX_1_PADMUX25_Msk
#define GPIOL_PIN_26_PADMUX_Pos                SOCCTRL_PAD_MUX_2_PADMUX33_Pos
#define GPIOL_PIN_26_PADMUX_Msk                SOCCTRL_PAD_MUX_2_PADMUX33_Msk
#define GPIOL_PIN_27_PADMUX_Pos                SOCCTRL_PAD_MUX_2_PADMUX34_Pos
#define GPIOL_PIN_27_PADMUX_Msk                SOCCTRL_PAD_MUX_2_PADMUX34_Msk
#define GPIOL_PIN_28_PADMUX_Pos                SOCCTRL_PAD_MUX_2_PADMUX35_Pos
#define GPIOL_PIN_28_PADMUX_Msk                SOCCTRL_PAD_MUX_2_PADMUX35_Msk
#define GPIOL_PIN_29_PADMUX_Pos                SOCCTRL_PAD_MUX_2_PADMUX36_Pos
#define GPIOL_PIN_29_PADMUX_Msk                SOCCTRL_PAD_MUX_2_PADMUX36_Msk
#define GPIOL_PIN_30_PADMUX_Pos                SOCCTRL_PAD_MUX_2_PADMUX37_Pos
#define GPIOL_PIN_30_PADMUX_Msk                SOCCTRL_PAD_MUX_2_PADMUX37_Msk
#define GPIOL_PIN_31_PADMUX_Pos                SOCCTRL_PAD_MUX_2_PADMUX38_Pos
#define GPIOL_PIN_31_PADMUX_Msk                SOCCTRL_PAD_MUX_2_PADMUX38_Msk

#define GPIOL_PIN_x_PADMUX_Pos(GPIOL_PIN_NUMBER) \
    ((GPIOL_PIN_NUMBER < 16) ? (GPIOL_PIN_NUMBER * 2) : \
    ((GPIOL_PIN_NUMBER < 26) ? ((GPIOL_PIN_NUMBER - 16) * 2) : \
    ((GPIOL_PIN_NUMBER - 25) * 2)))
/**
  * @}
  */

/**
  * @}
  */


/* Exported macro ------------------------------------------------------------*/
/** @defgroup GPIO_Exported_Macros GPIO Exported Macros
  * @{
  */
/* Private macros ------------------------------------------------------------*/
/** @defgroup GPIO_Private_Constants GPIO Private Constants
  * @{
  */
#define GPIO_MODE_Pos                           0U
#define GPIO_MODE_Msk                           (0x1UL << GPIO_MODE_Pos)
#define GPIO_MODE                               (0x3UL << GPIO_MODE_Pos)
#define MODE_INPUT                              (0x0UL << GPIO_MODE_Pos)
#define MODE_OUTPUT                             (0x1UL << GPIO_MODE_Pos)
#define TRIGGER_MODE_Pos                        20U
#define TRIGGER_MODE                            (0x3UL << TRIGGER_MODE_Pos)
#define TRIGGER_RISING                          (0x1UL << TRIGGER_MODE_Pos)
#define TRIGGER_FALLING                         (0x2UL << TRIGGER_MODE_Pos)
/**
  * @}
  */
/**
  * @}
  */

#endif

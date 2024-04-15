#ifndef __GPIO_HCL_DEF_H
#define __GPIO_HCL_DEF_H

/* Includes ------------------------------------------------------------------*/
#include "../pulpissimo/pulpissimo.h"

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
/**
  * @}
  */

/** @defgroup GPIO_mode GPIO mode
  * @brief GPIO Configuration Mode
  *        Elements values convention: 0x0000000Z
  *           - Z  : GPIO mode (Input, Output) on 1 bits
  * @{
  */ 
#define  GPIO_MODE_INPUT            MODE_INPUT                                                  /*!< Input Floating Mode                   */
#define  GPIO_MODE_OUTPUT           MODE_OUTPUT                                   /*!< Output Push Pull Mode                 */
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
/**
  * @}
  */
/**
  * @}
  */

#endif

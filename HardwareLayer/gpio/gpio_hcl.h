#ifndef __GPIO_HCL_H
#define __GPIO_HCL_HGPIO_TypeDef

#include "gpio_hcl_def.h"

/* Exported functions --------------------------------------------------------*/ 
/** @addtogroup GPIO_Exported_Functions GPIO Exported Functions
  * @{
  */

/** @addtogroup GPIO_Exported_Functions_Group1 Initialization/de-initialization functions 
 *  @brief    Initialization and Configuration functions
 * @{
 */
     
/* Initialization and de-initialization functions *****************************/
void              HCL_GPIO_Init(GPIO_TypeDef  *GPIOx, GPIO_InitTypeDef *GPIO_Init);
void              HCL_GPIO_DeInit(GPIO_TypeDef  *GPIOx, uint32_t GPIO_Pin);

/**
  * @}
  */

/** @addtogroup GPIO_Exported_Functions_Group2 IO operation functions 
 * @{
 */
   
/* IO operation functions *****************************************************/
GPIO_PinState     HCL_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void              HCL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);
void              HCL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

/**
  * @}
  */ 

/**
  * @}
  */ 

#endif

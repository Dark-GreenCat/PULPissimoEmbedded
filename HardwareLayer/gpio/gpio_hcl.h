#ifndef __GPIO_HCL_H
#define __GPIO_HCL_H

#include "pulpissimo_utils.h"
#include "gpio_def.h"

void HCL_GPIO_Init(void);

void HCL_GPIO_Config(GPIO_HandleTypeDef* hgpio, GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void HCL_GPIO_WritePin(GPIO_HandleTypeDef* hgpio, GPIO_PinState PinState);
GPIO_PinState HCL_GPIO_ReadPin(GPIO_HandleTypeDef* hgpio);
void HCL_GPIO_TogglePin(GPIO_HandleTypeDef* hgpio);

#endif

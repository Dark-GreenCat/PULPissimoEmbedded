#include "gpio_hcl.h"

void HCL_GPIO_Init() {
}

void HCL_GPIO_Config(GPIO_HandleTypeDef* hgpio, GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
    hgpio->Port = GPIOx;
    hgpio->Pin = GPIO_Pin;
}

void HCL_GPIO_WritePin(GPIO_HandleTypeDef *hgpio, GPIO_PinState PinState) {
    if (hgpio->Pin < 32) {
        if (PinState == GPIO_PIN_RESET) {
            SET_BIT(hgpio->Port->PADOUTSET, hgpio->Pin);
        } else {
            SET_BIT(hgpio->Port->PADOUTCLR, hgpio->Pin);
        }
    }
    else {
        if (PinState == GPIO_PIN_RESET) {
            SET_BIT(hgpio->Port->PADOUTSET_32_63, hgpio->Pin - 32);
        } else {
            SET_BIT(hgpio->Port->PADOUTCLR_32_63, hgpio->Pin - 32);
        }
    }
}

GPIO_PinState HCL_GPIO_ReadPin(GPIO_HandleTypeDef* hgpio) {
    return (hgpio->Pin < 32) ?  READ_BIT(hgpio->Port->PADIN, hgpio->Pin) : 
                                READ_BIT(hgpio->Port->PADIN_32_63, hgpio->Pin - 32);
}

void HCL_GPIO_TogglePin(GPIO_HandleTypeDef* hgpio) {
    if (hgpio->Pin < 32)
        TOGGLE_BIT(hgpio->Port->PADOUT, hgpio->Pin);
    else
        TOGGLE_BIT(hgpio->Port->PADOUT_32_63, hgpio->Pin - 32);
}


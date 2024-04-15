#include "gpio_hcl.h"

// void HCL_GPIO_Init() {
// }

// void HCL_GPIO_Config(GPIO_HandleTypeDef* hgpio, GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
//     hgpio->Port = GPIOx;
//     hgpio->Pin = GPIO_Pin;
// }

// void HCL_GPIO_WritePin(GPIO_HandleTypeDef *hgpio, GPIO_PinState PinState) {
//     if (hgpio->Pin < 32) {
//         if (PinState == GPIO_PIN_RESET) {
//             SET_BIT(hgpio->Port->PADOUTSET, hgpio->Pin);
//         } else {
//             SET_BIT(hgpio->Port->PADOUTCLR, hgpio->Pin);
//         }
//     }
//     else {
//         if (PinState == GPIO_PIN_RESET) {
//             SET_BIT(hgpio->Port->PADOUTSET_32_63, hgpio->Pin - 32);
//         } else {
//             SET_BIT(hgpio->Port->PADOUTCLR_32_63, hgpio->Pin - 32);
//         }
//     }
// }

// GPIO_PinState HCL_GPIO_ReadPin(GPIO_HandleTypeDef* hgpio) {
//     return (hgpio->Pin < 32) ?  READ_BIT(hgpio->Port->PADIN, hgpio->Pin) : 
//                                 READ_BIT(hgpio->Port->PADIN_32_63, hgpio->Pin - 32);
// }

// void HCL_GPIO_TogglePin(GPIO_HandleTypeDef* hgpio) {
//     if (hgpio->Pin < 32)
//         TOGGLE_BIT(hgpio->Port->PADOUT, hgpio->Pin);
//     else
//         TOGGLE_BIT(hgpio->Port->PADOUT_32_63, hgpio->Pin - 32);
// }

void HCL_GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_Init) {
    uint32_t position = 0x00u;
    uint32_t iocurrent;
    uint32_t temp;

    while (((GPIO_Init->Pin) >> position) != 0x00u) {
        /* Get current io position */
        iocurrent = (GPIO_Init->Pin) & (1uL << position);
        if (iocurrent == 0x00u) continue;

        /*--------------------- GPIO Mode Configuration ------------------------*/
        temp = (GPIO_Init->Mode & GPIO_MODE_Msk);
        MODIFY_REG(GPIOx->PADDIR, (1uL << position), (temp << position));

        /* Activate the Pull-up or Pull down resistor for the current IO */
        temp = (GPIO_Init->Pull & GPIO_PULL_Msk);
        MODIFY_REG(GPIOx->PADOUT, (1uL << position), (temp << position));

        /*--------------------- GPIO Clock Enable ------------------------------*/
        SET_BIT(GPIOx->GPIOEN, (1uL << position));

        position++;
    }
}

void HCL_GPIO_DeInit(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin) {
    uint32_t position = 0x00u;
    uint32_t iocurrent;
    uint32_t temp;

    while (((GPIO_Pin) >> position) != 0x00u) {
        /* Get current io position */
        iocurrent = (GPIO_Pin) & (1uL << position);
        if (iocurrent == 0x00u) continue;

        /*--------------------- GPIO Mode Configuration ------------------------*/
        /* Configure IO Direction in Input Floating Mode */
        CLEAR_BIT(GPIOx->PADDIR, (1UL << position));

        /*--------------------- GPIO Clock Disable ------------------------------*/
        CLEAR_BIT(GPIOx->GPIOEN, (1uL << position));
        
        position++;
    }
}

GPIO_PinState HCL_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin) {
    return (GPIO_PinState) READ_BIT(GPIOx->PADIN, GPIO_Pin);
}

void HCL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin, GPIO_PinState PinState) {
    if (PinState == GPIO_PIN_RESET)
        SET_BIT(GPIOx->PADOUTSET, GPIO_Pin);
    else 
        SET_BIT(GPIOx->PADOUTCLR, GPIO_Pin);
}

void HCL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin) {
    GPIOx->PADOUT ^= GPIO_Pin;
}

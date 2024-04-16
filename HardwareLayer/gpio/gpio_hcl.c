#include "gpio_hcl.h"

void HCL_GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_Init) {
    uint32_t position = 0x00u;
    uint32_t iocurrent;
    uint32_t temp;

    while (((GPIO_Init->Pin) >> position) != 0x00u) {
        /* Get current io position */
        iocurrent = (GPIO_Init->Pin) & (1uL << position);
        if (iocurrent == 0x00u) {
            position++;
            continue;
        }

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
        if (iocurrent == 0x00u) {
            position++;
            continue;
        }

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

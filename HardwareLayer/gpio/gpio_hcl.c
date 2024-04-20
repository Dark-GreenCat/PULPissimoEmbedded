#include "gpio_hcl.h"

void HCL_GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_Init) {
    uint32_t position = 0x00u;
    uint32_t iocurrent;
    uint32_t temp;

    for(position = 0x00u; ((GPIO_Init->Pin) >> position) != 0x00u; position++) {
        /* Get current io position */
        iocurrent = (GPIO_Init->Pin) & (1uL << position);
        if (iocurrent == 0x00u) continue;

        /*--------------------- GPIO Mode Configuration ------------------------*/
        temp = (GPIO_Init->Mode & GPIO_MODE_Msk);
        MODIFY_REG(GPIOx->PADDIR, (1uL << position), (temp << position));

        /* Activate the Pull-up or Pull down resistor for the current IO */
        temp = (GPIO_Init->Pull & GPIO_PULL_Msk);
        MODIFY_REG(GPIOx->PADOUT, (1uL << position), (temp << position));
        
        /* Disable GPIO Interrupt */
        CLEAR_BIT(GPIOx->INTEN, (1uL << position));

        /*--------------------- EXTI Mode Configuration ------------------------*/
        if (GPIO_Init->Mode & TRIGGER_MODE_Msk) {
            temp = (((GPIO_Init->Mode & TRIGGER_MODE_Msk) >> TRIGGER_MODE_Pos) - 1uL);   

            if (position < 16)  MODIFY_REG(GPIOx->INTTYPE0, (3uL << (position * 2)), (temp << (position * 2)));
            else                MODIFY_REG(GPIOx->INTTYPE1, (3uL << ((position - 16) * 2)), (temp << ((position - 16) * 2)));

            /* Enable GPIO Interrupt */
            SET_BIT(GPIOx->INTEN, (1uL << position));
        }

        /* Redirect Pad Mux to GPIO pin */
        if (GPIOx == GPIOL) {
            temp = GPIOL_PIN_x_PADMUX_Pos(GPIO_PIN_NUMBER(GPIO_Init->Pin));
            MODIFY_REG(SOCCTRL->PAD_MUX[((position < 16)? 0 : 1)], (3uL << temp), (1uL << temp)); 
        }

        /*--------------------- GPIO Clock Enable ----------------------    --------*/
        SET_BIT(GPIOx->GPIOEN, (1uL << position));

        position++;
    }
}

void HCL_GPIO_DeInit(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin) {
    uint32_t position = 0x00u;
    uint32_t iocurrent;
    uint32_t temp;

    for(position = 0x00u; ((GPIO_Pin) >> position) != 0x00u; position++) {
        /* Get current io position */
        iocurrent = (GPIO_Pin) & (1uL << position);
        if (iocurrent == 0x00u) continue;

        /*--------------------- GPIO Mode Configuration ------------------------*/
        /* Configure IO Direction in Input Floating Mode */
        CLEAR_BIT(GPIOx->PADDIR, (1uL << position));
        
        /* Reset Pull down resistor for the current IO */
        CLEAR_BIT(GPIOx->PADOUTCLR, (1uL << position));

        /* Disable GPIO Interrupt */
        CLEAR_BIT(GPIOx->INTEN, (1uL << position));

        /*--------------------- EXTI Mode Configuration ------------------------*/
        /* Reset Interrupt Mode to default */
        if (position < 16)  CLEAR_BIT(GPIOx->INTTYPE0, (3uL << (position * 2)));
        else                CLEAR_BIT(GPIOx->INTTYPE1, (3uL << ((position - 16) * 2)));     

        /* Reset Pad Mux */
        if (GPIOx == GPIOL) {
            temp = GPIOL_PIN_x_PADMUX_Pos(GPIO_PIN_NUMBER(GPIO_Pin));
            CLEAR_BIT(SOCCTRL->PAD_MUX[((position < 16)? 0 : 1)], (3uL << temp));
        }

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

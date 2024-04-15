#include "gpio/gpio_hcl.h"

#define PAD_MUX_1     0x00000000

#define LED_PIN           GPIO_PIN_11
GPIO_HandleTypeDef hgpio_led;

volatile GPIO_TypeDef *GPIO = (volatile GPIO_TypeDef *) ARCHI_GPIO_ADDR;

void delay_spin(uint32_t cnt) {
  while (cnt--) {
    __asm__ volatile ("nop");
  }
}

void HCL_Delay(uint32_t ms) {
  while (ms--) {
    delay_spin(10000);
  }
}

void MX_GPIO_Init(void) {
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /*Configure GPIO pins : L11 */
  GPIO_InitStruct.Pin = GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT;
  HCL_GPIO_Init(GPIOL_BASE, &GPIO_InitStruct);
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  hgpio_led.Port = GPIO;
  hgpio_led.Pin = LED_PIN;
  
  ARCHI_WRITE(ARCHI_APB_SOC_CTRL_ADDR, APB_SOC_PADFUN0_OFFSET, (1UL << (11 * 2)));
  SET_BIT(hgpio_led.Port->PADDIR, hgpio_led.Pin);
  SET_BIT(hgpio_led.Port->GPIOEN, hgpio_led.Pin);
}

int main()
{
  MX_GPIO_Init();

  while (1) {
    HCL_GPIO_TogglePin(&hgpio_led);
    HCL_Delay(1000);
  }

  return 0;
}

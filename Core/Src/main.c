#include "gpio/gpio_hcl.h"

#define PAD_MUX_1     0x00000000

#define LED_GPIO_Port     GPIOL
#define LED_Pin           GPIO_PIN_11

extern void delay_us(uint32_t us);

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

  /*Configure GPIO pins : LED */
  GPIO_InitStruct.Pin = LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HCL_GPIO_Init(LED_GPIO_Port, &GPIO_InitStruct);
}

int main()
{
  MX_GPIO_Init();

  while (1) {
    HCL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
    // HCL_Delay(1000);
    delay_us(500000);
  }

  return 0;
}

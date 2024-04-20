#include "gpio/gpio_hcl.h"
#include "implem/irq.h"

#define PAD_MUX_1     0x00000000

#define LED_GPIO_Port     GPIOL
#define LED_Pin           GPIO_PIN_11

#define BTN_GPIO_Port     GPIOL
#define BTN_Pin           GPIO_PIN_14

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

  /*Configure GPIO pins : LED */
  GPIO_InitStruct.Pin = BTN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HCL_GPIO_Init(BTN_GPIO_Port, &GPIO_InitStruct);
}

void HCL_GPIO_IRQ_Handler(void) {
  uint8_t count = 10;
  while (count--) {
    HCL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
    delay_us(100000);
  }
}

int main()
{
  MX_GPIO_Init();

  rt_irq_set_handler(15, HCL_GPIO_IRQ_Handler);
  SET_BIT(*((volatile uint32_t*) 0x1A109004), 1uL << 15);

  while (1) {
    HCL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
    // HCL_Delay(1000);
    delay_us(500000);
  }

  return 0;
}

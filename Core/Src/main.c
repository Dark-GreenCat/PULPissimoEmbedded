#include <stdint.h>

#include <hal/gpio/gpio_v3.h>

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

extern void delay_us(uint32_t us);

int main()
{
  hal_gpio_set_dir(1 << 11, 1);
  hal_gpio_en_set(1 << 11);

  while(1) {
    hal_gpio_set_pin_value(11, 1);
    delay_us(500000);
    hal_gpio_set_pin_value(11, 0);
    delay_us(500000);
  }
}

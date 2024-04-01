#include "archi/chips/pulpissimo/apb_soc.h"
#include "archi/chips/pulpissimo/memory_map.h"
#include "archi/gpio/gpio_v3.h"
#include "archi/utils.h"
#include <stdio.h>
#include <pulp.h>
#include <stdint.h>
#include <hal/gpio/gpio_v3.h>

#include "gpio_def.h"
#include "pulpissimo_utils.h"

#define PAD_MUX_1     0x00000000
volatile GPIO_TypeDef *GPIO = (volatile GPIO_TypeDef *) ARCHI_GPIO_ADDR;

void delay_spin(uint32_t cnt) {
  while (cnt--) {
    __asm__ volatile ("nop");
  }
}

int main()
{
  // // Map LED3 to GPIO11
  // ARCHI_WRITE(ARCHI_APB_SOC_CTRL_ADDR, APB_SOC_PADFUN0_OFFSET + PAD_MUX_1, 1UL << (11 * 2)); 
  // // Config GPIO11 as OUTPUT
  // ARCHI_WRITE(ARCHI_GPIO_ADDR, GPIO_PADDIR_OFFSET, 1UL << 11);
  // // Turn on GPIO11 Clock
  // ARCHI_WRITE(ARCHI_GPIO_ADDR, GPIO_GPIOEN_OFFSET, 1UL << 11);

  SET_BIT(GPIO->PADDIR, 11);
  SET_BIT(GPIO->GPIOEN, 11);
  // GPIO->PADDIR |= (1UL << 11);
  // GPIO->GPIOEN |= (1UL << 11);

  while (1) {
    SET_BIT(GPIO->PADOUT, 11);
    //GPIO->PADOUT |= (1UL << 11);
    delay_spin(1000000);
    CLEAR_BIT(GPIO->PADOUT, 11);
    //GPIO->PADOUT &= ~(1UL << 11);
    delay_spin(1000000);
  // Turn on GPIO11
  // ARCHI_WRITE(ARCHI_GPIO_ADDR, GPIO_PADOUT_OFFSET, 1UL << 11);
  }

  return 0;
}

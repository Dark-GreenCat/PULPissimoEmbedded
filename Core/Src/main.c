#include "gpio/gpio_hcl.h"
#include "implem/irq.h"

// #define hal_spr_read_then_clr(reg,val) \
//   ({ \
//     int state; \
//     asm volatile ("csrrc %0, %1, %2" :  "=r" (state) : "I" (reg), "I" (val) ); \
//     state; \
//   })

// #define hal_spr_read_then_set(reg,val) \
//   ({ \
//     int state; \
//     asm volatile ("csrrs %0, %1, %2" :  "=r" (state) : "I" (reg), "I" (val) ); \
//     state; \
//   })

// static inline void hal_irq_enable()
// {
//   // This memory barrier is needed to prevent the compiler to cross the irq barrier
//   __asm__ __volatile__ ("" : : : "memory");
//   hal_spr_read_then_set(0x300, 0x1<<3);
// }

// static inline int hal_irq_disable()
// {
//   int irq = hal_spr_read_then_clr(0x300, 0x1<<3);
//   // This memory barrier is needed to prevent the compiler to cross the irq barrier
//   __asm__ __volatile__ ("" : : : "memory");
//   return irq;
// }

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
  GPIO_InitStruct.Pin = LED_Pin | GPIO_PIN_5;
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
    HCL_GPIO_TogglePin(LED_GPIO_Port, GPIO_PIN_5);
    delay_us(100000);
  }
}

#define REG(x)  (*((volatile uint32_t*) (x)))

enum {
  GPIO_INTEN = 0x1A101018,
  GPIO_INTTYPE = 0x1A10101C,
  GPIO_INTSTATUS = 0x1A101024
};

enum {
  INT_MASK = 0x1A109000,
  INT_MASK_SET = 0x1A109004,
  INT_MASK_CLR = 0x1A109008,
  INT_INTTERUPT = 0X1A10900C,
  INT_INTTERUPT_SET = 0X1A109010,
  INT_INTTERUPT_CLR = 0X1A109014,
  INT_ACK = 0x1A109018,
  INT_ACK_SET = 0x1A10901C,
  INT_ACK_CLR = 0x1A109020,
  INT_FIFO = 0x1A109024
};

enum {
  SEG_FC_MASK_4 = 0x1A106004 + 0x4 * 4,
  SEG_PR_MASK_4 = 0x1A106044 + 0x4 * 4
};

uint32_t temp;

int main()
{
  hal_irq_disable();
  MX_GPIO_Init();
  hal_irq_disable();
  SET_BIT(REG(GPIO_INTEN), 1uL << 14);
  SET_BIT(REG(GPIO_INTTYPE), (0x1 << (14 * 2)));
  SET_BIT(REG(INT_MASK_SET), 1uL << 15);

  CLEAR_BIT(REG(SEG_FC_MASK_4), 1uL << 11);
  CLEAR_BIT(REG(SEG_PR_MASK_4), 1uL << 11);

  rt_irq_set_handler(15, HCL_GPIO_IRQ_Handler);

  hal_irq_enable();

  while (1) {
    temp = REG(GPIO_INTSTATUS);
    HCL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
    // HCL_Delay(1000);
    delay_us(500000);
  }

  return 0;
}

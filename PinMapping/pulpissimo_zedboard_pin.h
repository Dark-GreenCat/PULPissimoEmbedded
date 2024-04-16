#ifndef __PULPISSIMO_ZEDBOARD_PIN_H
#define __PULPISSIMO_ZEDBOARD_PIN_H

#include "pulpissimo_functional_pin.h"

#define ZEDBOARD_UART_RX_PIN           PULPISSIMO_UART_RX_PIN                       // Package Pin: AB11
#define ZEDBOARD_UART_TX_PIN           PULPISSIMO_UART_TX_PIN                       // Package Pin: AB10
#define ZEDBOARD_UART_RTS_PIN          PULPISSIMO_UART_RTS_PIN                       // Package Pin: AB9
#define ZEDBOARD_UART_CTS_PIN          PULPISSIMO_UART_CTS_PIN                       // Package Pin: AA8

#define ZEDBOARD_LED0_PIN              PULPISSIMO_SPIM_CSN1_PIN                       // Package Pin: T22
#define ZEDBOARD_LED1_PIN              PULPISSIMO_CAM_PCLK_PIN                       // Package Pin: T21
#define ZEDBOARD_LED2_PIN              PULPISSIMO_CAM_HSYNC_PIN                       // Package Pin: U22
#define ZEDBOARD_LED3_PIN              PULPISSIMO_CAM_DATA0_PIN                       // Package Pin: U21
#define ZEDBOARD_LED4_PIN              PULPISSIMO_SPIM_SDIO0_PIN                       // Package Pin: V22
#define ZEDBOARD_LED5_PIN              PULPISSIMO_SPIM_SDIO1_PIN                       // Package Pin: W22
#define ZEDBOARD_LED6_PIN              PULPISSIMO_SPIM_SDIO2_PIN                       // Package Pin: U19
#define ZEDBOARD_LED7_PIN              PULPISSIMO_SPIM_SDIO3_PIN                       // Package Pin: U14

#define ZEDBOARD_SWITCH0_PIN           PULPISSIMO_CAM_DATA1_PIN                       // Package Pin: F22
#define ZEDBOARD_SWITCH1_PIN           PULPISSIMO_CAM_DATA2_PIN                       // Package Pin: G22
#define ZEDBOARD_SWITCH2_PIN           PULPISSIMO_CAM_DATA7_PIN                       // Package Pin: H22
#define ZEDBOARD_SWITCH3_PIN           PULPISSIMO_CAM_VSYNC_PIN                       // Package Pin: F21
#define ZEDBOARD_SWITCH4_PIN           PULPISSIMO_SDIO_DATA0_PIN                       // Package Pin: H19
#define ZEDBOARD_SWITCH5_PIN           PULPISSIMO_SDIO_DATA1_PIN                       // Package Pin: H18
#define ZEDBOARD_SWITCH6_PIN           PULPISSIMO_SDIO_DATA2_PIN                       // Package Pin: H17
#define ZEDBOARD_SWITCH7_PIN           PULPISSIMO_SDIO_DATA3_PIN                       // Package Pin: M15

#define ZEDBOARD_BTNU_PIN              PULPISSIMO_CAM_DATA3_PIN                       // Package Pin: R16
#define ZEDBOARD_BTNR_PIN              PULPISSIMO_CAM_DATA4_PIN                       // Package Pin: N15
#define ZEDBOARD_BTND_PIN              PULPISSIMO_CAM_DATA5_PIN                       // Package Pin: R18
#define ZEDBOARD_BTNL_PIN              PULPISSIMO_CAM_DATA6_PIN                       // Package Pin: T18

#define ZEDBOARD_I2C0_SDA_PIN          PULPISSIMO_I2C0_SDA_PIN                       // Package Pin: W11
#define ZEDBOARD_I2C0_SCL_PIN          PULPISSIMO_I2C0_SCL_PIN                       // Package Pin: W12
#define ZEDBOARD_I2C1_SCL_PIN          PULPISSIMO_SDIO_CLK_PIN                       // Package Pin: V10
#define ZEDBOARD_I2C1_SDA_PIN          PULPISSIMO_SDIO_CMD_PIN                       // Package Pin: W8
#define ZEDBOARD_PMOD1_4_PIN           PULPISSIMO_I2S0_SCK_PIN                       // Package Pin: V12
#define ZEDBOARD_PMOD1_5_PIN           PULPISSIMO_I2S0_WS_PIN                       // Package Pin: W10
#define ZEDBOARD_PMOD1_6_PIN           PULPISSIMO_I2S0_SDI_PIN                       // Package Pin: V9
#define ZEDBOARD_PMOD1_7_PIN           PULPISSIMO_I2S1_SDI_PIN                       // Package Pin: V8

#endif
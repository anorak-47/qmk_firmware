/*
    ChibiOS - Copyright (C) 2006..2016 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/*
 * This file has been automatically generated using ChibiStudio board
 * generator plugin. Do not edit manually.
 */

#ifndef BOARD_H
#define BOARD_H

/*
 * Setup for anorak jellowcake board.
 */

/*
 * Board identifier.
 */
#define BOARD_JELLOWCAKE303
#define BOARD_NAME                  "jellowcake303"

/*
 * Board oscillators-related settings.
 * NOTE: LSE not fitted.
 */
#define STM32_HSECLK                8000000U
#define STM32_LSECLK                0U
#define STM32_LSEDRV                (3U << 3U)

//#define STM32_LSE_BYPASS
//#define STM32_HSE_BYPASS

/*
 * MCU type as defined in the ST header file stm32f3xx.h.
 */
#define STM32F303xC

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 * Please refer to the STM32 Reference Manual for details.
 */
#define PIN_MODE_INPUT(n) (0U << ((n)*2U))
#define PIN_MODE_OUTPUT(n) (1U << ((n)*2U))
#define PIN_MODE_ALTERNATE(n) (2U << ((n)*2U))
#define PIN_MODE_ANALOG(n) (3U << ((n)*2U))
#define PIN_ODR_LOW(n) (0U << (n))
#define PIN_ODR_HIGH(n) (1U << (n))
#define PIN_OTYPE_PUSHPULL(n) (0U << (n))
#define PIN_OTYPE_OPENDRAIN(n) (1U << (n))
#define PIN_OSPEED_VERYLOW(n) (0U << ((n)*2U))
#define PIN_OSPEED_LOW(n) (1U << ((n)*2U))
#define PIN_OSPEED_MEDIUM(n) (2U << ((n)*2U))
#define PIN_OSPEED_HIGH(n) (3U << ((n)*2U))
#define PIN_PUPDR_FLOATING(n) (0U << ((n)*2U))
#define PIN_PUPDR_PULLUP(n) (1U << ((n)*2U))
#define PIN_PUPDR_PULLDOWN(n) (2U << ((n)*2U))
#define PIN_AFIO_AF(n, v) ((v) << (((n) % 8U) * 4U))


#define LINE_INTB PAL_LINE(GPIOA, 7U)
#define LINE_SDB PAL_LINE(GPIOA, 8U)
#define LINE_USART1_TX PAL_LINE(GPIOA, 9U)
#define LINE_USART1_RX PAL_LINE(GPIOA, 10U)
#define LINE_USB_DM PAL_LINE(GPIOA, 11U)
#define LINE_USB_DP PAL_LINE(GPIOA, 12U)
#define LINE_SYS_SWDIO PAL_LINE(GPIOA, 13U)
#define LINE_SYS_SWCLK PAL_LINE(GPIOA, 14U)
#define LINE_IICRST PAL_LINE(GPIOA, 15U)

#define LINE_LED1 PAL_LINE(GPIOB, 0U)
#define LINE_LED2 PAL_LINE(GPIOB, 1U)
#define LINE_USB_DISC PAL_LINE(GPIOB, 2U)
#define LINE_I2C1_SCL PAL_LINE(GPIOB, 6U)
#define LINE_I2C1_SDA PAL_LINE(GPIOB, 7U)

#define PAD_INTB 7
#define PAD_SDB 8
#define PAD_USART1_TX 9
#define PAD_USART1_RX 10
#define PAD_USB_DM 11
#define PAD_USB_DP 12
#define PAD_SYS_SWDIO 13
#define PAD_SYS_SWCLK 14
#define PAD_IICRST 15

#define PAD_LED1 0
#define PAD_LED2 1
#define PAD_USB_DISC 2

#define PAD_I2C1_SCL 6
#define PAD_I2C1_SDA 7

#define PORT_IICRST GPIOA
#define PORT_INTB GPIOA
#define PORT_SDB GPIOA
#define PORT_SYS_SWCLK GPIOA
#define PORT_SYS_SWDIO GPIOA
#define PORT_USART1_RX GPIOA
#define PORT_USART1_TX GPIOA
#define PORT_USB_DM GPIOA
#define PORT_USB_DP GPIOA

#define PORT_LED1 GPIOB
#define PORT_LED2 GPIOB
#define PORT_USB_DISC GPIOB
#define PORT_I2C1_SCL GPIOB
#define PORT_I2C1_SDA GPIOB

#define I2C_I2C1_SCL 1
#define I2C_I2C1_SDA 1
#define USART_USART1_RX 1
#define USART_USART1_TX 1


/* PORT A */
#define VAL_GPIOA_MODER ( \
    PIN_MODE_INPUT(0) | \
    PIN_MODE_INPUT(1) | \
    PIN_MODE_INPUT(2) | \
    PIN_MODE_INPUT(3) | \
    PIN_MODE_INPUT(4) | \
    PIN_MODE_INPUT(5) | \
    PIN_MODE_INPUT(6) | \
    PIN_MODE_INPUT(7) | \
    PIN_MODE_OUTPUT(8) | \
    PIN_MODE_ALTERNATE(9) | \
    PIN_MODE_ALTERNATE(10) | \
    PIN_MODE_ALTERNATE(11) | \
    PIN_MODE_ALTERNATE(12) | \
    PIN_MODE_ALTERNATE(13) | \
    PIN_MODE_ALTERNATE(14) | \
    PIN_MODE_OUTPUT(15))

#define VAL_GPIOA_OTYPER ( \
    PIN_OTYPE_PUSHPULL(0) | \
    PIN_OTYPE_PUSHPULL(1) | \
    PIN_OTYPE_PUSHPULL(2) | \
    PIN_OTYPE_PUSHPULL(3) | \
    PIN_OTYPE_PUSHPULL(4) | \
    PIN_OTYPE_PUSHPULL(5) | \
    PIN_OTYPE_PUSHPULL(6) | \
    PIN_OTYPE_PUSHPULL(7) | \
    PIN_OTYPE_PUSHPULL(8) | \
    PIN_OTYPE_PUSHPULL(9) | \
    PIN_OTYPE_PUSHPULL(10) | \
    PIN_OTYPE_PUSHPULL(11) | \
    PIN_OTYPE_PUSHPULL(12) | \
    PIN_OTYPE_PUSHPULL(13) | \
    PIN_OTYPE_PUSHPULL(14) | \
    PIN_OTYPE_PUSHPULL(15))

#define VAL_GPIOA_OSPEEDR ( \
    PIN_OSPEED_VERYLOW(0) | \
    PIN_OSPEED_VERYLOW(1) | \
    PIN_OSPEED_VERYLOW(2) | \
    PIN_OSPEED_VERYLOW(3) | \
    PIN_OSPEED_VERYLOW(4) | \
    PIN_OSPEED_VERYLOW(5) | \
    PIN_OSPEED_VERYLOW(6) | \
    PIN_OSPEED_VERYLOW(7) | \
    PIN_OSPEED_VERYLOW(8) | \
    PIN_OSPEED_HIGH(9) | \
    PIN_OSPEED_HIGH(10) | \
    PIN_OSPEED_HIGH(11) | \
    PIN_OSPEED_HIGH(12) | \
    PIN_OSPEED_VERYLOW(13) | \
    PIN_OSPEED_VERYLOW(14) | \
    PIN_OSPEED_VERYLOW(15))

#define VAL_GPIOA_PUPDR ( \
    PIN_PUPDR_PULLUP(0) | \
    PIN_PUPDR_PULLUP(1) | \
    PIN_PUPDR_PULLUP(2) | \
    PIN_PUPDR_PULLUP(3) | \
    PIN_PUPDR_PULLUP(4) | \
    PIN_PUPDR_PULLUP(5) | \
    PIN_PUPDR_PULLUP(6) | \
    PIN_PUPDR_PULLUP(7) | \
    PIN_PUPDR_PULLUP(8) | \
    PIN_PUPDR_FLOATING(9) | \
    PIN_PUPDR_FLOATING(10) | \
    PIN_PUPDR_FLOATING(11) | \
    PIN_PUPDR_FLOATING(12) | \
    PIN_PUPDR_PULLUP(13) | \
    PIN_PUPDR_PULLUP(14) | \
    PIN_PUPDR_PULLUP(15))

#define VAL_GPIOA_ODR ( \
    PIN_ODR_LOW(0) | \
    PIN_ODR_LOW(1) | \
    PIN_ODR_LOW(2) | \
    PIN_ODR_LOW(3) | \
    PIN_ODR_LOW(4) | \
    PIN_ODR_LOW(5) | \
    PIN_ODR_LOW(6) | \
    PIN_ODR_LOW(7) | \
    PIN_ODR_LOW(8) | \
    PIN_ODR_HIGH(9) | \
    PIN_ODR_HIGH(10) | \
    PIN_ODR_HIGH(11) | \
    PIN_ODR_HIGH(12) | \
    PIN_ODR_HIGH(13) | \
    PIN_ODR_HIGH(14) | \
    PIN_ODR_HIGH(15))

#define VAL_GPIOA_AFRL ( \
    PIN_AFIO_AF(0, 0) | \
    PIN_AFIO_AF(1, 0) | \
    PIN_AFIO_AF(2, 0) | \
    PIN_AFIO_AF(3, 0) | \
    PIN_AFIO_AF(4, 0) | \
    PIN_AFIO_AF(5, 0) | \
    PIN_AFIO_AF(6, 0) | \
    PIN_AFIO_AF(7, 0))

#define VAL_GPIOA_AFRH ( \
    PIN_AFIO_AF(8, 0) | \
    PIN_AFIO_AF(9, 7U) | \
    PIN_AFIO_AF(10, 7U) | \
    PIN_AFIO_AF(11, 14U) | \
    PIN_AFIO_AF(12, 14U) | \
    PIN_AFIO_AF(13, 0) | \
    PIN_AFIO_AF(14, 0) | \
    PIN_AFIO_AF(15, 0))

/* PORT B */
#define VAL_GPIOB_MODER ( \
    PIN_MODE_OUTPUT(0) | \
    PIN_MODE_OUTPUT(1) | \
    PIN_MODE_OUTPUT(2) | \
    PIN_MODE_INPUT(3) | \
    PIN_MODE_INPUT(4) | \
    PIN_MODE_INPUT(5) | \
    PIN_MODE_ALTERNATE(6) | \
    PIN_MODE_ALTERNATE(7) | \
    PIN_MODE_INPUT(8) | \
    PIN_MODE_INPUT(9) | \
    PIN_MODE_INPUT(10) | \
    PIN_MODE_INPUT(11) | \
    PIN_MODE_INPUT(12) | \
    PIN_MODE_INPUT(13) | \
    PIN_MODE_INPUT(14) | \
    PIN_MODE_INPUT(15))

#define VAL_GPIOB_OTYPER ( \
    PIN_OTYPE_OPENDRAIN(0) | \
    PIN_OTYPE_OPENDRAIN(1) | \
    PIN_OTYPE_PUSHPULL(2) | \
    PIN_OTYPE_PUSHPULL(3) | \
    PIN_OTYPE_PUSHPULL(4) | \
    PIN_OTYPE_PUSHPULL(5) | \
    PIN_OTYPE_OPENDRAIN(6) | \
    PIN_OTYPE_OPENDRAIN(7) | \
    PIN_OTYPE_PUSHPULL(8) | \
    PIN_OTYPE_PUSHPULL(9) | \
    PIN_OTYPE_PUSHPULL(10) | \
    PIN_OTYPE_PUSHPULL(11) | \
    PIN_OTYPE_PUSHPULL(12) | \
    PIN_OTYPE_PUSHPULL(13) | \
    PIN_OTYPE_PUSHPULL(14) | \
    PIN_OTYPE_PUSHPULL(15))

#define VAL_GPIOB_OSPEEDR ( \
    PIN_OSPEED_VERYLOW(0) | \
    PIN_OSPEED_VERYLOW(1) | \
    PIN_OSPEED_VERYLOW(2) | \
    PIN_OSPEED_VERYLOW(3) | \
    PIN_OSPEED_VERYLOW(4) | \
    PIN_OSPEED_VERYLOW(5) | \
    PIN_OSPEED_HIGH(6) | \
    PIN_OSPEED_HIGH(7) | \
    PIN_OSPEED_VERYLOW(8) | \
    PIN_OSPEED_VERYLOW(9) | \
    PIN_OSPEED_VERYLOW(10) | \
    PIN_OSPEED_VERYLOW(11) | \
    PIN_OSPEED_VERYLOW(12) | \
    PIN_OSPEED_VERYLOW(13) | \
    PIN_OSPEED_VERYLOW(14) | \
    PIN_OSPEED_VERYLOW(15))

#define VAL_GPIOB_PUPDR ( \
    PIN_PUPDR_FLOATING(0) | \
    PIN_PUPDR_FLOATING(1) | \
    PIN_PUPDR_FLOATING(2) | \
    PIN_PUPDR_PULLUP(3) | \
    PIN_PUPDR_PULLUP(4) | \
    PIN_PUPDR_PULLUP(5) | \
    PIN_PUPDR_FLOATING(6) | \
    PIN_PUPDR_FLOATING(7) | \
    PIN_PUPDR_PULLUP(8) | \
    PIN_PUPDR_PULLUP(9) | \
    PIN_PUPDR_PULLUP(10) | \
    PIN_PUPDR_PULLUP(11) | \
    PIN_PUPDR_PULLUP(12) | \
    PIN_PUPDR_PULLUP(13) | \
    PIN_PUPDR_PULLUP(14) | \
    PIN_PUPDR_PULLUP(15))

#define VAL_GPIOB_ODR ( \
    PIN_ODR_HIGH(0) | \
    PIN_ODR_HIGH(1) | \
    PIN_ODR_LOW(2) | \
    PIN_ODR_LOW(3) | \
    PIN_ODR_LOW(4) | \
    PIN_ODR_LOW(5) | \
    PIN_ODR_HIGH(6) | \
    PIN_ODR_HIGH(7) | \
    PIN_ODR_LOW(8) | \
    PIN_ODR_LOW(9) | \
    PIN_ODR_LOW(10) | \
    PIN_ODR_LOW(11) | \
    PIN_ODR_LOW(12) | \
    PIN_ODR_LOW(13) | \
    PIN_ODR_LOW(14) | \
    PIN_ODR_LOW(15))

#define VAL_GPIOB_AFRL ( \
    PIN_AFIO_AF(0, 0) | \
    PIN_AFIO_AF(1, 0) | \
    PIN_AFIO_AF(2, 0) | \
    PIN_AFIO_AF(3, 0) | \
    PIN_AFIO_AF(4, 0) | \
    PIN_AFIO_AF(5, 0) | \
    PIN_AFIO_AF(6, 4U) | \
    PIN_AFIO_AF(7, 4U))

#define VAL_GPIOB_AFRH ( \
    PIN_AFIO_AF(8, 0) | \
    PIN_AFIO_AF(9, 0) | \
    PIN_AFIO_AF(10, 0) | \
    PIN_AFIO_AF(11, 0) | \
    PIN_AFIO_AF(12, 0) | \
    PIN_AFIO_AF(13, 0) | \
    PIN_AFIO_AF(14, 0) | \
    PIN_AFIO_AF(15, 0))

/* PORT C */
#define VAL_GPIOC_MODER ( \
    PIN_MODE_ANALOG(0) | \
    PIN_MODE_ANALOG(1) | \
    PIN_MODE_ANALOG(2) | \
    PIN_MODE_ANALOG(3) | \
    PIN_MODE_ANALOG(4) | \
    PIN_MODE_ANALOG(5) | \
    PIN_MODE_ANALOG(6) | \
    PIN_MODE_ANALOG(7) | \
    PIN_MODE_ANALOG(8) | \
    PIN_MODE_ANALOG(9) | \
    PIN_MODE_ANALOG(10) | \
    PIN_MODE_ANALOG(11) | \
    PIN_MODE_ANALOG(12) | \
    PIN_MODE_INPUT(13) | \
    PIN_MODE_INPUT(14) | \
    PIN_MODE_INPUT(15))

#define VAL_GPIOC_OTYPER ( \
    PIN_OTYPE_PUSHPULL(0) | \
    PIN_OTYPE_PUSHPULL(1) | \
    PIN_OTYPE_PUSHPULL(2) | \
    PIN_OTYPE_PUSHPULL(3) | \
    PIN_OTYPE_PUSHPULL(4) | \
    PIN_OTYPE_PUSHPULL(5) | \
    PIN_OTYPE_PUSHPULL(6) | \
    PIN_OTYPE_PUSHPULL(7) | \
    PIN_OTYPE_PUSHPULL(8) | \
    PIN_OTYPE_PUSHPULL(9) | \
    PIN_OTYPE_PUSHPULL(10) | \
    PIN_OTYPE_PUSHPULL(11) | \
    PIN_OTYPE_PUSHPULL(12) | \
    PIN_OTYPE_PUSHPULL(13) | \
    PIN_OTYPE_PUSHPULL(14) | \
    PIN_OTYPE_PUSHPULL(15))

#define VAL_GPIOC_OSPEEDR ( \
    PIN_OSPEED_VERYLOW(0) | \
    PIN_OSPEED_VERYLOW(1) | \
    PIN_OSPEED_VERYLOW(2) | \
    PIN_OSPEED_VERYLOW(3) | \
    PIN_OSPEED_VERYLOW(4) | \
    PIN_OSPEED_VERYLOW(5) | \
    PIN_OSPEED_VERYLOW(6) | \
    PIN_OSPEED_VERYLOW(7) | \
    PIN_OSPEED_VERYLOW(8) | \
    PIN_OSPEED_VERYLOW(9) | \
    PIN_OSPEED_VERYLOW(10) | \
    PIN_OSPEED_VERYLOW(11) | \
    PIN_OSPEED_VERYLOW(12) | \
    PIN_OSPEED_VERYLOW(13) | \
    PIN_OSPEED_VERYLOW(14) | \
    PIN_OSPEED_VERYLOW(15))

#define VAL_GPIOC_PUPDR ( \
    PIN_PUPDR_PULLUP(0) | \
    PIN_PUPDR_PULLUP(1) | \
    PIN_PUPDR_PULLUP(2) | \
    PIN_PUPDR_PULLUP(3) | \
    PIN_PUPDR_PULLUP(4) | \
    PIN_PUPDR_PULLUP(5) | \
    PIN_PUPDR_PULLUP(6) | \
    PIN_PUPDR_PULLUP(7) | \
    PIN_PUPDR_PULLUP(8) | \
    PIN_PUPDR_PULLUP(9) | \
    PIN_PUPDR_PULLUP(10) | \
    PIN_PUPDR_PULLUP(11) | \
    PIN_PUPDR_PULLUP(12) | \
    PIN_PUPDR_PULLUP(13) | \
    PIN_PUPDR_PULLUP(14) | \
    PIN_PUPDR_PULLUP(15))

#define VAL_GPIOC_ODR ( \
    PIN_ODR_LOW(0) | \
    PIN_ODR_LOW(1) | \
    PIN_ODR_LOW(2) | \
    PIN_ODR_LOW(3) | \
    PIN_ODR_LOW(4) | \
    PIN_ODR_LOW(5) | \
    PIN_ODR_LOW(6) | \
    PIN_ODR_LOW(7) | \
    PIN_ODR_LOW(8) | \
    PIN_ODR_LOW(9) | \
    PIN_ODR_LOW(10) | \
    PIN_ODR_LOW(11) | \
    PIN_ODR_LOW(12) | \
    PIN_ODR_LOW(13) | \
    PIN_ODR_LOW(14) | \
    PIN_ODR_LOW(15))

#define VAL_GPIOC_AFRL ( \
    PIN_AFIO_AF(0, 0) | \
    PIN_AFIO_AF(1, 0) | \
    PIN_AFIO_AF(2, 0) | \
    PIN_AFIO_AF(3, 0) | \
    PIN_AFIO_AF(4, 0) | \
    PIN_AFIO_AF(5, 0) | \
    PIN_AFIO_AF(6, 0) | \
    PIN_AFIO_AF(7, 0))

#define VAL_GPIOC_AFRH ( \
    PIN_AFIO_AF(8, 0) | \
    PIN_AFIO_AF(9, 0) | \
    PIN_AFIO_AF(10, 0) | \
    PIN_AFIO_AF(11, 0) | \
    PIN_AFIO_AF(12, 0) | \
    PIN_AFIO_AF(13, 0) | \
    PIN_AFIO_AF(14, 0) | \
    PIN_AFIO_AF(15, 0))

/* PORT D */
#define VAL_GPIOD_MODER ( \
    PIN_MODE_ANALOG(0) | \
    PIN_MODE_ANALOG(1) | \
    PIN_MODE_ANALOG(2) | \
    PIN_MODE_ANALOG(3) | \
    PIN_MODE_ANALOG(4) | \
    PIN_MODE_ANALOG(5) | \
    PIN_MODE_ANALOG(6) | \
    PIN_MODE_ANALOG(7) | \
    PIN_MODE_ANALOG(8) | \
    PIN_MODE_ANALOG(9) | \
    PIN_MODE_ANALOG(10) | \
    PIN_MODE_ANALOG(11) | \
    PIN_MODE_ANALOG(12) | \
    PIN_MODE_ANALOG(13) | \
    PIN_MODE_ANALOG(14) | \
    PIN_MODE_ANALOG(15))

#define VAL_GPIOD_OTYPER ( \
    PIN_OTYPE_PUSHPULL(0) | \
    PIN_OTYPE_PUSHPULL(1) | \
    PIN_OTYPE_PUSHPULL(2) | \
    PIN_OTYPE_PUSHPULL(3) | \
    PIN_OTYPE_PUSHPULL(4) | \
    PIN_OTYPE_PUSHPULL(5) | \
    PIN_OTYPE_PUSHPULL(6) | \
    PIN_OTYPE_PUSHPULL(7) | \
    PIN_OTYPE_PUSHPULL(8) | \
    PIN_OTYPE_PUSHPULL(9) | \
    PIN_OTYPE_PUSHPULL(10) | \
    PIN_OTYPE_PUSHPULL(11) | \
    PIN_OTYPE_PUSHPULL(12) | \
    PIN_OTYPE_PUSHPULL(13) | \
    PIN_OTYPE_PUSHPULL(14) | \
    PIN_OTYPE_PUSHPULL(15))

#define VAL_GPIOD_OSPEEDR ( \
    PIN_OSPEED_VERYLOW(0) | \
    PIN_OSPEED_VERYLOW(1) | \
    PIN_OSPEED_VERYLOW(2) | \
    PIN_OSPEED_VERYLOW(3) | \
    PIN_OSPEED_VERYLOW(4) | \
    PIN_OSPEED_VERYLOW(5) | \
    PIN_OSPEED_VERYLOW(6) | \
    PIN_OSPEED_VERYLOW(7) | \
    PIN_OSPEED_VERYLOW(8) | \
    PIN_OSPEED_VERYLOW(9) | \
    PIN_OSPEED_VERYLOW(10) | \
    PIN_OSPEED_VERYLOW(11) | \
    PIN_OSPEED_VERYLOW(12) | \
    PIN_OSPEED_VERYLOW(13) | \
    PIN_OSPEED_VERYLOW(14) | \
    PIN_OSPEED_VERYLOW(15))

#define VAL_GPIOD_PUPDR ( \
    PIN_PUPDR_PULLUP(0) | \
    PIN_PUPDR_PULLUP(1) | \
    PIN_PUPDR_PULLUP(2) | \
    PIN_PUPDR_PULLUP(3) | \
    PIN_PUPDR_PULLUP(4) | \
    PIN_PUPDR_PULLUP(5) | \
    PIN_PUPDR_PULLUP(6) | \
    PIN_PUPDR_PULLUP(7) | \
    PIN_PUPDR_PULLUP(8) | \
    PIN_PUPDR_PULLUP(9) | \
    PIN_PUPDR_PULLUP(10) | \
    PIN_PUPDR_PULLUP(11) | \
    PIN_PUPDR_PULLUP(12) | \
    PIN_PUPDR_PULLUP(13) | \
    PIN_PUPDR_PULLUP(14) | \
    PIN_PUPDR_PULLUP(15))

#define VAL_GPIOD_ODR ( \
    PIN_ODR_LOW(0) | \
    PIN_ODR_LOW(1) | \
    PIN_ODR_LOW(2) | \
    PIN_ODR_LOW(3) | \
    PIN_ODR_LOW(4) | \
    PIN_ODR_LOW(5) | \
    PIN_ODR_LOW(6) | \
    PIN_ODR_LOW(7) | \
    PIN_ODR_LOW(8) | \
    PIN_ODR_LOW(9) | \
    PIN_ODR_LOW(10) | \
    PIN_ODR_LOW(11) | \
    PIN_ODR_LOW(12) | \
    PIN_ODR_LOW(13) | \
    PIN_ODR_LOW(14) | \
    PIN_ODR_LOW(15))

#define VAL_GPIOD_AFRL ( \
    PIN_AFIO_AF(0, 0) | \
    PIN_AFIO_AF(1, 0) | \
    PIN_AFIO_AF(2, 0) | \
    PIN_AFIO_AF(3, 0) | \
    PIN_AFIO_AF(4, 0) | \
    PIN_AFIO_AF(5, 0) | \
    PIN_AFIO_AF(6, 0) | \
    PIN_AFIO_AF(7, 0))

#define VAL_GPIOD_AFRH ( \
    PIN_AFIO_AF(8, 0) | \
    PIN_AFIO_AF(9, 0) | \
    PIN_AFIO_AF(10, 0) | \
    PIN_AFIO_AF(11, 0) | \
    PIN_AFIO_AF(12, 0) | \
    PIN_AFIO_AF(13, 0) | \
    PIN_AFIO_AF(14, 0) | \
    PIN_AFIO_AF(15, 0))

/* PORT E */
#define VAL_GPIOE_MODER ( \
    PIN_MODE_ANALOG(0) | \
    PIN_MODE_ANALOG(1) | \
    PIN_MODE_ANALOG(2) | \
    PIN_MODE_ANALOG(3) | \
    PIN_MODE_ANALOG(4) | \
    PIN_MODE_ANALOG(5) | \
    PIN_MODE_ANALOG(6) | \
    PIN_MODE_ANALOG(7) | \
    PIN_MODE_ANALOG(8) | \
    PIN_MODE_ANALOG(9) | \
    PIN_MODE_ANALOG(10) | \
    PIN_MODE_ANALOG(11) | \
    PIN_MODE_ANALOG(12) | \
    PIN_MODE_ANALOG(13) | \
    PIN_MODE_ANALOG(14) | \
    PIN_MODE_ANALOG(15))

#define VAL_GPIOE_OTYPER ( \
    PIN_OTYPE_PUSHPULL(0) | \
    PIN_OTYPE_PUSHPULL(1) | \
    PIN_OTYPE_PUSHPULL(2) | \
    PIN_OTYPE_PUSHPULL(3) | \
    PIN_OTYPE_PUSHPULL(4) | \
    PIN_OTYPE_PUSHPULL(5) | \
    PIN_OTYPE_PUSHPULL(6) | \
    PIN_OTYPE_PUSHPULL(7) | \
    PIN_OTYPE_PUSHPULL(8) | \
    PIN_OTYPE_PUSHPULL(9) | \
    PIN_OTYPE_PUSHPULL(10) | \
    PIN_OTYPE_PUSHPULL(11) | \
    PIN_OTYPE_PUSHPULL(12) | \
    PIN_OTYPE_PUSHPULL(13) | \
    PIN_OTYPE_PUSHPULL(14) | \
    PIN_OTYPE_PUSHPULL(15))

#define VAL_GPIOE_OSPEEDR ( \
    PIN_OSPEED_VERYLOW(0) | \
    PIN_OSPEED_VERYLOW(1) | \
    PIN_OSPEED_VERYLOW(2) | \
    PIN_OSPEED_VERYLOW(3) | \
    PIN_OSPEED_VERYLOW(4) | \
    PIN_OSPEED_VERYLOW(5) | \
    PIN_OSPEED_VERYLOW(6) | \
    PIN_OSPEED_VERYLOW(7) | \
    PIN_OSPEED_VERYLOW(8) | \
    PIN_OSPEED_VERYLOW(9) | \
    PIN_OSPEED_VERYLOW(10) | \
    PIN_OSPEED_VERYLOW(11) | \
    PIN_OSPEED_VERYLOW(12) | \
    PIN_OSPEED_VERYLOW(13) | \
    PIN_OSPEED_VERYLOW(14) | \
    PIN_OSPEED_VERYLOW(15))

#define VAL_GPIOE_PUPDR ( \
    PIN_PUPDR_PULLUP(0) | \
    PIN_PUPDR_PULLUP(1) | \
    PIN_PUPDR_PULLUP(2) | \
    PIN_PUPDR_PULLUP(3) | \
    PIN_PUPDR_PULLUP(4) | \
    PIN_PUPDR_PULLUP(5) | \
    PIN_PUPDR_PULLUP(6) | \
    PIN_PUPDR_PULLUP(7) | \
    PIN_PUPDR_PULLUP(8) | \
    PIN_PUPDR_PULLUP(9) | \
    PIN_PUPDR_PULLUP(10) | \
    PIN_PUPDR_PULLUP(11) | \
    PIN_PUPDR_PULLUP(12) | \
    PIN_PUPDR_PULLUP(13) | \
    PIN_PUPDR_PULLUP(14) | \
    PIN_PUPDR_PULLUP(15))

#define VAL_GPIOE_ODR ( \
    PIN_ODR_LOW(0) | \
    PIN_ODR_LOW(1) | \
    PIN_ODR_LOW(2) | \
    PIN_ODR_LOW(3) | \
    PIN_ODR_LOW(4) | \
    PIN_ODR_LOW(5) | \
    PIN_ODR_LOW(6) | \
    PIN_ODR_LOW(7) | \
    PIN_ODR_LOW(8) | \
    PIN_ODR_LOW(9) | \
    PIN_ODR_LOW(10) | \
    PIN_ODR_LOW(11) | \
    PIN_ODR_LOW(12) | \
    PIN_ODR_LOW(13) | \
    PIN_ODR_LOW(14) | \
    PIN_ODR_LOW(15))

#define VAL_GPIOE_AFRL ( \
    PIN_AFIO_AF(0, 0) | \
    PIN_AFIO_AF(1, 0) | \
    PIN_AFIO_AF(2, 0) | \
    PIN_AFIO_AF(3, 0) | \
    PIN_AFIO_AF(4, 0) | \
    PIN_AFIO_AF(5, 0) | \
    PIN_AFIO_AF(6, 0) | \
    PIN_AFIO_AF(7, 0) | \
    0)

#define VAL_GPIOE_AFRH ( \
    PIN_AFIO_AF(8, 0) | \
    PIN_AFIO_AF(9, 0) | \
    PIN_AFIO_AF(10, 0) | \
    PIN_AFIO_AF(11, 0) | \
    PIN_AFIO_AF(12, 0) | \
    PIN_AFIO_AF(13, 0) | \
    PIN_AFIO_AF(14, 0) | \
    PIN_AFIO_AF(15, 0))

/* PORT F */
#define VAL_GPIOF_MODER ( \
    PIN_MODE_ANALOG(0) | \
    PIN_MODE_ANALOG(1) | \
    PIN_MODE_ANALOG(2) | \
    PIN_MODE_ANALOG(3) | \
    PIN_MODE_ANALOG(4) | \
    PIN_MODE_ANALOG(5) | \
    PIN_MODE_ANALOG(6) | \
    PIN_MODE_ANALOG(7) | \
    PIN_MODE_ANALOG(8) | \
    PIN_MODE_ANALOG(9) | \
    PIN_MODE_ANALOG(10) | \
    PIN_MODE_ANALOG(11) | \
    PIN_MODE_ANALOG(12) | \
    PIN_MODE_ANALOG(13) | \
    PIN_MODE_ANALOG(14) | \
    PIN_MODE_ANALOG(15))

#define VAL_GPIOF_OTYPER ( \
    PIN_OTYPE_PUSHPULL(0) | \
    PIN_OTYPE_PUSHPULL(1) | \
    PIN_OTYPE_PUSHPULL(2) | \
    PIN_OTYPE_PUSHPULL(3) | \
    PIN_OTYPE_PUSHPULL(4) | \
    PIN_OTYPE_PUSHPULL(5) | \
    PIN_OTYPE_PUSHPULL(6) | \
    PIN_OTYPE_PUSHPULL(7) | \
    PIN_OTYPE_PUSHPULL(8) | \
    PIN_OTYPE_PUSHPULL(9) | \
    PIN_OTYPE_PUSHPULL(10) | \
    PIN_OTYPE_PUSHPULL(11) | \
    PIN_OTYPE_PUSHPULL(12) | \
    PIN_OTYPE_PUSHPULL(13) | \
    PIN_OTYPE_PUSHPULL(14) | \
    PIN_OTYPE_PUSHPULL(15))

#define VAL_GPIOF_OSPEEDR ( \
    PIN_OSPEED_VERYLOW(0) | \
    PIN_OSPEED_VERYLOW(1) | \
    PIN_OSPEED_VERYLOW(2) | \
    PIN_OSPEED_VERYLOW(3) | \
    PIN_OSPEED_VERYLOW(4) | \
    PIN_OSPEED_VERYLOW(5) | \
    PIN_OSPEED_VERYLOW(6) | \
    PIN_OSPEED_VERYLOW(7) | \
    PIN_OSPEED_VERYLOW(8) | \
    PIN_OSPEED_VERYLOW(9) | \
    PIN_OSPEED_VERYLOW(10) | \
    PIN_OSPEED_VERYLOW(11) | \
    PIN_OSPEED_VERYLOW(12) | \
    PIN_OSPEED_VERYLOW(13) | \
    PIN_OSPEED_VERYLOW(14) | \
    PIN_OSPEED_VERYLOW(15))

#define VAL_GPIOF_PUPDR ( \
    PIN_PUPDR_PULLUP(0) | \
    PIN_PUPDR_PULLUP(1) | \
    PIN_PUPDR_PULLUP(2) | \
    PIN_PUPDR_PULLUP(3) | \
    PIN_PUPDR_PULLUP(4) | \
    PIN_PUPDR_PULLUP(5) | \
    PIN_PUPDR_PULLUP(6) | \
    PIN_PUPDR_PULLUP(7) | \
    PIN_PUPDR_PULLUP(8) | \
    PIN_PUPDR_PULLUP(9) | \
    PIN_PUPDR_PULLUP(10) | \
    PIN_PUPDR_PULLUP(11) | \
    PIN_PUPDR_PULLUP(12) | \
    PIN_PUPDR_PULLUP(13) | \
    PIN_PUPDR_PULLUP(14) | \
    PIN_PUPDR_PULLUP(15))

#define VAL_GPIOF_ODR ( \
    PIN_ODR_LOW(0) | \
    PIN_ODR_LOW(1) | \
    PIN_ODR_LOW(2) | \
    PIN_ODR_LOW(3) | \
    PIN_ODR_LOW(4) | \
    PIN_ODR_LOW(5) | \
    PIN_ODR_LOW(6) | \
    PIN_ODR_LOW(7) | \
    PIN_ODR_LOW(8) | \
    PIN_ODR_LOW(9) | \
    PIN_ODR_LOW(10) | \
    PIN_ODR_LOW(11) | \
    PIN_ODR_LOW(12) | \
    PIN_ODR_LOW(13) | \
    PIN_ODR_LOW(14) | \
    PIN_ODR_LOW(15))

#define VAL_GPIOF_AFRL ( \
    PIN_AFIO_AF(0, 0) | \
    PIN_AFIO_AF(1, 0) | \
    PIN_AFIO_AF(2, 0) | \
    PIN_AFIO_AF(3, 0) | \
    PIN_AFIO_AF(4, 0) | \
    PIN_AFIO_AF(5, 0) | \
    PIN_AFIO_AF(6, 0) | \
    PIN_AFIO_AF(7, 0) | \
    0)

#define VAL_GPIOF_AFRH ( \
    PIN_AFIO_AF(8, 0) | \
    PIN_AFIO_AF(9, 0) | \
    PIN_AFIO_AF(10, 0) | \
    PIN_AFIO_AF(11, 0) | \
    PIN_AFIO_AF(12, 0) | \
    PIN_AFIO_AF(13, 0) | \
    PIN_AFIO_AF(14, 0) | \
    PIN_AFIO_AF(15, 0))

/* PORT G */
#define VAL_GPIOG_MODER ( \
    PIN_MODE_ANALOG(0) | \
    PIN_MODE_ANALOG(1) | \
    PIN_MODE_ANALOG(2) | \
    PIN_MODE_ANALOG(3) | \
    PIN_MODE_ANALOG(4) | \
    PIN_MODE_ANALOG(5) | \
    PIN_MODE_ANALOG(6) | \
    PIN_MODE_ANALOG(7) | \
    PIN_MODE_ANALOG(8) | \
    PIN_MODE_ANALOG(9) | \
    PIN_MODE_ANALOG(10) | \
    PIN_MODE_ANALOG(11) | \
    PIN_MODE_ANALOG(12) | \
    PIN_MODE_ANALOG(13) | \
    PIN_MODE_ANALOG(14) | \
    PIN_MODE_ANALOG(15))

#define VAL_GPIOG_OTYPER ( \
    PIN_OTYPE_PUSHPULL(0) | \
    PIN_OTYPE_PUSHPULL(1) | \
    PIN_OTYPE_PUSHPULL(2) | \
    PIN_OTYPE_PUSHPULL(3) | \
    PIN_OTYPE_PUSHPULL(4) | \
    PIN_OTYPE_PUSHPULL(5) | \
    PIN_OTYPE_PUSHPULL(6) | \
    PIN_OTYPE_PUSHPULL(7) | \
    PIN_OTYPE_PUSHPULL(8) | \
    PIN_OTYPE_PUSHPULL(9) | \
    PIN_OTYPE_PUSHPULL(10) | \
    PIN_OTYPE_PUSHPULL(11) | \
    PIN_OTYPE_PUSHPULL(12) | \
    PIN_OTYPE_PUSHPULL(13) | \
    PIN_OTYPE_PUSHPULL(14) | \
    PIN_OTYPE_PUSHPULL(15))

#define VAL_GPIOG_OSPEEDR ( \
    PIN_OSPEED_VERYLOW(0) | \
    PIN_OSPEED_VERYLOW(1) | \
    PIN_OSPEED_VERYLOW(2) | \
    PIN_OSPEED_VERYLOW(3) | \
    PIN_OSPEED_VERYLOW(4) | \
    PIN_OSPEED_VERYLOW(5) | \
    PIN_OSPEED_VERYLOW(6) | \
    PIN_OSPEED_VERYLOW(7) | \
    PIN_OSPEED_VERYLOW(8) | \
    PIN_OSPEED_VERYLOW(9) | \
    PIN_OSPEED_VERYLOW(10) | \
    PIN_OSPEED_VERYLOW(11) | \
    PIN_OSPEED_VERYLOW(12) | \
    PIN_OSPEED_VERYLOW(13) | \
    PIN_OSPEED_VERYLOW(14) | \
    PIN_OSPEED_VERYLOW(15))

#define VAL_GPIOG_PUPDR ( \
    PIN_PUPDR_PULLUP(0) | \
    PIN_PUPDR_PULLUP(1) | \
    PIN_PUPDR_PULLUP(2) | \
    PIN_PUPDR_PULLUP(3) | \
    PIN_PUPDR_PULLUP(4) | \
    PIN_PUPDR_PULLUP(5) | \
    PIN_PUPDR_PULLUP(6) | \
    PIN_PUPDR_PULLUP(7) | \
    PIN_PUPDR_PULLUP(8) | \
    PIN_PUPDR_PULLUP(9) | \
    PIN_PUPDR_PULLUP(10) | \
    PIN_PUPDR_PULLUP(11) | \
    PIN_PUPDR_PULLUP(12) | \
    PIN_PUPDR_PULLUP(13) | \
    PIN_PUPDR_PULLUP(14) | \
    PIN_PUPDR_PULLUP(15))

#define VAL_GPIOG_ODR ( \
    PIN_ODR_LOW(0) | \
    PIN_ODR_LOW(1) | \
    PIN_ODR_LOW(2) | \
    PIN_ODR_LOW(3) | \
    PIN_ODR_LOW(4) | \
    PIN_ODR_LOW(5) | \
    PIN_ODR_LOW(6) | \
    PIN_ODR_LOW(7) | \
    PIN_ODR_LOW(8) | \
    PIN_ODR_LOW(9) | \
    PIN_ODR_LOW(10) | \
    PIN_ODR_LOW(11) | \
    PIN_ODR_LOW(12) | \
    PIN_ODR_LOW(13) | \
    PIN_ODR_LOW(14) | \
    PIN_ODR_LOW(15))

#define VAL_GPIOG_AFRL ( \
    PIN_AFIO_AF(0, 0) | \
    PIN_AFIO_AF(1, 0) | \
    PIN_AFIO_AF(2, 0) | \
    PIN_AFIO_AF(3, 0) | \
    PIN_AFIO_AF(4, 0) | \
    PIN_AFIO_AF(5, 0) | \
    PIN_AFIO_AF(6, 0) | \
    PIN_AFIO_AF(7, 0) | \
    0)

#define VAL_GPIOG_AFRH ( \
    PIN_AFIO_AF(8, 0) | \
    PIN_AFIO_AF(9, 0) | \
    PIN_AFIO_AF(10, 0) | \
    PIN_AFIO_AF(11, 0) | \
    PIN_AFIO_AF(12, 0) | \
    PIN_AFIO_AF(13, 0) | \
    PIN_AFIO_AF(14, 0) | \
    PIN_AFIO_AF(15, 0))

/* PORT H */
#define VAL_GPIOH_MODER ( \
    PIN_MODE_ANALOG(0) | \
    PIN_MODE_ANALOG(1) | \
    PIN_MODE_ANALOG(2) | \
    PIN_MODE_ANALOG(3) | \
    PIN_MODE_ANALOG(4) | \
    PIN_MODE_ANALOG(5) | \
    PIN_MODE_ANALOG(6) | \
    PIN_MODE_ANALOG(7) | \
    PIN_MODE_ANALOG(8) | \
    PIN_MODE_ANALOG(9) | \
    PIN_MODE_ANALOG(10) | \
    PIN_MODE_ANALOG(11) | \
    PIN_MODE_ANALOG(12) | \
    PIN_MODE_ANALOG(13) | \
    PIN_MODE_ANALOG(14) | \
    PIN_MODE_ANALOG(15))

#define VAL_GPIOH_OTYPER ( \
    PIN_OTYPE_PUSHPULL(0) | \
    PIN_OTYPE_PUSHPULL(1) | \
    PIN_OTYPE_PUSHPULL(2) | \
    PIN_OTYPE_PUSHPULL(3) | \
    PIN_OTYPE_PUSHPULL(4) | \
    PIN_OTYPE_PUSHPULL(5) | \
    PIN_OTYPE_PUSHPULL(6) | \
    PIN_OTYPE_PUSHPULL(7) | \
    PIN_OTYPE_PUSHPULL(8) | \
    PIN_OTYPE_PUSHPULL(9) | \
    PIN_OTYPE_PUSHPULL(10) | \
    PIN_OTYPE_PUSHPULL(11) | \
    PIN_OTYPE_PUSHPULL(12) | \
    PIN_OTYPE_PUSHPULL(13) | \
    PIN_OTYPE_PUSHPULL(14) | \
    PIN_OTYPE_PUSHPULL(15))

#define VAL_GPIOH_OSPEEDR ( \
    PIN_OSPEED_VERYLOW(0) | \
    PIN_OSPEED_VERYLOW(1) | \
    PIN_OSPEED_VERYLOW(2) | \
    PIN_OSPEED_VERYLOW(3) | \
    PIN_OSPEED_VERYLOW(4) | \
    PIN_OSPEED_VERYLOW(5) | \
    PIN_OSPEED_VERYLOW(6) | \
    PIN_OSPEED_VERYLOW(7) | \
    PIN_OSPEED_VERYLOW(8) | \
    PIN_OSPEED_VERYLOW(9) | \
    PIN_OSPEED_VERYLOW(10) | \
    PIN_OSPEED_VERYLOW(11) | \
    PIN_OSPEED_VERYLOW(12) | \
    PIN_OSPEED_VERYLOW(13) | \
    PIN_OSPEED_VERYLOW(14) | \
    PIN_OSPEED_VERYLOW(15))

#define VAL_GPIOH_PUPDR ( \
    PIN_PUPDR_PULLUP(0) | \
    PIN_PUPDR_PULLUP(1) | \
    PIN_PUPDR_PULLUP(2) | \
    PIN_PUPDR_PULLUP(3) | \
    PIN_PUPDR_PULLUP(4) | \
    PIN_PUPDR_PULLUP(5) | \
    PIN_PUPDR_PULLUP(6) | \
    PIN_PUPDR_PULLUP(7) | \
    PIN_PUPDR_PULLUP(8) | \
    PIN_PUPDR_PULLUP(9) | \
    PIN_PUPDR_PULLUP(10) | \
    PIN_PUPDR_PULLUP(11) | \
    PIN_PUPDR_PULLUP(12) | \
    PIN_PUPDR_PULLUP(13) | \
    PIN_PUPDR_PULLUP(14) | \
    PIN_PUPDR_PULLUP(15))

#define VAL_GPIOH_ODR ( \
    PIN_ODR_LOW(0) | \
    PIN_ODR_LOW(1) | \
    PIN_ODR_LOW(2) | \
    PIN_ODR_LOW(3) | \
    PIN_ODR_LOW(4) | \
    PIN_ODR_LOW(5) | \
    PIN_ODR_LOW(6) | \
    PIN_ODR_LOW(7) | \
    PIN_ODR_LOW(8) | \
    PIN_ODR_LOW(9) | \
    PIN_ODR_LOW(10) | \
    PIN_ODR_LOW(11) | \
    PIN_ODR_LOW(12) | \
    PIN_ODR_LOW(13) | \
    PIN_ODR_LOW(14) | \
    PIN_ODR_LOW(15))

#define VAL_GPIOH_AFRL ( \
    PIN_AFIO_AF(0, 0) | \
    PIN_AFIO_AF(1, 0) | \
    PIN_AFIO_AF(2, 0) | \
    PIN_AFIO_AF(3, 0) | \
    PIN_AFIO_AF(4, 0) | \
    PIN_AFIO_AF(5, 0) | \
    PIN_AFIO_AF(6, 0) | \
    PIN_AFIO_AF(7, 0))

#define VAL_GPIOH_AFRH ( \
    PIN_AFIO_AF(8, 0) | \
    PIN_AFIO_AF(9, 0) | \
    PIN_AFIO_AF(10, 0) | \
    PIN_AFIO_AF(11, 0) | \
    PIN_AFIO_AF(12, 0) | \
    PIN_AFIO_AF(13, 0) | \
    PIN_AFIO_AF(14, 0) | \
    PIN_AFIO_AF(15, 0))

/* PORT I */
#define VAL_GPIOI_MODER ( \
    PIN_MODE_ANALOG(0) | \
    PIN_MODE_ANALOG(1) | \
    PIN_MODE_ANALOG(2) | \
    PIN_MODE_ANALOG(3) | \
    PIN_MODE_ANALOG(4) | \
    PIN_MODE_ANALOG(5) | \
    PIN_MODE_ANALOG(6) | \
    PIN_MODE_ANALOG(7) | \
    PIN_MODE_ANALOG(8) | \
    PIN_MODE_ANALOG(9) | \
    PIN_MODE_ANALOG(10) | \
    PIN_MODE_ANALOG(11) | \
    PIN_MODE_ANALOG(12) | \
    PIN_MODE_ANALOG(13) | \
    PIN_MODE_ANALOG(14) | \
    PIN_MODE_ANALOG(15))

#define VAL_GPIOI_OTYPER ( \
    PIN_OTYPE_PUSHPULL(0) | \
    PIN_OTYPE_PUSHPULL(1) | \
    PIN_OTYPE_PUSHPULL(2) | \
    PIN_OTYPE_PUSHPULL(3) | \
    PIN_OTYPE_PUSHPULL(4) | \
    PIN_OTYPE_PUSHPULL(5) | \
    PIN_OTYPE_PUSHPULL(6) | \
    PIN_OTYPE_PUSHPULL(7) | \
    PIN_OTYPE_PUSHPULL(8) | \
    PIN_OTYPE_PUSHPULL(9) | \
    PIN_OTYPE_PUSHPULL(10) | \
    PIN_OTYPE_PUSHPULL(11) | \
    PIN_OTYPE_PUSHPULL(12) | \
    PIN_OTYPE_PUSHPULL(13) | \
    PIN_OTYPE_PUSHPULL(14) | \
    PIN_OTYPE_PUSHPULL(15))

#define VAL_GPIOI_OSPEEDR ( \
    PIN_OSPEED_VERYLOW(0) | \
    PIN_OSPEED_VERYLOW(1) | \
    PIN_OSPEED_VERYLOW(2) | \
    PIN_OSPEED_VERYLOW(3) | \
    PIN_OSPEED_VERYLOW(4) | \
    PIN_OSPEED_VERYLOW(5) | \
    PIN_OSPEED_VERYLOW(6) | \
    PIN_OSPEED_VERYLOW(7) | \
    PIN_OSPEED_VERYLOW(8) | \
    PIN_OSPEED_VERYLOW(9) | \
    PIN_OSPEED_VERYLOW(10) | \
    PIN_OSPEED_VERYLOW(11) | \
    PIN_OSPEED_VERYLOW(12) | \
    PIN_OSPEED_VERYLOW(13) | \
    PIN_OSPEED_VERYLOW(14) | \
    PIN_OSPEED_VERYLOW(15))

#define VAL_GPIOI_PUPDR ( \
    PIN_PUPDR_PULLUP(0) | \
    PIN_PUPDR_PULLUP(1) | \
    PIN_PUPDR_PULLUP(2) | \
    PIN_PUPDR_PULLUP(3) | \
    PIN_PUPDR_PULLUP(4) | \
    PIN_PUPDR_PULLUP(5) | \
    PIN_PUPDR_PULLUP(6) | \
    PIN_PUPDR_PULLUP(7) | \
    PIN_PUPDR_PULLUP(8) | \
    PIN_PUPDR_PULLUP(9) | \
    PIN_PUPDR_PULLUP(10) | \
    PIN_PUPDR_PULLUP(11) | \
    PIN_PUPDR_PULLUP(12) | \
    PIN_PUPDR_PULLUP(13) | \
    PIN_PUPDR_PULLUP(14) | \
    PIN_PUPDR_PULLUP(15))

#define VAL_GPIOI_ODR ( \
    PIN_ODR_LOW(0) | \
    PIN_ODR_LOW(1) | \
    PIN_ODR_LOW(2) | \
    PIN_ODR_LOW(3) | \
    PIN_ODR_LOW(4) | \
    PIN_ODR_LOW(5) | \
    PIN_ODR_LOW(6) | \
    PIN_ODR_LOW(7) | \
    PIN_ODR_LOW(8) | \
    PIN_ODR_LOW(9) | \
    PIN_ODR_LOW(10) | \
    PIN_ODR_LOW(11) | \
    PIN_ODR_LOW(12) | \
    PIN_ODR_LOW(13) | \
    PIN_ODR_LOW(14) | \
    PIN_ODR_LOW(15))

#define VAL_GPIOI_AFRL ( \
    PIN_AFIO_AF(0, 0) | \
    PIN_AFIO_AF(1, 0) | \
    PIN_AFIO_AF(2, 0) | \
    PIN_AFIO_AF(3, 0) | \
    PIN_AFIO_AF(4, 0) | \
    PIN_AFIO_AF(5, 0) | \
    PIN_AFIO_AF(6, 0) | \
    PIN_AFIO_AF(7, 0))

#define VAL_GPIOI_AFRH ( \
    PIN_AFIO_AF(8, 0) | \
    PIN_AFIO_AF(9, 0) | \
    PIN_AFIO_AF(10, 0) | \
    PIN_AFIO_AF(11, 0) | \
    PIN_AFIO_AF(12, 0) | \
    PIN_AFIO_AF(13, 0) | \
    PIN_AFIO_AF(14, 0) | \
    PIN_AFIO_AF(15, 0))


/*
 * The jellowcake 303 boards
 * have a 1.5k resistor connected on one end to the D+ line
 * and on the other end to a p-channel mosfet.
 * That mosfet is controlled by pin PB2.
 *
 */

/*
 * USB bus activation macro, required by the USB driver.
 */
#define usb_lld_connect_bus(usbp) palClearPad(PORT_USB_DISC, PAD_USB_DISC)

/*
 * USB bus de-activation macro, required by the USB driver.
 */
#define usb_lld_disconnect_bus(usbp) palSetPad(PORT_USB_DISC, PAD_USB_DISC)


#if !defined(_FROM_ASM_)
#    ifdef __cplusplus
extern "C" {
#    endif
void boardInit(void);
#    ifdef __cplusplus
}
#    endif
#endif /* _FROM_ASM_ */

#endif /* BOARD_H */

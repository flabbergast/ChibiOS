/*
    ChibiOS - Copyright (C) 2014 Derek Mulcahy

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

/**
 * @file    KL2x/kinetis_registry.h
 * @brief   KL2x capabilities registry.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef _KINETIS_REGISTRY_H_
#define _KINETIS_REGISTRY_H_

#if !defined(KL2x) || defined(__DOXYGEN__)
#define KL2x
#endif

/*===========================================================================*/
/* Platform capabilities.                                                    */
/*===========================================================================*/

/**
 * @name    KL2x capabilities
 * @{
 */
/*===========================================================================*/
/* KL25                                                                      */
/*===========================================================================*/
#if defined(KL25) || defined(__DOXYGEN__)

/**
 * @brief   Maximum system and core clock (f_SYS) frequency.
 */
#define KINETIS_SYSCLK_MAX      48000000

/**
 * @brief   Maximum bus clock (f_BUS) frequency.
 */
#define KINETIS_BUSCLK_MAX      24000000

/**
 * @brief   Maximum flash clock (f_FLASH) frequency.
 */
#define KINETIS_FLASHCLK_MAX    24000000L

/* ADC attributes.*/
#define KINETIS_HAS_ADC0            TRUE
#define KINETIS_ADC0_IRC_VECTOR     Vector7C

/* DAC attributes.*/
#define KINETIS_HAS_DAC0            TRUE
#define KINTEIS_DAC0_IRQ_VECTOR     VectorA4

/* DMA attributes.*/
#define KINETIS_DMA0_IRQ_VECTOR     Vector40
#define KINETIS_DMA1_IRQ_VECTOR     Vector44
#define KINETIS_DMA2_IRQ_VECTOR     Vector48
#define KINETIS_DMA3_IRQ_VECTOR     Vector4C
#define KINETIS_HAS_DMA_ERROR_IRQ   FALSE

/* EXT attributes.*/
#define KINETIS_HAS_PORTA           TRUE
#define KINETIS_HAS_PORTB           FALSE
#define KINETIS_HAS_PORTC           FALSE
#define KINETIS_HAS_PORTD           TRUE
#define KINETIS_HAS_PORTE           FALSE
#define KINETIS_PORTA_IRQ_VECTOR    VectorB8
#define KINETIS_PORTD_IRQ_VECTOR    VectorBC
#define KINETIS_GPIO_HAS_OPENDRAIN  FALSE

/* GPT attributes.*/
#define KINETIS_PIT0_HANDLER        Vector98

/* I2C attributes.*/
#define KINETIS_HAS_I2C0            TRUE
#define KINETIS_I2C0_IRQ_VECTOR     Vector60
#define KINETIS_HAS_I2C1            TRUE
#define KINETIS_I2C1_IRQ_VECTOR     Vector64

/* Serial attributes */
#define KINETIS_HAS_SERIAL0         TRUE
#define KINETIS_SERIAL0_IRQ_VECTOR  Vector70
#define KINETIS_HAS_SERIAL1         TRUE
#define KINETIS_SERIAL1_IRQ_VECTOR  Vector74
#define KINETIS_HAS_SERIAL2         TRUE
#define KINETIS_SERIAL2_IRQ_VECTOR  Vector78
#define KINETIS_HAS_SERIAL_ERROR_IRQ FALSE

/* SPI attributes.*/
#define KINETIS_HAS_SPI0            TRUE
#define KINETIS_SPI0_IRQ_VECTOR     Vector68
#define KINETIS_HAS_SPI1            TRUE
#define KINETIS_SPI1_IRQ_VECTOR     Vector6C

/* TPM attributes.*/
#define KINETIS_TPM0_CHANNELS       6
#define KINETIS_TPM1_CHANNELS       2
#define KINETIS_TPM2_CHANNELS       2
#define KINETIS_TPM0_IRQ_VECTOR     Vector84
#define KINETIS_TPM1_IRQ_VECTOR     Vector88
#define KINETIS_TPM2_IRQ_VECTOR     Vector8C

/* USB attributes.*/
#define KINETIS_HAS_USB             TRUE
#define KINETIS_USB_IRQ_VECTOR      VectorA0

#endif /* KL2Y */

/** @} */

#endif /* _KINETIS_REGISTRY_H_ */

/** @} */

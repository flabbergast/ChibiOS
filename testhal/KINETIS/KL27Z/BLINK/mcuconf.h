/*
    ChibiOS - Copyright (C) 2006..2015 Giovanni Di Sirio

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

#ifndef _MCUCONF_H_
#define _MCUCONF_H_

#define KL2x_MCUCONF

/*
 * HAL driver system settings.
 */
#if 1
/* High-frequency internal RC, 48MHz, possible USB clock recovery */
#define KINETIS_MCGLITE_MODE        KINETIS_MCGLITE_MODE_HIRC
#define KINETIS_SYSCLK_FREQUENCY    48000000UL
#define KINETIS_CLKDIV1_OUTDIV1     1
#endif

#if 0
/* Low-frequency internal RC, 8 MHz mode */
#define KINETIS_MCGLITE_MODE        KINETIS_MCGLITE_MODE_LIRC8M
#define KINETIS_SYSCLK_FREQUENCY    8000000UL
#define KINETIS_CLKDIV1_OUTDIV1     1
#endif

/*
 * SERIAL driver system settings.
 */
#define KINETIS_SERIAL_USE_UART0              TRUE

/*
 * USB driver settings
 */
#define KINETIS_USB_USE_USB0                  TRUE
/* need to redefine this, since the default is for K20x */
#define KINETIS_USB_USB0_IRQ_PRIORITY         2

#endif /* _MCUCONF_H_ */

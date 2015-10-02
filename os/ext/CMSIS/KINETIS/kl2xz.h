/*
 * Copyright (C) 2013-2014 Fabio Utzig, http://fabioutzig.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef _KL2xZ_H_
#define _KL2xZ_H_

/*
 * ==============================================================
 * ---------- Interrupt Number Definition -----------------------
 * ==============================================================
 */

/* Device dependent */

/*
 * ==========================================================================
 * ----------- Processor and Core Peripheral Section ------------------------
 * ==========================================================================
 */

/**
 * @brief KL2x Interrupt Number Definition, according to the selected device
 *        in @ref Library_configuration_section
 */
#define __MPU_PRESENT             0
#define __VTOR_PRESENT            1
#define __NVIC_PRIO_BITS          2
#define __Vendor_SysTickConfig    0

#include "core_cm0plus.h"        /* Cortex-M0+ processor and core peripherals */

typedef struct
{
  __IO uint32_t SOPT1;
  __IO uint32_t SOPT1CFG;
       uint32_t RESERVED0[1023];
  __IO uint32_t SOPT2;
  __I  uint32_t RESERVED1[1];
  __IO uint32_t SOPT4;
  __IO uint32_t SOPT5;
       uint32_t RESERVED2[1];
  __IO uint32_t SOPT7;
       uint32_t RESERVED3[2];
  __IO uint32_t SDID;
       uint32_t RESERVED4[3];
  __IO uint32_t SCGC4;
  __IO uint32_t SCGC5;
  __IO uint32_t SCGC6;
  __IO uint32_t SCGC7;
  __IO uint32_t CLKDIV1;
       uint32_t RESERVED5[1];
  __IO uint32_t FCFG1;
  __IO uint32_t FCFG2;
       uint32_t RESERVED6[1];
  __IO uint32_t UIDMH;
  __IO uint32_t UIDML;
  __IO uint32_t UIDL;
       uint32_t RESERVED7[39];
  __IO uint32_t COPC;
  __IO uint32_t SRVCOP;
} SIM_TypeDef;

typedef struct
{
  __IO uint8_t  PE1;
  __IO uint8_t  PE2;
  __IO uint8_t  PE3;
  __IO uint8_t  PE4;
  __IO uint8_t  ME;
  __IO uint8_t  F1;
  __IO uint8_t  F2;
  __I  uint8_t  F3;
  __IO uint8_t  FILT1;
  __IO uint8_t  FILT2;
} LLWU_TypeDef;

typedef struct
{
  __IO uint32_t PCR[32];
  __IO uint32_t GPCLR;
  __IO uint32_t GPCHR;
       uint32_t RESERVED0[6];
  __IO uint32_t ISFR;
} PORT_TypeDef;

/* Device dependent
  MCG_TypeDef;
*/

typedef struct
{
  __IO uint8_t  CR;
} OSC_TypeDef;

typedef struct
{
  __IO uint32_t  SAR;
  __IO uint32_t  DAR;
  __IO uint32_t  DSR_BCR;
  __IO uint32_t  DCR;
} DMAChannel_TypeDef;

typedef struct
{
  DMAChannel_TypeDef ch[4];
} DMA_TypeDef;

typedef struct
{
  __IO uint8_t  CHCFG[4];
} DMAMUX_TypeDef;

typedef struct  {
  __IO uint32_t MCR;             /* PIT Module Control Register */
  __I  uint32_t LTMR64H;         /* PIT Module Control Register */
  __I  uint32_t LTMR64L;         /* PIT Lower Lifetime Timer Register */
       uint8_t  RESERVED0[244];
  struct PIT_CHANNEL {
    __IO uint32_t LDVAL;         /* Timer Load Value Register */
    __I  uint32_t CVAL;          /* Current Timer Value Register */
    __IO uint32_t TCTRL;         /* Timer Control Register */
    __IO uint32_t TFLG;          /* Timer Flag Register */
  } CHANNEL[2];
} PIT_TypeDef;

/* Device dependent
  TPM_TypeDef;
*/

typedef struct
{
  __IO uint32_t SC1A;           // ADC Status and Control Registers 1
  __IO uint32_t SC1B;           // ADC Status and Control Registers 1
  __IO uint32_t CFG1;           // ADC Configuration Register 1
  __IO uint32_t CFG2;           // ADC Configuration Register 2
  __I  uint32_t RA;             // ADC Data Result Register
  __I  uint32_t RB;             // ADC Data Result Register
  __IO uint32_t CV1;            // Compare Value Registers
  __IO uint32_t CV2;            // Compare Value Registers
  __IO uint32_t SC2;            // Status and Control Register 2
  __IO uint32_t SC3;            // Status and Control Register 3
  __IO uint32_t OFS;            // ADC Offset Correction Register
  __IO uint32_t PG;             // ADC Plus-Side Gain Register
  __IO uint32_t MG;             // ADC Minus-Side Gain Register
  __IO uint32_t CLPD;           // ADC Plus-Side General Calibration Value Register
  __IO uint32_t CLPS;           // ADC Plus-Side General Calibration Value Register
  __IO uint32_t CLP4;           // ADC Plus-Side General Calibration Value Register
  __IO uint32_t CLP3;           // ADC Plus-Side General Calibration Value Register
  __IO uint32_t CLP2;           // ADC Plus-Side General Calibration Value Register
  __IO uint32_t CLP1;           // ADC Plus-Side General Calibration Value Register
  __IO uint32_t CLP0;           // ADC Plus-Side General Calibration Value Register
       uint32_t RESERVED0[1];   // ADC Minus-Side General Calibration Value Register
  __IO uint32_t CLMD;           // ADC Minus-Side General Calibration Value Register
  __IO uint32_t CLMS;           // ADC Minus-Side General Calibration Value Register
  __IO uint32_t CLM4;           // ADC Minus-Side General Calibration Value Register
  __IO uint32_t CLM3;           // ADC Minus-Side General Calibration Value Register
  __IO uint32_t CLM2;           // ADC Minus-Side General Calibration Value Register
  __IO uint32_t CLM1;           // ADC Minus-Side General Calibration Value Register
  __IO uint32_t CLM0;           // ADC Minus-Side General Calibration Value Register
} ADC_TypeDef;

typedef struct
{
  __IO uint32_t CSR;
  __IO uint32_t PSR;
  __IO uint32_t CMR;
  __I  uint32_t CNR;
} LPTMR_TypeDef;

/* Device dependent (TSI or FlexIO)
  TSI_TypeDef;
*/

typedef struct
{
  __IO uint32_t PDOR;
  __IO uint32_t PSOR;
  __IO uint32_t PCOR;
  __IO uint32_t PTOR;
  __IO uint32_t PDIR;
  __IO uint32_t PDDR;
} GPIO_TypeDef;

/* Device dependent
  SPI_TypeDef;
*/

/* Device dependent
  I2C_TypeDef;
*/

/* Device dependent
  UART_TypeDef;
*/

/* Device dependent
  LPUART_Typedef;
*/

typedef struct
{
  __IO uint8_t  LVDSC1;
  __IO uint8_t  LVDSC2;
  __IO uint8_t  REGSC;
} PMC_TypeDef;

/* Device dependent
  USBOTG_TypeDef;
*/

typedef struct
{
  __I  uint8_t  SRS0;
  __I  uint8_t  SRS1;
       uint8_t  RESERVED0[2];
  __IO uint8_t  RPFC;
  __IO uint8_t  RPFW;
} RCM_TypeDef;

typedef struct
{
  __IO uint8_t  PMPROT;
  __IO uint8_t  PMCTRL;
  __IO uint8_t  STOPCTRL;
  __I  uint8_t  PMSTAT;
} SMC_TypeDef;

/****************************************************************/
/*                  Peripheral memory map                       */
/****************************************************************/

/* Device dependent */

/****************************************************************/
/*                 Peripheral declaration                       */
/****************************************************************/

/* Device dependent */

/****************************************************************/
/*           Peripheral Registers Bits Definition               */
/****************************************************************/

/****************************************************************/
/*                                                              */
/*             System Integration Module (SIM)                  */
/*                                                              */
/****************************************************************/

/* Device dependent */

/****************************************************************/
/*                                                              */
/*              Low-Leakage Wakeup Unit (LLWU)                  */
/*                                                              */
/****************************************************************/
/**********  Bits definition for LLWU_PE1 register  *************/
#define LLWU_PE1_WUPE3_SHIFT        6                                                                          /*!< Wakeup Pin Enable for LLWU_P3 (shift) */
#define LLWU_PE1_WUPE3_MASK         ((uint8_t)((uint8_t)0x03 << LLWU_PE1_WUPE3_SHIFT))                         /*!< Wakeup Pin Enable for LLWU_P3 (mask) */
#define LLWU_PE1_WUPE3(x)           ((uint8_t)(((uint8_t)(x) << LLWU_PE1_WUPE3_SHIFT) & LLWU_PE1_WUPE3_MASK))  /*!< Wakeup Pin Enable for LLWU_P3 */
#define LLWU_PE1_WUPE2_SHIFT        4                                                                          /*!< Wakeup Pin Enable for LLWU_P2 (shift) */
#define LLWU_PE1_WUPE2_MASK         ((uint8_t)((uint8_t)0x03 << LLWU_PE1_WUPE2_SHIFT))                         /*!< Wakeup Pin Enable for LLWU_P2 (mask) */
#define LLWU_PE1_WUPE2(x)           ((uint8_t)(((uint8_t)(x) << LLWU_PE1_WUPE2_SHIFT) & LLWU_PE1_WUPE2_MASK))  /*!< Wakeup Pin Enable for LLWU_P2 */
#define LLWU_PE1_WUPE1_SHIFT        2                                                                          /*!< Wakeup Pin Enable for LLWU_P1 (shift) */
#define LLWU_PE1_WUPE1_MASK         ((uint8_t)((uint8_t)0x03 << LLWU_PE1_WUPE1_SHIFT))                         /*!< Wakeup Pin Enable for LLWU_P1 (mask) */
#define LLWU_PE1_WUPE1(x)           ((uint8_t)(((uint8_t)(x) << LLWU_PE1_WUPE1_SHIFT) & LLWU_PE1_WUPE1_MASK))  /*!< Wakeup Pin Enable for LLWU_P1 */
#define LLWU_PE1_WUPE0_SHIFT        0                                                                          /*!< Wakeup Pin Enable for LLWU_P0 (shift) */
#define LLWU_PE1_WUPE0_MASK         ((uint8_t)((uint8_t)0x03 << LLWU_PE1_WUPE0_SHIFT))                         /*!< Wakeup Pin Enable for LLWU_P0 (mask) */
#define LLWU_PE1_WUPE0(x)           ((uint8_t)(((uint8_t)(x) << LLWU_PE1_WUPE0_SHIFT) & LLWU_PE1_WUPE0_MASK))  /*!< Wakeup Pin Enable for LLWU_P0 */

/**********  Bits definition for LLWU_PE2 register  *************/
#define LLWU_PE2_WUPE7_SHIFT        6                                                                          /*!< Wakeup Pin Enable for LLWU_P7 (shift) */
#define LLWU_PE2_WUPE7_MASK         ((uint8_t)((uint8_t)0x03 << LLWU_PE2_WUPE7_SHIFT))                         /*!< Wakeup Pin Enable for LLWU_P7 (mask) */
#define LLWU_PE2_WUPE7(x)           ((uint8_t)(((uint8_t)(x) << LLWU_PE2_WUPE7_SHIFT) & LLWU_PE2_WUPE7_MASK))  /*!< Wakeup Pin Enable for LLWU_P7 */
#define LLWU_PE2_WUPE6_SHIFT        4                                                                          /*!< Wakeup Pin Enable for LLWU_P6 (shift) */
#define LLWU_PE2_WUPE6_MASK         ((uint8_t)((uint8_t)0x03 << LLWU_PE2_WUPE6_SHIFT))                         /*!< Wakeup Pin Enable for LLWU_P6 (mask) */
#define LLWU_PE2_WUPE6(x)           ((uint8_t)(((uint8_t)(x) << LLWU_PE2_WUPE6_SHIFT) & LLWU_PE2_WUPE6_MASK))  /*!< Wakeup Pin Enable for LLWU_P6 */
#define LLWU_PE2_WUPE5_SHIFT        2                                                                          /*!< Wakeup Pin Enable for LLWU_P5 (shift) */
#define LLWU_PE2_WUPE5_MASK         ((uint8_t)((uint8_t)0x03 << LLWU_PE2_WUPE5_SHIFT))                         /*!< Wakeup Pin Enable for LLWU_P5 (mask) */
#define LLWU_PE2_WUPE5(x)           ((uint8_t)(((uint8_t)(x) << LLWU_PE2_WUPE5_SHIFT) & LLWU_PE2_WUPE5_MASK))  /*!< Wakeup Pin Enable for LLWU_P5 */
#define LLWU_PE2_WUPE4_SHIFT        0                                                                          /*!< Wakeup Pin Enable for LLWU_P4 (shift) */
#define LLWU_PE2_WUPE4_MASK         ((uint8_t)((uint8_t)0x03 << LLWU_PE2_WUPE4_SHIFT))                         /*!< Wakeup Pin Enable for LLWU_P4 (mask) */
#define LLWU_PE2_WUPE4(x)           ((uint8_t)(((uint8_t)(x) << LLWU_PE2_WUPE4_SHIFT) & LLWU_PE2_WUPE4_MASK))  /*!< Wakeup Pin Enable for LLWU_P4 */

/**********  Bits definition for LLWU_PE3 register  *************/
#define LLWU_PE3_WUPE11_SHIFT       6                                                                            /*!< Wakeup Pin Enable for LLWU_P11 (shift) */
#define LLWU_PE3_WUPE11_MASK        ((uint8_t)((uint8_t)0x03 << LLWU_PE3_WUPE11_SHIFT))                          /*!< Wakeup Pin Enable for LLWU_P11 (mask) */
#define LLWU_PE3_WUPE11(x)          ((uint8_t)(((uint8_t)(x) << LLWU_PE3_WUPE11_SHIFT) & LLWU_PE3_WUPE11_MASK))  /*!< Wakeup Pin Enable for LLWU_P11 */
#define LLWU_PE3_WUPE10_SHIFT       4                                                                            /*!< Wakeup Pin Enable for LLWU_P10 (shift) */
#define LLWU_PE3_WUPE10_MASK        ((uint8_t)((uint8_t)0x03 << LLWU_PE3_WUPE10_SHIFT))                          /*!< Wakeup Pin Enable for LLWU_P10 (mask) */
#define LLWU_PE3_WUPE10(x)          ((uint8_t)(((uint8_t)(x) << LLWU_PE3_WUPE10_SHIFT) & LLWU_PE3_WUPE10_MASK))  /*!< Wakeup Pin Enable for LLWU_P10 */
#define LLWU_PE3_WUPE13_SHIFT        2                                                                          /*!< Wakeup Pin Enable for LLWU_P9 (shift) */
#define LLWU_PE3_WUPE13_MASK         ((uint8_t)((uint8_t)0x03 << LLWU_PE3_WUPE13_SHIFT))                         /*!< Wakeup Pin Enable for LLWU_P9 (mask) */
#define LLWU_PE3_WUPE13(x)           ((uint8_t)(((uint8_t)(x) << LLWU_PE3_WUPE13_SHIFT) & LLWU_PE3_WUPE13_MASK))  /*!< Wakeup Pin Enable for LLWU_P9 */
#define LLWU_PE3_WUPE8_SHIFT        0                                                                          /*!< Wakeup Pin Enable for LLWU_P8 (shift) */
#define LLWU_PE3_WUPE8_MASK         ((uint8_t)((uint8_t)0x03 << LLWU_PE3_WUPE8_SHIFT))                         /*!< Wakeup Pin Enable for LLWU_P8 (mask) */
#define LLWU_PE3_WUPE8(x)           ((uint8_t)(((uint8_t)(x) << LLWU_PE3_WUPE8_SHIFT) & LLWU_PE3_WUPE8_MASK))  /*!< Wakeup Pin Enable for LLWU_P8 */

/**********  Bits definition for LLWU_PE4 register  *************/
#define LLWU_PE4_WUPE15_SHIFT       6                                                                            /*!< Wakeup Pin Enable for LLWU_P15 (shift) */
#define LLWU_PE4_WUPE15_MASK        ((uint8_t)((uint8_t)0x03 << LLWU_PE4_WUPE15_SHIFT))                          /*!< Wakeup Pin Enable for LLWU_P15 (mask) */
#define LLWU_PE4_WUPE15(x)          ((uint8_t)(((uint8_t)(x) << LLWU_PE4_WUPE15_SHIFT) & LLWU_PE4_WUPE15_MASK))  /*!< Wakeup Pin Enable for LLWU_P15 */
#define LLWU_PE4_WUPE14_SHIFT       4                                                                            /*!< Wakeup Pin Enable for LLWU_P14 (shift) */
#define LLWU_PE4_WUPE14_MASK        ((uint8_t)((uint8_t)0x03 << LLWU_PE4_WUPE14_SHIFT))                          /*!< Wakeup Pin Enable for LLWU_P14 (mask) */
#define LLWU_PE4_WUPE14(x)          ((uint8_t)(((uint8_t)(x) << LLWU_PE4_WUPE14_SHIFT) & LLWU_PE4_WUPE14_MASK))  /*!< Wakeup Pin Enable for LLWU_P14 */
#define LLWU_PE4_WUPE13_SHIFT       2                                                                            /*!< Wakeup Pin Enable for LLWU_P13 (shift) */
#define LLWU_PE4_WUPE13_MASK        ((uint8_t)((uint8_t)0x03 << LLWU_PE4_WUPE13_SHIFT))                          /*!< Wakeup Pin Enable for LLWU_P13 (mask) */
#define LLWU_PE4_WUPE13(x)          ((uint8_t)(((uint8_t)(x) << LLWU_PE4_WUPE13_SHIFT) & LLWU_PE4_WUPE13_MASK))  /*!< Wakeup Pin Enable for LLWU_P13 */
#define LLWU_PE4_WUPE12_SHIFT       0                                                                            /*!< Wakeup Pin Enable for LLWU_P12 (shift) */
#define LLWU_PE4_WUPE12_MASK        ((uint8_t)((uint8_t)0x03 << LLWU_PE4_WUPE12_SHIFT))                          /*!< Wakeup Pin Enable for LLWU_P12 (mask) */
#define LLWU_PE4_WUPE12(x)          ((uint8_t)(((uint8_t)(x) << LLWU_PE4_WUPE12_SHIFT) & LLWU_PE4_WUPE12_MASK))  /*!< Wakeup Pin Enable for LLWU_P12 */

/**********  Bits definition for LLWU_ME register  *************/
#define LLWU_ME_WUME7               ((uint8_t)((uint8_t)1 << 7))    /*!< Wakeup Module Enable for Module 7 */
#define LLWU_ME_WUME6               ((uint8_t)((uint8_t)1 << 6))    /*!< Wakeup Module Enable for Module 6 */
#define LLWU_ME_WUME5               ((uint8_t)((uint8_t)1 << 5))    /*!< Wakeup Module Enable for Module 5 */
#define LLWU_ME_WUME4               ((uint8_t)((uint8_t)1 << 4))    /*!< Wakeup Module Enable for Module 4 */
#define LLWU_ME_WUME3               ((uint8_t)((uint8_t)1 << 3))    /*!< Wakeup Module Enable for Module 3 */
#define LLWU_ME_WUME2               ((uint8_t)((uint8_t)1 << 2))    /*!< Wakeup Module Enable for Module 2 */
#define LLWU_ME_WUME1               ((uint8_t)((uint8_t)1 << 1))    /*!< Wakeup Module Enable for Module 1 */
#define LLWU_ME_WUME0               ((uint8_t)((uint8_t)1 << 0))    /*!< Wakeup Module Enable for Module 0 */

/**********  Bits definition for LLWU_F1 register  *************/
#define LLWU_F1_WUF7                ((uint8_t)((uint8_t)1 << 7))    /*!< Wakeup Flag for LLWU_P7 */
#define LLWU_F1_WUF6                ((uint8_t)((uint8_t)1 << 6))    /*!< Wakeup Flag for LLWU_P6 */
#define LLWU_F1_WUF5                ((uint8_t)((uint8_t)1 << 5))    /*!< Wakeup Flag for LLWU_P5 */
#define LLWU_F1_WUF4                ((uint8_t)((uint8_t)1 << 4))    /*!< Wakeup Flag for LLWU_P4 */
#define LLWU_F1_WUF3                ((uint8_t)((uint8_t)1 << 3))    /*!< Wakeup Flag for LLWU_P3 */
#define LLWU_F1_WUF2                ((uint8_t)((uint8_t)1 << 2))    /*!< Wakeup Flag for LLWU_P2 */
#define LLWU_F1_WUF1                ((uint8_t)((uint8_t)1 << 1))    /*!< Wakeup Flag for LLWU_P1 */
#define LLWU_F1_WUF0                ((uint8_t)((uint8_t)1 << 0))    /*!< Wakeup Flag for LLWU_P0 */

/**********  Bits definition for LLWU_F2 register  *************/
#define LLWU_F2_WUF15               ((uint8_t)((uint8_t)1 << 7))    /*!< Wakeup Flag for LLWU_P15 */
#define LLWU_F2_WUF14               ((uint8_t)((uint8_t)1 << 6))    /*!< Wakeup Flag for LLWU_P14 */
#define LLWU_F2_WUF13               ((uint8_t)((uint8_t)1 << 5))    /*!< Wakeup Flag for LLWU_P13 */
#define LLWU_F2_WUF12               ((uint8_t)((uint8_t)1 << 4))    /*!< Wakeup Flag for LLWU_P12 */
#define LLWU_F2_WUF11               ((uint8_t)((uint8_t)1 << 3))    /*!< Wakeup Flag for LLWU_P11 */
#define LLWU_F2_WUF10               ((uint8_t)((uint8_t)1 << 2))    /*!< Wakeup Flag for LLWU_P10 */
#define LLWU_F2_WUF9                ((uint8_t)((uint8_t)1 << 1))    /*!< Wakeup Flag for LLWU_P9 */
#define LLWU_F2_WUF8                ((uint8_t)((uint8_t)1 << 0))    /*!< Wakeup Flag for LLWU_P8 */

/**********  Bits definition for LLWU_F3 register  *************/
#define LLWU_F3_MWUF7               ((uint8_t)((uint8_t)1 << 7))    /*!< Wakeup Flag for Module 7 */
#define LLWU_F3_MWUF6               ((uint8_t)((uint8_t)1 << 6))    /*!< Wakeup Flag for Module 6 */
#define LLWU_F3_MWUF5               ((uint8_t)((uint8_t)1 << 5))    /*!< Wakeup Flag for Module 5 */
#define LLWU_F3_MWUF4               ((uint8_t)((uint8_t)1 << 4))    /*!< Wakeup Flag for Module 4 */
#define LLWU_F3_MWUF3               ((uint8_t)((uint8_t)1 << 3))    /*!< Wakeup Flag for Module 3 */
#define LLWU_F3_MWUF2               ((uint8_t)((uint8_t)1 << 2))    /*!< Wakeup Flag for Module 2 */
#define LLWU_F3_MWUF1               ((uint8_t)((uint8_t)1 << 1))    /*!< Wakeup Flag for Module 1 */
#define LLWU_F3_MWUF0               ((uint8_t)((uint8_t)1 << 0))    /*!< Wakeup Flag for Module 0 */

/**********  Bits definition for LLWU_FILT1 register  *************/
#define LLWU_FILT1_FILTF            ((uint8_t)((uint8_t)1 << 7))    /*!< Filter Detect Flag */
#define LLWU_FILT1_FILTE_SHIFT      5                                                                              /*!< Digital Filter on External Pin (shift) */
#define LLWU_FILT1_FILTE_MASK       ((uint8_t)((uint8_t)0x03 << LLWU_FILT1_FILTE_SHIFT))                           /*!< Digital Filter on External Pin (mask) */
#define LLWU_FILT1_FILTE(x)         ((uint8_t)(((uint8_t)(x) << LLWU_FILT1_FILTE_SHIFT) & LLWU_FILT1_FILTE_MASK))  /*!< Digital Filter on External Pin */
#define LLWU_FILT1_FILTE_DISABLED   LLWU_FILT1_FILTE(0)  /*!< Filter disabled */
#define LLWU_FILT1_FILTE_POSEDGE    LLWU_FILT1_FILTE(1)  /*!< Filter posedge detect enabled */
#define LLWU_FILT1_FILTE_NEGEDGE    LLWU_FILT1_FILTE(2)  /*!< Filter negedge detect enabled */
#define LLWU_FILT1_FILTE_ANYEDGE    LLWU_FILT1_FILTE(3)  /*!< Filter any edge detect enabled */
#define LLWU_FILT1_FILTSEL_SHIFT    0                                                                                  /*!< Filter Pin Select (LLWU_P0 ... LLWU_P15) (shift) */
#define LLWU_FILT1_FILTSEL_MASK     ((uint8_t)((uint8_t)0x0F << LLWU_FILT1_FILTSEL_SHIFT))                             /*!< Filter Pin Select (LLWU_P0 ... LLWU_P15) (mask) */
#define LLWU_FILT1_FILTSEL(x)       ((uint8_t)(((uint8_t)(x) << LLWU_FILT1_FILTSEL_SHIFT) & LLWU_FILT1_FILTSEL_MASK))  /*!< Filter Pin Select (LLWU_P0 ... LLWU_P15) */

/**********  Bits definition for LLWU_FILT2 register  *************/
#define LLWU_FILT2_FILTF            ((uint8_t)((uint8_t)1 << 7))    /*!< Filter Detect Flag */
#define LLWU_FILT2_FILTE_SHIFT      5                                                                              /*!< Digital Filter on External Pin (shift) */
#define LLWU_FILT2_FILTE_MASK       ((uint8_t)((uint8_t)0x03 << LLWU_FILT2_FILTE_SHIFT))                           /*!< Digital Filter on External Pin (mask) */
#define LLWU_FILT2_FILTE(x)         ((uint8_t)(((uint8_t)(x) << LLWU_FILT2_FILTE_SHIFT) & LLWU_FILT2_FILTE_MASK))  /*!< Digital Filter on External Pin */
#define LLWU_FILT2_FILTE_DISABLED   LLWU_FILT2_FILTE(0)  /*!< Filter disabled */
#define LLWU_FILT2_FILTE_POSEDGE    LLWU_FILT2_FILTE(1)  /*!< Filter posedge detect enabled */
#define LLWU_FILT2_FILTE_NEGEDGE    LLWU_FILT2_FILTE(2)  /*!< Filter negedge detect enabled */
#define LLWU_FILT2_FILTE_ANYEDGE    LLWU_FILT2_FILTE(3)  /*!< Filter any edge detect enabled */
#define LLWU_FILT2_FILTSEL_SHIFT    0                                                                                  /*!< Filter Pin Select (LLWU_P0 ... LLWU_P15) (shift) */
#define LLWU_FILT2_FILTSEL_MASK     ((uint8_t)((uint8_t)0x0F << LLWU_FILT2_FILTSEL_SHIFT))                             /*!< Filter Pin Select (LLWU_P0 ... LLWU_P15) (mask) */
#define LLWU_FILT2_FILTSEL(x)       ((uint8_t)(((uint8_t)(x) << LLWU_FILT2_FILTSEL_SHIFT) & LLWU_FILT2_FILTSEL_MASK))  /*!< Filter Pin Select (LLWU_P0 ... LLWU_P15) */

/****************************************************************/
/*                                                              */
/*           Port Control and interrupts (PORT)                 */
/*                                                              */
/****************************************************************/
/********  Bits definition for PORTx_PCRn register  *************/
#define PORTx_PCRn_ISF               ((uint32_t)0x01000000)    /*!< Interrupt Status Flag */
#define PORTx_PCRn_IRQC_SHIFT        16
#define PORTx_PCRn_IRQC_MASK         ((uint32_t)0x000F0000)    /*!< Interrupt Configuration */
#define PORTx_PCRn_IRQC(x)           ((uint32_t)(((uint32_t)(x) << PORTx_PCRn_IRQC_SHIFT) & PORTx_PCRn_IRQC_MASK))
#define PORTx_PCRn_MUX_SHIFT         8                         /*!< Pin Mux Control (shift) */
#define PORTx_PCRn_MUX_MASK          ((uint32_t)0x00000700)    /*!< Pin Mux Control (mask) */
#define PORTx_PCRn_MUX(x)            ((uint32_t)(((uint32_t)(x) << PORTx_PCRn_MUX_SHIFT) & PORTx_PCRn_MUX_MASK))  /*!< Pin Mux Control */
#define PORTx_PCRn_DSE               ((uint32_t)0x00000040)    /*!< Drive Strength Enable */
#define PORTx_PCRn_PFE               ((uint32_t)0x00000010)    /*!< Passive Filter Enable */
#define PORTx_PCRn_SRE               ((uint32_t)0x00000004)    /*!< Slew Rate Enable */
#define PORTx_PCRn_PE                ((uint32_t)0x00000002)    /*!< Pull Enable */
#define PORTx_PCRn_PS                ((uint32_t)0x00000001)    /*!< Pull Select */

/****************************************************************/
/*                                                              */
/*                   Oscillator (OSC)                           */
/*                                                              */
/****************************************************************/
/***********  Bits definition for OSC_CR register  **************/
#define OSC_CR_ERCLKEN               ((uint8_t)0x80)    /*!< External Reference Enable */
#define OSC_CR_EREFSTEN              ((uint8_t)0x20)    /*!< External Reference Stop Enable */
#define OSC_CR_SC2P                  ((uint8_t)0x08)    /*!< Oscillator 2pF Capacitor Load Configure */
#define OSC_CR_SC4P                  ((uint8_t)0x04)    /*!< Oscillator 4pF Capacitor Load Configure */
#define OSC_CR_SC8P                  ((uint8_t)0x02)    /*!< Oscillator 8pF Capacitor Load Configure */
#define OSC_CR_SC16P                 ((uint8_t)0x01)    /*!< Oscillator 16pF Capacitor Load Configure */

/****************************************************************/
/*                                                              */
/*                 Direct Memory Access (DMA)                   */
/*                                                              */
/****************************************************************/
/***********  Bits definition for DMA_BCRn register  ************/
#define DMA_DSR_BCRn_CE          ((uint32_t)((uint32_t)1 << 30))    /*!< Configuration Error */
#define DMA_DSR_BCRn_BES         ((uint32_t)((uint32_t)1 << 29))    /*!< Bus Error on Source */
#define DMA_DSR_BCRn_BED         ((uint32_t)((uint32_t)1 << 28))    /*!< Bus Error on Destination */
#define DMA_DSR_BCRn_REQ         ((uint32_t)((uint32_t)1 << 26))    /*!< Request */
#define DMA_DSR_BCRn_BSY         ((uint32_t)((uint32_t)1 << 25))    /*!< Busy */
#define DMA_DSR_BCRn_DONE        ((uint32_t)((uint32_t)1 << 24))    /*!< Transactions done */
#define DMA_DSR_BCRn_BCR_SHIFT   0                                                                                /*!< Bytes yet to be transferred for block (shift) */
#define DMA_DSR_BCRn_BCR_MASK    ((uint32_t)((uint32_t)0x00FFFFFF << DMA_DSR_BCRn_BCR_SHIFT))                     /*!< Bytes yet to be transferred for block (mask) */
#define DMA_DSR_BCRn_BCR(x)      ((uint32_t)(((uint32_t)(x) << DMA_DSR_BCRn_BCR_SHIFT) & DMA_DSR_BCRn_BCR_MASK))  /*!< Bytes yet to be transferred for block */

/***********  Bits definition for DMA_DCRn register  ************/
#define DMA_DCRn_EINT            ((uint32_t)((uint32_t)1 << 31))         /*!< Enable interrupt on completion of transfer */
#define DMA_DCRn_ERQ             ((uint32_t)((uint32_t)1 << 30))         /*!< Enable peripheral request */
#define DMA_DCRn_CS              ((uint32_t)((uint32_t)1 << 29))         /*!< Cycle steal */
#define DMA_DCRn_AA              ((uint32_t)((uint32_t)1 << 28))         /*!< Auto-align */
#define DMA_DCRn_EADREQ          ((uint32_t)((uint32_t)1 << 23))         /*!< Enable asynchronous DMA requests */
#define DMA_DCRn_SINC            ((uint32_t)((uint32_t)1 << 22))        /*!< Source increment */
#define DMA_DCRn_SSIZE_SHIFT     20                                                               /*!< Source size (shift) */
#define DMA_DCRn_SSIZE_MASK      ((uint32_t)((uint32_t)0x03 << DMA_DCRn_SSIZE_SHIFT))                         /*!< Source size (mask) */
#define DMA_DCRn_SSIZE(x)        ((uint32_t)(((uint32_t)(x) << DMA_DCRn_SSIZE_SHIFT) & DMA_DCRn_SSIZE_MASK))  /*!< Source size */
#define DMA_DCRn_DINC            ((uint32_t)((uint32_t)1 << 19))                                              /*!< Destination increment */
#define DMA_DCRn_DSIZE_SHIFT     17                                                                           /*!< Destination size (shift) */
#define DMA_DCRn_DSIZE_MASK      ((uint32_t)((uint32_t)0x03 << DMA_DCRn_DSIZE_SHIFT))                         /*!< Destination size (mask) */
#define DMA_DCRn_DSIZE(x)        ((uint32_t)(((uint32_t)(x) << DMA_DCRn_DSIZE_SHIFT) & DMA_DCRn_DSIZE_MASK))  /*!< Destination size */
#define DMA_DCRn_START           ((uint32_t)((uint32_t)1 << 16))                                            /*!< Start transfer */
#define DMA_DCRn_SMOD_SHIFT      12                                                                         /*!< Source address modulo (shift) */
#define DMA_DCRn_SMOD_MASK       ((uint32_t)((uint32_t)0x0F << DMA_DCRn_SMOD_SHIFT))                        /*!< Source address modulo (mask) */
#define DMA_DCRn_SMOD(x)         ((uint32_t)(((uint32_t)(x) << DMA_DCRn_SMOD_SHIFT) & DMA_DCRn_SMOD_MASK))  /*!< Source address modulo */
#define DMA_DCRn_DMOD_SHIFT      8                                                                          /*!< Destination address modulo (shift) */
#define DMA_DCRn_DMOD_MASK       ((uint32_t)0x0F << DMA_DCRn_DMOD_SHIFT)                                    /*!< Destination address modulo (mask) */
#define DMA_DCRn_DMOD(x)         ((uint32_t)(((uint32_t)(x) << DMA_DCRn_DMOD_SHIFT) & DMA_DCRn_DMOD_MASK))  /*!< Destination address modulo */
#define DMA_DCRn_D_REQ           ((uint32_t)((uint32_t)1 <<  7))                                            /*!< Disable request */
#define DMA_DCRn_LINKCC_SHIFT    4                                                                              /*!< Link channel control (shift) */
#define DMA_DCRn_LINKCC_MASK     ((uint32_t)((uint32_t)0x03 << DMA_DCRn_LINKCC_SHIFT))                          /*!< Link channel control (mask) */
#define DMA_DCRn_LINKCC(x)       ((uint32_t)(((uint32_t)(x) << DMA_DCRn_LINKCC_SHIFT) & DMA_DCRn_LINKCC_MASK))  /*!< Link channel control */
#define DMA_DCRn_LCH1_SHIFT      2                                                                          /*!< Link channel 1 (shift) */
#define DMA_DCRn_LCH1_MASK       ((uint32_t)((uint32_t)0x03 << DMA_DCRn_LCH1_SHIFT))                        /*!< Link channel 1 (mask) */
#define DMA_DCRn_LCH1(x)         ((uint32_t)(((uint32_t)(x) << DMA_DCRn_LCH1_SHIFT) & DMA_DCRn_LCH1_MASK))  /*!< Link channel 1 */
#define DMA_DCRn_LCH2_SHIFT      0                                                                          /*!< Link channel 2 (shift) */
#define DMA_DCRn_LCH2_MASK       ((uint32_t)((uint32_t)0x03 << DMA_DCRn_LCH2_SHIFT))                        /*!< Link channel 2 (mask) */
#define DMA_DCRn_LCH2(x)         ((uint32_t)(((uint32_t)(x) << DMA_DCRn_LCH2_SHIFT) & DMA_DCRn_LCH2_MASK))  /*!< Link channel 2 */

/****************************************************************/
/*                                                              */
/*         Direct Memory Access Multiplexer (DMAMUX)            */
/*                                                              */
/****************************************************************/
/********  Bits definition for DMAMUX_CHCFGn register  **********/
#define DMAMUX_CHCFGn_ENBL           ((uint8_t)((uint8_t)1 << 7))  /*!< DMA Channel Enable */
#define DMAMUX_CHCFGn_TRIG           ((uint8_t)((uint8_t)1 << 6))  /*!< DMA Channel Trigger Enable */
#define DMAMUX_CHCFGn_SOURCE_SHIFT   0                                                                                      /*!< DMA Channel Source (Slot) (shift) */
#define DMAMUX_CHCFGn_SOURCE_MASK    ((uint8_t)((uint8_t)0x3F << DMAMUX_CHCFGn_SOURCE_SHIFT))                               /*!< DMA Channel Source (Slot) (mask) */
#define DMAMUX_CHCFGn_SOURCE(x)      ((uint8_t)(((uint8_t)(x) << DMAMUX_CHCFGn_SOURCE_SHIFT) & DMAMUX_CHCFGn_SOURCE_MASK))  /*!< DMA Channel Source (Slot) */

/****************************************************************/
/*                                                              */
/*               Periodic Interrupt Timer (PIT)                 */
/*                                                              */
/****************************************************************/
/***********  Bits definition for PIT_MCR register  *************/
#define PIT_MCR_MDIS            ((uint32_t)((uint32_t)1 << 1)) /*!< Module Disable */
#define PIT_MCR_FRZ             ((uint32_t)((uint32_t)1 << 0)) /*!< Freeze */
/**********  Bits definition for PIT_LDVALn register  ***********/
#define PIT_LDVALn_TSV_SHIFT    0 /*!< Timer Start Value */
#define PIT_LDVALn_TSV_MASK     ((uint32_t)((uint32_t)0xFFFFFFFF << PIT_LDVALn_TSV_SHIFT))
#define PIT_LDVALn_TSV(x)       (((uint32_t)(((uint32_t)(x))<<PIT_LDVALn_TSV_SHIFT))&PIT_LDVALn_TSV_MASK)
/**********  Bits definition for PIT_CVALn register  ************/
#define PIT_CVALn_TVL_SHIFT     0 /*!< Current Timer Value */
#define PIT_CVALn_TVL_MASK      ((uint32_t)((uint32_t)0xFFFFFFFF << PIT_CVALn_TVL_SHIFT))
#define PIT_CVALn_TVL(x)        (((uint32_t)(((uint32_t)(x))<<PIT_CVALn_TVL_SHIFT))&PIT_CVALn_TVL_MASK)
/**********  Bits definition for PIT_TCTRLn register  ***********/
#define PIT_TCTRLn_CHN          ((uint32_t)((uint32_t)1 << 2))  /*!< Chain Mode */
#define PIT_TCTRLn_TIE          ((uint32_t)((uint32_t)1 << 1))  /*!< Timer Interrupt Enable */
#define PIT_TCTRLn_TEN          ((uint32_t)((uint32_t)1 << 0))  /*!< Timer Enable */
/**********  Bits definition for PIT_TFLGn register  ************/
#define PIT_TFLGn_TIF           ((uint32_t)((uint32_t)1 << 0))  /*!< Timer Interrupt Flag */

/****************************************************************/
/*                                                              */
/*              Analog-to-Digital Converter (ADC)               */
/*                                                              */
/****************************************************************/
/***********  Bits definition for ADCx_SC1n register  ***********/
#define ADCx_SC1n_COCO          ((uint32_t)((uint32_t)1 << 7))  /*!< Conversion Complete Flag */
#define ADCx_SC1n_AIEN          ((uint32_t)((uint32_t)1 << 6))  /*!< Interrupt Enable */
#define ADCx_SC1n_DIFF          ((uint32_t)((uint32_t)1 << 5))  /*!< Differential Mode Enable */
#define ADCx_SC1n_ADCH_SHIFT    0                                                                            /*!< Input channel select (shift) */
#define ADCx_SC1n_ADCH_MASK     ((uint32_t)((uint32_t)0x1F << ADCx_SC1n_ADCH_SHIFT))                         /*!< Input channel select (mask) */
#define ADCx_SC1n_ADCH(x)       ((uint32_t)(((uint32_t)(x) << ADCx_SC1n_ADCH_SHIFT) & ADCx_SC1n_ADCH_MASK))  /*!< Input channel select */

/***********  Bits definition for ADCx_CFG1 register  ***********/
#define ADCx_CFG1_ADLPC         ((uint32_t)((uint32_t)1 << 7))  /*!< Low-Power Configuration */
#define ADCx_CFG1_ADIV_SHIFT    5                                                                            /*!< Clock Divide Select (shift) */
#define ADCx_CFG1_ADIV_MASK     ((uint32_t)((uint32_t)0x03 << ADCx_CFG1_ADIV_SHIFT))                         /*!< Clock Divide Select (mask) */
#define ADCx_CFG1_ADIV(x)       ((uint32_t)(((uint32_t)(x) << ADCx_CFG1_ADIV_SHIFT) & ADCx_CFG1_ADIV_MASK))  /*!< Clock Divide Select */
#define ADCx_CFG1_ADLSMP        ((uint32_t)((uint32_t)1 << 4))  /*!< Sample time configuration */
#define ADCx_CFG1_MODE_SHIFT    2                                                                            /*!< Conversion mode (resolution) selection (shift) */
#define ADCx_CFG1_MODE_MASK     ((uint32_t)((uint32_t)0x03 << ADCx_CFG1_MODE_SHIFT))                         /*!< Conversion mode (resolution) selection (mask) */
#define ADCx_CFG1_MODE(x)       ((uint32_t)(((uint32_t)(x) << ADCx_CFG1_MODE_SHIFT) & ADCx_CFG1_MODE_MASK))  /*!< Conversion mode (resolution) selection */
#define ADCx_CFG1_ADICLK_SHIFT  0                                                                                /*!< Input Clock Select (shift) */
#define ADCx_CFG1_ADICLK_MASK   ((uint32_t)((uint32_t)0x03 << ADCx_CFG1_ADICLK_SHIFT))                           /*!< Input Clock Select (mask) */
#define ADCx_CFG1_ADICLK(x)     ((uint32_t)(((uint32_t)(x) << ADCx_CFG1_ADICLK_SHIFT) & ADCx_CFG1_ADICLK_MASK))  /*!< Input Clock Select */

/***********  Bits definition for ADCx_CFG2 register  ***********/
#define ADCx_CFG2_MUXSEL        ((uint32_t)((uint32_t)1 << 4))  /*!< ADC Mux Select */
#define ADCx_CFG2_ADACKEN       ((uint32_t)((uint32_t)1 << 3))  /*!< Asynchronous Clock Output Enable */
#define ADCx_CFG2_ADHSC         ((uint32_t)((uint32_t)1 << 2))  /*!< High-Speed Configuration */
#define ADCx_CFG2_ADLSTS_SHIFT  0                                                                                /*!< Long Sample Time Select (shift) */
#define ADCx_CFG2_ADLSTS_MASK   ((uint32_t)((uint32_t)0x03 << ADCx_CFG2_ADLSTS_SHIFT))                           /*!< Long Sample Time Select (mask) */
#define ADCx_CFG2_ADLSTS(x)     ((uint32_t)(((uint32_t)(x) << ADCx_CFG2_ADLSTS_SHIFT) & ADCx_CFG2_ADLSTS_MASK))  /*!< Long Sample Time Select */

/***********  Bits definition for ADCx_SC2 register  ***********/
#define ADCx_SC2_ADACT          ((uint32_t)((uint32_t)1 << 7))  /*!< Conversion Active */
#define ADCx_SC2_ADTRG          ((uint32_t)((uint32_t)1 << 6))  /*!< Conversion Trigger Select */
#define ADCx_SC2_ACFE           ((uint32_t)((uint32_t)1 << 5))  /*!< Compare Function Enable */
#define ADCx_SC2_ACFGT          ((uint32_t)((uint32_t)1 << 4))  /*!< Compare Function Greater Than Enable */
#define ADCx_SC2_ACREN          ((uint32_t)((uint32_t)1 << 3))  /*!< Compare Function Range Enable */
#define ADCx_SC2_DMAEN          ((uint32_t)((uint32_t)1 << 2))  /*!< DMA Enable */
#define ADCx_SC2_REFSEL_SHIFT   0                                                                              /*!< Voltage Reference Selection (shift) */
#define ADCx_SC2_REFSEL_MASK    ((uint32_t)((uint32_t)0x03 << ADCx_SC2_REFSEL_SHIFT))                          /*!< Voltage Reference Selection (mask) */
#define ADCx_SC2_REFSEL(x)      ((uint32_t)(((uint32_t)(x) << ADCx_SC2_REFSEL_SHIFT) & ADCx_SC2_REFSEL_MASK))  /*!< Voltage Reference Selection */

/***********  Bits definition for ADCx_SC3 register  ***********/
#define ADCx_SC3_CAL            ((uint32_t)((uint32_t)1 << 7))  /*!< Calibration */
#define ADCx_SC3_CALF           ((uint32_t)((uint32_t)1 << 6))  /*!< Calibration Failed Flag */
#define ADCx_SC3_ADCO           ((uint32_t)((uint32_t)1 << 3))  /*!< Continuous Conversion Enable */
#define ADCx_SC3_AVGE           ((uint32_t)((uint32_t)1 << 2))  /*!< Hardware Average Enable */
#define ADCx_SC3_AVGS_SHIFT     0                                                                          /*!< Hardware Average Select (shift) */
#define ADCx_SC3_AVGS_MASK      ((uint32_t)((uint32_t)0x03 << ADCx_SC3_AVGS_SHIFT))                        /*!< Hardware Average Select (mask) */
#define ADCx_SC3_AVGS(x)        ((uint32_t)(((uint32_t)(x) << ADCx_SC3_AVGS_SHIFT) & ADCx_SC3_AVGS_MASK))  /*!< Hardware Average Select */

/****************************************************************/
/*                                                              */
/*                   Low-Power Timer (LPTMR)                    */
/*                                                              */
/****************************************************************/
/**********  Bits definition for LPTMRx_CSR register  ***********/
#define LPTMRx_CSR_TCF              ((uint32_t)((uint32_t)1 << 7))  /*!< Timer Compare Flag */
#define LPTMRx_CSR_TIE              ((uint32_t)((uint32_t)1 << 6))  /*!< Timer Interrupt Enable */
#define LPTMRx_CSR_TPS_SHIFT        4                                                                            /*!< Timer Pin Select (shift) */
#define LPTMRx_CSR_TPS_MASK         ((uint32_t)((uint32_t)0x03 << LPTMRx_CSR_TPS_SHIFT))                         /*!< Timer Pin Select (mask) */
#define LPTMRx_CSR_TPS(x)           ((uint32_t)(((uint32_t)(x) << LPTMRx_CSR_TPS_SHIFT) & LPTMRx_CSR_TPS_MASK))  /*!< Timer Pin Select */
#define LPTMRx_CSR_TPP              ((uint32_t)((uint32_t)1 << 3))  /*!< Timer Pin Polarity */
#define LPTMRx_CSR_TFC              ((uint32_t)((uint32_t)1 << 2))  /*!< Timer Free-Running Counter */
#define LPTMRx_CSR_TMS              ((uint32_t)((uint32_t)1 << 1))  /*!< Timer Mode Select */
#define LPTMRx_CSR_TEN              ((uint32_t)((uint32_t)1 << 0))  /*!< Timer Enable */

/**********  Bits definition for LPTMRx_PSR register  ***********/
#define LPTMRx_PSR_PRESCALE_SHIFT   3                                                                                      /*!< Prescale Value (shift) */
#define LPTMRx_PSR_PRESCALE_MASK    ((uint32_t)((uint32_t)0x0F << LPTMRx_PSR_PRESCALE_SHIFT))                              /*!< Prescale Value (mask) */
#define LPTMRx_PSR_PRESCALE(x)      ((uint32_t)(((uint32_t)(x) << LPTMRx_PSR_PRESCALE_SHIFT) & LPTMRx_PSR_PRESCALE_MASK))  /*!< Prescale Value */
#define LPTMRx_PSR_PBYP             ((uint32_t)((uint32_t)1 << 2))  /*!< Prescaler Bypass */
#define LPTMRx_PSR_PCS_SHIFT        0                                                                            /*!< Prescaler Clock Select (shift) */
#define LPTMRx_PSR_PCS_MASK         ((uint32_t)((uint32_t)0x03 << LPTMRx_PSR_PCS_SHIFT))                         /*!< Prescaler Clock Select (mask) */
#define LPTMRx_PSR_PCS(x)           ((uint32_t)(((uint32_t)(x) << LPTMRx_PSR_PCS_SHIFT) & LPTMRx_PSR_PCS_MASK))  /*!< Prescaler Clock Select */

/**********  Bits definition for LPTMRx_CMR register  ***********/
#define LPTMRx_CMR_COMPARE_SHIFT    0                                                                                    /*!< Compare Value (shift) */
#define LPTMRx_CMR_COMPARE_MASK     ((uint32_t)((uint32_t)0xFFFF << LPTMRx_CMR_COMPARE_SHIFT))                           /*!< Compare Value (mask) */
#define LPTMRx_CMR_COMPARE(x)       ((uint32_t)(((uint32_t)(x) << LPTMRx_CMR_COMPARE_SHIFT) & LPTMRx_CMR_COMPARE_MASK))  /*!< Compare Value */

/**********  Bits definition for LPTMRx_CNR register  ***********/
#define LPTMRx_CNR_COUNTER_SHIFT    0                                                                                    /*!< Counter Value (shift) */
#define LPTMRx_CNR_COUNTER_MASK     ((uint32_t)((uint32_t)0xFFFF << LPTMRx_CNR_COUNTER_SHIFT))                           /*!< Counter Value (mask) */
#define LPTMRx_CNR_COUNTER(x)       ((uint32_t)(((uint32_t)(x) << LPTMRx_CNR_COUNTER_SHIFT) & LPTMRx_CNR_COUNTER_MASK))  /*!< Counter Value */

/****************************************************************/
/*                                                              */
/*                  Touch Sensing Input (TSI)                   */
/*                                                              */
/****************************************************************/

/* Device dependent */

/****************************************************************/
/*                                                              */
/*             Multipurpose Clock Generator (MCG)               */
/*                                                              */
/****************************************************************/

/* Device dependent */

/****************************************************************/
/*                                                              */
/*             Serial Peripheral Interface (SPI)                */
/*                                                              */
/****************************************************************/

/* Device dependent */

/****************************************************************/
/*                                                              */
/*             Inter-Integrated Circuit (I2C)                   */
/*                                                              */
/****************************************************************/

/* Device dependent */

/****************************************************************/
/*                                                              */
/*     Universal Asynchronous Receiver/Transmitter (UART)       */
/*                                                              */
/****************************************************************/

/* Device dependent */

/****************************************************************/
/*                                                              */
/*             Power Management Controller (PMC)                */
/*                                                              */
/****************************************************************/
/*********  Bits definition for PMC_LVDSC1 register  *************/
#define PMC_LVDSC1_LVDF               ((uint8_t)0x80)   /*!< Low-Voltage Detect Flag */
#define PMC_LVDSC1_LVDACK             ((uint8_t)0x40)   /*!< Low-Voltage Detect Acknowledge */
#define PMC_LVDSC1_LVDIE              ((uint8_t)0x20)   /*!< Low-Voltage Detect Interrupt Enable */
#define PMC_LVDSC1_LVDRE              ((uint8_t)0x10)   /*!< Low-Voltage Detect Reset Enable */
#define PMC_LVDSC1_LVDV_MASK          ((uint8_t)0x3)    /*!< Low-Voltage Detect Voltage Select */
#define PMC_LVDSC1_LVDV_SHIFT         0
#define PMC_LVDSC1_LVDV(x)            (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC1_LVDV_SHIFT))&PMC_LVDSC1_LVDV_MASK)
/*********  Bits definition for PMC_LVDSC1 register  *************/
#define PMC_LVDSC2_LVWF               ((uint8_t)0x80)   /*!< Low-Voltage Warning Flag */
#define PMC_LVDSC2_LVWACK             ((uint8_t)0x40)   /*!< Low-Voltage Warning Acknowledge */
#define PMC_LVDSC2_LVWIE              ((uint8_t)0x20)   /*!< Low-Voltage Warning Interrupt Enable */
#define PMC_LVDSC2_LVWV_MASK          0x3               /*!< Low-Voltage Warning Voltage Select */
#define PMC_LVDSC2_LVWV_SHIFT         0
#define PMC_LVDSC2_LVWV(x)            (((uint8_t)(((uint8_t)(x))<<PMC_LVDSC2_LVWV_SHIFT))&PMC_LVDSC2_LVWV_MASK)
/*********  Bits definition for PMC_REGSC register  *************/
#define PMC_REGSC_BGEN                ((uint8_t)0x10)   /*!< Bandgap Enable In VLPx Operation */
#define PMC_REGSC_ACKISO              ((uint8_t)0x8)    /*!< Acknowledge Isolation */
#define PMC_REGSC_REGONS              ((uint8_t)0x4)    /*!< Regulator In Run Regulation Status */
#define PMC_REGSC_BGBE                ((uint8_t)0x1)    /*!< Bandgap Buffer Enable */

/****************************************************************/
/*                                                              */
/*                  Timer/PWM Module (TPM)                      */
/*                                                              */
/****************************************************************/

/* Device dependent */

/****************************************************************/
/*                                                              */
/*                         USB/OTG                              */
/*                                                              */
/****************************************************************/

/* Device dependent */

/****************************************************************/
/*                                                              */
/*                 Reset Control Module (RCM)                   */
/*                                                              */
/****************************************************************/
/**********  Bits definition for RCM_SRS0 register  *************/
#define RCM_SRS0_POR                  ((uint8_t)0x80)   /*!< Power-On Reset */
#define RCM_SRS0_PIN                  ((uint8_t)0x40)   /*!< External Reset Pin */
#define RCM_SRS0_WDOG                 ((uint8_t)0x20)   /*!< Watchdog */
#define RCM_SRS0_LOL                  ((uint8_t)0x08)   /*!< Loss-of-Lock Reset */
#define RCM_SRS0_LOC                  ((uint8_t)0x04)   /*!< Loss-of-Clock Reset */
#define RCM_SRS0_LVD                  ((uint8_t)0x02)   /*!< Low-Voltage Detect Reset */
#define RCM_SRS0_WAKEUP               ((uint8_t)0x01)   /*!< Low Leakage Wakeup Reset */

/**********  Bits definition for RCM_SRS1 register  *************/
#define RCM_SRS1_SACKERR              ((uint8_t)0x20)   /*!< Stop Mode Acknowledge Error Reset */
#define RCM_SRS1_MDM_AP               ((uint8_t)0x08)   /*!< MDM-AP System Reset Request */
#define RCM_SRS1_SW                   ((uint8_t)0x04)   /*!< Software */
#define RCM_SRS1_LOCKUP               ((uint8_t)0x02)   /*!< Core Lockup */

/**********  Bits definition for RCM_RPFC register  *************/
#define RCM_RPFC_RSTFLTSS             ((uint8_t)0x04)   /*!< Reset Pin Filter Select in Stop Mode */
#define RCM_RPFC_RSTFLTSRW_SHIFT      0                                                                                  /*!< Reset Pin Filter Select in Run and Wait Modes (shift) */
#define RCM_RPFC_RSTFLTSRW_MASK       ((uint8_t)((uint8_t)0x03 << RCM_RPFC_RSTFLTSRW_SHIFT))                             /*!< Reset Pin Filter Select in Run and Wait Modes (mask) */
#define RCM_RPFC_RSTFLTSRW(x)         ((uint8_t)(((uint8_t)(x) << RCM_RPFC_RSTFLTSRW_SHIFT) & RCM_RPFC_RSTFLTSRW_MASK))  /*!< Reset Pin Filter Select in Run and Wait Modes */

/**********  Bits definition for RCM_RPFW register  *************/
#define RCM_RPFW_RSTFLTSEL_SHIFT      0                                                                                  /*!< Reset Pin Filter Bus Clock Select (shift) */
#define RCM_RPFW_RSTFLTSEL_MASK       ((uint8_t)((uint8_t)0x1F << RCM_RPFW_RSTFLTSEL_SHIFT))                             /*!< Reset Pin Filter Bus Clock Select (mask) */
#define RCM_RPFW_RSTFLTSEL(x)         ((uint8_t)(((uint8_t)(x) << RCM_RPFW_RSTFLTSEL_SHIFT) & RCM_RPFW_RSTFLTSEL_MASK))  /*!< Reset Pin Filter Bus Clock Select */

/****************************************************************/
/*                                                              */
/*                System Mode Controller (SMC)                  */
/*                                                              */
/****************************************************************/
/*********  Bits definition for SMC_PMPROT register  ************/
#define SMC_PMPROT_AVLP               ((uint8_t)0x20)   /*!< Allow Very-Low-Power Modes */
#define SMC_PMPROT_ALLS               ((uint8_t)0x08)   /*!< Allow Low-Leakage Stop Mode */
#define SMC_PMPROT_AVLLS              ((uint8_t)0x02)   /*!< Allow Very-Low-Leakage Stop Mode */

/*********  Bits definition for SMC_PMCTRL register  ************/
#define SMC_PMCTRL_RUNM_SHIFT         5                                                                            /*!< Run Mode Control (shift) */
#define SMC_PMCTRL_RUNM_MASK          ((uint8_t)((uint8_t)0x03 << SMC_PMCTRL_RUNM_SHIFT))                          /*!< Run Mode Control (mask) */
#define SMC_PMCTRL_RUNM(x)            ((uint8_t)(((uint8_t)(x) << SMC_PMCTRL_RUNM_SHIFT) & SMC_PMCTRL_RUNM_MASK))  /*!< Run Mode Control */
#define SMC_PMCTRL_STOPA              ((uint8_t)0x08)   /*!< Stop Aborted */
#define SMC_PMCTRL_STOPM_SHIFT        0                                                                              /*!< Stop Mode Control (shift) */
#define SMC_PMCTRL_STOPM_MASK         ((uint8_t)((uint8_t)0x07 << SMC_PMCTRL_STOPM_SHIFT))                           /*!< Stop Mode Control (mask) */
#define SMC_PMCTRL_STOPM(x)           ((uint8_t)(((uint8_t)(x) << SMC_PMCTRL_STOPM_SHIFT) & SMC_PMCTRL_STOPM_MASK))  /*!< Stop Mode Control */

#define SMC_PMCTRL_RUNM_RUN           ((uint8_t)0x00)
#define SMC_PMCTRL_RUNM_VLPR          ((uint8_t)0x02)
#define SMC_PMCTRL_STOPM_STOP         ((uint8_t)0x00)
#define SMC_PMCTRL_STOPM_VLPS         ((uint8_t)0x02)
#define SMC_PMCTRL_STOPM_LLS          ((uint8_t)0x03)
#define SMC_PMCTRL_STOPM_VLLSx        ((uint8_t)0x04)

/********  Bits definition for SMC_STOPCTRL register  ***********/
#define SMC_STOPCTRL_PSTOPO_SHIFT     6                                                                                   /*!< Partial Stop Option (shift) */
#define SMC_STOPCTRL_PSTOPO_MASK      ((uint8_t)((uint8_t)0x03 << SMC_STOPCTRL_PSTOPO_SHIFT))                             /*!< Partial Stop Option (mask) */
#define SMC_STOPCTRL_PSTOPO(x)        ((uint8_t)(((uint8_t)(x) << SMC_STOPCTRL_PSTOPO_SHIFT) & SMC_STOPCTRL_PSTOPO_MASK)) /*!< Partial Stop Option */
#define SMC_STOPCTRL_PORP0            ((uint8_t)0x20)   /*!< POR Power Option */
#define SMC_STOPCTRL_VLLSM_SHIFT      0                                                                                  /*!< VLLS Mode Control (shift) */
#define SMC_STOPCTRL_VLLSM_MASK       ((uint8_t)((uint8_t)0x07 << SMC_STOPCTRL_VLLSM_  SHIFT))                           /*!< VLLS Mode Control (mask) */
#define SMC_STOPCTRL_VLLSM(x)         ((uint8_t)(((uint8_t)(x) << SMC_STOPCTRL_VLLSM_SHIFT) & SMC_STOPCTRL_VLLSM_MASK))  /*!< VLLS Mode Control */

#define SMC_STOPCTRL_PSTOPO_STOP      ((uint8_t)0x00)
#define SMC_STOPCTRL_PSTOPO_PSTOP1    ((uint8_t)0x01)
#define SMC_STOPCTRL_PSTOPO_PSTOP2    ((uint8_t)0x02)
#define SMC_STOPCTRL_VLLSM_VLLS0      ((uint8_t)0x00)
#define SMC_STOPCTRL_VLLSM_VLLS1      ((uint8_t)0x01)
#define SMC_STOPCTRL_VLLSM_VLLS2      ((uint8_t)0x03)

/*********  Bits definition for SMC_PMSTAT register  ************/
#define SMC_PMSTAT_PMSTAT_SHIFT       0                                                                                /*!< Power Mode Status (shift) */
#define SMC_PMSTAT_PMSTAT_MASK        ((uint8_t)((uint8_t)0x7F << SMC_PMSTAT_PMSTAT_  SHIFT))                          /*!< Power Mode Status (mask) */
#define SMC_PMSTAT_PMSTAT(x)          ((uint8_t)(((uint8_t)(x) << SMC_PMSTAT_PMSTAT_SHIFT) & SMC_PMSTAT_PMSTAT_MASK))  /*!< Power Mode Status */

#define SMC_PMSTAT_RUN                ((uint8_t)0x01)
#define SMC_PMSTAT_STOP               ((uint8_t)0x02)
#define SMC_PMSTAT_VLPR               ((uint8_t)0x04)
#define SMC_PMSTAT_VLPW               ((uint8_t)0x08)
#define SMC_PMSTAT_VLPS               ((uint8_t)0x10)
#define SMC_PMSTAT_LLS                ((uint8_t)0x20)
#define SMC_PMSTAT_VLLS               ((uint8_t)0x40)

#endif /* _KL2xZ_H_ */

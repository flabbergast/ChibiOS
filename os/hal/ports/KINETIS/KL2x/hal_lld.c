/*
    ChibiOS - Copyright (C) 2013-2015 Fabio Utzig

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
 * @file    KL2x/hal_lld.c
 * @brief   Kinetis KL2x HAL Driver subsystem low level driver source.
 *
 * @addtogroup HAL
 * @{
 */

#include "osal.h"
#include "hal.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

#ifdef __CC_ARM
__attribute__ ((section(".ARM.__at_0x400")))
#else
__attribute__ ((used,section(".cfmconfig")))
#endif
const uint8_t _cfm[0x10] = {
  0xFF,  /* NV_BACKKEY3: KEY=0xFF */
  0xFF,  /* NV_BACKKEY2: KEY=0xFF */
  0xFF,  /* NV_BACKKEY1: KEY=0xFF */
  0xFF,  /* NV_BACKKEY0: KEY=0xFF */
  0xFF,  /* NV_BACKKEY7: KEY=0xFF */
  0xFF,  /* NV_BACKKEY6: KEY=0xFF */
  0xFF,  /* NV_BACKKEY5: KEY=0xFF */
  0xFF,  /* NV_BACKKEY4: KEY=0xFF */
  0xFF,  /* NV_FPROT3: PROT=0xFF */
  0xFF,  /* NV_FPROT2: PROT=0xFF */
  0xFF,  /* NV_FPROT1: PROT=0xFF */
  0xFF,  /* NV_FPROT0: PROT=0xFF */
  0x7E,  /* NV_FSEC: KEYEN=1,MEEN=3,FSLACC=3,SEC=2 */
  0xFF,  /* NV_FOPT: ??=1,??=1,FAST_INIT=1,LPBOOT1=1,RESET_PIN_CFG=1,
                      NMI_DIS=1,EZPORT_DIS=1,LPBOOT0=1 */
  0xFF,
  0xFF
};

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level HAL driver initialization.
 *
 * @notapi
 */
void hal_lld_init(void) {
}

/**
 * @brief   KL2x clocks and PLL initialization.
 * @note    All the involved constants come from the file @p board.h.
 * @note    This function should be invoked just after the system reset.
 *
 * @special
 */
void kl2x_clock_init(void) {
#if !KINETIS_NO_INIT

  /* Disable COP watchdog */
  SIM->COPC = 0;

  /* Enable PORTA */
  SIM->SCGC5 |= SIM_SCGC5_PORTA;

  /* --- MCG mode: FEI (default out of reset) ---
     f_MCGOUTCLK = f_int * F
     F is the FLL factor selected by C4[DRST_DRS] and C4[DMX32] bits.
     Typical f_MCGOUTCLK = 21 MHz immediately after reset.
     C4[DMX32]=0 and C4[DRST_DRS]=00  =>  FLL factor=640.
     C3[SCTRIM] and C4[SCFTRIM] factory trim values apply to f_int. */

  /* System oscillator drives 32 kHz clock (OSC32KSEL=0) */
  SIM->SOPT1 &= ~SIM_SOPT1_OSC32KSEL_MASK;

#if KINETIS_MCG_MODE == KINETIS_MCG_MODE_FEI
  /* This is the default mode at reset. */
  /* The MCGOUTCLK is divided by OUTDIV1 and OUTDIV4:
   * OUTDIV1 (divider for core/system and bus/flash clock)
   * OUTDIV4 (additional divider for bus/flash clock) */
  SIM->CLKDIV1 =
          SIM_CLKDIV1_OUTDIV1(KINETIS_CLKDIV1_OUTDIV1-1) |
          SIM_CLKDIV1_OUTDIV4(KINETIS_CLKDIV1_OUTDIV4-1);

  /* Configure FEI mode */
  MCG->C4 = MCG_C4_DRST_DRS(KINETIS_MCG_FLL_DRS) |
            (KINETIS_MCG_FLL_DMX32 ? MCG_C4_DMX32 : 0);

#elif KINETIS_MCG_MODE == KINETIS_MCG_MODE_FEE
  /*
   * FLL Enabled External (FEE) MCG Mode
   * 24 MHz core, 12 MHz bus - using 32.768 kHz crystal with FLL.
   * f_MCGOUTCLK = (f_ext / FLL_R) * F
   *             = (32.768 kHz ) *
   *  FLL_R is the reference divider selected by C1[FRDIV]
   *  F is the FLL factor selected by C4[DRST_DRS] and C4[DMX32].
   *
   * Then the core/system and bus/flash clocks are divided:
   *   f_SYS = f_MCGOUTCLK / OUTDIV1 = 48 MHz / 1 = 48 MHz
   *   f_BUS = f_MCGOUTCLK / OUTDIV1 / OUTDIV4 =  MHz / 4 = 24 MHz
   */

  SIM->SOPT2 =
          SIM_SOPT2_TPMSRC(1);  /* MCGFLLCLK clock or MCGPLLCLK/2 */
          /* PLLFLLSEL=0 -> MCGFLLCLK */

  /* The MCGOUTCLK is divided by OUTDIV1 and OUTDIV4:
   * OUTDIV1 (divider for core/system and bus/flash clock)
   * OUTDIV4 (additional divider for bus/flash clock) */
  SIM->CLKDIV1 =
          SIM_CLKDIV1_OUTDIV1(KINETIS_MCG_FLL_OUTDIV1 - 1) |
          SIM_CLKDIV1_OUTDIV4(KINETIS_MCG_FLL_OUTDIV4 - 1);

  /* EXTAL0 and XTAL0 */
  PORTA->PCR[18] &= ~0x01000700; /* Set PA18 to analog (default) */
  PORTA->PCR[19] &= ~0x01000700; /* Set PA19 to analog (default) */

  OSC0->CR = 0;

  /* From KL25P80M48SF0RM section 24.5.1.1 "Initializing the MCG". */
  /* To change from FEI mode to FEE mode: */
  /* (1) Select the external clock source in C2 register.
         Use low-power OSC mode (HGO0=0) which enables internal feedback
         resistor, for 32.768 kHz crystal configuration.  */
  MCG->C2 =
          MCG_C2_RANGE0(0) |  /* low frequency range (<= 40 kHz) */
          MCG_C2_EREFS0;      /* external reference (using a crystal) */
  /* (2) Write to C1 to select the clock mode. */
  MCG->C1 = /* Clear the IREFS bit to switch to the external reference. */
          MCG_C1_CLKS_FLLPLL |  /* Use FLL for system clock, MCGCLKOUT. */
          MCG_C1_FRDIV(0);      /* Don't divide 32kHz ERCLK FLL reference. */
  MCG->C6 = 0;  /* PLLS=0: Select FLL as MCG source, not PLL */

  /* Loop until S[OSCINIT0] is 1, indicating the
     crystal selected by C2[EREFS0] has been initialized. */
  while ((MCG->S & MCG_S_OSCINIT0) == 0)
    ;
  /* Loop until S[IREFST] is 0, indicating the
     external reference is the current reference clock source. */
  while ((MCG->S & MCG_S_IREFST) != 0)
    ;  /* Wait until external reference clock is FLL reference. */
  /* (1)(e) Loop until S[CLKST] indicates FLL feeds MCGOUTCLK. */
  while ((MCG->S & MCG_S_CLKST_MASK) != MCG_S_CLKST_FLL)
    ;  /* Wait until FLL has been selected. */

  /* --- MCG mode: FEE --- */
  /* Set frequency range for DCO output (MCGFLLCLK). */
  MCG->C4 = (KINETIS_MCG_FLL_DMX32 ? MCG_C4_DMX32 : 0) |
            MCG_C4_DRST_DRS(KINETIS_MCG_FLL_DRS);

  /* Wait for the FLL lock time; t[fll_acquire][max] = 1 ms */
  /* TODO - not implemented - is it required? Freescale example code
     seems to omit it. */

#elif KINETIS_MCG_MODE == KINETIS_MCG_MODE_PEE
  uint32_t ratio, frdiv;
  uint32_t ratios[] = { 32, 64, 128, 256, 512, 1024, 1280, 1536 };
  uint8_t ratio_quantity = sizeof(ratios) / sizeof(ratios[0]);
  uint8_t i;

  /*
   * PLL Enabled External (PEE) MCG Mode
   * 48 MHz core, 24 MHz bus - using a crystal (KINETIS_XTAL_FREQUENCY) with PLL.
   * f_MCGOUTCLK = (OSCCLK / PLL_R) * M (a.k.a. KINETIS_PLLCLK_FREQUENCY)
   *             =  {8 MHz} / 2 * 24 = {96 MHz}
   *  PLL_R is the reference divider selected by C5[PRDIV0]
   *  M is the multiplier selected by C6[VDIV0]
   *
   * Then the core/system and bus/flash clocks are divided:
   *   f_SYS = f_MCGOUTCLK / OUTDIV1 = 96 MHz / 2 = 48 MHz
   *   f_BUS = f_MCGOUTCLK / OUTDIV1 / OUTDIV4 = 96 MHz / 4 = 24 MHz
   */

  /* EXTAL0 and XTAL0 */
  PORTA->PCR[18] &= ~0x01000700; /* Set PA18 to analog (default) */
  PORTA->PCR[19] &= ~0x01000700; /* Set PA19 to analog (default) */

  /* Start in FEI mode */

  /* Disable capacitors for crystal */
  OSC0->CR = 0;

  /* From KL25P80M48SF0RM section 24.5.1.1 "Initializing the MCG". */
  /* To change from FEI mode to FBE mode: */
  /* (1) Select the external clock source in C2 register.
         Use low-power OSC mode (HGO0=0) which enables internal feedback
         resistor since FRDM-KL25Z has feedback resistor R25 unpopulated.
         Use high-gain mode by setting C2[HGO0] instead if external
         feedback resistor Rf is installed.  */
  MCG->C2 = MCG_C2_EREFS0;      /* external reference (using a crystal) */
  if (KINETIS_XTAL_FREQUENCY > 8000000UL)
    MCG->C2 |= MCG_C2_RANGE0(2);
  else
    MCG->C2 |= MCG_C2_RANGE0(1);
  /* (2) Write to C1 to select the clock mode. */
  frdiv = 7;
  ratio = KINETIS_XTAL_FREQUENCY / 31250UL;
  for (i = 0; i < ratio_quantity; ++i) {
    if (ratio == ratios[i]) {
      frdiv = i;
      break;
    }
  }

  /* Switch to crystal as clock source, FLL input of 31.25 KHz */
  MCG->C1 = /* Clear the IREFS bit to switch to the external reference. */
          MCG_C1_CLKS_ERCLK |  /* Use Ext Ref Clock for system clock, MCGCLKOUT. */
          MCG_C1_FRDIV(frdiv); /* Divide ERCLK / 256 for FLL reference. */
  /* Note: FLL reference frequency must be 31.25 kHz to 39.0625 kHz. */

  MCG->C4 &= ~(MCG_C4_DMX32 | MCG_C4_DRST_DRS_MASK);
  MCG->C6 = 0;  /* PLLS=0: Select FLL as MCG source, not PLL */

  /* (3) Once configuration is set, wait for MCG mode change. */

  /* From KL25P80M48SF0RM section 24.5.31: */
  /* (1)(c) Loop until S[OSCINIT0] is 1, indicating the
     crystal selected by C2[EREFS0] has been initialized. */
  while ((MCG->S & MCG_S_OSCINIT0) == 0)
    ;
  /* (1)(d) Loop until S[IREFST] is 0, indicating the
     external reference is the current reference clock source. */
  while ((MCG->S & MCG_S_IREFST) != 0)
    ;  /* Wait until external reference clock is FLL reference. */
  /* (1)(e) Loop until S[CLKST] is 2'b10, indicating
     the external reference clock is selected to feed MCGOUTCLK. */
  while ((MCG->S & MCG_S_CLKST_MASK) != MCG_S_CLKST_ERCLK)
    ;  /* Wait until external reference clock has been selected. */

  /* --- MCG mode: FBE (FLL bypassed, external crystal) ---
     Now the MCG is in FBE mode.
     Although the FLL is bypassed, it is still on. */

  /* (2)    Then configure C5[PRDIV0] to generate the
     correct PLL reference frequency. */
  #define KINETIS_PLLIN_FREQUENCY 2000000UL
  /* TODO: Make sure KINETIS_XTAL_FREQUENCY >= 2Mhz && <= 50Mhz */
  /* PLL External Reference Divide by ... */
  MCG->C5 = MCG_C5_PRDIV0((KINETIS_XTAL_FREQUENCY/KINETIS_PLLIN_FREQUENCY) - 1);
  /* (3)    Then from FBE transition to PBE mode. */
  /* (3)(b) C6[PLLS]=1 to select PLL. */
  /* (3)(b) C6[VDIV0]= PLLIN MHz * i = PLLCLK MHz. */
  /* Config PLL output to match KINETIS_SYSCLK_FREQUENCY
   * TODO: make sure KINETIS_SYSCLK_FREQUENCY is a match */
  for(i = 24; i < 56; i++) {
    if(i == (KINETIS_PLLCLK_FREQUENCY/KINETIS_PLLIN_FREQUENCY)) {
      /* Config PLL to match KINETIS_PLLCLK_FREQUENCY */
      MCG->C6 = MCG_C6_PLLS | MCG_C6_VDIV0(i-24);
      break;
    }
  }
  if(i>=56) /* Config PLL for 96 MHz output as default setting */
    MCG->C6 = MCG_C6_PLLS | MCG_C6_VDIV0(0);

  /* (3)(d) Loop until S[PLLST], indicating PLL
     is the PLLS clock source. */
  while ((MCG->S & MCG_S_PLLST) == 0)
    ;  /* wait until PLL is the PLLS clock source. */
  /* (3)(e) Loop until S[LOCK0] is set, indicating the PLL has acquired lock. */
  /* PLL selected as MCG source. VDIV0=00000 (Multiply=24). */
  while ((MCG->S & MCG_S_LOCK0) == 0)
    ;  /* wait until PLL locked */

  /* --- MCG mode: PBE (PLL bypassed, external crystal) --- */

  /* Set the PLL dividers for the different clocks */
  /* The MCGOUTCLK is divided by OUTDIV1 and OUTDIV4:
   * OUTDIV1 (divider for core/system and bus/flash clock)
   * OUTDIV4 (additional divider for bus/flash clock)
   *  - these are computed in .h */
  SIM->CLKDIV1 =
          SIM_CLKDIV1_OUTDIV1(KINETIS_CLKDIV1_OUTDIV1-1) |
          SIM_CLKDIV1_OUTDIV4(KINETIS_CLKDIV1_OUTDIV4-1);

  SIM->SOPT2 =
          SIM_SOPT2_TPMSRC(1) | /* MCGFLLCLK clock or MCGPLLCLK/2 */
          SIM_SOPT2_PLLFLLSEL;  /* PLLFLLSEL=MCGPLLCLK/2 */

  /* (4)    Transition from PBE mode to PEE mode. */
  /* (4)(a) C1[CLKS] = 2'b00 to select PLL output as system clock source. */
  // Switch to PEE mode
  //    Select PLL output (CLKS=0)
  //    FLL external reference divider (FRDIV) already set
  //    External reference clock for FLL (IREFS=0)
  MCG->C1 = MCG_C1_CLKS(0);
  /* (4)(b) Loop until S[CLKST] are 2'b11, indicating the PLL output is selected for MCGOUTCLK. */
  while ((MCG->S & MCG_S_CLKST_MASK) != MCG_S_CLKST_PLL)
    ;  /* wait until clock switched to PLL output */

  /* --- MCG mode: PEE (PLL enabled, external crystal) --- */

#else /* KINETIS_MCG_MODE != KINETIS_MCG_MODE_PEE */
#error Unimplemented KINETIS_MCG_MODE
#endif /* KINETIS_MCG_MODE != KINETIS_MCG_MODE_PEE */

#endif /* !KINETIS_NO_INIT */
}

/**
 * @brief   Platform early initialization.
 * @note    All the involved constants come from the file @p board.h.
 * @note    This function is meant to be invoked early during the system
 *          initialization, it is usually invoked from the file
 *          @p board.c.
 *
 * @special
 */
void platform_early_init(void) {

}

/** @} */

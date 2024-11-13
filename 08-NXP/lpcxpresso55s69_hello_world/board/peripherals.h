/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PERIPHERALS_H_
#define _PERIPHERALS_H_

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/
#include "fsl_common.h"
#include "fsl_ctimer.h"
#include "fsl_clock.h"

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/
/* Definitions for BOARD_InitPeripherals functional group */
/* Definition of peripheral ID */
#define CTIMER1_PERIPHERAL CTIMER1
/* Timer tick frequency in Hz (input frequency of the timer) */
#define CTIMER1_TICK_FREQ 96000UL
/* Timer tick period in ns (input period of the timer) */
#define CTIMER1_TICK_PERIOD 10417UL
/* Definition of channel 0 ID */
#define CTIMER1_MATCH_0_CHANNEL kCTIMER_Match_0
/* CTIMER1 interrupt vector ID (number). */
#define CTIMER1_TIMER_IRQN CTIMER1_IRQn
/* Definition of peripheral ID */
#define CTIMER2_PERIPHERAL CTIMER2
/* Timer tick frequency in Hz (input frequency of the timer) */
#define CTIMER2_TICK_FREQ 96000UL
/* Timer tick period in ns (input period of the timer) */
#define CTIMER2_TICK_PERIOD 10417UL
/* Definition of channel 1 ID */
#define CTIMER2_MATCH_1_CHANNEL kCTIMER_Match_1
/* CTIMER2 interrupt vector ID (number). */
#define CTIMER2_TIMER_IRQN CTIMER2_IRQn

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/
extern const ctimer_config_t CTIMER1_config;
extern const ctimer_match_config_t CTIMER1_Match_0_config;
extern const ctimer_config_t CTIMER2_config;
extern const ctimer_match_config_t CTIMER2_Match_1_config;

/***********************************************************************************************************************
 * Callback functions
 **********************************************************************************************************************/
  /* Single callback function declaration */
extern void TimerIRQ(uint32_t flags);
extern ctimer_callback_t CTIMER1_callback[];
  /* Single callback function declaration */
extern void Timer2IRQ(uint32_t flags);
extern ctimer_callback_t CTIMER2_callback[];

/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/

void BOARD_InitPeripherals(void);

/***********************************************************************************************************************
 * BOARD_InitBootPeripherals function
 **********************************************************************************************************************/
void BOARD_InitBootPeripherals(void);

#if defined(__cplusplus)
}
#endif

#endif /* _PERIPHERALS_H_ */

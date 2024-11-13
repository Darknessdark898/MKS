/*
 * Copyright (c) 2013 - 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"

#include "pin_mux.h"
#include "clock_config.h"

#include "peripherals.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/


void TimerIRQ(uint32_t flags)
{
    PRINTF("hello world.\r\n");
}

void Timer2IRQ(uint32_t flags)
{
    PRINTF("LED.\r\n");
}

/*!
 * @brief Main function
 */

char ch;

int main(void)
{

    /* Init board hardware. */
    /* attach main clock divide to FLEXCOMM0 (debug console) */
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);

    BOARD_InitPins();
    BOARD_BootClockFROHF96M();
    BOARD_InitBootPeripherals();
    BOARD_InitDebugConsole();

    /* Init output LED GPIO. */
    //GPIO_PortInit(GPIO, BOARD_LED_PORT);
    //GPIO_PinInit(GPIO, BOARD_LED_PORT, BOARD_LED_PIN, &led_config);

    PRINTF("hello world.\r\n");

    CTIMER_StartTimer(CTIMER1_PERIPHERAL);
    CTIMER_StartTimer(CTIMER2_PERIPHERAL);

    while (1)
    {
        ch = GETCHAR();
        PUTCHAR(ch);
    }
}

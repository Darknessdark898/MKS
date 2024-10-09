/*
 * sct.c
 *
 *  Created on: Oct 9, 2024
 *      Author: 272242
 *
 *      SCT library for controlling 3 digit 7-segment display trough 2 16bit shift registers linked together to one 32bit shift register.
 *
 *
 */


#include "sct.h"



void sct_init()
{
	sct_led(0);
}


void sct_led(uint32_t value)
{

	//uint32_t output = 0b01110000000001110111000000000111;

	//HAL_GPIO_WritePin(SCT_NOE_GPIO_Port, SCT_NOE_Pin, 1);	//pull the OE pin to high

	for (uint8_t i = 0; i < 32; ++i)
	{
		if((value >> i) & 1)	//set the data on SDI pin
		{
			HAL_GPIO_WritePin(SCT_SDI_GPIO_Port, SCT_SDI_Pin, 1);
		}
		else
		{
			HAL_GPIO_WritePin(SCT_SDI_GPIO_Port, SCT_SDI_Pin, 0);
		}

		HAL_GPIO_WritePin(SCT_CLK_GPIO_Port, SCT_CLK_Pin, 1);	//clk ON
		HAL_Delay(1);
		HAL_GPIO_WritePin(SCT_CLK_GPIO_Port, SCT_CLK_Pin, 0);	//clk OFF
	}

	//set output sequence
	HAL_GPIO_WritePin(SCT_NLA_GPIO_Port, SCT_NLA_Pin, 1);
	HAL_Delay(1);
	HAL_GPIO_WritePin(SCT_NLA_GPIO_Port, SCT_NLA_Pin, 0);
	//HAL_Delay(1);
	//HAL_GPIO_WritePin(SCT_NOE_GPIO_Port, SCT_NOE_Pin, 0);
	//HAL_Delay(2);
	//HAL_GPIO_WritePin(SCT_NOE_GPIO_Port, SCT_NOE_Pin, 1);
}


void sct_value(uint16_t value)
{
	HAL_Delay(2);
}

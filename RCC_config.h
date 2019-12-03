/*
 * gonfig.h
 *
 *  Created on: 4 Aug 2019
 *      Author: Yahia
 */

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

#include "std_types.h"
#include "common_macros.h"

/* Choose HSI as system CLK */
#define Enable_HSI						0

/* Choose HSE as system CLK */
#define Enable_HSE						0
/* Choose PLL as system CLK */
#define Enable_PLL						1
#if(Enable_PLL)

/* * * * * * * * * * * *
 *   PLL CLK Source    *
 * * * * * * * * * * * */
/*
 	Half_HSI,
	Half_HSE,
	HSE
  */
#define PLL_CLK_Source					HSE

/* * * * * * * * * * * * * * *
 * PLL Multiplication Factor *
 * * * * * * * * * * * * * * */
/*
	PLL_input_clock_x2,
	PLL_input_clock_x3,
	PLL_input_clock_x4,
	PLL_input_clock_x5,
	PLL_input_clock_x6,
	PLL_input_clock_x7,
	PLL_input_clock_x8,
	PLL_input_clock_x9,
	PLL_input_clock_x10,
	PLL_input_clock_x11,
	PLL_input_clock_x12,
	PLL_input_clock_x13,
	PLL_input_clock_x14,
	PLL_input_clock_x15,
	PLL_input_clock_x16,
	*/
#define PLL_Multiplication_Factor		PLL_input_clock_x16
#endif

/* 40 kHz low speed internal RC (LSI RC),
   which drives the independent watchdog
   and optionally the RTC used for
   Auto-wakeup from Stop/Standby mode. */
#define Enable_LSI						0

/* 32.768 kHz low speed external crystal
   (LSE crystal), which optionally drives
   the real-time clock (RTCCLK) */
#define Enable_LSE						0

#define Enable_RTC						0

#define Enable_AHB						0
#if(Enable_AHB)
/* * * * * * * * * * * * * * *
 *   AHB Prescaler Factor    *
 * * * * * * * * * * * * * * */
/*
 	AHB_SYSCLK_not_divided,
	AHB_SYSCLK_divided_by_2,
	AHB_SYSCLK_divided_by_4,
	AHB_SYSCLK_divided_by_8,
	AHB_SYSCLK_divided_by_16,
	AHB_SYSCLK_divided_by_64,
	AHB_SYSCLK_divided_by_128,
	AHB_SYSCLK_divided_by_256,
	AHB_SYSCLK_divided_by_512
 */
#define AHB_Prescaler_Factor			AHB_SYSCLK_not_divided
#endif

#define Enable_APB1						0
#if(Enable_AHB)
/* * * * * * * * * * * * * * *
 *   APB1 Prescaler Factor   *
 * * * * * * * * * * * * * * */
/*
	APB1_HCLK_not_divided,
	APB1_HCLK_divided_by_2,
	APB1_HCLK_divided_by_4,
	APB1_HCLK_divided_by_8,
	APB1_HCLK_divided_by_16
 */
#define APB1_Prescaler_Factor			APB1_HCLK_not_divided
#endif

#define Enable_APB2						0
#if(Enable_AHB)
/* * * * * * * * * * * * * * *
 *   APB2 Prescaler Factor   *
 * * * * * * * * * * * * * * */
/*
	APB2_HCLK_not_divided,
	APB2_HCLK_divided_by_2,
	APB2_HCLK_divided_by_4,
	APB2_HCLK_divided_by_8,
	APB2_HCLK_divided_by_16
 */
#define APB2_Prescaler_Factor			APB2_HCLK_not_divided
#endif

#define Enable_MCO						0
#if(Enable_MCO)
/* * * * * * * * * * * * * * *
 *   MCO Prescaler Factor    *
 * * * * * * * * * * * * * * */
/*
	MCO_No_clock,
	MCO_System_clock_selected,
	MCO_HSI_clock_selected,
	MCO_HSE_clock_selected,
	MCO_PLL_clock_divided_by_2_selected
 */
#define MCO_Prescaler_Factor			MCO_PLL_clock_divided_by_2_selected
#endif

#define Enable_ADC_CLK					0
#if(Enable_ADC_CLK)
/* * * * * * * * * * * * * * *
 *   ADCs Prescaler Factor   *
 * * * * * * * * * * * * * * */
/*
	ADC_PCLK2_divided_by_2,
	ADC_PCLK2_divided_by_4,
	ADC_PCLK2_divided_by_6,
	ADC_PCLK2_divided_by_8
 */
#define ADC_Prescaler_Factor			ADC_PCLK2_divided_by_2
#endif

#define Enable_USB_CLK					0
#if(Enable_ADC_CLK)
/* * * * * * * * * * * * * * *
 *   USB Prescaler Factor    *
 * * * * * * * * * * * * * * */
/*
	USB_PLL_clock_is_divided_by_OneHalf,
	USB_PLL_clock_is_not_divided
 */
#define USB_Prescaler_Factor			USB_PLL_clock_is_not_divided
#endif

#endif /* CONFIG_H_ */

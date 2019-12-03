/*
 * private.h
 *
 *  Created on: 4 Aug 2019
 *      Author: Yahia
 */

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

#include "std_types.h"
#include "common_macros.h"

/* Define the size of register in STM32F103C8T6 */
#define SIZE_OF_REGISTER 32

/* Check if the peripheral id is in the RCC_APB2RSTR register */
#define PERIPHERAL_IN_RCC_APB2RSTR (peripheralIdx < 32)

/* Check if the peripheral id is in the RCC_APB1RSTR register */
#define PERIPHERAL_IN_RCC_APB1RSTR (peripheralIdx < 64)

/* Check if the peripheral id is in the RCC_AHBENR register */
#define PERIPHERAL_IN_RCC_AHBENR (peripheralIdx < 32)

/* Check if the peripheral id is in the RCC_APB2ENR register */
#define PERIPHERAL_IN_RCC_APB2ENR (peripheralIdx < 64)

/* Check if the peripheral id is in the RCC_APB1ENR register */
#define PERIPHERAL_IN_RCC_APB1ENR (peripheralIdx < 96)

/* * * * * * * * * * * * * * * * * * * * * *
 *  Clock control register (RCC_CR) Pins   *
 * * * * * * * * * * * * * * * * * * * * * */
enum{
	HSION,
	HSIRDY,
	HSITRIM0 = 3,
	HSITRIM1,
	HSITRIM2,
	HSITRIM3,
	HSITRIM4,
	HSICAL0,
	HSICAL1,
	HSICAL2,
	HSICAL3,
	HSICAL4,
	HSICAL5,
	HSICAL6,
	HSICAL7,
	HSEON,
	HSERDY,
	HSEBYP,
	CSSON,
	PLLON = 24,
	PLLRDY
};

/* * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Clock configuration register (RCC_CFGR) Pins   *
 * * * * * * * * * * * * * * * * * * * * * * * * * */
enum{
	SW0,
	SW1,
	SWS0,
	SWS1,
	HPRE0,
	HPRE1,
	HPRE2,
	HPRE3,
	PPRE10,
	PPRE11,
	PPRE12,
	PPRE20,
	PPRE21,
	PPRE22,
	ADCPRE0,
	ADCPRE1,
	PLLSRC,
	PLLXTPRE,
	PLLMUL0,
	PLLMUL1,
	PLLMUL2,
	PLLMUL3,
	USBPRE,
	MCO0 = 24,
	MCO1,
	MCO2
};

/* * * * * * * * * * * * * * * * * * * * * * * *
 *  Clock interrupt register (RCC_CIR) Pins    *
 * * * * * * * * * * * * * * * * * * * * * * * */
enum{
	LSIRDYF,
	LSERDYF,
	HSIRDYF,
	HSERDYF,
	PLLRDYF,
	CSSF = 7,
	LSIRDYIE,
	LSERDYIE,
	HSIRDYIE,
	HSERDYIE,
	PLLRDYIE,
	LSIRDYC = 16,
	LSERDYC,
	HSIRDYC,
	HSERDYC,
	PLLRDYC,
	CSSC = 23
};

/* * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Backup domain control register (RCC_BDCR) Pins   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * */
enum{
	LSEON,
	LSERDY,
	LSEBYP,
	RTCSEL0 = 8,
	RTCSEL1,
	RTCEN = 15,
	BDRST
};

/* * * * * * * * * * * * * * * * * * * * * * *
 *  Control/status register (RCC_CSR) Pins   *
 * * * * * * * * * * * * * * * * * * * * * * */
enum{
	LSION,
	LSIRDY,
	RMVF = 24,
	PINRSTF = 26,
	PORRSTF,
	SFTRSTF,
	IWDGRSTF,
	WWDGRSTF,
	LPWRRSTF
};


#endif /* PRIVATE_H_ */

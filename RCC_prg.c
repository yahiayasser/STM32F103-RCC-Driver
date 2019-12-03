/*
 * prg.c
 *
 *  Created on: 4 Aug 2019
 *      Author: Yahia
 */

/* * * * * * * * * * * * * * * * * * *
 *        Include Libraries          *
 * * * * * * * * * * * * * * * * * * */
#include "std_types.h"
#include "common_macros.h"

#include "RCC_interface.h"
#include "RCC_config.h"
#include "RCC_private.h"

/* * * * * * * * * * * * * * * * * * *
 * Create a pointer to RCC Structure *
 * * * * * * * * * * * * * * * * * * */

void RCC_Enable8MHzHSI(void){
	SET_BIT(RCC -> RCC_CR, HSION); //Enable HSI.
	while(BIT_IS_CLEAR(RCC -> RCC_CR, HSIRDY)); //Polling until HSI is ready.
	SET_BIT(RCC -> RCC_CIR, HSIRDYC); //Clear HSI ready flag.
	CLEAR_BIT(RCC -> RCC_CFGR, SW0); //Select HSI as system clock.
	CLEAR_BIT(RCC -> RCC_CFGR, SW1); //Select HSI as system clock.
}

void RCC_EnableHSE(void){
	SET_BIT(RCC -> RCC_CR, HSEON); //Enable HSE.
	while(BIT_IS_CLEAR(RCC -> RCC_CR, HSERDY)); //Polling until HSE is ready.
	SET_BIT(RCC -> RCC_CIR, HSERDYC); //Clear HSE ready flag.
	SET_BIT(RCC -> RCC_CFGR, SW0); //Select HSE as system clock.
	CLEAR_BIT(RCC -> RCC_CFGR, SW1); //Select HSE as system clock.
}

void RCC_EnablePLL(uint8 PLL_CLKSource, uint8 PLL_Value){
	SET_BIT(RCC -> RCC_CR, PLLON); //Enable PLL.
	while(BIT_IS_CLEAR(RCC -> RCC_CR, PLLRDY)); //Polling until PLL is ready.
	SET_BIT(RCC -> RCC_CIR, PLLRDYC); //Clear PLL ready flag.
	switch(PLL_CLKSource){ //Jump to CLK source of PLL.
	case Half_HSI: //If PLL CLK source is half HSI.
		CLEAR_BIT(RCC -> RCC_CFGR, PLLSRC); //HSI oscillator clock / 2 selected as PLL input clock.
		break;
	case Half_HSE: //If PLL CLK source is half HSE.
		SET_BIT(RCC -> RCC_CFGR, PLLSRC); //HSE oscillator clock selected as PLL input clock.
		SET_BIT(RCC -> RCC_CFGR, PLLXTPRE); //HSE clock divided by 2.
		break;
	case HSE: //If PLL CLK source is HSE.
		SET_BIT(RCC -> RCC_CFGR, PLLSRC); //HSE oscillator clock selected as PLL input clock.
		CLEAR_BIT(RCC -> RCC_CFGR, PLLXTPRE); //HSE clock not divided.
		break;
	default :
		// Error Message
		break;
	}
	RCC -> RCC_CFGR = ((RCC -> RCC_CFGR) & 0xFFC3FFFF) | (PLL_Value << PLLMUL0); //Set value of PLL multiplication factor.
}

void RCC_EnableLSI(void){
	SET_BIT(RCC -> RCC_CSR, LSION); //Enable LSI.
	while(BIT_IS_SET(RCC -> RCC_CSR, LSIRDY)); //Polling until LSI is ready.
	SET_BIT(RCC -> RCC_CIR, LSIRDYC); //Clear LSI ready flag.
	CLEAR_BIT(RCC -> RCC_BDCR, RTCSEL0); //RTC clock source selection.
	SET_BIT(RCC -> RCC_BDCR, RTCSEL1); //RTC clock source selection.
}

void RCC_EnableLSE(void){
	SET_BIT(RCC -> RCC_BDCR, LSEON); //Enable LSE.
	while(	BIT_IS_SET(RCC -> RCC_BDCR, LSERDY)); //Polling until LSE is ready.
	SET_BIT(RCC -> RCC_CIR, LSERDYC);  //Clear LSE ready flag.
	SET_BIT(RCC -> RCC_BDCR, RTCSEL0); //RTC clock source selection.
	CLEAR_BIT(RCC -> RCC_BDCR, RTCSEL1); //RTC clock source selection.
}

void RCC_Enable_RTC(void){
	SET_BIT(RCC -> RCC_BDCR, RTCEN);; //Enable RTC.
}

void RCC_MCO_CLK(uint8 MCO_CLKSource){
	RCC -> RCC_CFGR = ((RCC -> RCC_CFGR) & 0xF8FFFFFF) | (MCO_CLKSource << MCO0); //Micro-controller clock output.
}

void AHB_Prescaler(uint8 AHB_PrescalerValue){
	RCC -> RCC_CFGR = ((RCC -> RCC_CFGR) & 0xFFFFFF0F) | (AHB_PrescalerValue << HPRE0); //Control the division factor of the AHB clock.
}

void APB1_Prescaler(uint8 APB1_PrescalerValue){
	RCC -> RCC_CFGR = ((RCC -> RCC_CFGR) & 0xFFFFF8FF) | (APB1_PrescalerValue << PPRE10); //Control the division factor of the APB1 clock.
}

void APB2_Prescaler(uint8 APB2_PrescalerValue){
	RCC -> RCC_CFGR = ((RCC -> RCC_CFGR) & 0xFFFFC7FF) | (APB2_PrescalerValue << PPRE20); //Control the division factor of the APB2 clock.
}

void ADC_Prescaler(uint8 ADC_PrescalerValue){
	RCC -> RCC_CFGR = ((RCC -> RCC_CFGR) & 0xFFFF3FFF) | (ADC_PrescalerValue << ADCPRE0); //Control the division factor of the ADCs clock.
}

void USB_Prescaler(uint8 USB_PrescalerValue){
	RCC -> RCC_CFGR = ((RCC -> RCC_CFGR) & 0xFFBFFFFF) | (USB_PrescalerValue << USBPRE); //Control the division factor of the USB clock.
}

void Reset_Module(uint8 peripheralIdx){
	if(PERIPHERAL_IN_RCC_APB2RSTR){ //Check if this HW module is in RCC_APB2RSTR Register.
		SET_BIT(RCC -> RCC_APB2RSTR, peripheralIdx); //Reset the chosen HW module.
	}
	else if(PERIPHERAL_IN_RCC_APB1RSTR){ //Check if this HW module is in RCC_APB1RSTR Register.
		peripheralIdx %= SIZE_OF_REGISTER; //peripheralIdx = peripheralIdx - 32
		SET_BIT(RCC -> RCC_APB1RSTR, peripheralIdx); //Reset CLK for the chosen HW module.
	}
}

void Remove_ResetFlag(void){
	SET_BIT(RCC -> RCC_CSR, RMVF);//Remove reset flag.
}

void RCC_EnableCLK(uint8 peripheralIdx){
	if(PERIPHERAL_IN_RCC_AHBENR){ //Check if this HW module is in RCC_AHBENR Register.
		SET_BIT(RCC -> RCC_AHBENR, peripheralIdx); //Enable CLK for the chosen HW module.
	}
	else if(PERIPHERAL_IN_RCC_APB2ENR){ //Check if this HW module is in RCC_APB2ENR Register.
		peripheralIdx %= SIZE_OF_REGISTER; //peripheralIdx = peripheralIdx - 32
		SET_BIT(RCC -> RCC_APB2ENR, peripheralIdx); //Enable CLK for the chosen HW module.
	}
	else if(PERIPHERAL_IN_RCC_APB1ENR){ //Check if this HW module is in RCC_APB1ENR Register.
		peripheralIdx %= SIZE_OF_REGISTER; //peripheralIdx = peripheralIdx - 64
		SET_BIT(RCC -> RCC_APB1ENR, peripheralIdx); //Enable CLK for the chosen HW module.
	}
}

void RCC_DisableCLK(uint8 peripheralIdx){
	if(PERIPHERAL_IN_RCC_AHBENR){ //Check if this HW module is in RCC_AHBENR Register.
		CLEAR_BIT(RCC -> RCC_AHBENR, peripheralIdx); //Disable CLK for the chosen HW module.
	}
	else if(PERIPHERAL_IN_RCC_APB2ENR){ //Check if this HW module is in RCC_APB2ENR Register.
		peripheralIdx %= SIZE_OF_REGISTER; //peripheralIdx = peripheralIdx - 32
		CLEAR_BIT(RCC -> RCC_APB2ENR, peripheralIdx); //Disable CLK for the chosen HW module.
	}
	else if(PERIPHERAL_IN_RCC_APB1ENR){ //Check if this HW module is in RCC_APB1ENR Register.
		peripheralIdx %= SIZE_OF_REGISTER; //peripheralIdx = peripheralIdx - 64
		CLEAR_BIT(RCC -> RCC_APB1ENR, peripheralIdx); //Disable CLK for the chosen HW module.
	}
}

void RCC_Config(void){

	/*******************************************
	 - This function enables system clock based
	   on the user configuration.
	 - It also configure some registers in the RCC
	   Peripheral.
	 *******************************************/
#if(Enable_HSI)
	RCC_Enable8MHzHSI();
#elif(Enable_HSE)
	RCC_EnableHSE();
#elif(Enable_PLL)
	RCC_EnablePLL(PLL_CLK_Source, PLL_Multiplication_Factor);
#else
	/* Error message: No system clock is enabled */
#endif

#if(Enable_LSI)
	RCC_EnableLSI();
#endif

#if(Enable_LSE)
	RCC_EnableLSE();
#endif

#if(Enable_RTC)
	RCC_Enable_RTC();
#endif

#if(Enable_AHB)
	AHB_Prescaler(AHB_Prescaler_Factor);
#endif

#if(Enable_APB1)
	APB1_Prescaler(APB1_Prescaler_Factor);
#endif

#if(Enable_APB2)
	APB2_Prescaler(APB2_Prescaler_Factor);
#endif

#if(Enable_ADC_CLK)
	ADC_Prescaler(ADC_Prescaler_Factor);
#endif

#if(Enable_USB_CLK)
	USB_Prescaler(USB_Prescaler_Factor);
#endif

#if(Enable_MCO)
	RCC_MCO_CLK(MCO_Prescaler_Factor);
#endif

}

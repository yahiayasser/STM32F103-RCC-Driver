/*
 * interface.h
 *
 *  Created on: 4 Aug 2019
 *      Author: Yahia
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#include "std_types.h"
#include "common_macros.h"

/* * * * * * * * * * * * * * *
 *  RCC Registers Structure  *
 * * * * * * * * * * * * * * */
typedef struct{
	uint32 RCC_CR;
	uint32 RCC_CFGR;
	uint32 RCC_CIR;
	uint32 RCC_APB2RSTR;
	uint32 RCC_APB1RSTR;
	uint32 RCC_AHBENR;
	uint32 RCC_APB2ENR;
	uint32 RCC_APB1ENR;
	uint32 RCC_BDCR;
	uint32 RCC_CSR;
}RCC_Registers;

/* RCC is a pointer to RCC_Registers structure
 * RCC address is the base address of RCC module in STM32F103C8T6
 * */
#define RCC  ((RCC_Registers *)(0x40021000))

/* * * * * * * * * * * * * * *
 *   MCO Prescaler Factor    *
 * * * * * * * * * * * * * * */
enum{
	/* These are the values that are used to choose the MCO
	   clock source.
	 * You can choose one value to pass it to:
	   void RCC_MCO_CLK(uint8 MCO_CLKSource)
	   as function argument.
	 * These Values can't be edited by the user.
	 * */
	MCO_No_clock,
	MCO_System_clock_selected = 4,
	MCO_HSI_clock_selected,
	MCO_HSE_clock_selected,
	MCO_PLL_clock_divided_by_2_selected
};


/* * * * * * * * * * * *
 *   PLL CLK Source    *
 * * * * * * * * * * * */
enum{
	/* These are the values that are used to choose Input
	   Clock source of PLL.
	 * You can choose one value to pass it to:
	   void RCC_EnablePLL(uint8 PLL_CLKSource, uint8 PLL_Value)
	   as the first argument.
	 * These Values can be edited by the user.
	 * */
	Half_HSI,
	Half_HSE,
	HSE
};

/* * * * * * * * * * * * * * *
 * PLL Multiplication Factor *
 * * * * * * * * * * * * * * */
enum{
	/* These are the values that are used to choose the PLL
	   Multiplication factor.
	 * You can choose one value to pass it to:
	   void RCC_EnablePLL(uint8 PLL_CLKSource, uint8 PLL_Value)
	   as the second argument.
	 * These Values can't be edited by the user.
	 * */
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
};

/* * * * * * * * * * * * * * *
 *   AHB Prescaler Factor    *
 * * * * * * * * * * * * * * */
enum{
	/* These are the values that are used to choose the AHB
	   prescaler value.
	 * You can choose one value to pass it to:
	   void AHB_Prescaler(uint8 AHB_PrescalerValue)
	   as function argument.
	 * These Values can't be edited by the user.
	 * */
	AHB_SYSCLK_not_divided,
	AHB_SYSCLK_divided_by_2 = 8,
	AHB_SYSCLK_divided_by_4,
	AHB_SYSCLK_divided_by_8,
	AHB_SYSCLK_divided_by_16,
	AHB_SYSCLK_divided_by_64,
	AHB_SYSCLK_divided_by_128,
	AHB_SYSCLK_divided_by_256,
	AHB_SYSCLK_divided_by_512
};

/* * * * * * * * * * * * * * *
 *   APB1 Prescaler Factor   *
 * * * * * * * * * * * * * * */
enum{
	/* These are the values that are used to choose the APB1
	   prescaler value.
	 * You can choose one value to pass it to:
	   void APB1_Prescaler(uint8 APB1_PrescalerValue)
	   as function argument.
	 * These Values can't be edited by the user.
	 * */
	APB1_HCLK_not_divided,
	APB1_HCLK_divided_by_2 = 4,
	APB1_HCLK_divided_by_4,
	APB1_HCLK_divided_by_8,
	APB1_HCLK_divided_by_16
};
/* * * * * * * * * * * * * * *
 *   APB2 Prescaler Factor   *
 * * * * * * * * * * * * * * */
enum{
	/* These are the values that are used to choose the APB2
	   prescaler value.
	 * You can choose one value to pass it to:
	   void APB2_Prescaler(uint8 APB2_PrescalerValue)
	   as function argument.
	 * These Values can't be edited by the user.
	 * */
	APB2_HCLK_not_divided,
	APB2_HCLK_divided_by_2 = 4,
	APB2_HCLK_divided_by_4,
	APB2_HCLK_divided_by_8,
	APB2_HCLK_divided_by_16
};

/* * * * * * * * * * * * * * *
 *   ADCs Prescaler Factor   *
 * * * * * * * * * * * * * * */
enum{
	/* These are the values that are used to choose the ADCs
	   prescaler value.
	 * You can choose one value to pass it to:
	   void ADC_Prescaler(uint8 ADC_PrescalerValue)
	   as function argument.
	 * These Values can't be edited by the user.
	 * */
	ADC_PCLK2_divided_by_2,
	ADC_PCLK2_divided_by_4,
	ADC_PCLK2_divided_by_6,
	ADC_PCLK2_divided_by_8
};

/* * * * * * * * * * * * * * *
 *   USB Prescaler Factor    *
 * * * * * * * * * * * * * * */
enum{
	/* These are the values that are used to choose the USB
	   prescaler value.
	 * You can choose one value to pass it to:
	   void USB_Prescaler(uint8 USB_PrescalerValue)
	   as function argument.
	 * These Values can't be edited by the user.
	 * */
	USB_PLL_clock_is_divided_by_OneHalf,
	USB_PLL_clock_is_not_divided
};

/* * * * * * * * * * * * * * *
 *  RCC_APB2RSTR Registers   *
 * * * * * * * * * * * * * * */
enum{
	/* These are the values that are used to choose the module's ID
	 * You can choose one value to pass it to:
	   void Reset_Module(uint8 peripheralIdx)
	   as function argument.
	 * These Values can't be edited by the user.
	 * */
	AFIORST,
	IOPARST = 2,
	IOPBRST,
	IOPCRST,
	IOPDRST,
	IOPERST,
	IOPFRST,
	IOPGRST,
	ADC1RST,
	ADC2RST,
	TIM1RST,
	SPI1RST,
	TIM8RST,
	USART1RST,
	ADC3RST,
	TIM9RST = 19,
	TIM10RST,
	TIM11RST
};

/* * * * * * * * * * * * * * *
 *  RCC_APB1RSTR Registers   *
 * * * * * * * * * * * * * * */
enum{
	/* These are the values that are used to choose the module's ID
	 * You can choose one value to pass it to:
	   void Reset_Module(uint8 peripheralIdx)
	   as function argument.
	 * These Values can't be edited by the user.
	 * */
	TIM2RST = 32,
	TIM3RST,
	TIM4RST,
	TIM5RST,
	TIM6RST,
	TIM7RST,
	TIM12RST,
	TIM13RST,
	TIM14RST,
	WWDGRST = 43,
	SPI2RST = 46,
	SPI3RST,
	USART2RST = 49,
	USART3RST,
	UART4RST,
	UART5RST,
	I2C1RST,
	I2C2RST,
	USBRST,
	CANRST = 57,
	BKPRST = 59,
	PWRRST,
	DACRST
};

/* * * * * * * * * * * * * * *
 *   RCC_AHBENR Registers    *
 * * * * * * * * * * * * * * */
enum{
	/* These are the values that are used to enable clock for a
	 * specific module.
	 * You can choose one value to pass it to:
	   void RCC_DisableCLK(uint8 peripheralIdx)
	   void RCC_EnableCLK(uint8 peripheralIdx)
	   as function argument.
	 * These Values can't be edited by the user.
	 * */
	DMA1EN,
	DMA2EN,
	SRAMEN,
	FLIFTEN = 4,
	CRCEN = 6,
	FSMCEN = 8,
	SDIOEN = 10
};

/* * * * * * * * * * * * * * *
 *   RCC_APB2ENR Registers   *
 * * * * * * * * * * * * * * */
enum{
	/* These are the values that are used to enable clock for a
	 * specific module.
	 * You can choose one value to pass it to:
	   void RCC_DisableCLK(uint8 peripheralIdx)
	   void RCC_EnableCLK(uint8 peripheralIdx)
	   as function argument.
	 * These Values can't be edited by the user.
	 * */
	AFIOEN = 32,
	IOPAEN = 34,
	IOPBEN,
	IOPCEN,
	IOPDEN,
	IOPEEN,
	IOPFEN,
	IOPGEN,
	ADC1EN,
	ADC2EN,
	TIM1REN,
	SPI1EN,
	TIM8EN,
	USART1EN,
	ADC3EN,
	TIM9EN = 51,
	TIM10EN,
	TIM11EN
};

/* * * * * * * * * * * * * * *
 *   RCC_APB1ENR Registers   *
 * * * * * * * * * * * * * * */
enum{
	/* These are the values that are used to enable clock for a
	 * specific module.
	 * You can choose one value to pass it to:
	   void RCC_DisableCLK(uint8 peripheralIdx)
	   void RCC_EnableCLK(uint8 peripheralIdx)
	   as function argument.
	 * These Values can't be edited by the user.
	 * */
	TIM2EN = 64,
	TIM3EN,
	TIM4EN,
	TIM5EN,
	TIM6EN,
	TIM7EN,
	TIM12EN,
	TIM13EN,
	TIM14EN,
	WWDGEN = 75,
	SPI2EN = 78,
	SPI3EN,
	USART2EN = 81,
	USART3EN,
	UART4EN,
	UART5EN,
	I2C1EN,
	I2C2EN,
	USBEN,
	CANEN = 89,
	BKPEN = 91,
	PWREN,
	DACEN
};


/* void RCC_EnableHSI(void)
 * Function Description: Configure RCC module to operate in
   HSI(High Speed Internal) mode.
 * Processor operate by the internal RC oscillator of the uC.
 * Internal oscillator Has a Frequency of 8MHz.
 * Parameters(In) : None.
 * Parameters(Out) : None.
 * */
void RCC_EnableHSI(void);

/* void RCC_EnableHSE(void)
 * Function Description: Configure RCC module to operate in
   HSE(High Speed External) mode.
 * User has to connect External oscillator.
 * External oscillator Has a range 4MHz:16MHz.
 * Parameters(In) : None.
 * Parameters(Out) : None.
 * */
void RCC_EnableHSE(void);

/* void RCC_EnablePLL(uint8 PLL_CLKSource, uint8 PLL_Value)
 * Function Description: Configure RCC module to operate in
   PLL(Phase Locked Loop) mode.
 * User can operate on either External oscillator, External
   oscillator divided by 2 or the Internal RC oscillator
   divided by 2.
 * External oscillator Has a range 4MHz:16MHz.
 * Internal oscillator Has a Frequency of 8MHz.
 * Parameters(In) : - PLL_CLKSource --> The clock source to
   the PLL.
    - PLL_Value --> the values that are used to choose the PLL
      Multiplication factor.
 * There are three options for PLL_CLKSource:
    - Half_HSI
    - Half_HSE
    - HSE
 * There are multiple options for PLL_Value:
    - PLL_input_clock_x2
	- PLL_input_clock_x3
	- PLL_input_clock_x4
	- PLL_input_clock_x5
	- PLL_input_clock_x6
	- PLL_input_clock_x7
	- PLL_input_clock_x8
	- PLL_input_clock_x9
	- PLL_input_clock_x10
	- PLL_input_clock_x11
	- PLL_input_clock_x12
	- PLL_input_clock_x13
	- PLL_input_clock_x14
	- PLL_input_clock_x15
	- PLL_input_clock_x16
 * Parameters(Out) : None.
 * */
void RCC_EnablePLL(uint8 PLL_CLKSource, uint8 PLL_Value);

/* void RCC_EnableLSI(void)
 * Function Description: Configure RTC module to operate in
   LSI(Low Speed Internal) mode.
 * Processor operate by the internal RC oscillator of the uC.
 * Internal oscillator Has a Frequency of 40KHz.
 * Parameters(In) : None.
 * Parameters(Out) : None.
 * */
void RCC_EnableLSI(void);

/* void RCC_EnableLSE(void)
 * Function Description: Configure RTC module to operate in
   LSE(Low Speed External) mode.
 * User has to connect 32.768KHz External oscillator.
 * Parameters(In) : None.
 * Parameters(Out) : None.
 * */
void RCC_EnableLSE(void);

/* void RCC_Enable_RTC(void)
 * Function Description: Enable RTC module of the uC.
 * Parameters(In) : None.
 * Parameters(Out) : None.
 * */
void RCC_Enable_RTC(void);

/* void RCC_MCO_CLK(uint8 MCO_CLKSource)
 * Function Description: Select specific clock to be generated
   by MCO pin.
 * Parameters(In) : - MCO_CLKSource --> The clock source to
   the MCO.
 * There are three options for MCO_CLKSource:
    - MCO_No_clock
	- MCO_System_clock_selected
	- MCO_HSI_clock_selected
	- MCO_HSE_clock_selected
	- MCO_PLL_clock_divided_by_2_selected
 * Parameters(Out) : None.
 * */
void RCC_MCO_CLK(uint8 MCO_CLKSource);

/* void AHB_Prescaler(uint8 AHB_PrescalerValue)
 * Function Description: Set the value of AHB Prescaler.
 * Parameters(In) : AHB_PrescalerValue --> prescaler value.
 * There are three options for AHB_PrescalerValue:
    - AHB_SYSCLK_not_divided
	- AHB_SYSCLK_divided_by_2
	- AHB_SYSCLK_divided_by_4
	- AHB_SYSCLK_divided_by_8
	- AHB_SYSCLK_divided_by_16
	- AHB_SYSCLK_divided_by_64
	- AHB_SYSCLK_divided_by_128
	- AHB_SYSCLK_divided_by_256
	- AHB_SYSCLK_divided_by_512
 * Parameters(Out) : None.
 * */
void AHB_Prescaler(uint8 AHB_PrescalerValue);

/* void APB1_Prescaler(uint8 APB1_PrescalerValue)
 * Function Description: Set the value of APB1 Prescaler.
 * Parameters(In) : APB1_PrescalerValue --> prescaler value.
 * There are three options for APB1_PrescalerValue:
	- APB1_HCLK_not_divided
	- APB1_HCLK_divided_by_2
	- APB1_HCLK_divided_by_4
	- APB1_HCLK_divided_by_8
	- APB1_HCLK_divided_by_16
 * Parameters(Out) : None.
 * */
void APB1_Prescaler(uint8 APB1_PrescalerValue);

/* void APB2_Prescaler(uint8 APB2_PrescalerValue)
 * Function Description: Set the value of APB2 Prescaler.
 * Parameters(In) : APB2_PrescalerValue --> prescaler value.
 * There are three options for APB2_PrescalerValue:
	- APB2_HCLK_not_divided
	- APB2_HCLK_divided_by_2
	- APB2_HCLK_divided_by_4
	- APB2_HCLK_divided_by_8
	- APB2_HCLK_divided_by_16
 * Parameters(Out) : None.
 * */
void APB2_Prescaler(uint8 APB2_PrescalerValue);

/* void ADC_Prescaler(uint8 ADC_PrescalerValue)
 * Function Description: Set the value of ADC prescaler.
 * Parameters(In) : ADC_PrescalerValue --> prescaler value.
 * There are three options for ADC_PrescalerValue:
   	- ADC_PCLK2_divided_by_2
	- ADC_PCLK2_divided_by_4
	- ADC_PCLK2_divided_by_6
	- ADC_PCLK2_divided_by_8
 * Parameters(Out) : None.
 * */
void ADC_Prescaler(uint8 ADC_PrescalerValue);

/* void USB_Prescaler(uint8 USB_PrescalerValue)
 * Function Description: Set the value of USB prescaler.
 * Parameters(In) : USB_PrescalerValue --> prescaler value.
 * There are three options for USB_PrescalerValue:
	 - USB_PLL_clock_is_divided_by_OneHalf
	 - USB_PLL_clock_is_not_divided
 * Parameters(Out) : None.
 * */
void USB_Prescaler(uint8 USB_PrescalerValue);

/* void Reset_Module(uint8 peripheralIdx)
 * Function Description: Reset specific hardware module
   in the uC.
 * Parameters(In) : peripheralIdx --> hardware module.
 * There are three options for Module:
   	- AFIORST
	- IOPARST
	- IOPBRST
	- IOPCRST
	- IOPDRST
	- IOPERST
	- IOPFRST
	- IOPGRST
	- ADC1RST
	- ADC2RST
	- TIM1RST
	- SPI1RST
	- TIM8RST
	- USART1RST
	- ADC3RST
	- TIM9RST
	- TIM10RST
	- TIM11RST
	- TIM2RST
	- TIM3RST
	- TIM4RST
	- TIM5RST
	- TIM6RST
	- TIM7RST
	- TIM12RST
	- TIM13RST
	- TIM14RST
	- WWDGRST
	- SPI2RST
	- SPI3RST
	- USART2RST
	- USART3RST
	- UART4RST
	- UART5RST
	- I2C1RST
	- I2C2RST
	- USBRST
	- CANRST
	- BKPRST
	- PWRRST
	- DACRST
 * Parameters(Out) : None.
 * */
void Reset_Module(uint8 peripheralIdx);

/* void Remove_ResetFlag(void)
 * Function Description: Remove reset flag.
 * Parameters(In) : None.
 * Parameters(Out) : None.
 * */
void Remove_ResetFlag(void);

/* void RCC_EnableCLK(uint8 peripheralIdx);
 * Function Description: Enable specific hardware module
   in the uC.
 * Parameters(In) : peripheralIdx --> hardware module.
 * There are Multiple options for peripheralIdx:
	- DMA1EN
	- DMA2EN
	- SRAMEN
	- FLIFTEN
	- CRCEN
	- FSMCEN
	- SDIOEN
	- AFIOEN
	- IOPAEN
	- IOPBEN
	- IOPCEN
	- IOPDEN
	- IOPEEN
	- IOPFEN
	- IOPGEN
	- ADC1EN
	- ADC2EN
	- TIM1REN
	- SPI1EN
	- TIM8EN
	- USART1EN
	- ADC3EN
	- TIM9EN
	- TIM10EN
	- TIM11EN
	- TIM2EN
	- TIM3EN
	- TIM4EN
	- TIM5EN
	- TIM6EN
	- TIM7EN
	- TIM12EN
	- TIM13EN
	- TIM14EN
	- WWDGEN
	- SPI2EN
	- SPI3EN
	- USART2EN
	- USART3EN
	- UART4EN
	- UART5EN
	- I2C1EN
	- I2C2EN
	- USBEN
	- CANEN
	- BKPEN
	- PWREN
	- DACEN
 * Parameters(Out) : None.
 * */
void RCC_EnableCLK(uint8 peripheralIdx);

/* void RCC_DisableCLK(uint8 peripheralIdx);
 * Function Description: Disable specific hardware module
   in the uC.
 * Parameters(In) : peripheralIdx --> hardware module.
 * There are Multiple options for peripheralIdx:
	- DMA1EN
	- DMA2EN
	- SRAMEN
	- FLIFTEN
	- CRCEN
	- FSMCEN
	- SDIOEN
	- AFIOEN
	- IOPAEN
	- IOPBEN
	- IOPCEN
	- IOPDEN
	- IOPEEN
	- IOPFEN
	- IOPGEN
	- ADC1EN
	- ADC2EN
	- TIM1REN
	- SPI1EN
	- TIM8EN
	- USART1EN
	- ADC3EN
	- TIM9EN
	- TIM10EN
	- TIM11EN
	- TIM2EN
	- TIM3EN
	- TIM4EN
	- TIM5EN
	- TIM6EN
	- TIM7EN
	- TIM12EN
	- TIM13EN
	- TIM14EN
	- WWDGEN
	- SPI2EN
	- SPI3EN
	- USART2EN
	- USART3EN
	- UART4EN
	- UART5EN
	- I2C1EN
	- I2C2EN
	- USBEN
	- CANEN
	- BKPEN
	- PWREN
	- DACEN
 * Parameters(Out) : None.
 * */
void RCC_DisableCLK(uint8 peripheralIdx);

/* void RCC_Config(void)
 * Function Description: Configure RCC based on
   the user configuration.
 * Parameters(In) : None.
 * Parameters(Out) : None.
 * */
void RCC_Config(void);

#endif /* INTERFACE_H_ */

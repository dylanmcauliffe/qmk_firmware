#pragma once
#include_next <mcuconf.h>

#ifdef CONVERT_TO_PROTON_C
/*
	Credit for the SERIAL and WS2812 settings belongs to:
		Drashna [https://github.com/drashna]
		ItsWaffIe [https://github.com/ItsWaffIe]
*/

	#undef STM32_PWM_USE_TIM3
	#define STM32_PWM_USE_TIM3			TRUE

	#undef STM32_SERIAL_USE_USART1
	#define STM32_SERIAL_USE_USART1		TRUE
#endif

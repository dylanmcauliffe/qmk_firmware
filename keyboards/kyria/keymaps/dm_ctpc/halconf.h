#pragma once
#include_next <halconf.h>

#ifdef CONVERT_TO_PROTON_C
/*
	Credit for the SERIAL and PWM settings belongs to:
		Drashna [https://github.com/drashna]
		ItsWaffIe [https://github.com/ItsWaffIe]
*/

	#define HAL_USE_PWM		TRUE

	#undef HAL_USE_SERIAL
	#define HAL_USE_SERIAL	TRUE
#endif

#pragma once
#include_next <halconf.h>

#ifdef CONVERT_TO_PROTON_C
/*
	Credit for settings goes here:
*/

	#define HAL_USE_PWM		TRUE

	#undef HAL_USE_SERIAL
	#define HAL_USE_SERIAL	TRUE
#endif

/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

#define MATRIX_ROWS 10
#define MATRIX_COLS 6

#define MATRIX_ROW_PINS { A10, A9, A8, B15, C13, C14, C15, A2, A3, A6 }
#define MATRIX_COL_PINS { B11, B10, B2, B1, A7, B0 }

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#ifdef ENCODER_ENABLE
	#define ENCODERS_PAD_A { B12 }
	#define ENCODERS_PAD_B { B13 }

	#define ENCODER_RESOLUTION 2
	#define TAP_CODE_DELAY		5 // Needed for media keys
#endif

#ifdef AUDIO_ENABLE
	#define AUDIO_PIN A5
	#define AUDIO_PIN_ALT A4
	#define AUDIO_PIN_ALT_AS_NEGATIVE

	#define AUDIO_INIT_DELAY

	#define STARTUP_SONG SONG(PLANCK_SOUND)
	// #define STARTUP_SONG SONG(NO_SOUND)

	#define DEFAULT_LAYER_SONGS \
        { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND) }
#endif

#ifdef RGBLIGHT_ENABLE
	#define RGB_DI_PIN			A1
	
	#define RGBLED_NUM			9
	#define DRIVER_LED_TOTAL		RGBLED_NUM

	#define RGBLIGHT_DEFAULT_MODE	RGBLIGHT_MODE_STATIC_LIGHT
	#define RGBLIGHT_DEFAULT_HUE	16

	#define RGBLIGHT_HUE_STEP	4
	#define RGBLIGHT_SAT_STEP	4
	#define RGBLIGHT_VAL_STEP	4
//	#define RGBLIGHT_LIMIT_VAL	150

	#define WS2812_PWM_DRIVER	PWMD2
	#define WS2812_PWM_CHANNEL	2
	#define WS2812_PWM_PAL_MODE	1
	#define WS2812_DMA_STREAM	STM32_DMA1_STREAM2
	#define WS2812_DMA_CHANNEL	2
#endif

#define TAPPING_TERM 150
#define TAPPING_TERM_PER_KEY

#define IGNORE_MOD_TAP_INTERRUPT

//#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY

//#define TAPPING_FORCE_HOLD
#define TAPPING_FORCE_HOLD_PER_KEY

//#define AUTO_SHIFT
#define AUTO_SHIFT_REPEAT
#define AUTO_SHIFT_TIMEOUT 150
#define AUTO_SHIFT_TIMEOUT_PER_KEY
#define NO_AUTO_SHIFT_TAB

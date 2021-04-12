/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 * Modified by Dylan McAuliffe
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.	 If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define OLED_FONT_H "keyboards/kyria/keymaps/dylanmcauliffe/carbon_font.c"

#ifdef ENCODER_ENABLE
	// See readme.md for required hardware changes
	#undef ENCODERS_PAD_A
	#undef ENCODERS_PAD_B
	#undef ENCODERS_PAD_A_RIGHT
	#undef ENCODERS_PAD_B_RIGHT

	// Swapped A/B pads to correct clockwise detection in keymap.c
	#define ENCODERS_PAD_A { D2 } // modified pin
	#define ENCODERS_PAD_B { C6 }
	#define ENCODERS_PAD_A_RIGHT { C6 }
	#define ENCODERS_PAD_B_RIGHT { D2 } // modified pin
	
	#define ENCODER_RESOLUTION 2 // ALPS encoders
	#define TAP_CODE_DELAY 10 // Needed for media keys
#endif

#ifdef SPLIT_KEYBOARD
	// See readme.md for required hardware changes
	#undef SOFT_SERIAL_PIN
	#define SOFT_SERIAL_PIN D3 // modified pin
	
	#ifdef CONVERT_TO_PROTON_C
	/*
		Credit for the SERIAL settings belongs to:
			Drashna [https://github.com/drashna]
			ItsWaffIe [https://github.com/ItsWaffIe]
	*/

		#define SELECT_SOFT_SERIAL_SPEED 0	// or 0, 2, 3, 4, 5
											//  0: about 460800 baud
											//  1: about 230400 baud (default)
											//  2: about 115200 baud
											//  3: about 57600 baud
											//  4: about 38400 baud
											//  5: about 19200 baud
		#define SERIAL_USART_DRIVER SD1
		#define SERIAL_USART_TX_PAL_MODE 7
		#define SERIAL_USART_TIMEOUT 100
		#endif
#endif

#ifdef OLED_DRIVER_ENABLE
	#define OLED_DISPLAY_128X64
	#define OLED_TIMEOUT 0
	#define OLED_SCROLL_TIMEOUT 30000
#endif

#ifdef RGBLIGHT_ENABLE
	// See readme.md for required hardware changes
	#undef RGB_DI_PIN
	#define RGB_DI_PIN B5 // modified pin
	
	#define RGBLIGHT_LED_MAP { 8, 9, 6, 5, 7, 2, 4, 3, 1, 0, 10, 11, 13, 14, 12, 17, 15, 16, 19, 18 }

	#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT
	#define RGBLIGHT_DEFAULT_HUE 16

	#define RGBLIGHT_ANIMATIONS
	#define RGBLIGHT_HUE_STEP 4
	#define RGBLIGHT_SAT_STEP 4
	#define RGBLIGHT_VAL_STEP 4
	#define RGBLIGHT_LIMIT_VAL 150

	#ifdef CONVERT_TO_PROTON_C
	/*
		Credit for the WS2812 settings belongs to:
			Drashna [https://github.com/drashna]
			ItsWaffIe [https://github.com/ItsWaffIe]
	*/

		#define WS2812_PWM_DRIVER PWMD3
		#define WS2812_PWM_CHANNEL 3
		#define WS2812_PWM_PAL_MODE 2
		#define WS2812_DMA_STREAM STM32_DMA1_STREAM3
		#define WS2812_DMA_CHANNEL 3
	#endif
#endif

#ifdef AUDIO_ENABLE
	#ifdef CONVERT_TO_PROTON_C
		#define AUDIO_PIN A5
		#define AUDIO_PIN_ALT A4
		#define AUDIO_PIN_ALT_AS_NEGATIVE
	#endif
#endif

// Home row mods helpers
#define TAPPING_TERM 200
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD
#define PERMISSIVE_HOLD

// Copyright 2022 dylanmcauliffe (@dylanmcauliffe)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID		0xAB17
#define PRODUCT_ID		0x0002
#define DEVICE_VER		0x0001
#define MANUFACTURER	abstruse systems
#define PRODUCT		tubi

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_COL_PINS	{ B5, B4, B3, B2, B1, B0 }
#define MATRIX_ROW_PINS	{ A2, A1, A0, B8, B13, B14, A13, B9 }
#define UNUSED_PINS

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION	COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE	5

#ifdef ENCODER_ENABLE
	// See readme.md for required hardware changes
	#undef ENCODERS_PAD_A
	#undef ENCODERS_PAD_B
	#undef ENCODERS_PAD_A_RIGHT
	#undef ENCODERS_PAD_B_RIGHT

	// Swapped A/B pads to correct clockwise detection in keymap.c
	#define ENCODERS_PAD_A		{ B11, B12 }
	#define ENCODERS_PAD_B		{ B10, A14 } // modified pin
	
	#define ENCODER_RESOLUTION	2 // ALPS encoders
	#define TAP_CODE_DELAY		5 // Needed for media keys
#endif

#ifdef AUDIO_ENABLE
	#define AUDIO_PIN	A5
	#define AUDIO_PIN_ALT A4
	#define AUDIO_PIN_ALT_AS_NEGATIVE
	
//	#define STARTUP_SONG SONG(PLANCK_SOUND)
//	#define STARTUP_SONG SONG(NO_SOUND)

	#define DEFAULT_LAYER_SONGS {	\
		SONG(QWERTY_SOUND),		\
		SONG(COLEMAK_SOUND),	\
		SONG(PLANCK_SOUND)		\
	}

	#define AUDIO_INIT_DELAY
#endif

#ifdef OLED_ENABLE
	#define OLED_DISPLAY_128X64
	#define OLED_TIMEOUT		0
	#define OLED_SCROLL_TIMEOUT	30000
	
	#define OLED_FONT_H "yubi_font.c"
#endif

#ifdef RGBLIGHT_ENABLE
	#define RGB_DI_PIN			A3
	
	#define RGBLED_NUM			1
	#define RGBLIGHT_LED_MAP		{ 0 }

	#define RGBLIGHT_DEFAULT_MODE	RGBLIGHT_MODE_STATIC_LIGHT
	#define RGBLIGHT_DEFAULT_HUE	16

	#define RGBLIGHT_ANIMATIONS
	#define RGBLIGHT_HUE_STEP	4
	#define RGBLIGHT_SAT_STEP	4
	#define RGBLIGHT_VAL_STEP	4
	#define RGBLIGHT_LIMIT_VAL	150

	#define WS2812_PWM_DRIVER	PWMD2
	#define WS2812_PWM_CHANNEL	4
	#define WS2812_PWM_PAL_MODE	1
	#define WS2812_DMA_STREAM	STM32_DMA1_STREAM2
	#define WS2812_DMA_CHANNEL	2
	#define WS2812_DMAMUX_ID		STM32_DMAMUX1_TIM2_UP
#endif

#ifdef SPLIT_KEYBOARD
	// NOT CONFIGURED, DO NOT ENABLE
	#define SERIAL_USART_TX_PIN		A9
	#define SERIAL_USART_RX_PIN		A10

	#define SERIAL_USART_FULL_DUPLEX			// Enable full duplex operation mode.
	#define SERIAL_USART_PIN_SWAP				// Swap TX and RX pins if keyboard is master halve.

	#define SERIAL_USART_DRIVER		SD1		// USART driver of TX pin. default: SD1
	#define SERIAL_USART_TX_PAL_MODE	7		// Pin "alternate function", see the respective datasheet for the appropriate values for your MCU. default: 7
	
	#define SELECT_SOFT_SERIAL_SPEED	1		// or 0, 2, 3, 4, 5
										//  0: about 460800 baud
										//  1: about 230400 baud (default)
										//  2: about 115200 baud
										//  3: about 57600 baud
										//  4: about 38400 baud
										//  5: about 19200 baud
#endif

// Mod key helpers
#define TAPPING_TERM 300
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

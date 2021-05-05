/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2018 Danny Nguyen <danny@keeb.io>

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

#define USE_I2C
#undef SOFT_SERIAL_PIN

#undef DEBOUNCE
#define DEBOUNCE 15

#define UNUSED_PINS

#ifdef ENCODER_ENABLE
	// RGB pins used for encoders
	#undef RGB_DI_PIN
	#undef RGBLED_NUM
	#undef RGBLED_SPLIT
	#undef BACKLIGHT_PIN
	#undef BACKLIGHT_LEVELS

	// Encoder Support
	#define ENCODER_RESOLUTION 2 // ALPS encoders
	#define ENCODERS_PAD_A { D7 }
	#define ENCODERS_PAD_B { B6 }
	#define ENCODERS_PAD_A_RIGHT { B6 }
	#define ENCODERS_PAD_B_RIGHT { D7 }

	// Media Key Fix
	#define TAP_CODE_DELAY 10 // Needed for media keys
#endif

#define TAPPING_TOGGLE 2

// Home row mods helpers
#define TAPPING_TERM 300
#define TAPPING_TERM_PER_KEY

#define IGNORE_MOD_TAP_INTERRUPT

//#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY

//#define TAPPING_FORCE_HOLD
#define TAPPING_FORCE_HOLD_PER_KEY
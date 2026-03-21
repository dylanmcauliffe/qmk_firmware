// Copyright 2022 dylanmcauliffe (@dylanmcauliffe)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

void keyboard_post_init_user(void) {
//	Customise these values to desired behaviour
//	debug_enable=true;
//	debug_matrix=true;
//	debug_keyboard=true;
//	debug_mouse=true;
}

// Defines names for use in layer keycodes and the keymap
enum layers {
	_QWERTY = 0,
	_COLEMAKdm,
	_COLEMAKDHm,
	_FUNCTION,
	_NAVIGATION,
	_NUMBER,
	_QUANTUM,
	_BLANK,
};

const uint8_t highest_base_layer_index = _COLEMAKDHm;

enum encoders {
	_LEFT = 0,
	_RIGHT,
};

#include "custom_keymaps.c"

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case NV_DEL:
		case NM_SPC:
			return true;
		default:
			return false;
	}
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case LC_LGUI:
		case LG_F8:

		case LA_PLUS:
		case NM_BSPC:
		case NV_DEL:

		case FN_ENT:
		case NM_SPC:
		case QT_MINS:

		case RG_F5:
		case RC_RGUI:
			return true;
		default:
			return false;
    }
}

bool get_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
	#ifndef NO_AUTO_SHIFT_ALPHA
		case KC_A ... KC_Z:
	#endif
	#ifndef NO_AUTO_SHIFT_NUMERIC
		case KC_1 ... KC_0:
	#endif
	#ifndef NO_AUTO_SHIFT_SPECIAL
		case KC_MINUS ... KC_SLASH:
		case KC_NONUS_BACKSLASH:
	#endif
	#ifndef NO_AUTO_SHIFT_TAB
		case KC_TAB:
	#endif
		return true;
	}
	return get_custom_auto_shifted_key(keycode, record);
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
	    case QT_CAPS:
		return TAPPING_TERM - 150;
        default:
            return TAPPING_TERM;
    }
}

uint16_t get_autoshift_timeout(uint16_t keycode, keyrecord_t *record) {
	switch(keycode) {
		case AUTO_SHIFT_NUMERIC:
		case AUTO_SHIFT_SPECIAL:
		case AUTO_SHIFT_ALPHA:
		default:
			return AUTO_SHIFT_TIMEOUT;
	}
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_QWERTY] = LAYOUT_tubi_pcb(
		KC_ESC,	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,					KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,	KC_BSLS,
		KC_TAB,	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,					KC_H,	KC_J,	KC_K,	KC_L,	KC_SCLN,	KC_QUOT,
		KC_LSFT,	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,	LG_F8,	RG_F5,	KC_N,	KC_M,	KC_COMM,	KC_DOT,	KC_SLSH,	KC_RSFT,
		LC_LGUI,			KC_MPLY,			LA_MPRV,	NM_BSPC,	NV_DEL,	FN_ENT,	NM_SPC,	QT_MNXT,			KC_MUTE,			RC_RGUI
	),		

	[_COLEMAKdm] = LAYOUT_tubi_pcb(
		_______,	_______,	_______,	KC_F,	KC_D,	KC_P,					KC_J,	KC_L,	KC_U,	KC_Y,	KC_SCLN,	_______,
		_______,	_______,	KC_R,	KC_S,	KC_T,	_______,					_______,	KC_N,	KC_E,	KC_O,	KC_I,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_K,	_______,	_______,	_______,	_______,	_______,
		_______,			_______,			_______,	_______,	_______,	_______,	_______,	_______,			_______,			_______
	),		

	[_COLEMAKDHm] = LAYOUT_tubi_pcb(
		_______,	_______,	_______,	KC_F,	KC_P,	KC_B,					KC_J,	KC_L,	KC_U,	KC_Y,	KC_SCLN,	_______,
		_______,	_______,	KC_R,	KC_S,	KC_T,	_______,					KC_M,	KC_N,	KC_E,	KC_I,	KC_O,	_______,
		_______,	_______,	_______,	_______,	KC_D,	KC_V,	_______,	_______,	KC_K,	KC_H,	_______,	_______,	_______,	_______,
		_______,			_______,			_______,	_______,	_______,	_______,	_______,	_______,			_______,			_______
	),		

	[_FUNCTION] = LAYOUT_tubi_pcb(
		KC_NLCK,	_______,	_______,	_______,	_______,	_______,					_______,	KC_F9,	KC_F10,	KC_F11,	KC_F12,	KC_PAUS,
		KC_CAPS,	_______,	_______,	_______,	_______,	_______,					_______,	KC_F5,	KC_F6,	KC_F7,	KC_F8,	KC_SLCK,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_PSCR,
		_______,			_______,			_______,	_______,	KC_INS,	_______,	_______,	_______,			_______,			KC_F16
	),		

	[_NAVIGATION] = LAYOUT_tubi_pcb(
		_______,	KC_HOME,	KC_PGDN,	KC_PGUP,	KC_END,	M_NTAB,					_______,	_______,	_______,	_______,	_______,	_______,
		KC_DEL,	KC_LEFT,	KC_DOWN,	KC_UP,	KC_RGHT,	KC_ENT,					_______,	_______,	_______,	_______,	_______,	_______,
		_______,	M_UNDO,	M_CUT,	M_COPY,	M_PASTE,	M_REDO,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,			_______,			_______,	_______,	_______,	_______,	_______,	_______,			_______,			_______
	),		

	[_NUMBER] = LAYOUT_tubi_pcb(
		KC_EQL,	KC_EXLM,	KC_AT,	KC_HASH,	KC_DLR,	KC_PERC,					KC_CIRC,	KC_AMPR,	KC_ASTR,	KC_LPRN,	KC_RPRN,	KC_UNDS,
		KC_PLUS,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,					KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	KC_MINS,
		KC_LBRC,	KC_BSLS,	KC_LCBR,	KC_RCBR,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_RBRC,
		_______,			_______,			_______,	_______,	KC_GRV,	KC_TILD,	_______,	_______,			_______,			_______
	),		

	[_QUANTUM] = LAYOUT_tubi_pcb(
		RESET,	BL_QWTY,	_______,	_______,	_______,	_______,					_______,	_______,	_______,	_______,	_______,	DF_CLMK,
		_______,	_______,	_______,	_______,	_______,	_______,					_______,	_______,	_______,	_______,	_______,	DF_QWTY,
		KC_ASTG,	_______,	_______,	BL_CLMK,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	DF_CMKD,
		EEP_RST,			_______,			_______,	_______,	_______,	_______,	_______,	_______,			_______,			_______
	),		

	[_BLANK] = LAYOUT_tubi_pcb(
		_______,	_______,	_______,	_______,	_______,	_______,					_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,					_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,			_______,			_______,	_______,	_______,	_______,	_______,	_______,			_______,			_______
	),		
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
	if (index == _LEFT) {
		if (clockwise) {
//			tap_code16(M_NDSKT);
			tap_code16(M_NDSKT);
		} else {
//			tap_code16(M_PDSKT);
			tap_code16(M_PDSKT);
		}
	}
	else if (index == _RIGHT) {
		if (clockwise) {
			tap_code(KC_VOLU);
		} else {
			tap_code(KC_VOLD);
		}
	}
	
	return true;
}
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_0;
}

static void render_tubi_logo(void) {
	static const char PROGMEM tubi_logo[] = {
		0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
		0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
		0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
	};

	oled_write_P(tubi_logo, false);
}

static void render_status(void) {
	uint16_t highest_base_layer = pow(2, highest_base_layer_index);

	// QMK Logo and version information
	render_tubi_logo();
	oled_write_P(PSTR("\n     tubi v0.2a\n"), false);

	// Host Keyboard Layer Status
	switch ( default_layer_state ) {
		case (uint16_t)pow( 2, _COLEMAKDHm ):
			oled_write_P(PSTR("     COLEMAK-DHm\n"), false);
			break;
		case (uint16_t)pow( 2, _QWERTY ):
			oled_write_P(PSTR("     QWERTY\n"), false);
			break;
		default:
			oled_write_P(PSTR(" UNKNOWN BASE LAYER\n"), false);
	}

	if ( layer_state > highest_base_layer ) {
		switch ( get_highest_layer( layer_state ) ) {
			case _FUNCTION:
				oled_write_P(PSTR("     FUNCTION\n"), false);
				break;
			case _NAVIGATION:
				oled_write_P(PSTR("     NAVIGATION\n"), false);
				break;
			case _NUMBER:
				oled_write_P(PSTR("     NUMBER/SYMBOL\n"), false);
				break;
			case _QUANTUM:
				oled_write_P(PSTR("     QUANTUM\n"), false);
				break;
			default:
				oled_write_P(PSTR(" UNKNOWN MOD LAYER\n"), false);
		}
	} else {
		oled_write_P(PSTR("\n"), false);
	}

	// Host Keyboard LED Status
	uint8_t led_usb_state = host_keyboard_leds();
	oled_write_P(PSTR("     "), false);
	oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUM ") : PSTR("    "), false);
	oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPS ") : PSTR("     "), false);
	oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRL ") : PSTR("     "), false);
}

bool oled_task_user(void) {
	if (is_keyboard_master()) {
		render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
	} else {
		render_status();
	}
	
	return true;
}
#endif

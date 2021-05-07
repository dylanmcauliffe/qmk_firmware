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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layers {
	_COLEMAKDHm = 0,
	_QWERTY,
	_GAMEPAD,
	_WEAPONS,
	_MEDIA,
	_FUNCTION,
	_NAVIGATION,
	_NUMBER,
	_QUANTUM,
};

#include "custom_keymaps.c"

const uint8_t highest_base_layer_index = 2;

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case FN_ESC:  
        case NV_TAB:
        case NM_SPC:
            return true;
        default:
            return false;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case FN_ESC:
        case NM_BSPC:
        case NV_TAB:
        case NV_ENT:
        case NM_SPC:
        case FN_DEL:

        case ME_DEL:
        case ME_RGUI:
            return true;
        default:
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LS_S:
            return TAPPING_TERM - 150;
        case LS_D:
        case RS_E:
        case RS_K:
            return 150;
        default:
            return TAPPING_TERM;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_COLEMAKDHm] = LAYOUT(
		KC_ESC,	KC_Q,	KC_W,	KC_F,	KC_P,	KC_B,										KC_J,	KC_L,	KC_U,	KC_Y,	KC_SCLN,	KC_BSLS,
		KC_TAB,	LG_A,	LA_R,	LS_S,	LC_T,	KC_G,										KC_M,	RC_N,	RS_E,	RA_I,	RG_O,	KC_QUOT,
		ME_DEL,	KC_Z,	KC_X,	KC_C,	KC_D,	KC_V,	TG_MEDI,	TG_QUAN,		DF_GAME,	BL_CLMK,	KC_K,	KC_H,	KC_COMM,	KC_DOT,	KC_SLSH,	ME_RGUI,
								M_RDESC,	DF_QWTY,	FN_ESC,	NM_BSPC,	NV_TAB,		NV_ENT,	NM_SPC,	FN_DEL,	DF_CLMK,	KC_F16
		),
	[_QWERTY] = LAYOUT(
		_______,	_______,	_______,	KC_E,	KC_R,	KC_T,										KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,	_______,
		_______,	_______,	LA_S,	LS_D,	LC_F,	_______,										KC_H,	RC_J,	RS_K,	RA_L,	RG_SCLN,	_______,
		_______,	_______,	_______,	_______,	KC_V,	KC_B,	_______,	_______,		_______,	_______,	KC_N,	KC_M,	_______,	_______,	_______,	_______,
								_______,	_______,	_______,	_______,	_______,		_______,	_______,	_______,	_______,	_______
	),
	[_GAMEPAD] = LAYOUT(
		_______,	_______,	_______,	_______,	_______,	_______,										_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,										_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
								KC_F16,	_______,	_______,	_______,	_______,		_______,	_______,	_______,	_______,	KC_MPLY
	),
	[_FUNCTION] = LAYOUT(
		_______,	KC_F9,	KC_F10,	KC_F11,	KC_F12,	KC_PAUS,										KC_SLCK,	_______,	_______,	_______,	_______,	EEP_RST,
		_______,	KC_F5,	KC_F6,	KC_F7,	KC_F8,	KC_CAPS,										KC_NLCK,	_______,	_______,	_______,	_______,	_______,
		_______,	KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_PSCR,	_______,	_______,		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
								_______,	_______,	_______,	_______,	_______,		_______,	_______,	_______,	_______,	_______
	),
	[_MEDIA] = LAYOUT(
		_______,	_______,	_______,	_______,	_______,	_______,										_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,										_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
								KC_MPLY,	_______,	_______,	_______,	_______,		_______,	_______,	_______,	_______,	KC_MUTE
	),
	[_NAVIGATION] = LAYOUT(
		_______,	KC_PGUP,	KC_HOME,	KC_UP,	KC_END,	KC_INS,										_______,	_______,	_______,	_______,	_______,	_______,
		_______,	KC_PGDN,	KC_LEFT,	KC_DOWN,	KC_RGHT,	KC_ENT,										_______,	_______,	_______,	_______,	_______,	_______,
		_______,	M_UNDO,	M_CUT,	M_COPY,	M_PASTE,	M_REDO,	_______,	_______,		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
								_______,	_______,	_______,	_______,	_______,		_______,	_______,	_______,	_______,	_______
	),
	[_NUMBER] = LAYOUT(
		KC_GRV,	KC_EXLM,	KC_AT,	KC_HASH,	KC_DLR,	KC_PERC,										KC_CIRC,	KC_AMPR,	KC_ASTR,	KC_LPRN,	KC_RPRN,	KC_TILD,
		KC_PLUS,	LG_1,	LA_2,	LS_3,	LC_4,	KC_5,										KC_6,	RC_7,	RS_8,	RA_9,	RG_0,	KC_MINS,
		KC_EQL,	KC_BSLS,	_______,	_______,	KC_LBRC,	KC_LCBR,	_______,	_______,		_______,	_______,	KC_RCBR,	KC_RBRC,	_______,	_______,	_______,	KC_UNDS,
								_______,	_______,	KC_GRV,	_______,	KC_MINS,		KC_EQL,	_______,	KC_QUOT,	_______,	_______
	),
	[_QUANTUM] = LAYOUT(
		_______,	_______,	_______,	_______,	_______,	_______,										_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,										_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
								_______,	_______,	_______,	_______,	_______,		_______,	_______,	_______,	_______,	_______
	),
/*	[_BLANK] = LAYOUT(
		_______,	_______,	_______,	_______,	_______,	_______,										_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,										_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
								_______,	_______,	_______,	_______,	_______,		_______,	_______,	_______,	_______,	_______
	),
*/
};

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
	switch (get_highest_layer(layer_state)) {
		case _NAVIGATION:
			if (index == 0) {
				if (clockwise) {
					tap_code(KC_PGDN);
				} else {
					tap_code(KC_PGUP); 
				}
			} else if (index == 1) {
				if (clockwise) {
					tap_code(KC_WH_U);
				} else {
					tap_code(KC_WH_D);
				}
			}
			break;
		case _MEDIA:
			if (index == 0) {
				if (clockwise) {
					tap_code(KC_MNXT);
				} else {
					tap_code(KC_MPRV);
				}
			} else if (index == 1) {
				if (clockwise) {
					tap_code(KC_VOLU);
				} else {
					tap_code(KC_VOLD);
				}
			}
			break;
		case _QUANTUM:
			if (index == 0) {
				if (clockwise) {
					rgblight_step_noeeprom();
				} else {
					rgblight_step_reverse_noeeprom();
				}
			} else if (index == 1) {
				if (clockwise) {
					rgblight_increase_val_noeeprom();
				} else {
					rgblight_decrease_val_noeeprom();
				}
			}
			break;
		default:
			switch ( default_layer_state ) {
			case (uint16_t)pow( 2, _GAMEPAD):
				if (index == 0) {
					if (clockwise) {
						tap_code(KC_VOLU);
					} else {
						tap_code(KC_VOLD); 
					}
				}
				break;
			default:
				if (index == 0) {
					if (clockwise) {
						tap_code16(M_NDSKT);
					} else {
						tap_code16(M_PDSKT);
					}
				} else if (index == 1) {
					if (clockwise) {
						tap_code(KC_VOLU);
					} else {
						tap_code(KC_VOLD);
					}
				}
			}
		}
}
#endif

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_qmk_logo(void) {
	static const char PROGMEM qmk_logo[] = {
		0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
		0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
		0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
	};

	oled_write_P(qmk_logo, false);
}

static void render_carbon_logo(void) {
	static const char PROGMEM carbon_logo[] = {
		// 'carbon', 128x64px
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 
		0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf8, 0xf8, 0xfc, 0xfc, 0x7e, 0x7e, 0x3f, 0x3f, 0x1f, 
		0x1f, 0x3f, 0x3f, 0x7e, 0x7e, 0xfc, 0xfc, 0xf8, 0xf8, 0xf0, 0xf0, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 
		0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0xe0, 0xe0, 0xf0, 0xf0, 0xf8, 0xf8, 0xfc, 0xfc, 0x7e, 0x7e, 0x3f, 0x3f, 0x1f, 
		0x1f, 0x0f, 0x0f, 0x07, 0x07, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0xf8, 0xf8, 0xf0, 0xf0, 0xe0, 0xe0, 0xc1, 0xc1, 0x83, 0x83, 0x07, 0x07, 0x0f, 0x0f, 0x1f, 
		0x1f, 0x3f, 0x3f, 0x7e, 0x7e, 0xfc, 0xfc, 0xf8, 0xf8, 0xf0, 0xf0, 0xe0, 0xe0, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x01, 0x01, 0x03, 0x03, 0x07, 0x07, 0x0f, 0x0f, 0x1f, 0x1f, 0x3f, 0x3f, 0x7e, 0x7e, 0x3c, 
		0x3c, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x80, 0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf8, 0xf8, 0xfc, 0xfc, 0x7e, 0x7e, 0x3c, 
		0x3c, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x07, 0x07, 0x0f, 0x0f, 0x1f, 0x1f, 0x3f, 0x3f, 0x7e, 0x7e, 0xfc, 0xfc, 0xf8, 
		0xf8, 0xf0, 0xf0, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x1f, 0x1f, 0x0f, 0x0f, 0x07, 0x07, 0x83, 0x83, 0xc1, 0xc1, 0xe0, 0xe0, 0xf0, 0xf0, 0xf8, 
		0xf8, 0xfc, 0xfc, 0x7e, 0x7e, 0x3f, 0x3f, 0x1f, 0x1f, 0x0f, 0x0f, 0x07, 0x07, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
		0x01, 0x03, 0x03, 0x07, 0x07, 0x0f, 0x0f, 0x1f, 0x1f, 0x3f, 0x3f, 0x7e, 0x7e, 0xfc, 0xfc, 0xf8, 
		0xf8, 0xfc, 0xfc, 0x7e, 0x7e, 0x3f, 0x3f, 0x1f, 0x1f, 0x0f, 0x0f, 0x07, 0x07, 0x03, 0x03, 0x01, 
		0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	};

	oled_write_raw_P(carbon_logo, sizeof(carbon_logo));
}

static void render_status(void) {
	uint16_t highest_base_layer = pow(2, highest_base_layer_index);

	// QMK Logo and version information
	render_qmk_logo();
	oled_write_P(PSTR("\n     Kyria v1.3\n"), false);

	// Host Keyboard Layer Status
		switch ( default_layer_state ) {
			case (uint16_t)pow( 2, _COLEMAKDHm ):
				oled_write_P(PSTR("     COLEMAK-DHm\n"), false);
				break;
			case (uint16_t)pow( 2, _QWERTY ):
				oled_write_P(PSTR("     QWERTY\n"), false);
				break;
			case (uint16_t)pow( 2, _GAMEPAD ):
				oled_write_P(PSTR("     GAMEPAD\n"), false);
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
			case _MEDIA:
				oled_write_P(PSTR("     MEDIA\n"), false);
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

void oled_task_user(void) {
	if (is_keyboard_master()) {
		render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
	} else {
		render_carbon_logo();
	}
}
#endif

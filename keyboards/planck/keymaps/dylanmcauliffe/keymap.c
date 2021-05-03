/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"
#include "custom_keymaps.c"

enum layers {
	_COLEMAKDHm,
	_QWERTY,
	_GAMEPAD,
	_MEDIA,
	_FUNCTION,
	_NAVIGATION,
	_NUMBER,
	_QUANTUM,
};

enum custom_keycodes  {
	BL_CLMK = SAFE_RANGE,
	BL_QWTY,
	BL_GAME,
	KC_P00,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case BL_CLMK:
		  if (record->event.pressed) {
			set_single_persistent_default_layer(_COLEMAKDHm);
		  }
		  return false;
		  break;
		case BL_QWTY:
		  if (record->event.pressed) {
			set_single_persistent_default_layer(_QWERTY);
		  }
		  return false;
		  break;
		case BL_GAME:
		  if (record->event.pressed) {
			set_single_persistent_default_layer(_GAMEPAD);
		  }
		  return false;
		  break;
		case KC_P00:
		  if (record->event.pressed) {
			tap_code(KC_P0);
			tap_code(KC_P0);
		  }
			return false;
		break;
	}
	return true;
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NM_SPC:
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
	[_COLEMAKDHm] = LAYOUT_planck_grid(
		KC_Q,	KC_W,	KC_F,	KC_P,	KC_B,	BL_CLMK,	BL_QWTY,	KC_J,	KC_L,	KC_U,	KC_Y,	KC_SCLN,
		LG_A,	LA_R,	LS_S,	LC_T,	KC_G,	_______,	_______,	KC_M,	RC_N,	RS_E,	RA_I,	RG_O,
		KC_Z,	KC_X,	KC_C,	KC_D,	KC_V,	_______,	_______,	KC_K,	KC_H,	KC_COMM,	KC_DOT,	KC_SLSH,
		M_RDESC,	_______,	_______,	FN_ESC,	NV_BSPC,	KC_TAB,	NV_ENT,	NM_SPC,	FN_DEL,	_______,	_______,	_______
	),

	[_QWERTY] = LAYOUT_planck_grid(
		_______,	_______,	KC_E,	KC_R,	KC_T,	_______,	_______,	KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,
		_______,	LA_S,	LS_D,	LC_F,	_______,	_______,	_______,	KC_H,	RC_J,	RS_K,	RA_L,	RG_SCLN,
		_______,	_______,	_______,	KC_V,	KC_B,	_______,	_______,	KC_N,	KC_M,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______
	),
	
	[_MEDIA] = LAYOUT_planck_grid(
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______
	),
	
	[_FUNCTION] = LAYOUT_planck_grid(
		KC_F9,	KC_F10,	KC_F11,	KC_F12,	KC_PSCR,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		KC_F5,	KC_F6,	KC_F7,	KC_F8,	KC_SLCK,	_______,	_______,	KC_NLCK,	_______,	_______,	_______,	_______,
		KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_PAUS,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______
	),
	
	[_NAVIGATION] = LAYOUT_planck_grid(
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	M_REDO,	M_PASTE,	M_COPY,	M_CUT,	M_UNDO,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_CAPS,	KC_LEFT,	KC_DOWN,	KC_UP,	KC_RGHT,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_INS,	KC_HOME,	KC_PGDN,	KC_PGUP,	KC_END,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______
	),
	
	[_NUMBER] = LAYOUT_planck_grid(
		_______,	KC_7,	KC_8,	KC_9,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	KC_4,	KC_5,	KC_6,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	KC_1,	KC_2,	KC_3,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	KC_0,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______
	),
};

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
	switch (get_highest_layer(layer_state)) {
		case _MEDIA:
			if (clockwise) {
				tap_code(KC_VOLU);
			} else {
				tap_code(KC_VOLD);
			}
			break;
		default:
			if (clockwise) {
				tap_code16(M_NDSKT);
			} else {
				tap_code16(M_PDSKT);
			}
		}
}
#endif

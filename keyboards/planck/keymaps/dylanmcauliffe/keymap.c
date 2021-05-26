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

enum layers {
	_QWERTY,
	_COLEMAKDHm,
	_GAMEPAD,
	_WEAPONS,
	_MEDIA,
	_FUNCTION,
	_NAVIGATION,
	_NUMBER,
	_QUANTUM,
};

#include "custom_keymaps.c"

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LS_S:
        case LS_D:
        case RS_E:
        case RS_K:
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
	[_QWERTY] = LAYOUT_planck_grid(
		KC_ESC,	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,	KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,	KC_BSLS,
		KC_TAB,	LG_A,	LA_S,	LS_D,	LC_F,	KC_G,	KC_H,	RC_J,	RS_K,	RA_L,	RG_SCLN,	KC_QUOT,
		ME_DEL,	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,	KC_N,	KC_M,	KC_COMM,	KC_DOT,	KC_SLSH,	ME_RGUI,
		M_RDESC,	MO_QUAN,	_______,	FN_ESC,	NM_BSPC,	NV_TAB,	NV_ENT,	NM_SPC,	FN_DEL,	_______,	MO_QUAN,	KC_F16
	),
	
	[_COLEMAKDHm] = LAYOUT_planck_grid(
		_______,	_______,	_______,	KC_F,	KC_P,	KC_B,	KC_J,	KC_L,	KC_U,	KC_Y,	KC_SCLN,	_______,
		_______,	_______,	LA_R,	LS_S,	LC_T,	_______,	KC_M,	RC_N,	RS_E,	RA_I,	RG_O,	_______,
		_______,	_______,	_______,	_______,	KC_D,	KC_V,	KC_K,	KC_H,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______
	),

	[_GAMEPAD] = LAYOUT_planck_grid (
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		KC_LSFT,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		KC_F16,	_______,	KC_LALT,	WP_ZERO,	KC_SPC,	KC_LCTL,	_______,	NM_BSPC,	FN_DEL,	_______,	_______,	_______
	),
	
	[_WEAPONS] = LAYOUT_planck_grid (
		KC_GRV,	KC_7,	KC_8,	KC_9,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		KC_EQL,	KC_4,	KC_5,	KC_6,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		KC_MINS,	KC_1,	KC_2,	KC_3,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		KC_0,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______
	),
	
	[_MEDIA] = LAYOUT_planck_grid(
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		KC_MPLY,	KC_MPRV,	KC_MNXT,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_MUTE
	),
	
	[_FUNCTION] = LAYOUT_planck_grid(
		_______,	KC_F9,	KC_F10,	KC_F11,	KC_F12,	KC_PSCR,	KC_SLCK,	_______,	_______,	_______,	_______,	_______,
		_______,	KC_F5,	KC_F6,	KC_F7,	KC_F8,	KC_CAPS,	KC_NLCK,	_______,	_______,	_______,	_______,	_______,
		_______,	KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_PAUS,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______
	),
	
	[_NAVIGATION] = LAYOUT_planck_grid(
		_______,	KC_PGUP,	KC_HOME,	KC_UP,	KC_END,	KC_INS,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	KC_PGDN,	KC_LEFT,	KC_DOWN,	KC_RGHT,	KC_ENT,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	M_UNDO,	M_CUT,	M_COPY,	M_PASTE,	M_REDO,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______
	),
	
	[_NUMBER] = LAYOUT_planck_grid(
		KC_GRV,	KC_EXLM,	KC_AT,	KC_HASH,	KC_DLR,	KC_PERC,	KC_CIRC,	KC_AMPR,	KC_ASTR,	KC_LPRN,	KC_RPRN,	KC_TILD,
		KC_PLUS,	LG_1,	LA_2,	LS_3,	LC_4,	KC_5,	KC_6,	RC_7,	RS_8,	RA_9,	RG_0,	KC_MINS,
		KC_EQL,	KC_BSLS,	_______,	_______,	KC_LBRC,	KC_LCBR,	KC_RCBR,	KC_RBRC,	_______,	_______,	_______,	KC_UNDS,
		_______,	_______,	_______,	KC_EQL,	_______,	KC_MINS,	KC_QUOT,	_______,	KC_GRV,	_______,	_______,	_______
	),
	
	[_QUANTUM] = LAYOUT_planck_grid (
		DF_CLMK,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	DF_CLMK,
		DF_QWTY,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	DF_QWTY,
		DF_GAME,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	DF_GAME,
		TG_MEDI,	RESET,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	RESET,	TG_MEDI
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
			switch ( default_layer_state ) {
			case (uint16_t)pow( 2, _GAMEPAD):
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
}
#endif

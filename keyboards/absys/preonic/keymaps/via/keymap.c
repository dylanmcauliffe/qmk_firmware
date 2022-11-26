/* Copyright 2015-2021 Jack Humbert
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

enum preonic_layers {
	_QWERTY = 0,
	_COLEMAKdm,
	_FUNCTION,
	_NAVIGATION,
	_QUANTUM,
	_SYMBOL,
	_BLANK,
	_BLANK2,
};

#define MO_FUNC	MO(_FUNCTION)
#define DF_CMKD	DF(_COLEMAKdm)		// Default Layer: Colemak Custom
#define DF_QWTY	DF(_QWERTY)		// Default Layer: QWERTY
#define SY_SPC		LT(_SYMBOL,KC_SPC)
#define M_RDESC	LCA(KC_HOME)		// CTRL + ALT + HOME: RDP Escape Sequence
#define M_NDSKT	G(C(KC_RGHT))		// GUI + CTRL + RIGHT: Next Desktop
#define M_PDSKT	G(C(KC_LEFT))		// GUI + CTRL + Left: Prev Desktop

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case SY_SPC:
			return true;
		default:
			return false;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case SY_SPC:
			return true;
		default:
			return false;
	}
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_QWERTY] = LAYOUT_ortho_5x12(
		KC_F16,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,	KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	KC_BSLS,
		KC_ESC,	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,	KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,	KC_BSPC,
		KC_TAB,	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,	KC_H,	KC_J,	KC_K,	KC_L,	KC_SCLN,	KC_QUOT,
		KC_LSFT,	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,	KC_N,	KC_M,	KC_COMM,	KC_DOT,	KC_SLSH,	KC_RSFT,
		KC_LCTL,	MO_FUNC,	KC_LGUI,	KC_LALT,	KC_SPC,	KC_DEL,	KC_ENT,	SY_SPC,	KC_LEFT,	KC_DOWN,	KC_UP,	KC_RGHT
	),

	[_COLEMAKdm] = LAYOUT_ortho_5x12(
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	KC_F,	KC_D,	KC_P,	KC_J,	KC_L,	KC_U,	KC_Y,	KC_SCLN,	_______,
		_______,	_______,	KC_R,	KC_S,	KC_T,	_______,	_______,	KC_N,	KC_E,	KC_I,	KC_O,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	KC_K,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______
	),

	[_FUNCTION] = LAYOUT_ortho_5x12(
		M_RDESC,	KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_F5,	KC_F6,	KC_F7,	KC_F8,	KC_F9,	KC_F10,	KC_F11,
		KC_NLCK,	DF_QWTY,	KC_PGUP,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_F12,
		KC_CAPS,	KC_HOME,	KC_PGDN,	KC_END,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_PAUS,
		_______,	_______,	_______,	DF_CMKD,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_SLCK,
		_______,	_______,	_______,	_______,	_______,	KC_INS,	_______,	_______,	_______,	_______,	_______,	KC_PSCR
	),

	[_NAVIGATION] = LAYOUT_ortho_5x12(
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______
	),

	[_SYMBOL] = LAYOUT_ortho_5x12(
		KC_MPLY,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_PIPE,
		KC_GRV,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_MINS,
		KC_LBRC,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_RBRC,
		_______,	_______,	KC_LCBR,	KC_RCBR,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_PLUS,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_EQL
	),

	[_QUANTUM] = LAYOUT_ortho_5x12(
		RESET,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______
	),

	[_BLANK] = LAYOUT_ortho_5x12(
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______
	),

	[_BLANK2] = LAYOUT_ortho_5x12(
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______
	),

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
	[_QWERTY]		=	{ ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
	[_COLEMAKdm]	=	{ ENCODER_CCW_CW(_______, _______) },
	[_FUNCTION]	=	{ ENCODER_CCW_CW(M_PDSKT, M_NDSKT) },
	[_NAVIGATION]	=	{ ENCODER_CCW_CW(_______, _______) },
	[_SYMBOL]		=	{ ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
	[_QUANTUM]	=	{ ENCODER_CCW_CW(_______, _______) },
	[_BLANK]		=	{ ENCODER_CCW_CW(_______, _______) },
	[_BLANK2]		=	{ ENCODER_CCW_CW(_______, _______) },
};
#endif

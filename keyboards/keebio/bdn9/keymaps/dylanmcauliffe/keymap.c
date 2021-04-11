/* Copyright 2019 Danny Nguyen <danny@keeb.io>
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

enum encoder_names {
  _LEFT,
  _RIGHT,
  _MIDDLE,
};

#define M_RDPESC	LCA(KC_HOME)
#define M_NDSKTP	G(C(KC_RGHT))
#define M_PDSKTP	G(C(KC_LEFT))

#define LAY_DOT		LT(1,KC_DOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_MPLY,	KC_F16,	 	KC_MUTE,
        M_PDSKTP,	M_RDPESC,	M_NDSKTP,
        KC_1,		LAY_DOT,	KC_0
    ),
    [1] = LAYOUT(
        RESET,		_______,	_______,
        _______,	_______,	_______,
        _______,	_______,	_______
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _LEFT) {
        if (clockwise) {
            tap_code(KC_MNXT);
        } else {
            tap_code(KC_MPRV);
        }
    }
    else if (index == _MIDDLE) {
    }
    else if (index == _RIGHT) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}

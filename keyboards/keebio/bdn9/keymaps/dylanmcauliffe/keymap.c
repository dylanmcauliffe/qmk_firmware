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

enum layers {
	_MACRO,
	_QUANTUM,
};

enum encoder_names {
	_LEFT,
	_RIGHT,
	_MIDDLE,
};

#define M_RDESC	LCA(KC_HOME)
#define M_NDSKT	G(C(KC_RGHT))
#define M_PDSKT	G(C(KC_LEFT))

#define QT_F16		LT(_QUANTUM,KC_F16)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MACRO] = LAYOUT(
		KC_MPLY,	QT_F16,	KC_MUTE,
		KC_P1,	KC_PDOT,	KC_P0,
		M_PDSKT,	M_RDESC,	M_NDSKT
    ),
    [_QUANTUM] = LAYOUT(
		RESET,	_______,	_______,
		RGB_HUD,	RGB_TOG,	RGB_HUI,
		RGB_RMOD,	RGB_TOG,	RGB_MOD
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

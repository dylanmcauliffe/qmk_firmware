#include QMK_KEYBOARD_H

enum layers {
	_QWERTY = 0,
	_COLEMAK,
	_QUANTUM,
};

#include "keymap.custom.c" // custom defines and functions moves here for readablity

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT(
		KC_0,	KC_1,
		KC_2,	KC_3
	),

	[_COLEMAK] = LAYOUT(
		_______,	_______,
		_______,	_______
	),

	[_QUANTUM] = LAYOUT(
		QK_BOOT,	EE_CLR,
		QK_RBT,	_______
	),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] = { ENCODER_CCW_CW( KC_LEFT, KC_RGHT ),  ENCODER_CCW_CW( KC_DOWN, KC_UP )  },
    [_COLEMAK] = { ENCODER_CCW_CW( _______, _______ ),  ENCODER_CCW_CW( _______, _______ )  },
    [_QUANTUM] = { ENCODER_CCW_CW( _______, _______ ),  ENCODER_CCW_CW( _______, _______ )  },
};
#endif

#include QMK_KEYBOARD_H

enum layers {
	_QWERTY = 0,
	_COLEMAK,
	_QUANTUM,
};

#include "keymap.custom.c" // custom defines and functions moves here for readablity

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT(
		KC_P7,	KC_P8,	KC_P9,	KC_PSLS,
		KC_P4,	KC_P5,	KC_P6,	KC_PAST,
		KC_P1,	KC_P2,	KC_P3,	KC_PMNS,
		KC_P0,	KC_PDOT,	KC_PENT,	KC_PPLS
	),

	[_COLEMAK] = LAYOUT(
		_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______
	),

	[_QUANTUM] = LAYOUT(
		QK_BOOT,	_______,	_______,	EE_CLR,
		_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,
		QK_RBT,	_______,	_______,	_______
	),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] = { ENCODER_CCW_CW( KC_LEFT, KC_RGHT ),  ENCODER_CCW_CW( KC_DOWN, KC_UP )  },
    [_COLEMAK] = { ENCODER_CCW_CW( _______, _______ ),  ENCODER_CCW_CW( _______, _______ )  },
    [_QUANTUM] = { ENCODER_CCW_CW( _______, _______ ),  ENCODER_CCW_CW( _______, _______ )  },
};
#endif

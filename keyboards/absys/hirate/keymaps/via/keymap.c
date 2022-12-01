#include QMK_KEYBOARD_H

enum layers {
	_BASE = 0,
	_FUNCTION,
	_QUANTUM,
	_BLANK,
};

#include "keymap.custom.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT_hirate_v1a (
		KC_UP,	KC_ESC,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,
		KC_DOWN,	KC_TAB,	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,
		KC_RIGHT,	KC_LSFT,	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,
		KC_LEFT,	QT_ENT,	KC_Z,	KC_X,	KC_C,	KC_V,	FN_F16,
						KC_MUTE,			KC_LALT,	KC_P9,	KC_LCTL
	),

	[_FUNCTION] = LAYOUT_hirate_v1a (
		_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,
						_______,			_______,	_______,	_______
	),

	[_QUANTUM] = LAYOUT_hirate_v1a (
		_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,
						_______,			_______,	_______,	_______
	),

	[_BLANK] = LAYOUT_hirate_v1a (
		_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,
						_______,			_______,	_______,	_______
	),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
	[_BASE]		= { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
	[_FUNCTION]	= { ENCODER_CCW_CW(_______, _______) },
	[_QUANTUM]	= { ENCODER_CCW_CW(_______, _______) },
	[_BLANK]		= { ENCODER_CCW_CW(_______, _______) },
};
#endif

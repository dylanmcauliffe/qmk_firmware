// best viewed with tab size of 5
#include QMK_KEYBOARD_H

enum layers {
	_QWERTY = 0,
	_COLEMAK,
	_QUANTUM,
	_BLANK,
};

#include "keymap.custom.c" // custom defines and functions moves here for readablity

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_yubi (
		KC_ESC,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,					KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	KC_GRV,
		KC_TAB,	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,					KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,	KC_BSLS,
		KC_LALT,	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,					KC_H,	KC_J,	KC_K,	KC_L,	KC_SCLN,	KC_QUOT,
		KC_LCTL,	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,	KC_F1,	KC_F2,	KC_N,	KC_M,	KC_COMM,	KC_DOT,	KC_SLSH,	KC_RCTL,
						KC_MINS,			KC_LGUI,	KC_BSPC,	KC_DEL,	KC_ENT,	KC_SPC,	KC_RGUI,			KC_EQL
	),

	[_COLEMAK] = LAYOUT_yubi (
		_______,	_______,	_______,	_______,	_______,	_______,					_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	KC_F,	KC_P,	KC_G,					KC_J,	KC_L,	KC_U,	KC_Y,	KC_SCLN,	_______,
		_______,	_______,	KC_R,	KC_S,	KC_T,	KC_D,					_______,	KC_N,	KC_E,	KC_I,	KC_O,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_K,	_______,	_______,	_______,	_______,	_______,
						_______,			_______,	_______,	_______,	_______,	_______,	_______,			_______
	),

	[_QUANTUM] = LAYOUT_yubi (
		_______,	_______,	_______,	_______,	_______,	_______,					_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,					_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,					_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
						_______,			_______,	_______,	_______,	_______,	_______,	_______,			_______
	),

	[_BLANK] = LAYOUT_yubi (
		_______,	_______,	_______,	_______,	_______,	_______,					_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,					_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,					_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
						_______,			_______,	_______,	_______,	_______,	_______,	_______,			_______
	),

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY]	= { ENCODER_CCW_CW( KC_LEFT,	KC_RGHT ),	ENCODER_CCW_CW( KC_DOWN,	KC_UP )  },
    [_COLEMAK]	= { ENCODER_CCW_CW( _______,	_______ ),	ENCODER_CCW_CW( _______,	_______ )  },
    [_QUANTUM]	= { ENCODER_CCW_CW( _______,	_______ ),	ENCODER_CCW_CW( _______,	_______ )  },
    [_BLANK]	= { ENCODER_CCW_CW( _______,	_______ ),	ENCODER_CCW_CW( _______,	_______ )  },
};
#endif

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable =	false;
  debug_matrix =	false;
  debug_keyboard =	false;
  debug_mouse =	false;
}

// best viewed with tab size of 5
#include QMK_KEYBOARD_H

enum layers {
	_QWERTY = 0,
	_COLEMAK,
	_FUNCTION,
	_NAVIGATION,
	_NUMBER,
	_QUANTUM,
	_BLANK,
};

#include "keymap.custom.c" // custom defines and functions moves here for readablity

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_yubi (
		KC_ESC,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,					KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	KC_GRV,
		KC_TAB,	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,					KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,	KC_BSLS,
		KC_LALT,	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,					KC_H,	KC_J,	KC_K,	KC_L,	KC_SCLN,	RA_QUOT,
		LC_MINS,	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,	FN_F8,	FN_F16,	KC_N,	KC_M,	KC_COMM,	KC_DOT,	KC_SLSH,	RC_EQL,
						KC_MINS,			KC_LGUI,	NV_BSPC,	LS_DEL,	RS_ENT,	NM_SPC,	KC_RGUI,			KC_EQL
	),

	[_COLEMAK] = LAYOUT_yubi (
		_______,	_______,	_______,	_______,	_______,	_______,					_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	KC_F,	KC_P,	KC_G,					KC_J,	KC_L,	KC_U,	KC_Y,	KC_SCLN,	_______,
		_______,	_______,	KC_R,	KC_S,	KC_T,	KC_D,					_______,	KC_N,	KC_E,	KC_I,	KC_O,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_K,	_______,	_______,	_______,	_______,	_______,
						_______,			_______,	_______,	_______,	_______,	_______,	_______,			_______
	),

	[_FUNCTION] = LAYOUT_yubi (
		KC_F11,	KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_F5,					KC_F6,	KC_F7,	KC_F8,	KC_F9,	KC_F10,	KC_F12,
		KC_NUM,	DF_QWTY,	_______,	_______,	_______,	_______,					_______,	_______,	_______,	_______,	_______,	KC_PAUS,
		LA_CAPS,	_______,	_______,	_______,	_______,	_______,					_______,	_______,	_______,	_______,	_______,	RA_LSCR,
		_______,	_______,	_______,	DF_CLMK,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	RC_PSCR,
						_______,			_______,	_______,	LS_INS,	_______,	_______,	RG_APP,			_______
	),

	[_NAVIGATION] = LAYOUT_yubi (
		_______,	_______,	_______,	_______,	_______,	_______,					_______,	_______,	_______,	_______,	_______,	_______,
		_______,	KC_HOME,	KC_PGDN,	KC_PGUP,	KC_END,	_______,					_______,	_______,	_______,	_______,	_______,	_______,
		_______,	KC_LEFT,	KC_DOWN,	KC_UP,	KC_RGHT,	KC_ENT,					_______,	_______,	_______,	_______,	_______,	_______,
		_______,	KC_UNDO,	KC_CUT,	KC_COPY,	KC_PSTE,	M_REDO,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
						_______,			_______,	_______,	_______,	_______,	_______,	_______,			_______
	),

	[_NUMBER] = LAYOUT_yubi (
		_______,	_______,	_______,	_______,	_______,	_______,					_______,	_______,	_______,	_______,	_______,	KC_TILD,
		_______,	KC_EXLM,	KC_AT,	KC_HASH,	KC_DLR,	KC_PERC,					KC_CIRC,	KC_AMPR,	KC_ASTR,	KC_LPRN,	KC_RPRN,	KC_PIPE,
		_______,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,					KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	RA_DQUO,
		LC_UNDS,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_QUES,	RC_PLUS,
						_______,			_______,	_______,	_______,	_______,	_______,	_______,			_______
	),

	[_QUANTUM] = LAYOUT_yubi (
		QK_BOOT,	_______,	_______,	_______,	_______,	_______,					_______,	_______,	_______,	_______,	_______,	_______,
		_______,	PD_QWTY,	_______,	_______,	_______,	_______,					_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	DB_TOGG,					_______,	_______,	EE_CLR,	_______,	_______,	_______,
		QK_RBT,	_______,	_______,	PD_CLMK,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
						_______,			_______,	_______,	_______,	_______,	_______,	QK_MAKE,			_______
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
    [_QWERTY]		= { ENCODER_CCW_CW( KC_LEFT,	KC_RGHT ),	ENCODER_CCW_CW( KC_DOWN,	KC_UP )  },
    [_COLEMAK]		= { ENCODER_CCW_CW( _______,	_______ ),	ENCODER_CCW_CW( _______,	_______ )  },
    [_FUNCTION]	= { ENCODER_CCW_CW( _______,	_______ ),	ENCODER_CCW_CW( _______,	_______ )  },
    [_NAVIGATION]	= { ENCODER_CCW_CW( _______,	_______ ),	ENCODER_CCW_CW( _______,	_______ )  },
    [_NUMBER]		= { ENCODER_CCW_CW( _______,	_______ ),	ENCODER_CCW_CW( _______,	_______ )  },
    [_QUANTUM]		= { ENCODER_CCW_CW( _______,	_______ ),	ENCODER_CCW_CW( _______,	_______ )  },
    [_BLANK]		= { ENCODER_CCW_CW( _______,	_______ ),	ENCODER_CCW_CW( _______,	_______ )  },
};
#endif

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable =	false;
  debug_matrix =	false;
  debug_keyboard =	false;
  debug_mouse =	false;
}

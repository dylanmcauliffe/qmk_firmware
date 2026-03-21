// best viewed with tab size of 5
#include QMK_KEYBOARD_H
#include <math.h>

enum layers {
	_QWERTY = 0,
	_COLEMAK,
	_FUNCTION,
	_NAVIGATION,
	_NUMBER,
	_QUANTUM,
	_BLANK,
};

const uint8_t highest_base_layer_index = _COLEMAK;

#include "keymap.custom.c" // custom defines and functions moves here for readablity

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_yubi (
		KC_ESC,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,					KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	KC_GRV,
		KC_TAB,	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,					KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,	KC_BSLS,
		KC_LALT,	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,					KC_H,	KC_J,	KC_K,	KC_L,	KC_SCLN,	RA_QUOT,
		LC_MINS,	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,	FN_F8,	QT_F16,	KC_N,	KC_M,	KC_COMM,	KC_DOT,	KC_SLSH,	RC_EQL,
						M_RDESC,			KC_LGUI,	NV_BSPC,	LS_DEL,	RS_ENT,	NM_SPC,	KC_RGUI,			KC_MPLY
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
		LA_CAPS,	_______,	_______,	_______,	_______,	_______,					_______,	_______,	_______,	_______,	_______,	RA_SCRL,
		_______,	_______,	_______,	DF_CLMK,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	RC_PSCR,
						_______,			_______,	_______,	LS_INS,	_______,	_______,	RG_APP,			_______
	),

	[_NAVIGATION] = LAYOUT_yubi (
		_______,	_______,	_______,	_______,	_______,	_______,					_______,	_______,	_______,	_______,	_______,	_______,
		_______,	KC_HOME,	KC_PGDN,	KC_PGUP,	KC_END,	_______,					_______,	_______,	_______,	_______,	_______,	_______,
		_______,	KC_LEFT,	KC_DOWN,	KC_UP,	KC_RGHT,	KC_ENT,					_______,	_______,	_______,	_______,	_______,	_______,
		_______,	M_UNDO,	M_CUT,	M_COPY,	M_PASTE,	M_REDO,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
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
		QK_RBT,	_______,	_______,	PD_CLMK,	_______,	_______,	_______,	TG_QNTM,	_______,	_______,	_______,	_______,	_______,	_______,
						_______,			_______,	_______,	_______,	_______,	_______,	UG_TOGG,			_______
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
    [_QWERTY]		= { ENCODER_CCW_CW( M_NAVL,	M_NAVR ),		ENCODER_CCW_CW( KC_MPRV,	KC_MNXT )  },
    [_COLEMAK]		= { ENCODER_CCW_CW( _______,	_______ ),	ENCODER_CCW_CW( _______,	_______ )  },
    [_FUNCTION]	= { ENCODER_CCW_CW( _______,	_______ ),	ENCODER_CCW_CW( _______,	_______ )  },
    [_NAVIGATION]	= { ENCODER_CCW_CW( _______,	_______ ),	ENCODER_CCW_CW( MS_WHLD,	MS_WHLU )  },
    [_NUMBER]		= { ENCODER_CCW_CW( _______,	_______ ),	ENCODER_CCW_CW( _______,	_______ )  },
    [_QUANTUM]		= { ENCODER_CCW_CW( UG_PREV,	UG_NEXT ),	ENCODER_CCW_CW( UG_VALD,	UG_VALU )  },
    [_BLANK]		= { ENCODER_CCW_CW( _______,	_______ ),	ENCODER_CCW_CW( _______,	_______ )  },
};
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_0;
}

static void render_yubi_logo(void) {
	static const char PROGMEM yubi_logo[] = {
		0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
		0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
		0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
	};

	oled_write_P(yubi_logo, false);
}

static void render_status(void) {
	uint16_t highest_base_layer = pow(2, highest_base_layer_index);

	// QMK Logo and version information
	render_yubi_logo();
	oled_write_P(PSTR("\n"), false); // 20 chars per line

	// Host Keyboard Layer Status
	switch ( default_layer_state ) {
		case (uint16_t)pow( 2, _COLEMAK ):
			oled_write_P(PSTR("     COLEMAK\n"), false);
			break;
		case (uint16_t)pow( 2, _QWERTY ):
			oled_write_P(PSTR("     QWERTY\n"), false);
			break;
		default:
			oled_write_P(PSTR(" UNKNOWN BASE LAYER\n"), false);
	}

	if ( layer_state > highest_base_layer ) {
		switch ( get_highest_layer( layer_state ) ) {
			case _FUNCTION:
				oled_write_P(PSTR("     FUNCTION\n"), false);
				break;
			case _NAVIGATION:
				oled_write_P(PSTR("     NAVIGATION\n"), false);
				break;
			case _NUMBER:
				oled_write_P(PSTR("     NUMBER/SYMBOL\n"), false);
				break;
			case _QUANTUM:
				oled_write_P(PSTR("     QUANTUM\n"), false);
				break;
			default:
				oled_write_P(PSTR(" UNKNOWN MOD LAYER\n"), false);
		}
	} else {
		oled_write_P(PSTR("\n"), false);
	}

	// Host Keyboard LED Status
	oled_write_P(PSTR("     "), false);
	oled_write_P( ( host_keyboard_led_state().num_lock ) ? PSTR( "NUM " ) : PSTR( "    " ), false);
	oled_write_P( ( host_keyboard_led_state().caps_lock ) ? PSTR( "CAPS " ) : PSTR( "     " ), false);
	oled_write_P( ( host_keyboard_led_state().scroll_lock ) ? PSTR( "SCRL " ) : PSTR( "     " ), false);

	oled_write_P(PSTR("\n                v1.0"), false);
}

bool oled_task_user(void) {
	if (is_keyboard_master()) {
		render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
	} else {
		render_status();
	}

	return false;
}
#endif

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable =	false;
  debug_matrix =	false;
  debug_keyboard =	false;
  debug_mouse =	false;
}

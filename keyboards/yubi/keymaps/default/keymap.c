#include QMK_KEYBOARD_H

enum layers {
	_QWERTY = 0,
	_COLEMAKDHm,
	_COLEMAKdm,
	_FUNCTION,
	_NAVIGATION,
	_NUMBER,
	_QUANTUM,
	_BLANK,
};

#include "keymap.custom.c"

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_EXLM ... KC_RPRN:
        case KC_BSPC:
        case KC_DEL:
        case KC_MINS:
        case KC_PLUS:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case LC_F8:
		case FN_F5:

		case LA_EQL:
		case NV_BSPC:
		case LS_DEL:

		case RS_ENT:
		case NM_SPC:
		case QT_P00:
			return true;
		default:
			return false;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case LS_DEL:
		
		case RS_ENT:
		case NM_SPC:
			return true;
		default:
			return false;
	}
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* RowCol
     * ┌────┬────┬────┬────┬────┬────┐         ┌────┬────┬────┬────┬────┬────┐
     * │ 00 │ 01 │ 02 │ 03 │ 04 │ 05 │         │ 15 │ 14 │ 13 │ 12 │ 11 │ 10 │
     * ├────┼────┼────┼────┼────┼────┤         ├────┼────┼────┼────┼────┼────┤
     * │ 20 │ 21 │ 22 │ 23 │ 24 │ 25 │         │ 35 │ 34 │ 33 │ 32 │ 31 │ 30 │
     * ├────┼────┼────┼────┼────┼────┼────┬────┼────┼────┼────┼────┼────┼────┤
     * │ 40 │ 41 │ 42 │ 43 │ 44 │ 45 │ 65 │ 75 │ 55 │ 54 │ 53 │ 52 │ 51 │ 50 │
     * ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤
     * │ 60 │    │ 61 │    │ 62 │ 63 │ 64 │ 74 │ 73 │ 72 │    │ 71 │    │ 70 │
     * └────┘    └────┘    └────┴────┴────┴────┴────┴────┘    └────┘    └────┘
     */
	[_QWERTY] = LAYOUT_yubi_v5a(
		KC_ESC,	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,					KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,	KC_MINS,
		KC_TAB,	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,					KC_H,	KC_J,	KC_K,	KC_L,	KC_SCLN,	KC_QUOT,
		KC_GRV,	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,	LC_F8,	FN_F5,	KC_N,	KC_M,	KC_COMM,	KC_DOT,	KC_SLSH,	KC_BSLS,
		KC_LGUI,			KC_MPLY,			LA_PLUS,	NV_BSPC,	LS_DEL,	RS_ENT,	NM_SPC,	QT_CAPWD,			KC_MUTE,			KC_RGUI
	),

	[_FUNCTION] = LAYOUT_yubi_v5a(
		KC_NLCK,	_______,	_______,	_______,	_______,	_______,					_______,	KC_F9,	KC_F10,	KC_F11,	KC_F12,	KC_PAUS,
		KC_CAPS,	_______,	_______,	_______,	_______,	_______,					_______,	KC_F5,	KC_F6,	KC_F7,	KC_F8,	KC_SLCK,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_PSCR,
		_______,			_______,			_______,	_______,	KC_INS,	_______,	_______,	_______,			_______,			_______
	),

	[_NAVIGATION] = LAYOUT_yubi_v5a(
		_______,	KC_HOME,	KC_PGDN,	KC_PGUP,	KC_END,	_______,					_______,	_______,	_______,	_______,	_______,	_______,
		KC_DEL,	KC_LEFT,	KC_DOWN,	KC_UP,	KC_RGHT,	KC_ENT,					_______,	_______,	_______,	_______,	_______,	_______,
		_______,	M_UNDO,	M_CUT,	M_COPY,	M_PASTE,	M_REDO,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		M_RDESC,			_______,			_______,	_______,	_______,	_______,	_______,	_______,			_______,			_______
	),

	[_NUMBER] = LAYOUT_yubi_v5a(
		KC_EQL,	KC_EXLM,	KC_AT,	KC_HASH,	KC_DLR,	KC_PERC,					KC_CIRC,	KC_AMPR,	KC_ASTR,	KC_LPRN,	KC_RPRN,	KC_UNDS,
		KC_LBRC,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,					KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	KC_RBRC,
		_______,	_______,	KC_LCBR,	KC_RCBR,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,			_______,			KC_EQL,	_______,	_______,	_______,	_______,	_______,			_______,			_______
	),

	[_QUANTUM] = LAYOUT_yubi_v5a(
		_______,	PD_QWTY,	_______,	_______,	_______,	_______,					_______,	_______,	_______,	_______,	_______,	DF_CLMK,
		_______,	_______,	_______,	_______,	_______,	_______,					_______,	_______,	_______,	_______,	_______,	DF_QWTY,
		_______,	_______,	_______,	PD_CLMK,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	DF_CMKD,
		EEP_RST,			_______,			RESET,	_______,	_______,	_______,	_______,	_______,			_______,			_______
	),

	[_BLANK] = LAYOUT_yubi_v5a(
		_______,	_______,	_______,	_______,	_______,	_______,					_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,					_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,			_______,			_______,	_______,	_______,	_______,	_______,	_______,			_______,			_______
	),

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY] =   { ENCODER_CCW_CW(M_PDSKT, M_NDSKT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_BLANK] = { ENCODER_CCW_CW(KC_UP, KC_DOWN),          ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
#endif

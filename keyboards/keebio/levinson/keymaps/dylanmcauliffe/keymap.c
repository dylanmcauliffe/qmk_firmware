#include QMK_KEYBOARD_H

enum layers {
	_COLEMAKDHm,
	_QWERTY,
	_GAMEPAD,
	_WEAPONS,
	_MEDIA,
	_FUNCTION,
	_NAVIGATION,
	_NUMBER,
	_QUANTUM,
};

#include "custom_keymaps.c"

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NM_SPC:
            return true;
        default:
            return false;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NM_BSPC:
        case NV_DEL:

        case NV_ENT:
        case NM_SPC:
        case FN_F2:

        case QT_P00:
            return true;
        default:
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return TAPPING_TERM;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_COLEMAKDHm] = LAYOUT_ortho_4x12 (
		KC_ESC,	KC_Q,	KC_W,	KC_F,	KC_P,	KC_B,	KC_J,	KC_L,	KC_U,	KC_Y,	KC_SCLN,	KC_BSLS,
		KC_TAB,	KC_A,	KC_R,	KC_S,	KC_T,	KC_G,	KC_M,	KC_N,	KC_E,	KC_I,	KC_O,	KC_QUOT,
		KC_LSFT,	KC_Z,	KC_X,	KC_C,	KC_D,	KC_V,	KC_K,	KC_H,	KC_COMM,	KC_DOT,	KC_SLSH,	KC_RSFT,
		KC_LCTL,	KC_LGUI,	M_RDESC,	KC_LALT,	NM_BSPC,	NV_DEL,	NV_ENT,	NM_SPC,	FN_F2,	KC_F16,	QT_P00,	KC_RGUI
	),

	[_QWERTY] = LAYOUT_ortho_4x12 (
		_______,	_______,	_______,	KC_E,	KC_R,	KC_T,	KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,	_______,
		_______,	_______,	KC_S,	KC_D,	KC_F,	_______,	KC_H,	KC_J,	KC_K,	KC_L,	KC_SCLN,	_______,
		_______,	_______,	_______,	_______,	KC_V,	KC_B,	KC_N,	KC_M,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______
	),
	
	[_GAMEPAD] = LAYOUT_ortho_4x12 (
		_______,	_______,	_______,	KC_E,	KC_R,	KC_T,	KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,	KC_BSPC,
		_______,	_______,	KC_S,	KC_D,	KC_F,	_______,	KC_H,	RC_J,	RS_K,	RA_L,	RG_SCLN,	_______,
		_______,	_______,	_______,	_______,	KC_V,	KC_B,	KC_N,	KC_M,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	KC_SPC,	WP_ONE,	_______,	_______,	_______,	_______,	_______,	_______
	),
	
	[_WEAPONS] = LAYOUT_ortho_4x12 (
		_______,	KC_7,	KC_8,	KC_9,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	KC_4,	KC_5,	KC_6,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	KC_1,	KC_2,	KC_3,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______
	),
	
	[_MEDIA] = LAYOUT_ortho_4x12 (
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______
	),
	
	[_FUNCTION] = LAYOUT_ortho_4x12 (
		_______,	KC_F9,	KC_F10,	KC_F11,	KC_F12,	_______,	KC_PAUS,	_______,	_______,	_______,	_______,	KC_NLCK,
		KC_CAPS,	KC_F5,	KC_F6,	KC_F7,	KC_F8,	_______,	KC_SLCK,	_______,	_______,	_______,	_______,	_______,
		_______,	KC_F1,	KC_F2,	KC_F3,	KC_F4,	_______,	KC_PSCR,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______
	),
	
	[_NAVIGATION] = LAYOUT_ortho_4x12 (
		_______,	KC_PGUP,	KC_HOME,	KC_UP,	KC_END,	KC_INS,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	KC_PGDN,	KC_LEFT,	KC_DOWN,	KC_RGHT,	KC_ENT,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	M_UNDO,	M_CUT,	M_COPY,	M_PASTE,	M_REDO,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______
	),
	
	[_NUMBER] = LAYOUT_ortho_4x12 (
		KC_EQL,	KC_EXLM,	KC_AT,	KC_HASH,	KC_DLR,	KC_PERC,	KC_CIRC,	KC_AMPR,	KC_ASTR,	KC_LPRN,	KC_RPRN,	KC_UNDS,
		KC_PLUS,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,	KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	KC_MINS,
		_______,	KC_BSLS,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	KC_GRV,	_______,	KC_LBRC,	KC_RBRC,	_______,	KC_TILD,	_______,	_______,	_______
	),
	
	[_QUANTUM] = LAYOUT_ortho_4x12 (
		RESET,	BL_QWTY,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	DF_CLMK,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	DF_QWTY,
		_______,	_______,	_______,	BL_CLMK,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	DF_GAME,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_MUTE,	_______,	_______
	),
};

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
	switch (get_highest_layer(layer_state)) {
		case _MEDIA:
		case _QUANTUM:
			if (index == 0) {
				if (clockwise) {
					tap_code16(M_NDSKT);
//					tap_code(KC_VOLU);
				} else {
					tap_code16(M_PDSKT);
//					tap_code(KC_VOLD);
				}
			} else if (index == 1) {
				if (clockwise) {
//					tap_code(KC_MNXT);
				} else {
//					tap_code(KC_MPRV);
				}
			}
			break;
		default:
			switch ( default_layer_state ) {
			case (uint16_t)pow( 2, _GAMEPAD):
				if (index == 0) {
					if (clockwise) {
						tap_code(KC_MS_WH_DOWN);
					} else {
						tap_code(KC_MS_WH_UP); 
					}
				}
				else if (index == 1) {
					if (clockwise) {
						tap_code(KC_MNXT);
					} else {
						tap_code(KC_MPRV);
					}
				}
				break;
			default:
				if (index == 0) {
					if (clockwise) {
						tap_code16(M_NDSKT);
					} else {
						tap_code16(M_PDSKT);
					}
				} else if (index == 1) {
					if (clockwise) {
						tap_code(KC_MS_WH_DOWN);
					} else {
						tap_code(KC_MS_WH_UP);
					}
				}
			}
		}
}
#endif

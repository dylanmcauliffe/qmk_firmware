#include QMK_KEYBOARD_H
#include "custom_keymaps.c"

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

enum custom_keycodes  {
	BL_CLMK = SAFE_RANGE,
	BL_QWTY,
	BL_GAME,
	KC_P00,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case BL_CLMK:
		  if (record->event.pressed) {
			set_single_persistent_default_layer(_COLEMAKDHm);
		  }
		  return false;
		  break;
		case BL_QWTY:
		  if (record->event.pressed) {
			set_single_persistent_default_layer(_QWERTY);
		  }
		  return false;
		  break;
		case BL_GAME:
		  if (record->event.pressed) {
			set_single_persistent_default_layer(_GAMEPAD);
		  }
		  return false;
		  break;
		case KC_P00:
		  if (record->event.pressed) {
			tap_code(KC_P0);
			tap_code(KC_P0);
		  }
			return false;
		break;
	}
	return true;
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NM_SPC:
        case NV_TAB:
        case FN_RGUI:
            return true;
        default:
            return false;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case FN_DEL:
        case NM_BSPC:
        case NV_TAB:
        case NV_ENT:
        case NM_SPC:
        case FN_RGUI:
            return true;
        default:
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LS_S:
            return TAPPING_TERM - 150;
        case LS_D:
        case RS_E:
        case RS_K:
            return 150;
        default:
            return TAPPING_TERM;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_COLEMAKDHm] = LAYOUT_ortho_4x12 (
		KC_Q,	KC_W,	KC_F,	KC_P,	KC_B,	DF_CLMK,	DF_CLMK,	KC_J,	KC_L,	KC_U,	KC_Y,	KC_SCLN,
		LG_A,	LA_R,	LS_S,	LC_T,	KC_G,	DF_QWTY,	DF_QWTY,	KC_M,	RC_N,	RS_E,	RA_I,	RG_O,
		KC_Z,	KC_X,	KC_C,	KC_D,	KC_V,	DF_GAME,	DF_GAME,	KC_K,	KC_H,	KC_COMM,	KC_DOT,	KC_SLSH,
		TT_MEDI,	MO_QUAN,	M_RDESC,	FN_DEL,	NM_BSPC,	NV_TAB,	NV_ENT,	NM_SPC,	FN_RGUI,	KC_F16,	MO_QUAN,	TT_MEDI
	),

	[_QWERTY] = LAYOUT_ortho_4x12 (
		_______,	_______,	KC_E,	KC_R,	KC_T,	_______,	_______,	KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,
		_______,	LA_S,	LS_D,	LC_F,	_______,	_______,	_______,	KC_H,	RC_J,	RS_K,	RA_L,	RG_SCLN,
		_______,	_______,	_______,	KC_V,	KC_B,	_______,	_______,	KC_N,	KC_M,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______
	),
	
	[_GAMEPAD] = LAYOUT_ortho_4x12 (
		KC_ESC,	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,	_______,	KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,
		KC_TAB,	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,	_______,	KC_H,	RC_J,	RS_K,	RA_L,	RG_SCLN,
		KC_LSFT,	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,	_______,	KC_N,	KC_M,	_______,	_______,	_______,
		ME_LALT,	KC_O,	KC_F16,	WP_ZERO,	KC_SPC,	KC_LCTL,	_______,	NM_BSPC,	_______,	KC_MPLY,	_______,	_______
	),
	
	[_WEAPONS] = LAYOUT_ortho_4x12 (
		KC_GRV,	KC_7,	KC_8,	KC_9,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		KC_EQL,	KC_4,	KC_5,	KC_6,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		KC_MINS,	KC_1,	KC_2,	KC_3,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		KC_0,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______
	),
	
	[_MEDIA] = LAYOUT_ortho_4x12 (
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	KC_MPLY,	_______,	_______,	_______,	_______,	_______,	_______,	KC_MUTE,	_______,	_______
	),
	
	[_FUNCTION] = LAYOUT_ortho_4x12 (
		KC_F9,	KC_F10,	KC_F11,	KC_F12,	KC_PSCR,	_______,	_______,	KC_SLCK,	_______,	_______,	_______,	_______,
		KC_F5,	KC_F6,	KC_F7,	KC_F8,	KC_CAPS,	_______,	_______,	KC_NLCK,	_______,	_______,	_______,	_______,
		KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_PAUS,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______
	),
	
	[_NAVIGATION] = LAYOUT_ortho_4x12 (
		KC_ESC,	KC_HOME,	KC_UP,	KC_END,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	KC_LEFT,	KC_DOWN,	KC_RGHT,	KC_ENT,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		M_UNDO,	M_CUT,	M_COPY,	M_PASTE,	M_REDO,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	KC_INS,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______
	),
	
	[_NUMBER] = LAYOUT_ortho_4x12 (
		KC_EXLM,	KC_AT,	KC_HASH,	KC_DLR,	KC_PERC,	_______,	_______,	KC_CIRC,	KC_AMPR,	KC_ASTR,	KC_LPRN,	KC_RPRN,
		LG_1,	LA_2,	LS_3,	LC_4,	KC_5,	_______,	_______,	KC_6,	RC_7,	RS_8,	RA_9,	RG_0,
		_______,	_______,	_______,	KC_LBRC,	KC_LCBR,	_______,	_______,	KC_RCBR,	KC_RBRC,	_______,	_______,	_______,
		_______,	_______,	_______,	KC_GRV,	KC_DQUO,	KC_EQL,	KC_MINS,	KC_QUOT,	KC_BSLS,	_______,	_______,	_______
	),
	
	[_QUANTUM] = LAYOUT_ortho_4x12 (
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	RESET,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	RESET,	_______
	),
};

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
	switch (get_highest_layer(layer_state)) {
		case _MEDIA:
			if (index == 0) {
				if (clockwise) {
					tap_code(KC_MNXT);
				} else {
					tap_code(KC_MPRV);
				}
			} else if (index == 1) {
				if (clockwise) {
					tap_code(KC_VOLU);
				} else {
					tap_code(KC_VOLD);
				}
			}
			break;
		default:
			switch ( default_layer_state ) {
			case (uint16_t)pow( 2, _GAMEPAD):
				if (index == 0) {
					if (clockwise) {
						tap_code(KC_VOLU);
					} else {
						tap_code(KC_VOLD); 
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
						tap_code(KC_VOLU);
					} else {
						tap_code(KC_VOLD);
					}
				}
			}
		}
}
#endif

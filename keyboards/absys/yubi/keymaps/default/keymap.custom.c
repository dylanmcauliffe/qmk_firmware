// Layer Triggers
//#define DF_CLMK	DF(_COLEMAKDHm)	// Default Layer: Colemak DHm
#define DF_CMKD	DF(_COLEMAKdm)		// Default Layer: Colemak Custom
#define DF_QWTY	DF(_QWERTY)		// Default Layer: QWERTY
#define DF_GAME	DF(_GAME)			// Default Layer: Game

#define FN_F16		LT(_FUNCTION,KC_F16)

#define NV_BSPC	LT(_NAVIGATION,KC_BSPC)

#define NM_SPC		LT(_NUMBER,KC_SPC)

#define QT_RGUI	LT(_QUANTUM,KC_RGUI)
#define QT_F16		LT(_QUANTUM,KC_F16)
#define QT_P00		LT(_QUANTUM,KC_P00)

// Macro Shortcuts
#define M_RDESC	LCA(KC_HOME)		// CTRL + ALT + HOME: RDP Escape Sequence
#define M_NDSKT	G(C(KC_RGHT))		// GUI + CTRL + RIGHT: Next Desktop
#define M_PDSKT	G(C(KC_LEFT))		// GUI + CTRL + Left: Prev Desktop

#define M_UNDO		LCTL(KC_Z)
#define M_CUT		LCTL(KC_X)
#define M_COPY		LCTL(KC_C)
#define M_PASTE	LCTL(KC_V)
#define M_REDO		LCTL(KC_Y)

// Mod Keys

#define LS_F8		LSFT_T(KC_F8)
#define RS_F5		RSFT_T(KC_F5)

#define LA_CAPWD	LALT_T(KC_CAPWD)

#define LC_DEL		LCTL_T(KC_DEL)
#define RC_ENT		RCTL_T(KC_ENT)

// Custom Keycodes
enum custom_keycodes {
	PD_CLMD = SAFE_RANGE,	// Persistant Default Layer: Colemak DHm
	PD_QWTY,				// Persistant Default Layer: QWERTY
	KC_P00,				// Numpad 00
	KC_CAPWD,				// Caps Word On
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case PD_CLMD:
			if (record->event.pressed) {
				set_single_persistent_default_layer(_COLEMAKdm);
			}
			return false;
		break;

		case PD_QWTY:
			if (record->event.pressed) {
				set_single_persistent_default_layer(_QWERTY);
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
/*
		case LALT_T(KC_PLUS):
			if (record->tap.count && record->event.pressed) {
				 tap_code16(KC_PLUS); // Send KC_PLUS on tap
			 return false;        // Return false to ignore further processing of key
			}
		break;
*/
		case KC_CAPWD:
			if (record->event.pressed) {
				caps_word_on();
			 return false;
			}
		break;

		case LALT_T(KC_CAPWD):
			if (record->tap.count && record->event.pressed) {
				 caps_word_on(); // Send KC_DQUO on tap
			 return false;        // Return false to ignore further processing of key
			}
		break;
/*
		case QT_CAPWD:
			if (record->tap.count && record->event.pressed) {
				tap_code16(KC_CAPWD);
			}
			else if (record->event.pressed) {
				layer_on(_QUANTUM);
			}
			else if (record->tap.count) {
			}
			else {
				layer_off(_QUANTUM);
			}
			return false;
		break;
*/
		case QT_P00:
			if (record->tap.count && record->event.pressed) {
				tap_code(KC_P0);
				tap_code(KC_P0);
			}
			else if (record->event.pressed) {
				layer_on(_QUANTUM);
			}
			else if (record->tap.count) {
			}
			else {
				layer_off(_QUANTUM);
			}
			return false;
		break;
	}
	return true;
}

// Behavior Modification

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
        case KC_QUOT:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case LS_F8:
		case RS_F5:

		case LA_CAPWD:
		case NV_BSPC:
		case LC_DEL:

		case RC_ENT:
		case NM_SPC:
		case FN_F16:

		case QT_RGUI:
			return true;
		default:
			return false;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case LC_DEL:
		
		case RC_ENT:
		case NM_SPC:
			return true;
		default:
			return false;
	}
}
/*
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
	    case false:
		return TAPPING_TERM + 150;
        default:
            return TAPPING_TERM;
    }
}
*/
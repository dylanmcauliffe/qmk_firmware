// layer triggers

#define PD_CLMK	PDF( _COLEMAK )		// Default Layer: Colemak Custom
#define DF_CLMK	DF( _COLEMAK )			// Default Layer: Colemak Custom
#define PD_QWTY	PDF( _QWERTY )			// Default Layer: QWERTY
#define DF_QWTY	DF( _QWERTY )			// Default Layer: QWERTY

#define FN_F8		LT( _FUNCTION,KC_F8 )
#define FN_F16		LT( _FUNCTION,KC_F16 )

#define NV_BSPC	LT( _NAVIGATION,KC_BSPC )

#define NM_SPC		LT( _NUMBER,KC_SPC )

#define QT_F16		LT( _QUANTUM,KC_F16 )
#define TG_QNTM	TG( _QUANTUM )



// macros

#define M_TSKMGR	LCTL( LSFT( KC_ESC ) )	// Control + Shift + Escape: Open Task Manager
//#define M_RDESC	LCTL( LALT( KC_HOME ) )

#define M_UNDO		LCTL( KC_Z )
#define M_CUT		LCTL( KC_X )
#define M_COPY		LCTL( KC_C )
#define M_PASTE	LCTL( KC_V )
#define M_REDO		LCTL( KC_Y )

#define M_NAVL		LGUI( KC_LEFT )		// Niri Navigation
#define M_NAVD		LGUI( KC_DOWN )		// Niri Navigation
#define M_NAVU		LGUI( KC_UP )			// Niri Navigation
#define M_NAVR		LGUI( KC_RGHT )		// Niri Navigation

#define M_MOVL		LGUI( LSFT( KC_LEFT ) )	// Niri Navigation
#define M_MOVD		LGUI( LSFT( KC_DOWN ) )	// Niri Navigation
#define M_MOVU		LGUI( LSFT( KC_UP ) )	// Niri Navigation
#define M_MOVR		LGUI( LSFT( KC_RGHT ) )	// Niri Navigation



// mod tap keys

#define LC_MINS	LCTL_T( KC_MINS )
#define LC_UNDS 	LCTL_T( KC_UNDS )

#define LA_CAPS	LALT_T( KC_CAPS )
#define LA_TAB		LALT_T( KC_TAB )

#define LS_DEL		LSFT_T( KC_DEL )
#define LS_INS		LSFT_T( KC_INS )
#define RS_ENT		RSFT_T( KC_ENT )

#define RG_APP		RGUI_T( KC_APP )

#define RA_QUOT	RALT_T( KC_QUOT )
#define RA_DQUO	RALT_T( KC_DQUO )
#define RA_SCRL	RALT_T( KC_SCRL )

#define RC_EQL		RCTL_T( KC_EQL )
#define RC_PLUS	RCTL_T( KC_PLUS )
#define RC_PSCR	RCTL_T( KC_PSCR )



// combos

enum combos {
	C_TASK_MANAGER,	// M_TSKMGR
	C_OSL_QUANTUM,
	C_TG_QUANTUM,
};

const uint16_t PROGMEM combo_esc_1[]		= { KC_ESC, KC_1, COMBO_END };
const uint16_t PROGMEM combo_mins_eql[]		= { LC_MINS, RC_EQL, COMBO_END };

combo_t key_combos[] = {
	[C_TASK_MANAGER]	= COMBO( combo_esc_1, M_TSKMGR ),
//	[C_OSL_QUANTUM]	= COMBO( combo_mins_eql, OSL( _QUANTUM ) ),
	[C_TG_QUANTUM]		= COMBO( combo_mins_eql, TG( _QUANTUM ) ),
};




// custom keycodes

enum custom_keycodes {
	KC_P00 = SAFE_RANGE,	// Numpad 00
	M_RDESC,				// Control + Alt + Home: Escape RDP
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//	if (!process_custom_shift_keys(keycode, record)) { return false; }

	switch ( keycode ) {
		case KC_P00:
			if ( record->event.pressed ) {
				tap_code( KC_P0 );
				tap_code( KC_P0 );
			}
			return false;	// Return false to ignore further processing of key
		break;

		case M_RDESC:
			if (record->event.pressed) {
				register_code(KC_LCTL);
				SEND_STRING(SS_DELAY(10));
				register_code(KC_LALT);
				SEND_STRING(SS_DELAY(10));
				register_code(KC_HOME);
				SEND_STRING(SS_DELAY(10));
			} else {
				unregister_code(KC_HOME);
				SEND_STRING(SS_DELAY(10));
				unregister_code(KC_LALT);
				SEND_STRING(SS_DELAY(10));
				unregister_code(KC_LCTL);
			}
			return false;
		break;
	}

	return true;
}



// behavior modification

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
		case KC_DQUO:
		case KC_GRV:
		case KC_TILD:
			return true;

		default:
			return false;  // Deactivate Caps Word.
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
	// If set to 0, it will remove the auto-repeat ability and activate the hold function instead
    switch (keycode) {
		case RS_ENT:
		case NM_SPC:
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
            // Immediately select the hold action when another key is pressed.
	   case LS_DEL:
        case RS_ENT:
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

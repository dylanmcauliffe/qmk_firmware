// Layer Triggers
#define DF_CLMK	DF(_COLEMAKDHm)
#define DF_CMKD	DF(_COLEMAKdm)
#define DF_QWTY	DF(_QWERTY)
#define DF_GAME	DF(_GAME)

#define QT_P00		LT(_QUANTUM,KC_P00)
#define QT_CAPS	LT(_QUANTUM,KC_CAPS)
#define QT_MINS	LT(_QUANTUM,KC_MINS)
#define QT_MNXT	LT(_QUANTUM,KC_MNXT)

#define NM_BSPC	LT(_NUMBER,KC_BSPC)
#define NV_DEL		LT(_NAVIGATION,KC_DEL)

#define FN_ENT		LT(_FUNCTION,KC_ENT)
#define NM_SPC		LT(_NUMBER,KC_SPC)

// Macro Shortcuts
#define M_RDESC	LCA(KC_HOME)
#define M_NDSKT	G(C(KC_RGHT))
#define M_PDSKT	G(C(KC_LEFT))

#define M_NTAB		LCTL(KC_T)

#define M_UNDO		LCTL(KC_Z)
#define M_CUT		LCTL(KC_X)
#define M_COPY		LCTL(KC_C)
#define M_PASTE	LCTL(KC_V)
#define M_REDO		LCTL(KC_Y)

// Mod Keys
#define LS_RBRC	LSFT_T(KC_RBRC)

#define LA_F16		LALT_T(KC_F16)
#define LA_PLUS	LALT_T(KC_PLUS)
#define LA_MPRV	LALT_T(KC_MPRV)

#define RS_LBRC	RSFT_T(KC_LBRC)

#define RG_F5		RGUI_T(KC_F5)
#define RG_MINS	RGUI_T(KC_MINS)
#define LG_PLUS	LGUI_T(KC_PLUS)
#define LG_F8		LGUI_T(KC_F8)

#define LC_LGUI	LCTL_T(KC_LGUI)
#define RC_RGUI	RCTL_T(KC_RGUI)

enum custom_keycodes {
	BL_CLMK = SAFE_RANGE,
	BL_QWTY,
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

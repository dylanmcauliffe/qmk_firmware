// Number Home Row Mods
#define LG_1		LGUI_T(KC_1)
#define LA_2		LALT_T(KC_2)
#define LS_3		LSFT_T(KC_3)
#define LC_4		LCTL_T(KC_4)

#define RC_7		RCTL_T(KC_7)
#define RS_8		RSFT_T(KC_8)
#define RA_9		RALT_T(KC_9)
#define RG_0		RGUI_T(KC_0)

// Colemak Home Row Mods
#define LG_A		LGUI_T(KC_A)
#define LA_R		LALT_T(KC_R)
#define LS_S		LSFT_T(KC_S)
#define LC_T		LCTL_T(KC_T)

#define RC_N		RCTL_T(KC_N)
#define RS_E		RSFT_T(KC_E)
#define RA_I		RALT_T(KC_I)
#define RG_O		RGUI_T(KC_O)

// QWERTY Home Row Mods
#define LA_S		LALT_T(KC_S)
#define LS_D		LSFT_T(KC_D)
#define LC_F		LCTL_T(KC_F)

#define RC_J		RCTL_T(KC_J)
#define RS_K		RSFT_T(KC_K)
#define RA_L		RALT_T(KC_L)
#define RG_SCLN	RGUI_T(KC_SCLN)

// Layer Triggers
#define DF_CLMK	DF(_COLEMAKDHm)
#define DF_GAME	DF(_GAMEPAD)
#define DF_QWTY	DF(_QWERTY)

#define TG_QUAN	TG(_QUANTUM)
#define TG_MEDI	TG(_MEDIA)
#define MO_QUAN	MO(_QUANTUM)

#define ME_DEL		LT(_MEDIA,KC_DEL)
#define ME_RGUI	LT(_MEDIA,KC_RGUI)

#define FN_ESC		LT(_FUNCTION,KC_ESC)
#define NM_SPC		LT(_NUMBER, KC_SPC)
#define NV_TAB		LT(_NAVIGATION,KC_TAB)

#define NV_ENT		LT(_NAVIGATION,KC_ENT)
#define NM_BSPC	LT(_NUMBER, KC_BSPC)
#define FN_DEL		LT(_FUNCTION,KC_DEL)

// Macro Shortcuts
#define M_RDESC	LCA(KC_HOME)
#define M_NDSKT	G(C(KC_RGHT))
#define M_PDSKT	G(C(KC_LEFT))

#define M_UNDO		LCTL(KC_Z)
#define M_CUT		LCTL(KC_X)
#define M_COPY		LCTL(KC_C)
#define M_PASTE	LCTL(KC_V)
#define M_REDO		LCTL(KC_Y)

enum custom_keycodes {
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

// Layer Triggers
#define DF_CLMK	DF(_COLEMAKDHm)
#define DF_QWTY	DF(_QWERTY)
#define DF_GAME	DF(_GAMEPAD)

#define WP_ZERO	LT(_WEAPONS,KC_0)
#define WP_ONE		LT(_WEAPONS,KC_1)

#define NM_BSPC	LT(_NUMBER,KC_BSPC)
#define NV_DEL		LT(_NAVIGATION,KC_DEL)

#define NV_ENT		LT(_NAVIGATION,KC_ENT)
#define NM_SPC		LT(_NUMBER,KC_SPC)
#define FN_F2		LT(_FUNCTION,KC_F2)

#define QT_P00		LT(_QUANTUM,KC_P00)

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

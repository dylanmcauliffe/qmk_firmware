// macros

#define M_TSKMGR	LCTL(LSFT(KC_ESC)) // Control + Shift + Escape: Open Task Manager

// combos
enum combos {
	C_TSKMGR, // M_TSKMGR
};

const uint16_t PROGMEM combo_esc_1[] = { KC_ESC, KC_1, COMBO_END };

combo_t key_combos[] = {
	[C_TSKMGR] = COMBO( combo_esc_1, M_TSKMGR ),
};

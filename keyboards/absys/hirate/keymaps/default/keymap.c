#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_hirate_v1a(
		KC_P7,	KC_P8,	KC_P9,	KC_PSLS,	KC_P8,	KC_P9,	KC_PSLS,
		KC_P7,	KC_P8,	KC_P9,	KC_PSLS,	KC_P8,	KC_P9,	KC_PSLS,
		KC_P7,	KC_P8,	KC_P9,	KC_PSLS,	KC_P8,	KC_P9,	KC_PSLS,
		KC_P7,	KC_P8,	KC_P9,	KC_PSLS,	KC_P8,	KC_P9,	KC_PSLS,
						KC_P9,			KC_P8,	KC_P9,	KC_PSLS
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
	[0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
};
#endif

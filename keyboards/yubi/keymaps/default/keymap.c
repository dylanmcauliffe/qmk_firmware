#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │ K │ L │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │ K │ L │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │ K │ L │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │ K │ L │
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
    [0] = LAYOUT_yubi(
		KC_TAB,	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,					KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,	KC_BSLS,
		KC_CAPS,	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,					KC_H,	KC_J,	KC_K,	KC_L,	KC_SCLN,	KC_QUOT,
		KC_LSFT,	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,	KC_0,	KC_1,	KC_N,	KC_M,	KC_COMM,	KC_DOT,	KC_SLSH,	KC_RSFT,
		KC_LCTL,			KC_LGUI,			KC_LALT,	KC_BSPC,	KC_PLUS,	KC_UNDS,	KC_SPC,	KC_RALT,			KC_RGUI,			KC_RCTL
    )
};

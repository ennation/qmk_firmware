#include QMK_KEYBOARD_H

// Custom Macros
enum custom_keycodes {
    PRNTLN = SAFE_RANGE,
    PRNT
};
// More necessities for custom macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case PRNTLN:
        if (record->event.pressed) {
            // when keycode is pressed
            SEND_STRING("System.out.println(  );" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) );
        } else {
            // when keycode is released
        }
        break;
    case PRNT:
        if (record->event.pressed) {
            // when keycode is pressed
            SEND_STRING("System.out.print(  );" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) );
        } else {
            // when keycode is released
        }
        break;
    }
    return true;
};

// KEYMAPS
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Default Qwerty (Mac Default, Switch Alt/GUI in Config Layer)
   * ,-----------------------------------------------------------------------------------------.
   * | ESC |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  | Backspace |
   * |-----------------------------------------------------------------------------------------+
   * |  Tab   |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
   * |-----------------------------------------------------------------------------------------+
   * |  MO(14) |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
   * |-----------------------------------------------------------------------------------------+
   * |   Shift   |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |      Shift      |
   * |-----------------------------------------------------------------------------------------+
   * | Ctrl  |  ALT  |  GUI  |              Space              | Left  |  GUI  | Right |MO(14) |
   * `-----------------------------------------------------------------------------------------'
   */
    [0] = LAYOUT_60_ansi(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
        LT(14, KC_GRV), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_LEFT, KC_RGUI, KC_RGHT, MO(14)),

/* Gaming (Mac Default, Switch Alt/GUI in Config Layer)
Only difference is persistent arrow keys, and caps lock, for those games that use it
   * ,-----------------------------------------------------------------------------------------.
   * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  | Backspace |
   * |-----------------------------------------------------------------------------------------+
   * |  Tab   |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
   * |-----------------------------------------------------------------------------------------+
   * |  Caps   |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
   * |-----------------------------------------------------------------------------------------+
   * |   Shift   |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  | Up  |      Shift      |
   * |-----------------------------------------------------------------------------------------+
   * | Ctrl  |  ALT  |  GUI  |              Space                | Left | Down | Right |MO(14) |
   * `-----------------------------------------------------------------------------------------'
   */
    [1] = LAYOUT_60_ansi(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, KC_RSFT,
        KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_LEFT, KC_DOWN, KC_RGHT, MO(14)),

// Layers 2–13 are unused at the moment

/* Function
   * ,-----------------------------------------------------------------------------------------.
   * |  `  | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |    Del    |
   * |-----------------------------------------------------------------------------------------+
   * |  Caps  |     | Up  |     |     |     |     |     |PrevT|NextT|Pause|VolDn|VolUp| LT(15) |
   * |-----------------------------------------------------------------------------------------+
   * |    \/   |Left |Down |Right|     |     |     |     |     |     |     |     |   PRINTLN   |
   * |-----------------------------------------------------------------------------------------+
   * |     \/    |     |     |     |     |BrtDn|BrtUp|     |     |     | Up  |       \/        |
   * |-----------------------------------------------------------------------------------------+
   * |  \/   |  \/   |  \/   |                                 |  Right | Down  | Left |  \/   |
   * `-----------------------------------------------------------------------------------------'
   */
    [14] = LAYOUT_60_ansi(
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
        KC_CAPS, KC_NO, KC_UP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MRWD, KC_MFFD, KC_MPLY, KC_VOLD, KC_VOLU, TG(15),
        KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, PRNT, PRNTLN,
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_BRID, KC_BRIU, KC_NO, KC_NO, KC_NO, KC_UP, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS),

/* Config and Layer Launcher
Use Layer 1 to get back to 15 (launcher) to return from "permanent" layers
   * ,-----------------------------------------------------------------------------------------.
   * |TO(0)|TO(1)|TO(2)|TO(3)|TO(4)|TO(5)|TO(6)|TO(7)|TO(8)|TO(9)|T(10)|T(11)|T(12)|   Reset   |
   * |-----------------------------------------------------------------------------------------+
   * |        |Plain|Brthe|Rnbow|Swirl|Gradi|Snake|KnRid|X-mas|     |     |     |     |        |
   * |-----------------------------------------------------------------------------------------+
   * |         |RGBDn|RGBUp|HueDn|HueUp|SatDn|SatUp|SpdDn|SpdUp|     |     |     |             |
   * |-----------------------------------------------------------------------------------------+
   * |           |     |     |     |     |     |NKRO |     |     |     |     |                 |
   * |-----------------------------------------------------------------------------------------+
   * |       |AG Norm|GUI On |                                 |GUI Off|AG SWAP|       |  \/   |
   * `-----------------------------------------------------------------------------------------'
   */
    [15] = LAYOUT_60_ansi(
        // Set TO(x) to respective layer as they are added. All set to highest non-momentary layer by default to prevent firmware crashes if pressed
        TO(0), TO(1), TO(1), TO(1), TO(1), TO(1), TO(1), TO(1), TO(1), TO(1), TO(1), TO(1), TO(14), RESET,
        KC_NO, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_G, RGB_M_SN, RGB_M_K, RGB_M_X, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
        KC_NO, RGB_VAD, RGB_VAI, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_SPD, RGB_SPI, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, NK_TOGG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, AG_NORM, GUI_ON, KC_NO, GUI_OFF, AG_SWAP, KC_NO, KC_TRNS),
};

// Necessary for modal RGB underglow
void matrix_init_user(void) {
    rgblight_enable();
}

// Custom function for modal RGB underglow ()
void matrix_scan_user(void) {
    #ifdef RGBLIGHT_ENABLE

    static uint8_t old_layer = 255;
    uint8_t new_layer = biton32(layer_state);

    if (old_layer != new_layer) {
        switch (new_layer) {
            // Now using HSV instead of RGB, to enable onboard brightness control
            case 0:
                // Set to full-spectrum RGB Twinkle for layer 0 (Default Layer)
                rgblight_mode(RGBLIGHT_MODE_TWINKLE + 1);
                rgblight_sethsv(128, 255, rgblight_get_val());
                break;
            case 1:
                // Set to Blue for layer 1 (Gaming Layer)
                rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
                // rgblight_setrgb(RGB_BLUE);
                rgblight_sethsv(176, 255, rgblight_get_val());
                break;
            case 14:
                // Set to Turqoise for layer 14 (Function Layer)
                rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
                // rgblight_setrgb(0x00, 0xA0, 0xFF);
                rgblight_sethsv(128, 255, rgblight_get_val());
                break;
            case 15:
                // Set to Magenta Snake Mode for layer 15 (Config Mode)
                rgblight_mode(RGBLIGHT_MODE_SNAKE + 2);
                // rgblight_setrgb(0xFF, 0x00, 0xFF);
                rgblight_sethsv(223, 255, rgblight_get_val());
                break;
            default:
                // Set to Purple for any other layers
                rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
                rgblight_sethsv(192, 255, rgblight_get_val());
                break;
        }
        old_layer = new_layer;
    }
    #endif //RGBLIGHT_ENABLE
}

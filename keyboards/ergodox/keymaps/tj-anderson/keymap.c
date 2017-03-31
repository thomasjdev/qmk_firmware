#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define CNTL 2 // control layer
#define MOVE 3 // mouse layer

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ~    |   1  |   2  |   3  |   4  |   5  |  MEH |           |   -  |   6  |   7  |   8  |   9  |   0  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  [   |           | ]    |  Y   |   U  |   I  |   O  |   P  | \ / L1 |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Esc   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;   | ' / L2 |
 * |--------+------+------+------+------+------|  {   |           | }    |------+------+------+------+------+--------|
 * | Shift  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |  Shift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCtl | LAlt | LGui | ShGu | AlGu |                                       | AlGu | ShGu | RGui | RAlt | L3/Ctl |
 *   `----------------------------------'                                       `----------------------------------'
 *                                         ,-------------.       ,-------------.
 *                                         |  (   | Lead |       |  L1  |   )  |
 *                                 ,-------|------|------|       |------+--------+------.
 *                                 |       |      |ShfGui|       |AltGui|       |       |
 *                                 | BkSpc |  Del |------|       |------| Enter | Space |
 *                                 |       |      |CmdSpc|       |CmdSpc|       |       |
 *                                 `--------------------'       `-----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV,   KC_1,          KC_2,    KC_3,    KC_4,    KC_5,   KC_MEH,
        KC_TAB,          KC_Q,          KC_W,    KC_E,    KC_R,    KC_T,   KC_LBRC,
        KC_ESC,          KC_A,          KC_S,    KC_D,    KC_F,    KC_G,
        KC_LSFT,         KC_Z,          KC_X,    KC_C,    KC_V,    KC_B,   KC_LCBR,
        KC_LCTL,         KC_LALT,       KC_LGUI, LSFT(KC_LGUI), LALT(KC_LGUI),
                                                                       KC_LPRN,   KC_LEAD,
                                                                             LSFT(KC_LGUI),
                                                           KC_BSPC, KC_DELT,  LGUI(KC_SPC),
        // right hand
       KC_MINS,        KC_6,    KC_7,     KC_8,     KC_9,      KC_0,             KC_EQL,
       KC_RBRC,        KC_Y,    KC_U,     KC_I,     KC_O,      KC_P,             LT(SYMB,KC_BSLS),
                       KC_H,    KC_J,     KC_K,     KC_L,      KC_SCLN,          LT(CNTL,KC_QUOT),
       KC_RCBR,        KC_N,    KC_M,     KC_COMM,  KC_DOT,    KC_SLSH,          KC_RSFT,
                                LALT(KC_LGUI), LSFT(KC_LGUI),  KC_RGUI,  KC_RALT,          LT(MOVE,KC_RCTL),
       KC_FN1,    KC_RPRN,
       LALT(KC_LGUI),
       LGUI(KC_SPC), KC_ENT, KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  | F6   |           |  F7  |  F8  |  F9  | F10  | F11  |  F12 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      | F14  |           |  F15 |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |       |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       _______,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,
       _______,_______,_______,  _______,_______,_______,KC_F14,
       _______,_______,_______, _______,_______,_______,
       _______,_______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,_______,
                                       _______,_______,
                                               _______,
                               _______,_______,_______,
       // right hand
       KC_F6,    KC_F7,   KC_F8,     KC_F9,     KC_F10,     KC_F11,     KC_F12,
       KC_F15,    _______, _______,   _______,    _______,   _______,    _______,
                   _______, _______,     _______,   _______,    _______,    _______,
       _______,    _______, _______,   _______,   _______,   _______,    _______,
                            _______,   _______,  _______,    _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),

/* Keymap 2: Control Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           | Mute |      |      |      | Prev | Next |  Play  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | CmdQ | CmdW |      |      | CmdT |      |           | VolUp|      |      |      |      | PrtSc|        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  CmdA| CmdS |      |CmAltF|      |------|           |------|  Left| Down |  Up  | Right|      |        |
 * |--------+------+------+------+------+------|      |           | VolDn|------+------+------+------+------+--------|
 * |        | CmdZ | CmdX | CmdC | CmdV |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | PgDn | PgUp |       | Home | End  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Control
[CNTL] = KEYMAP(
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       _______, LGUI(KC_Q), LGUI(KC_W), KC_TRNS, KC_TRNS, LGUI(KC_T), XXXXXXX,
       _______, LGUI(KC_A), LGUI(KC_S), KC_TRNS, LGUI(LALT(KC_F)), XXXXXXX,
       _______, LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), XXXXXXX, XXXXXXX,
       _______, _______, _______, _______, _______,
                                           KC_PGDN, KC_PGUP,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       KC_MUTE,  XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV,      KC_MNXT, KC_MPLY,
       KC_VOLU,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, _______,
                 KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,     XXXXXXX, _______,
       KC_VOLD,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, _______,
                          _______,  _______, _______,     _______, _______,
       KC_HOME, KC_END,
       _______,
       _______, _______, _______
),
/* Keymap 3: Mouse Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght| Lclk |------|           |------|  Left| Down |  Up  | Right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |MsDown|      | Rclk |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Mouse
[MOVE] = KEYMAP(
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       _______, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX,
       _______, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1,
       _______, XXXXXXX, XXXXXXX, KC_MS_D, XXXXXXX, KC_BTN2, XXXXXXX,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX,
       XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                 KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,     XXXXXXX, _______,
       XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, _______,
                          _______,  _______, _______,     _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),

};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB),
    [2] = ACTION_LAYER_TAP_TOGGLE(CNTL)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

LEADER_EXTERNS();
// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_2_on();
            break;
        case 2:
            ergodox_right_led_3_on();
            break;
        case 3:
          ergodox_right_led_1_on();
          break;
        case 4:
          ergodox_right_led_1_on();
          ergodox_right_led_2_on();
          ergodox_right_led_3_on();
          break;
        default:
            // none
            break;
    }

  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_LBRC) {
      register_code(KC_LSFT);
      register_code(KC_LGUI);
      register_code(KC_3);
      unregister_code(KC_LSFT);
      unregister_code(KC_LGUI);
      unregister_code(KC_3);
    }

    SEQ_ONE_KEY(KC_LCBR) {
      register_code(KC_LSFT);
      register_code(KC_LGUI);
      register_code(KC_4);
      unregister_code(KC_LSFT);
      unregister_code(KC_LGUI);
      unregister_code(KC_4);
    }

    SEQ_TWO_KEYS(KC_D, KC_D) {
      register_code(KC_LGUI);
      register_code(KC_BSPC);
      unregister_code(KC_LGUI);
      unregister_code(KC_BSPC);
    }

  }

};

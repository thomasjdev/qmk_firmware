#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define CNTL 2 // control layer
#define MOVE 3 // mouse layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | HYP/~  |   1  |   2  |   3  |   4  |   5  |  HYP |           |   -  |   6  |   7  |   8  |   9  |   0  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  [   |           | ]    |  Y   |   U  |   I  |   O  |   P  | \      |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctl/Esc|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;   | ' / L1 |
 * |--------+------+------+------+------+------|  {   |           | }    |------+------+------+------+------+--------|
 * | Shift  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |  Shift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | PgDn | PgUp | LCtl | LAlt | LGui |                                       |  L2  | Hyp  |  _   | Home | L3/End |
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
        ALL_T(KC_GRV),   KC_1,          KC_2,    KC_3,    KC_4,    KC_5,   KC_HYPR,
        KC_TAB,          KC_Q,          KC_W,    KC_E,    KC_R,    KC_T,   KC_LBRC,
        CTL_T(KC_ESC),   KC_A,          KC_S,    KC_D,    KC_F,    KC_G,
        KC_LSFT,         KC_Z,          KC_X,    KC_C,    KC_V,    KC_B,   KC_LCBR,
        KC_PGDN,         KC_PGUP,       KC_LCTL, KC_LALT, KC_LGUI,
                                                                       KC_LPRN,   KC_LEAD,
                                                                             LSFT(KC_LGUI),
                                                           KC_BSPC, KC_DELT,  LGUI(KC_SPC),
        // right hand
       KC_MINS,        KC_6,    KC_7,     KC_8,     KC_9,      KC_0,             KC_EQL,
       KC_RBRC,        KC_Y,    KC_U,     KC_I,     KC_O,      KC_P,             KC_BSLS,
                       KC_H,    KC_J,     KC_K,     KC_L,      KC_SCLN,          LT(SYMB,KC_QUOT),
       KC_RCBR,        KC_N,    KC_M,     KC_COMM,  KC_DOT,    KC_SLSH,          KC_RSFT,
                                OSL(CNTL), KC_HYPR,  KC_UNDS,  KC_HOME,          LT(MOVE,KC_END),
       KC_FN1,    KC_RPRN,
       LALT(KC_LGUI),
       LGUI(KC_SPC), KC_ENT, KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      | F14  |  F15 |      |           |      |  +   |  -   |  =   |   ~  |   _  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   1  |   2  |   3  |   4  |   5  |------|           |------|   !  |   @  |   #  |   $  |   %  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   6  |   7  |   8  |   9  |   0  |      |           |      |   ^  |   &  |   *  |   (  |   )  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   <  |   >  |   /  |  ?   |       |
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
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,  KC_TRNS,KC_F14,KC_F15,KC_TRNS,
       KC_TRNS,KC_1,KC_2, KC_3,KC_4,KC_5,
       KC_TRNS,KC_6,KC_7,KC_8,KC_9,KC_0,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS,    KC_F6,   KC_F7,     KC_F8,     KC_F9,     KC_F10,     KC_F11,
       KC_TRNS,    KC_PLUS, KC_MINS,   KC_EQL,    KC_TILD,   KC_UNDS,    KC_F12,
                   KC_EXLM, KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,    KC_TRNS,
       KC_TRNS,    KC_CIRC, KC_AMPR,   KC_ASTR,   KC_LPRN,   KC_RPRN,    KC_TRNS,
                            KC_LABK,   KC_RABK,  KC_SLSH,    S(KC_SLSH), KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 2: Control Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           | Mute |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | CmdQ | CmdW |      |      | CmdT |      |           | VolUp|      |      |      |      | PrtSc| Play   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  CmdA| CmdS |      |CmAltF|      |------|           |------|  Left| Down |  Up  | Right|      | Prev   |
 * |--------+------+------+------+------+------|      |           | VolDn|------+------+------+------+------+--------|
 * |        | CmdZ | CmdX | CmdC | CmdV |      |      |           |      |      |      |      |      |      | Next   |
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
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LGUI(LSFT(KC_3)),
       KC_TRNS, LGUI(KC_Q), LGUI(KC_W), KC_TRNS, KC_TRNS, LGUI(KC_T), KC_TRNS,
       KC_TRNS, LGUI(KC_A), LGUI(KC_S), KC_TRNS, LGUI(LALT(KC_F)), KC_TRNS,
       KC_TRNS, LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_PGDN, KC_PGUP,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_MUTE,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS,
       KC_VOLU,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_MPLY,
                 KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,     KC_TRNS, KC_MPRV,
       KC_VOLD,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_MNXT,
                          KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
       KC_HOME, KC_END,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
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
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_D, KC_TRNS, KC_BTN2, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,     KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS,
                          KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
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

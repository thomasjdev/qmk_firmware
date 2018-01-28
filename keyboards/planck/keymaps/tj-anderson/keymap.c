// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _HYP,
  _LOWER,
  _RAISE,
  _CUSTOM,
  _NUMPAD,
  _ADJUST
};

#define HYP_ESC LT(_HYP, KC_ESC)
#define CUST_TAB LT(_CUSTOM, KC_TAB)
#define CUST_LCAG LCTL(LALT(KC_LGUI))

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  HYP,
  LOWER,
  RAISE,
  CUSTOM,
  NUMPAD,
  BACKLIT
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,--------------------------------------------------------------------------------------.
 * |     Tab |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |---------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc     |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |---------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift   |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |---------+------+------+------+------+------+------+------+------+------+------+------|
 * | CmdSp   | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Num | Cmd` | hypr |Cmdsp |
 * `--------------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {CUST_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS},
  {HYP_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {LGUI(KC_SPC), KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_BSPC,  KC_SPC,  RAISE,   NUMPAD, KC_HYPR, LGUI(KC_GRV),   LGUI(KC_SPC)}
},

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CmdSp| Ctrl | Alt  | GUI  |Lower |    Space    |Raise |Custm | Cmd` | hypr |CmdSp |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS},
  {HYP_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
  {KC_LSFT, CTL_T(KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {LGUI(KC_SPC), KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_BSPC,  KC_SPC,  RAISE,   CUSTOM, LGUI(KC_GRV), KC_HYPR,   LGUI(KC_SPC)}
},

/* Hyp
 * ,--------------------------------------------------------------------------------------.
 * |     Tab |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |---------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc     |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |---------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift   |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |---------+------+------+------+------+------+------+------+------+------+------+------|
 * | CmdSp   | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Cust | Cmd` | hypr |Cmdsp |
 * `--------------------------------------------------------------------------------------'
 */
[_HYP] = {
  {_______, HYPR(KC_Q), HYPR(KC_W), HYPR(KC_E), HYPR(KC_R), HYPR(KC_T), HYPR(KC_Y), HYPR(KC_U), HYPR(KC_I),    HYPR(KC_O),   HYPR(KC_P),    HYPR(KC_BSLS)},
  {_______, HYPR(KC_A), HYPR(KC_S), HYPR(KC_D), HYPR(KC_F), HYPR(KC_G), KC_LEFT,    KC_DOWN,    KC_UP,         KC_RIGHT,     HYPR(KC_SCLN), HYPR(KC_QUOT)},
  {_______, HYPR(KC_Z), HYPR(KC_X), HYPR(KC_C), HYPR(KC_V), HYPR(KC_B), HYPR(KC_N), HYPR(KC_M), HYPR(KC_COMM), HYPR(KC_DOT), HYPR(KC_SLSH), _______},
  {_______, _______, _______, _______, _______, HYPR(KC_SPC), HYPR(KC_SPC), _______, _______, _______, _______, _______}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  ~   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  | F10  | F11  |  F12 |   _  |   =  |   [  |  ]   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {_______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD},
  {_______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_UNDS, KC_EQL,  KC_LBRC, KC_RBRC, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   `  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   +  |   *  |   \  |  =   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   [  |   ]  |   (  |   )  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {_______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_PLUS,  KC_ASTR, KC_SLSH, KC_EQL},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Custom
 * ,-----------------------------------------------------------------------------------.
 * |      | Scrn3|Scrn4 | Scrn3| Scrn4|      | end  | pgdn | pgup | home |      | Mute |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      | Find |      |  Lf  |  Dn  |  Up  |  Rt  | Prev | Next |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      | Cmd{ | Cmd} | Cmd[ | Cmd] | Vol- | Vol+ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  BL  |      |      |      |      | Bksp |  Del |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_CUSTOM] = {
  {_______, LCTL(LGUI(S(KC_3))), LCTL(LGUI(S(KC_4))), LGUI(S(KC_3)), LGUI(S(KC_4)),    _______, KC_END,        KC_PGDN,       KC_PGUP,       KC_HOME,       KC_MPLY, KC_MUTE},
  {_______, LGUI(LALT(KC_LEFT)), LGUI(LALT(KC_RIGHT)), _______,       LGUI(LALT(KC_F)), _______, KC_LEFT,       KC_DOWN,       KC_UP,         KC_RIGHT,      KC_MRWD, KC_MFFD},
  {_______, LCTL(KC_LEFT), LCTL(KC_UP), LCTL(KC_DOWN), LCTL(KC_RIGHT),       _______, LGUI(KC_LCBR), LGUI(KC_RCBR), LGUI(KC_LBRC), LGUI(KC_RBRC), KC_VOLD, KC_VOLU},
  {BACKLIT, _______, LGUI(KC_GRV), _______, _______,       KC_BSPC,          KC_DELT, _______,       _______,       _______,       _______,       _______}
},

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |   /  |   *  |  7   |   8  |   9  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   -  |  4   |   5  |  6   |   =  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   +  |  1   |  2   |   3  |  Ent |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |   0  |   0  |   .  |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = {
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLSH, KC_ASTR, KC_7, KC_8, KC_9, KC_DEL},
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, KC_4, KC_5, KC_6, KC_EQL},
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PLUS, KC_1, KC_2, KC_3, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_0, KC_0, KC_DOT}
},
/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|      |      |Qwerty|Colemk|      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL},
  {_______, _______, _______, AU_ON,   AU_OFF,  _______, _______, QWERTY,  COLEMAK, _______,  _______,  _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}


};

#ifdef AUDIO_ENABLE

float tone_startup[][2]    = SONG(STARTUP_SOUND);
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);
float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
      set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case CUSTOM:
      if (record->event.pressed) {
        layer_on(_CUSTOM);
      } else {
        layer_off(_CUSTOM);
      }
      return false;
      break;
    case NUMPAD:
      if (record->event.pressed) {
        layer_on(_NUMPAD);
      } else {
        layer_off(_NUMPAD);
      }
      return false;
      break;
    case HYP:
      if (record->event.pressed) {
        layer_on(_HYP);
      } else {
        layer_off(_HYP);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
  }
  return true;
}

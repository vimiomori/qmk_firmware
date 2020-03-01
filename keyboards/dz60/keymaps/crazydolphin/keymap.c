#include QMK_KEYBOARD_H
#define ______ KC_TRNS

enum layouts{
    _DEFAULT = 0,
    _FN = 1,
    _LIGHTS = 2,
    _MOUSE = 3,
    _VIM = 4,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /* BASE LAYER
 *
 * ,-----------------------------------------------------------------------------------------.
 * | ~ ` |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \| | Esc |
 * |-----------------------------------------------------------------------------------------+
 * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
 * |-----------------------------------------------------------------------------------------+
 * | CTRL    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
 * |-----------------------------------------------------------------------------------------+
 * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |  RShift   |  FN |
 * |-----------------------------------------------------------------------------------------+
 * |    VIM  |    Alt  |      Gui  |            Space             |   Alt   |  Gui | LIGHTS  |
 * `-----------------------------------------------------------------------------------------'
 */

	[_DEFAULT] = LAYOUT_60_tsangan_hhkb(
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSLS, KC_ESC,
		KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC, KC_RBRC, KC_BSPC,
		KC_LCTL,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,      KC_ENT,
		KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,           KC_RSFT, MO(_FN),
	    TO(_VIM), KC_LALT,      KC_LGUI,                      KC_SPC,                    MO(_LIGHTS),           KC_RGUI,         MO(_MOUSE)),


/* FN LAYER
 *
 *  ,-----------------------------------------------------------------------------------------------------.
 * |         | F1  | F2  | F3  | F4   | F5   | F6   | F7  | F8   | F9  | F10  | F11  | F12  |INSERT |  _  |
 * |------------------------------------------------------------------------------------------------------+
 * | CAPS     |  _  |  _  |  _   |  _  |  _  |  _  |  _  |  PRSC  |  SLOCK |  PAUSE |  UP   |  _  | DEL   |
 * |------------------------------------------------------------------------------------------------------+
 * | CTRL       |  _  |  VOLDOWN  |  VOLUP  |  VOLMUTE  | _ | _ | _ | HOME | PGUP  | LEFT | IGHT |   _    |
 * |------------------------------------------------------------------------------------------------------+
 * | Shift         |  _   | PREV | PLAY | NEXT |  _   |  _   |  _   |  END  |  PGDN  | DOWN  |  _  |   _  |
 * |------------------------------------------------------------------------------------------------------+
 * |                 _    |      _     |               _               |     _      |     _               |
 * `------------------------------------------------------------------------------------------------------'
 */

    [_FN] = LAYOUT_60_tsangan_hhkb(
		______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_INS,  ______,
		KC_CAPS,          ______,  ______,  ______,  ______,  ______,  ______,  ______,  KC_PSCR, KC_SLCK, KC_PAUS,  KC_UP,   ______,  KC_DEL,
		______,           KC_VOLD, KC_VOLU, KC_MUTE, ______,  ______,  KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT,  KC_RGHT, ______,
		______,           KC_MPRV, KC_MPLY, KC_MNXT, ______,  ______,  KC_PPLS, KC_PMNS, KC_END,  KC_PGDN, KC_DOWN,           ______,  ______,
		______,  ______,           ______,                    ______,                      ______,         ______,            ______),


/* LIGHTS LAYER
 *
 *  ,---------------------------------------------------------------------------------------------------------------------.
 * | RGB_TOGGLE  | STATIC | BREATHE | RAINBOW | SWIRL | SNAKE | KNIGHTRIDER | XMAS | STATIC_GRAD | _ |  _ | _ | _ | _ | _ |
 * |----------------------------------------------------------------------------------------------------------------------+
 * | RBG_MOD      |  HUE_INC |  SATURATION_INC  |  BRIGHT_INC   |  _  |  _  |  _  |  _ |  _ |  _ |  _ |  _  |  _  |  _    |
 * |----------------------------------------------------------------------------------------------------------------------+
 * |                |  HUE_DEC |  SATURATION_DEC  |  BRIGHT_DEC  |  _  |  _  |  _ |  _  |  _  |  _  |  _  |  _  |    _    |
 * |----------------------------------------------------------------------------------------------------------------------+
 * |                      |   _   |   _   |   _   |   _   |   _   |   _   |   _   |   _   |   _   |   _   |  _   |    _   |
 * |----------------------------------------------------------------------------------------------------------------------+
 * |                             _    |      _     |               _               |     _      |     _                   |
 * `----------------------------------------------------------------------------------------------------------------------'
 */

	[_LIGHTS] = LAYOUT_60_tsangan_hhkb(
		RGB_TOG, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, ______, ______, ______, ______, ______, ______,
		RGB_MOD,          RGB_HUI, RGB_SAI, RGB_VAI,  ______,   ______,  ______,  ______,  ______, ______, ______, ______, ______, ______,
		______,           RGB_HUD, RGB_SAD, RGB_VAD,  ______,   ______,  ______,  ______,  ______, ______, ______, ______, ______,
		______,           ______,  ______,  ______,   ______,  ______,  ______,  ______,  ______, ______, ______,          ______, ______,
		______,  ______,           ______,                      ______,                          ______,   ______,         ______),


/* MOUSEFN LAYER
 *
 *  ,---------------------------------------------------------------------------------------------------------------------
 * |        |  ACC_1  |  ACC_2  |  ACC_3  |  _    |  _    |  _    |  _   |  _    |  _   |  _   |  _   |  _   | _  |  _   |
 * |---------------------------------------------------------------------------------------------------------------------+
 * | CAPS     |   _  |   _  |   _   |    _  |    _  |    _  |    _  |    _   |  _  |  WHEEL_UP  |   _   |    _   |   _   |
 * |---------------------------------------------------------------------------------------------------------------------+
 * | CTRL       |   _   |   _   |   _   |   _   |   _    |   _  | _ |   _    |  WH_LEFT |  WH_DOWN |  WH_RIGHT  |    _   |
 * |---------------------------------------------------------------------------------------------------------------------+
 * | Shift         |  _   |  _   |  _   |  _   |  _   |  _   |  _   |   _    |    _    |    _    |    _       |   _      |
 * |---------------------------------------------------------------------------------------------------------------------+
 * |                          _    |      _     |               _               |     _      |     _                     |
 * `---------------------------------------------------------------------------------------------------------------------'
 */


	[_MOUSE] = LAYOUT_60_tsangan_hhkb(
		______, KC_ACL0, KC_ACL1, KC_ACL2, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,
		______,         ______, ______, ______, ______, ______, ______, ______, ______,  ______,  KC_MS_U, ______, ______,  ______,
		______,         ______, ______, ______, ______, ______, ______, ______, ______,  KC_MS_L, KC_MS_D, KC_MS_R,   ______,
		______,         ______, ______, ______, ______, ______, ______, ______, ______,  KC_BTN1, KC_BTN2,       ______,  ______,
		______, ______,           ______,                    ______,                          ______,    ______,        ______),


 /* VIM LAYER
 *
 * ,-----------------------------------------------------------------------------------------.
 * | ~ ` |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \| | Esc |
 * |-----------------------------------------------------------------------------------------+
 * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
 * |-----------------------------------------------------------------------------------------+
 * | CTRL    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
 * |-----------------------------------------------------------------------------------------+
 * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |  RShift   |  FN |
 * |-----------------------------------------------------------------------------------------+
 * |    VIM  |    Alt  |      Gui  |            Space             |   Alt   |  Gui | LIGHTS  |
 * `-----------------------------------------------------------------------------------------'
 */

	[_VIM] = LAYOUT_60_tsangan_hhkb(
		______, ______, ______, ______, ______, ______, ______, ______,   ______,  ______, ______, ______, ______, ______, ______,
		______,         ______, ______, ______, ______, ______, ______,   ______,  TO(_DEFAULT), ______, ______, ______, ______, ______,
		______,         ______, ______, ______, ______, ______, KC_RIGHT, KC_DOWN, KC_UP, KC_LEFT, ______, ______, ______,
		______,         ______, ______, ______, ______, ______, ______,   ______,  ______, ______, ______,         ______, ______,
		______,  ______,           ______,                      ______,                          ______,   ______,         ______),

};

enum combos {
    JK_ESC,
    WRITE
};

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM write_combo[] = {KC_SCLN, KC_W, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [JK_ESC] = COMBO(jk_combo, KC_ESC),
    [WRITE] = COMBO_ACTION(write_combo)
};

void process_combo_event(uint8_t combo_index, bool pressed) {
    switch(combo_index) {
    case WRITE:
        if (pressed) {
            register_code(KC_LGUI);
            register_code(KC_S);
            unregister_code(KC_LGUI);
            unregister_code(KC_S);
        }
        break;
    }
};


uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case _FN:
        rgblight_setrgb (0x00,  0x00, 0xFF);
        break;
    case _MOUSE:
        rgblight_setrgb (0xFF,  0x00, 0x00);
        break;
    case _VIM:
        rgblight_setrgb (0x00,  0xFF, 0x00);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0x00,  0xFF, 0xFF);
        break;
    }
  return state;
};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case FOO:
//       if (record->event.pressed) {
//         // Do something when pressed
//       } else {
//         // Do something else when release
//       }
//       return false; // Skip all further processing of this key
//     case KC_ENTER:
//       // Play a tone when enter is pressed
//       if (record->event.pressed) {
//         PLAY_NOTE_ARRAY(tone_qwerty);
//       }
//       return true; // Let QMK send the enter press/release events
//     default:
//       return true; // Process all other keycodes normally
//   }
// }
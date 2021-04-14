/* Copyright 2020 Masayuki Takagi
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _VIM,
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    CMD = SAFE_RANGE,
    VIMS,
    VIML,
    VIMR,
    WORD,
    BACK,
    YANK,
    PASTE
};

#define LOWER TT(_LOWER)
#define RAISE TT(_RAISE)
#define QWERTY TO(_QWERTY)
#define ADJUST MO(_ADJUST)
#define NUMPAD TT(_NUMPAD)
#define VIM TO(_VIM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | VIM  | Num  | Alt  | GUI  |Lower |    Space    |Raise |      |      |      |ADJUST|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    VIM    , NUMPAD , KC_LALT, KC_LGUI, LOWER,       KC_SPC,       RAISE,   _______, _______, _______, ADJUST 
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Enter    |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT(
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______,  _______,
    _______, _______, _______, _______, _______,     KC_ENT ,      _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Enter    |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT(
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______,  _______,
    _______, _______, _______, _______, _______,     KC_ENT ,      _______, _______, _______, _______, _______
),

/* Adjust
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      | Volx |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | Bri+ | Vol+ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | Bri- | Vol- |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BRIU, KC_VOLU,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BRID, KC_VOLD,
    _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
),

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |  =   |  -   |  +   |      |      |      |      |      |      |  1   |  2   |  3   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  +   |  /   |  *   |      |      |      |      |      |      |  4   |  5   |  6   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  -   |      |      |      |      |      |      |      |      |  7   |  8   |  9   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  =   |      |      |      |      |    Enter    |      |      |  *   |  0   |  #   |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT(
    KC_PEQL, KC_PMNS, KC_PPLS, _______, _______, _______, _______, _______, _______, KC_1   , KC_2   , KC_3   ,
    KC_PPLS, KC_PSLS, KC_PAST, _______, _______, _______, _______, _______, _______, KC_4   , KC_5   , KC_6   ,
    KC_PMNS, _______, _______, _______, _______, _______, _______, _______, _______, KC_7   , KC_8   , KC_9   ,
    KC_PEQL, _______, _______, _______, _______,     KC_ENT ,      _______, _______, KC_PAST, KC_0   , KC_HASH
),

/* VIM
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      | YANK |      |QWERTY|      |PASTE |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CMD  |      | WORD |      |  $   |  G   | Left |  Up  | Down |Right |  0   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | VimS |      |      |      |      | BACK |      |      |      |      |      | VimS |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | VimL |             | VimR |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_VIM] = LAYOUT(
    _______, _______, _______, _______, _______, _______, YANK   , _______, QWERTY , _______, PASTE  , _______,
    CMD    , _______, WORD   , _______, KC_DLR , KC_G   , KC_LEFT, KC_UP  , KC_DOWN, KC_RGHT, KC_0   , _______,
    VIMS   , _______, _______, _______, BACK   , _______, _______, _______, _______, _______, _______, VIMS   ,
    _______, _______, _______, _______, _______,     KC_ENT ,      _______, _______, _______, _______, _______
),

/* Blank
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
)

};

/*
https://docs.qmk.fm/#/custom_quantum_functions?id=programming-the-behavior-of-any-keycode
*/

enum combos {
  KJ_ESC,
  UD_ESC,
  CT_ESC
};

const uint16_t PROGMEM kj_esc_combo[] = {KC_K, KC_J, COMBO_END};
const uint16_t PROGMEM ud_esc_combo[] = {KC_UP, KC_DOWN, COMBO_END};
const uint16_t PROGMEM ct_esc_combo[] = {KC_LCTL, KC_TAB, COMBO_END};
// const uint16_t PROGMEM write_combo[] = {KC_LSFT, KC_SCLN, KC_W, KC_ENT, COMBO_END};
// const uint16_t PROGMEM cmdtabl_combo[] = {KC_LSFT, KC_LEFT, COMBO_END};
// const uint16_t PROGMEM cmdtabr_combo[] = {KC_LSFT, KC_RIGHT, COMBO_END};
// const uint16_t PROGMEM pgdn_combo[] = {KC_LSFT, KC_G, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [KJ_ESC] = COMBO_ACTION(kj_esc_combo),
    [UD_ESC] = COMBO(ud_esc_combo, KC_ESC),
    [CT_ESC] = COMBO(ct_esc_combo, KC_ESC),
};

void process_combo_event(uint8_t combo_index, bool pressed) {
  switch(combo_index) {
    case KJ_ESC:
      if (pressed) {
        layer_on(_VIM);
      }
      break;
}


static bool cmd_active = false;
static bool vims_active = false;
static bool viml_active = false;
static bool vimr_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case WORD:
            if (record->event.pressed) {
                tap_code16(KC_LALT(KC_RIGHT))
            }
            return false;
            break;
        case BACK:
            if (record->event.pressed) {
                tap_code16(KC_LALT(KC_LEFT))
            }
            return false;
            break;
        case YANK:
            if (record->event.pressed) {
                tap_code16(KC_LGUI(KC_C))
            }
            return false;
            break;
        case PASTE:
            if (record->event.pressed) {
                tap_code16(KC_LGUI(KC_V))
            }
            return false;
            break;
        case CMD:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                cmd_active = true;
            } else {
                unregister_code(KC_LGUI);
                cmd_active = false;
            }
            return false;
            break;
        case KC_RIGHT:
            if (cmd_active) {
                if (record->event.pressed) {
                    register_code(KC_TAB)
                } else {
                    unregister_code(KC_TAB)
                }
                return false;
            } else {
                return true;
            }
            break;
        case KC_LEFT:
            if (cmd_active) {
                if (record->event.pressed) {
                    register_code(KC_LSFT)
                    register_code(KC_TAB)
                } else {
                    unregister_code(KC_LSFT)
                    unregister_code(KC_TAB)
                }
                return false;
            } else {
                return true;
            }
            break;
        case VIMS:
            if (record->event.pressed) {
                vims_active = true;
            } else {
                vims_active = false;
            }
            return false;
            break;
        case VIML:
            if (record->event.pressed) {
                viml_active = true;
            } else {
                viml_active = false;
            }
            return false;
            break;
        case VIMR:
            if (record->event.pressed) {
                vimr_active = true;
            } else {
                vimr_active = false;
            }
            return false;
            break;
        case KC_G:
            if (vims_active) {
                if (record->event.pressed) {
                    register_code(KC_PGUP)
                } else {
                    unregister_code(KC_PGUP)
                }
                return false;
            } else {
                return true;
            }
            break;
        case KC_0:
            if (viml_active) {
                if (record->event.pressed) {
                    register_code(KC_HOME)
                } else {
                    unregister_code(KC_HOME)
                }
                return false;
            } else {
                return true;
            }
            break;
        case KC_DLR:
            if (vims_active) {
                if (record->event.pressed) {
                    register_code(KC_END)
                } else {
                    unregister_code(KC_END)
                }
                return false;
            } else {
                return true;
            }
            break;

    }
    return true;
}

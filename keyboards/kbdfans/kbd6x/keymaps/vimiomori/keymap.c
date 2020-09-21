/* Copyright 2018 MechMerlin
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
#include <print.h>

enum layouts{
    _DEFAULT = 0,
    _COLEMAK = 1, 
    _FN = 2,
    _VIM = 3
};

// Tap Dance declarations
enum {
    TD_GG,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_GG] = ACTION_TAP_DANCE_DOUBLE(KC_G, KC_PGUP),
};


// stock hhkb as referenced by https://i.imgur.com/QoBTDHf.png 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT(
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_ESC,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(2),
      _______ , KC_LALT, KC_LGUI,                   KC_SPACE,                 KC_RGUI, KC_RALT, _______
      ),

  [_COLEMAK] = LAYOUT(
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_ESC,
      KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,     KC_J,   KC_L,   KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSPC,
      KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,     KC_H,   KC_N,   KC_E,    KC_I,    KC_O,    KC_QUOT, KC_ENT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_K,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(2),
      _______ , KC_LALT, KC_LGUI,                   KC_SPACE,                 KC_RGUI, KC_RALT, _______
      ),

  [_FN] = LAYOUT(
      KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS, KC_DEL,
      KC_CAPS, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP, _______, RESET,
      TO(_COLEMAK), KC_VOLU, KC_VOLD, KC_MUTE, KC_MSTP, _______, KC_ASTR, KC_SLSH, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, _______,
      TO(_DEFAULT), _______, _______, _______,  _______, _______,  KC_PLUS, KC_UNDS, KC_END, KC_PGDN, KC_DOWN, _______, _______,
      RGB_MOD, RGB_HUI, RGB_SAI,                   RGB_TOG,                   RGB_VAI, _______, _______
      ),

  [_VIM] = LAYOUT(
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_ESC,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,   KC_U,   TO(_DEFAULT),    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    TD(TD_GG),     KC_LEFT,   KC_DOWN,   KC_UP,    KC_RIGHT,    KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(2),
      _______ , KC_LALT, KC_LGUI,                   KC_SPACE,                 KC_RGUI, KC_RALT, _______
      )
};

// enum combos {
//     VI,
//     WRITE,
//     CMDTABL,
//     CMDTABR,
//     PG_DN
// };

// const uint16_t PROGMEM vi_combo[] = {KC_F, KC_D, COMBO_END};
// const uint16_t PROGMEM write_combo[] = {KC_LSFT, KC_SCLN, KC_W, KC_ENT, COMBO_END};
// const uint16_t PROGMEM cmdtabl_combo[] = {KC_LSFT, KC_LEFT, COMBO_END};
// const uint16_t PROGMEM cmdtabr_combo[] = {KC_LSFT, KC_RIGHT, COMBO_END};
// const uint16_t PROGMEM pgdn_combo[] = {KC_LSFT, KC_G, COMBO_END};

// combo_t key_combos[COMBO_COUNT] = {
//     [VI] = COMBO_ACTION(vi_combo),
//     [WRITE] = COMBO_ACTION(write_combo),
//     [CMDTABR] = COMBO_ACTION(cmdtabr_combo),
//     [CMDTABL] = COMBO_ACTION(cmdtabl_combo),
//     [PG_DN] = COMBO(pgdn_combo, KC_PGDN)
// };

// void process_combo_event(uint8_t combo_index, bool pressed) {
//   switch(combo_index) {
//     case WRITE:
//       if (pressed) {
//         tap_code16(LGUI(KC_S));
//       }
//       break;
//     case VI:
//       if (pressed) {
//         layer_on(_VIM);
//       }
//       break;
//     // case CMDTABR:
//     //   uprintf("%u", get_highest_layer(layer_state) == _VIM);
//     //   if (pressed && IS_LAYER_ON(_VIM)) {
//     //     tap_code16(LGUI(KC_TAB));
//     //   }
//     //   break;
//     // case CMDTABL:
//     //   if (pressed && IS_LAYER_ON(_VIM)) {
//     //     tap_code16(LGUI(LSFT(KC_TAB)));
//     //   }
//     //   break;
//   }
// }

// void matrix_init_user(void) {

// }

// void matrix_scan_user(void) {

// }

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


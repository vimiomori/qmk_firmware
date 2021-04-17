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
#include <string.h>
#include "print.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _PURE,
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUMPAD,
    _VIM,
    _VIML,
    _VISUAL,
    _
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    CMD = SAFE_RANGE,
    PURE,
    QWERTY,
    VIMS,
    VIML,
    VIMR,
    VISUAL,
    WORD,
    BACK,
    PASTE,
    REDO,
    UNDO,
    SEARCH,
    ILINE,
    CMDSFT
};

// Tap Dance declarations
enum {
    TD_G,
    TD_Y,
    TD_D
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define NUMPAD TT(_NUMPAD)

// TODO: Add emoji layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* PURE Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |ADJUST| Num  | Alt  | GUI  |Lower |    Space    |Raise |   ←  |   ↓  |   ↑  |  →   |
 * `-----------------------------------------------------------------------------------'
 */
[_PURE] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
    ADJUST,  NUMPAD,  KC_LALT, KC_LGUI, LOWER,       KC_SPC,       RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |ADJUST| Num  | Alt  | GUI  |Lower |    Space    |Raise |   ←  |   ↓  |   ↑  |  →   |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
    ADJUST,  NUMPAD,  KC_LALT, KC_LGUI, LOWER,       KC_SPC,       RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   =  |   |  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |   `  |      |      |      |      |      |   \  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Space    |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_EQL,  KC_PIPE, KC_BSPC,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, _______, _______, _______, KC_GRV,  _______, _______, _______, _______, _______, KC_BSLS, KC_ENT,
    _______, _______, _______, _______, _______,     KC_SPC,       CMDSFT,  _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |  [   |  ]   |      |      |   +  |   =  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  (   |  )   |      |      |   _  |   -  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  {   |  }   |      |      |   \  |   |  |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Space    |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT(
    _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, KC_MINS, KC_PLUS, _______, _______, _______,
    _______, _______, _______, KC_LPRN, KC_RPRN, _______, _______, KC_UNDS, KC_EQL,  _______, _______, _______,
    _______, _______, _______, KC_LCBR, KC_RCBR, _______, _______, KC_BSLS, KC_PIPE, _______, _______, KC_ENT,
    _______, _______, _______, _______, _______,     KC_SPC,       _______, _______, _______, _______, _______
),

/* Adjust
 * ,-----------------------------------------------------------------------------------.
 * | Volx |      |      |      |      |      |      |      |      |  F1  |  F2  |  F3  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Vol+ | Bri+ |      |      |      |      |      |      |      |  F4  |  F5  |  F6  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Vol- | Bri- |      |      |      |      |      |      |      |  F7  |  F8  |  F9  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |PURE  |      |      |      |   QWERTY    |      |      |  F10 |  F11 |  F12 |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT(
    KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   
    KC_VOLU, KC_BRIU, _______, _______, _______, _______, _______, _______, _______, KC_F4,   KC_F5,   KC_F6,  
    KC_VOLD, KC_BRID, _______, _______, _______, _______, _______, _______, _______, KC_F7,   KC_F8,   KC_F9,  
    _______, PURE,    _______, _______, _______,     QWERTY,       _______, _______, KC_F10,  KC_F11,  KC_F12  
),

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |  =   |  -   |  +   |      |      |      |      |      |      |  1   |  2   |  3   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  +   |  /   |  *   |      |      |      |      |      |      |  4   |  5   |  6   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  -   |      |      |      |      |      |      |      |      |  7   |  8   |  9   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  =   |      |      |      |      |    Space    |      |      |  *   |  0   |  #   |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT(
    KC_PEQL, KC_PMNS, KC_PPLS, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,
    KC_PPLS, KC_PSLS, KC_PAST, _______, _______, _______, _______, _______, _______, KC_4,    KC_5,    KC_6,
    KC_PMNS, _______, _______, _______, _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,
    KC_PEQL, _______, _______, _______, _______,     KC_SPC,       _______, _______, KC_PAST, KC_0,    KC_HASH
),

/* VIM
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |      | WORD | WORD | REDO |      | YANK | UNDO |QWERTY|ILINE |PASTE | Left |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CMD  |QWERTY|VIM_D |      |      |VIM_G | Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | VimS | Del  |      |      |VISUAL| BACK |      |      |      |      |SEARCH| Down |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | VimL |    Space    | VimR |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_VIM] = LAYOUT(
    KC_TAB,  _______, WORD,    WORD,    _______,    _______, TD(TD_Y),UNDO,    QWERTY , ILINE,   PASTE,   KC_LEFT,
    CMD,     QWERTY,  _______, _______, _______, TD(TD_G),KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
    VIMS,    KC_DEL,  _______, _______, VISUAL,  BACK,    _______, _______, _______, _______, SEARCH,  KC_DOWN,
    _______, _______, _______, _______, VIML,        KC_SPC,       _______, _______, _______, _______, _______
),

/* VIM Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   =  |   |  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |   `  |      |      |      |      |      |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Space    |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_VIML] = LAYOUT(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_EQL,  KC_PIPE, KC_BSPC,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, _______, _______, _______, KC_GRV,  _______, _______, _______, _______, _______, KC_BSLS, _______,
    _______, _______, _______, _______, _______,     KC_SPC,       _______, _______, _______, _______, _______
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

enum combos_events {
  DU,
  JK
};

// TODO use JK instead of KJ
const uint16_t PROGMEM du_combo[] = {KC_DOWN, KC_UP,   COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J,    KC_K,    COMBO_END};

static bool cmd_active = false;
static bool vim_active = false;
static bool vims_active = false;
static bool viml_active = false;
static bool vimr_active = false;
static bool visual_active = false;
static bool pure_active = false;
static int codevals[6];
static uint8_t codeval_index = 0;
static int times = 1;

combo_t key_combos[COMBO_COUNT] = {
  [DU] = COMBO_ACTION(du_combo),
  [JK] = COMBO_ACTION(jk_combo)
};

void dance_gg(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            if (vims_active) {
                tap_code(KC_PGDN);
            }
            break;
        case 2:
            tap_code(KC_PGUP);
            break;
    }
}

void dance_yy(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            // TODO: check if anything is highlighted first to allow yanking a word with yw too
            if (visual_active) {
                unregister_code(KC_LSFT);
                visual_active = false;
            }
            tap_code16(LGUI(KC_C));
            break;
        case 2:
            tap_code(KC_HOME);
            register_code(KC_LSFT);
            tap_code(KC_END);
            unregister_code(KC_LSFT);
            tap_code16(LGUI(KC_C));
            break;
    }
}

void dance_dd(qk_tap_dance_state_t *state, void *user_data) {
    return;
}

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_G] = ACTION_TAP_DANCE_FN(dance_gg),
    [TD_Y] = ACTION_TAP_DANCE_FN(dance_yy),
    [TD_D] = ACTION_TAP_DANCE_FN(dance_dd),
};

int calc_times(void) {
    int i, k = 0;
    for (i = 0; i < codeval_index; i++) {
        k = 10 * k + codevals[i];
    }
    return k;
}

void execute_x_times(uint16_t keycode) {
    while (times > 0) {
        tap_code16(keycode);
        times--;
    }
    times = 1;
}


void process_combo_event(uint16_t combo_index, bool pressed) {
    if (combo_index == JK || combo_index == DU) {
        if (pure_active && pressed) {
            tap_code(KC_ESC);
            return;
        }
        if (!pure_active && pressed) {
            if (visual_active) {
                visual_active = false;
                unregister_code(KC_LSFT);
            }
            layer_clear();
            set_single_persistent_default_layer(_VIM);
            return;
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool is_num = keycode >= KC_1 && keycode <= KC_0;
    // bool is_alp = keycode >= KC_A && keycode <= KC_Z;
    bool is_nav = (
        keycode == KC_UP ||
        keycode == KC_DOWN ||
        keycode == KC_LEFT ||
        keycode == KC_RGHT
    );
    bool is_act = (
        keycode == PASTE
    );
    if (is_num && record->event.pressed) {
        if (!viml_active) {
            return true;
        }
        codevals[codeval_index++] = (keycode == KC_0) ? 0 : keycode - KC_1 + 1;
        if (codeval_index == 6) {
            codeval_index = 0;
            times = 1;
        }
        return false;
    }

    if (is_nav && record->event.pressed) {
        execute_x_times(keycode);
        return false;
    }

    if (is_act && visual_active && record->event.pressed) {
        unregister_code(KC_LSFT);
        clear_mods();
        visual_active = false;
    }

    // if (is_alp && record->event.pressed) {
    //     if (vim_active) {
    //         return false;
    //     }
    //     // TODO: add command mode
    //     return true;
    // }

    if (cmd_active) {
        switch (keycode) {
            case QWERTY:
                if (record->event.pressed) {
                    vim_active = false;
                }
                return true;
                break;
            case KC_R:
                if (record->event.pressed) {
                    register_code(KC_LGUI);
                    register_code(KC_LSFT);
                    register_code(KC_Z);
                } else {
                    unregister_code(KC_LGUI);
                    unregister_code(KC_LSFT);
                    unregister_code(KC_Z);
                }
                return false;
                break;
            case KC_UP:
                if (record->event.pressed) {
                    tap_code16(LCTL(KC_RGHT));
                } 
                return false;
                break;
            case KC_DOWN:
                if (record->event.pressed) {
                    tap_code16(LCTL(KC_LEFT));
                } 
                return false;
                break;
            case KC_RIGHT:
                if (record->event.pressed) {
                    register_code(KC_LGUI);
                    register_code(KC_TAB);
                } else {
                    unregister_code(KC_TAB);
                    unregister_code(KC_LGUI);
                }
                return false;
                break;
            case KC_LEFT:
                if (record->event.pressed) {
                    register_code(KC_LGUI);
                    register_code(KC_LSFT);
                    register_code(KC_TAB);
                } else {
                    unregister_code(KC_LSFT);
                    unregister_code(KC_TAB);
                    unregister_code(KC_LGUI);
                }
                return false;
                break;
        }
    }

    if (viml_active) {
        switch (keycode) {
            case KC_DLR:
                tap_code(KC_END);
                return false;
            case KC_0: 
                tap_code(KC_HOME);
                return false;
            break;
        }
    }

    switch (keycode) {
        case PURE:
            if (record->event.pressed) {
                print("moving to pure");
                pure_active = true;
                layer_clear();
                set_single_persistent_default_layer(_PURE);
            }
            return false;
            break;
        case QWERTY:
            if (record->event.pressed) {
                print("MOVING TO QWERTY");
                pure_active = false;
                layer_clear();
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case CMDSFT:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LSFT);
            }
            return false;
            break;
        case WORD:
            if (record->event.pressed) {
                execute_x_times(LALT(KC_RGHT));
            }
            return false;
            break;
        case BACK:
            if (record->event.pressed) {
                execute_x_times(LALT(KC_LEFT));
            }
            return false;
            break;
        case PASTE:
            if (record->event.pressed) {
                tap_code16(LGUI(KC_V));
            }
            return false;
            break;
        case CMD:
            if (record->event.pressed) {
                cmd_active = true;
            } else {
                cmd_active = false;
            }
            return false;
            break;
        case VIMS:
            if (record->event.pressed) {
                vims_active = true;
            } else {
                vims_active = false;
            }
            return false;
            break;
        case ILINE:
            if (record->event.pressed) {
                if (vims_active) {
                    tap_code(KC_UP);
                    tap_code(KC_END);
                    tap_code(KC_ENT);
                } else {
                    tap_code(KC_END);
                    tap_code(KC_ENT);
                }
                layer_clear();
                set_single_persistent_default_layer(_QWERTY);
                return false;
            }
            break;
        case VIML:
            if (record->event.pressed) {
                viml_active = true;
                layer_move(_VIML);
            } else {
                if (codeval_index > 0) {
                    times = calc_times();
                    memset(codevals, 0, sizeof(codevals));
                    codeval_index = 0;
                }
                viml_active = false;
                layer_move(_VIM);
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
        case VISUAL:
            if (record->event.pressed) {
                if (vims_active) {
                    tap_code(KC_HOME);
                    register_code(KC_LSFT);
                    tap_code(KC_END);
                } else {
                    register_code(KC_LSFT);
                }
                visual_active = true;
            }
            return false;
            break;
    }
    return true;
}

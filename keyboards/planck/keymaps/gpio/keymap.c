/* Copyright 2015-2017 Jack Humbert
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
#include <keymap_uk.h>
#include "muse.h"
#include "unicode_map.h"
#include "rgb_matrix.h"
#include "pointing_device.h"

#include "print.h" //pour debug


enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FUNCT,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  POTMOD
};


#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define RAISE_L DF(_RAISE)
#define FUNCT MO(_FUNCT)
#define FUNCT_L DF(_FUNCT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
    POTMOD,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, LT(LOWER, KC_BSPC),
    KC_GESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_LEAD,
    RSFT_T(KC_TAB),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_UP, KC_SFTENT,
    LCTL_T(KC_CAPS), LT(FUNCT, KC_Z), LGUI_T(KC_X), LALT_T(KC_C), LT(LOWER, KC_V), KC_B, KC_N, LT(RAISE, KC_M), KC_SPC, KC_LEFT, KC_DOWN, KC_RIGHT 
),

[_LOWER] = LAYOUT_planck_grid(
    _______,  S(KC_1), S(UK_QUOT),  UK_HASH,   UK_DLR, UK_PERC , UK_CIRC,  UK_AMPR, UK_ASTR, UK_LPRN, UK_RPRN, UK_PIPE,
    KC_GRV ,  XXXXXXX,    U_ECIRC, U_EACUTE, U_EGRAVE,   U_EUML, XXXXXXX, U_UGRAVE, U_ICIRC, U_OCIRC, UK_HASH, KC_CAPS,
    _______, U_AGRAVE,    U_ACIRC,   U_AUML,  XXXXXXX,  XXXXXXX, XXXXXXX,  U_UCIRC,  U_IUML,  U_OUML, UK_SCLN, UK_QUOT,
    _______,  _______,    _______, U_CCEDIL,  _______,  _______, _______,   _______, UK_COMM,  UK_DOT, UK_SLSH, UK_BSLS
),

[_RAISE] = LAYOUT_planck_grid(
    _______,      KC_F1,      KC_F2,       KC_F3,   KC_F4,   KC_F5,   KC_F6,     KC_F7,   KC_F8,    KC_F9,  KC_F10,  KC_DEL,
    QWERTY, KC_MS_BTN1,   KC_MS_UP,  KC_MS_BTN2,  KC_F11,  KC_F12, KC_HOME, KC_PGDOWN, KC_PGUP,  KC_END , _______,  KC_PSCREEN,
    _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______, _______, KC_LEFT,   KC_DOWN,   KC_UP, KC_RIGHT, _______, _______,
    _______, _______   , KC_DEL   , _______    , _______, _______, _______, _______, _______,  _______ , _______, _______
), 

[_FUNCT] = LAYOUT_planck_grid(
    _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,    S(KC_9),    S(KC_0), KC_P7,  KC_P8,   KC_P9, KC_PSLS, _______,
    UK_TILD, KC_MUTE, KC_VOLD, KC_VOLU, _______,    KC_LBRC,    KC_RBRC, KC_P4,  KC_P5,   KC_P6, KC_PAST, KC_NLCK,
    _______, KC_MPLY, KC_MPRV, KC_MNXT, _______, S(KC_LBRC), S(KC_RBRC), KC_P1,  KC_P2,   KC_P3, KC_PMNS, UK_DQUO,
    _______, _______, KC_BRID, KC_BRIU, _______, S(KC_COMM),  S(KC_DOT), KC_P0, KC_EQL, KC_PDOT, KC_PPLS, UK_UNDS
),
/* Adjust (Lower + RAISE)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______,  _______,  _______,  FUNCT_L,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, RAISE_L
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool is_potMod_active = false;
uint16_t potMod_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        layer_off(_RAISE);
        layer_off(_FUNCT);
        set_single_persistent_default_layer(_QWERTY);
        rgb_matrix_set_color_all(255,0,0);
      }
      return false;
      break;
    case POTMOD:
      if (record->event.pressed) {
        if (!is_potMod_active) {
          is_potMod_active= true;
          potMod_timer = timer_read();
          register_code16(KC_MS_BTN1);
        } else {
          unregister_code16(KC_MS_BTN1);
          is_potMod_active = false;
        }
      }
      return true;
      break;

    default:
      return true; // Process all other keycodes normally
  }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (IS_LAYER_ON(_LOWER)) {
      if (clockwise) {
        tap_code16(S(LCTL(KC_TAB)));
      } else {
        tap_code16(LCTL(KC_TAB));
      }
  } else if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        tap_code16(LSA(KC_TAB));
      } else {
        tap_code16(LALT(KC_TAB));
      }
  } else if (is_potMod_active) {
      potMod_timer = timer_read();
      report_mouse_t currentReport = pointing_device_get_report();
      if (clockwise) {
        currentReport.x = -4;
        currentReport.y = 4;
        currentReport.buttons |= MOUSE_BTN1;  // this is defined in report.h
        //tap_code16(KC_MS_D);
        //tap_code16(KC_MS_L);
      } else {
        currentReport.x = 4;
        currentReport.y = -4;
        currentReport.buttons &= MOUSE_BTN1;
        //tap_code16(KC_MS_U);
        //tap_code16(KC_MS_R);
      }
      pointing_device_set_report(currentReport);
      pointing_device_send();
      
  } else {
    if (clockwise) {
        tap_code(KC_MS_WH_DOWN);
    } else {
        tap_code(KC_MS_WH_UP);
    }
  }
  return true;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_F) {
      // Anything you can do in a macro.
      SEND_STRING("QMK is awesome.");
    }
    SEQ_ONE_KEY(KC_LEAD) {
      rgb_matrix_set_color_all(0,255,0);
        layer_move(_RAISE);
    }
    SEQ_TWO_KEYS(KC_LEAD, KC_LEAD) {
      rgb_matrix_set_color_all(0,0,255);
        layer_move(_FUNCT);
    }
    SEQ_TWO_KEYS(KC_D, KC_D) {
      SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    }
    SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
      SEND_STRING("https://\n");
    }
    SEQ_TWO_KEYS(KC_A, KC_S) {
      register_code(KC_LGUI);
      register_code(KC_S);
      unregister_code(KC_S);
      unregister_code(KC_LGUI);
    }
  }
  if (is_potMod_active) {
    if (timer_elapsed(potMod_timer) > 2000) {
      unregister_code16(KC_MS_BTN1);
      is_potMod_active = false;
    }
  }
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}


// COMBOS

enum combo_events {
  BN_SPC,
  QW_TAB
};

const uint16_t PROGMEM space_combo[] = {KC_B, KC_N, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_Q, KC_W, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [BN_SPC] = COMBO_ACTION(space_combo),
  [QW_TAB] = COMBO_ACTION(tab_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case BN_SPC:
      if (pressed) {
        tap_code16(KC_SPC);
      }
      break;
    case QW_TAB:
      if (pressed) {
        tap_code16(KC_TAB);
      }
      break;
  }
}


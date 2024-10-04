/*
- **Bases de données** : SQL
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _NAV,
    _MOUSE,
    _MEDIA,
    _FUNC,
    _NUM,
    _SYM,
};

enum custom_keycodes {
    SMTD_KEYCODES_BEGIN = SAFE_RANGE,
    CKC_A, // reads as C(ustom) + KC_A, but you may give any name here
    CKC_S,
    CKC_D,
    CKC_F,

    CKC_ESC,
    CKC_TAB,
    CKC_SPC,

    CKC_J, // reads as C(ustom) + KC_A, but you may give any name here
    CKC_K,
    CKC_L,
    CKC_SCLN,

    CKC_ENT,
    CKC_BSPC,
    CKC_DEL,
    SMTD_KEYCODES_END,
};

#include "sm_td.h"
// https://github.com/stasmarkin/sm_td
// https://github.com/azzamsa/qmk_userspace/blob/main/keyboards/sofle/keymaps/azzamsa/keymap.c
// Layer definitions

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   CKC_A,   CKC_S,   CKC_D,   CKC_F,    KC_G,                         KC_H,   CKC_J,   CKC_K,   CKC_L,CKC_SCLN,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          CKC_ESC, CKC_TAB, CKC_SPC,    CKC_ENT,CKC_BSPC, CKC_DEL
                                      //`--------------------------'  `--------------------------'
    ),
    [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO , KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_SCLN,    KC_4,    KC_5,    KC_6,  KC_EQL,                        KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,  KC_GRV,    KC_1,    KC_2,    KC_3, KC_BSLS,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_DOT ,    KC_0, KC_MINS,      KC_NO,   KC_NO,   KC_NO
                                      //`--------------------------'  `--------------------------'
    ),

    [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO , KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_COLN,  KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,                        KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LCTL, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TILD, KC_EXLM,   KC_AT, KC_HASH, KC_PIPE,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_LPRN , KC_RPRN, KC_UNDS,      KC_NO,   KC_NO,   KC_NO
                                      //`--------------------------'  `--------------------------'
    ),

    [_FUNC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,  KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_PSCR,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,  KC_F11,   KC_F4,   KC_F5,   KC_F6, KC_SCRL,                        KC_NO, KC_LSFT,  KC_LCTL,KC_LALT, KC_LGUI,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,  KC_F10,   KC_F1,   KC_F2,   KC_F3, KC_PAUS,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_APP,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO
                                      //`--------------------------'  `--------------------------'
    ),

    [_MEDIA] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,   KC_NO,                      KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_NO ,   KC_NO,   KC_NO,    KC_MSTP, KC_MPLY, KC_MUTE
                                      //`--------------------------'  `--------------------------'
    ),

    [_MOUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,   KC_NO,                        KC_NO, MS_LEFT, MS_DOWN,   MS_UP, MS_RGHT,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_NO ,   KC_NO,   KC_NO,    MS_BTN3, MS_BTN1, MS_BTN2
                                      //`--------------------------'  `--------------------------'
    ),

    [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_AGIN, KC_UNDO,  KC_CUT, KC_COPY, KC_PSTE,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,   KC_NO,                        KC_NO, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                       KC_INS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_NO ,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO
                                      //`--------------------------'  `--------------------------'
    ),

  /*   [_FUN] = LAYOUT_split_3x6_3( */
  /* //,-----------------------------------------------------.                    ,-----------------------------------------------------. */
  /*       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, */
  /* //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------| */
  /*       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, */
  /* //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------| */
  /*       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, */
  /* //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------| */
  /*                                          KC_NO ,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO */
  /*                                     //`--------------------------'  `--------------------------' */
  /*   ), */
 };
void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        SMTD_MT(CKC_A, KC_A, KC_LGUI)
        SMTD_MT(CKC_S, KC_S, KC_LALT)
        SMTD_MT(CKC_D, KC_D, KC_LCTL)
        SMTD_MT(CKC_F, KC_F, KC_LSFT)

        SMTD_LT(CKC_ESC, KC_ESC, _MEDIA)
        SMTD_LT(CKC_SPC, KC_SPACE, _NAV)
        SMTD_LT(CKC_TAB, KC_TAB, _MOUSE)

        SMTD_MT(CKC_J, KC_J, KC_LSFT)
        SMTD_MT(CKC_K, KC_K, KC_LCTL)
        SMTD_MT(CKC_L, KC_L, KC_LALT)
        SMTD_MT(CKC_SCLN, KC_SCLN, KC_LGUI)

        SMTD_LT(CKC_ENT, KC_ENT, _FUNC)
        SMTD_LT(CKC_BSPC, KC_BSPC, _NUM)
        SMTD_LT(CKC_DEL, KC_DEL, _SYM)
    }
}

uint32_t get_smtd_timeout(uint16_t keycode, smtd_timeout timeout) {
    switch (keycode) {
        // left side
        case CKC_A:
            if (timeout == SMTD_TIMEOUT_TAP) return 350;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 20;
            break;
        case CKC_S:
            if (timeout == SMTD_TIMEOUT_TAP) return 300;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 20;
            break;
        case CKC_D:
            if (timeout == SMTD_TIMEOUT_TAP) return 300;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 20;
            break;
        case CKC_F:
            if (timeout == SMTD_TIMEOUT_TAP) return 300;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 20;
            break;

        case CKC_ESC:
            if (timeout == SMTD_TIMEOUT_TAP) return 300;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 20;
            break;
        case CKC_SPC:
            if (timeout == SMTD_TIMEOUT_TAP) return 300;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 20;
            break;
        case CKC_TAB:
            if (timeout == SMTD_TIMEOUT_TAP) return 300;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 20;
            break;

        // right side
        case CKC_J:
            if (timeout == SMTD_TIMEOUT_TAP) return 300;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 20;
            break;
        case CKC_K:
            if (timeout == SMTD_TIMEOUT_TAP) return 300;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 20;
            break;
        case CKC_L:
            if (timeout == SMTD_TIMEOUT_TAP) return 300;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 20;
            break;
        case CKC_SCLN:
            if (timeout == SMTD_TIMEOUT_TAP) return 350;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 20;
            break;

        case CKC_ENT:
            if (timeout == SMTD_TIMEOUT_TAP) return 500;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 50;
            break;
        case CKC_BSPC:
            if (timeout == SMTD_TIMEOUT_TAP) return 300;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 20;
            break;
        case CKC_DEL:
            if (timeout == SMTD_TIMEOUT_TAP) return 300;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 20;
            break;
   }

    return get_smtd_timeout_default(timeout);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_smtd(keycode, record)) {
        return false;
    }
    return true; // Continue processing
}



#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _NAV,
    _NUM,
    _FUN,
};

enum custom_keycodes {
    SMTD_KEYCODES_BEGIN = SAFE_RANGE,
    CKC_A,
    CKC_S,
    CKC_D,
    CKC_F,

    CKC_SPC,

    CKC_J,
    CKC_K,
    CKC_L,
    CKC_SCLN,
    CKC_DOT,

    CKC_BSPC,
    CKC_DEL,

    SMTD_KEYCODES_END,
};

#include "sm_td.h"
// https://github.com/stasmarkin/sm_td
// Https://github.com/azzamsa/qmk_userspace/blob/main/keyboards/sofle/keymaps/azzamsa/keymap.c
// Layer definitions

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_LBRC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_RBRC,   CKC_A,   CKC_S,   CKC_D,   CKC_F,    KC_G,                         KC_H,   CKC_J,   CKC_K,   CKC_L,CKC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  CKC_DOT, KC_SLSH, KC_GRV,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_ESC, CKC_SPC, KC_TAB,    KC_ENT,  CKC_BSPC, CKC_DEL
                                      //`--------------------------'  `--------------------------'
    ),

    [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT,   KC_NO,                      KC_AGIN, KC_UNDO,  KC_CUT, KC_COPY, KC_PSTE, KC_VOLU,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,   KC_NO,                        KC_NO, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_VOLD,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                       KC_INS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_MUTE,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_NO ,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO
                                    //`--------------------------'  `--------------------------'
    ),

    [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO, KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_SCLN,    KC_4,    KC_5,    KC_6,  KC_EQL,                        KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_GRV,   KC_1,    KC_2,    KC_3, KC_BSLS,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_DOT,   KC_0,  KC_MINS,      KC_NO,   KC_NO,  KC_RALT
                                      //`--------------------------'  `--------------------------'
    ),
    [_FUN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,                        KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_NO ,   KC_NO,   KC_NO,      KC_NO,   KC_NO,  KC_RALT
                                      //`--------------------------'  `--------------------------'
    ),
 };

void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        // Modifier Tap Definitions
        SMTD_MT(CKC_A, KC_A, KC_LGUI)   // A with Left GUI when held
        SMTD_MT(CKC_S, KC_S, KC_LALT)   // S with Left ALT when held
        SMTD_MT(CKC_D, KC_D, KC_LCTL)   // D with Left Control when held
        SMTD_MT(CKC_F, KC_F, KC_LSFT)   // F with Left Shift when held

        // Layer Tap Definitions
        SMTD_LT(CKC_SPC, KC_SPACE, _NAV) // Space bar for number layer

        // Additional Modifier Taps
        SMTD_MT(CKC_J, KC_J, KC_LSFT)    // J with Left Shift when held
        SMTD_MT(CKC_K, KC_K, KC_LCTL)    // K with Left Control when held
        SMTD_MT(CKC_L, KC_L, KC_LALT)    // L with Left ALT when held
        SMTD_MT(CKC_SCLN, KC_SCLN, KC_LGUI) // Semicolon with Left GUI when held
        SMTD_MT(CKC_DOT, KC_DOT, KC_RALT) // Semicolon with Left GUI when held

        SMTD_LT(CKC_DEL, KC_DEL, _FUN) // Space bar for number layer
        SMTD_LT(CKC_BSPC, KC_BSPC, _NUM) // Space bar for number layer
}
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_smtd(keycode, record)) {
        return false;
    }
        return true;
}

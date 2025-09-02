#include QMK_KEYBOARD_H
#include "sm_td.h"

enum layer_names {
    _BASE,
    _GAM,
    _MSE,
    _NAV,
    _NUM,
    _SYM,
    _FUN,
    _MSE,
    _GAM,
};

// Custom keycodes for mod-tap behavior
enum custom_keycodes {
    CKC_A = SAFE_RANGE,
    CKC_S,
    CKC_D,
    CKC_F,
    CKC_J,
    CKC_K,
    CKC_L,
    CKC_SCLN,
    CKC_TAB,
    CKC_SPC,
    CKC_ESC,
    CKC_BSPC,
    CKC_DEL,
};

enum combos {
    COMBO_MOUSE,
};

// Define combo keys - V and M keys for mouse layer
const uint16_t PROGMEM combo_mouse[] = {KC_M, KC_COMM, COMBO_END};

// Map combos to actions
combo_t key_combos[] = {
    [COMBO_MOUSE] = COMBO(combo_mouse, OSL(_MSE)), // One-shot layer for mouse
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_LBRC,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_RBRC,     CKC_A,   CKC_S,   CKC_D,   CKC_F,    KC_G,                         KC_H,   CKC_J,   CKC_K,   CKC_L, CKC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      TG(_GAM),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_GRV,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          CKC_ESC, CKC_SPC, CKC_TAB,    KC_ENT, CKC_BSPC, CKC_DEL
    ),
    [_GAM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     TG(_GAM),     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_GRV,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_ESC, KC_SPC, KC_TAB,    KC_ENT, CKC_BSPC, KC_DEL
                                      //`--------------------------'  `--------------------------'
    ),
    [_GAM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     TG(_GAM),    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_GRV,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_ESC,  KC_SPC,  KC_TAB,     KC_ENT, KC_BSPC,   KC_DEL
                                      //`--------------------------'  `--------------------------'
    ),

    [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_AGIN, KC_UNDO,  KC_CUT, KC_COPY, KC_PSTE,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL,   KC_NO,                      KC_CAPS, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_VOLD,                        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_NO, XXXXXXX,   KC_NO,     CW_TOGG, KC_NO,  KC_NO
                                      //`--------------------------'  `--------------------------'
    ),
[_MSE] = LAYOUT_split_3x6_3(
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_NO, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,   KC_NO,                        KC_NO, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI,   KC_NO,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_NO, KC_WH_L, KC_WH_D,  KC_WH_U,   KC_WH_R,   KC_NO,                     KC_NO, XXXXXXX,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_BTN3, KC_BTN1,KC_BTN2, KC_NO,   XXXXXXX,   KC_NO
                                //`--------------------------'  `--------------------------'
),
    [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO, KC_LBRC, KC_7   , KC_8   , KC_9   , KC_RBRC,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_SCLN, KC_4   , KC_5   , KC_6   , KC_EQL ,                        KC_NO, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_GRV , KC_1   , KC_2   , KC_3   , KC_BSLS,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_DOT,    KC_0, KC_MINS,      KC_NO, XXXXXXX,   KC_NO
                                      //`--------------------------'  `--------------------------'
    ),

    [_FUN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,  KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_PSCR,                      QK_BOOT, KC_RAL), CW_TOGG,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,  KC_F11,   KC_F4,   KC_F5,   KC_F6, KC_SCRL,                        KC_NO, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,  KC_F10,   KC_F1,   KC_F2,   KC_F3, KC_PAUS,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX, KC_NO, KC_NO,    KC_MSTP, KC_MPLY, KC_MUTE
                                      //`--------------------------'  `--------------------------'
    ),

    [_MSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, QK_BOOT,                        QK_BOOT,   KC_UNDO,   KC_CUT,   KC_COPY,   KC_PSTE,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL,   KC_NO,                        KC_NO, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        XXXXXXX,   KC_NO,   KC_NO,    KC_BTN2, KC_BTN1, KC_BTN3
                                      //`--------------------------'  `--------------------------'
    ),
    // ... rest of your layers remain unchanged ...
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_smtd(keycode, record)) {
        return false;
    }

    // your code here

    return true;
}
CD
smtd_resolution on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        // Left home row: GUI, Alt, Shift, Control
        SMTD_MT_ON_MKEY(CKC_A, KC_A, KC_LGUI)
        SMTD_MT_ON_MKEY(CKC_S, KC_S, KC_LALT)
        SMTD_MT_ON_MKEY(CKC_D, KC_D, KC_LSFT)
        SMTD_MT_ON_MKEY(CKC_F, KC_F, KC_LCTL)

        // Left cluster
        SMTD_LT_ON_MKEY(CKC_ESC, KC_ESC, _FUNg)
        SMTD_LT_ON_MKEY(CKC_TAB, KC_TAB, _MSE)
        SMTD_LT_ON_MKEY(CKC_SPC, KC_SPACE, _NAV)

        // Right row: Control, Shift, Alt, GUI
        SMTD_MT_ON_MKEY(CKC_J, KC_J, KC_LCTL)
        SMTD_MT_ON_MKEY(CKC_K, KC_K, KC_LSFT)
        SMTD_MT_ON_MKEY(CKC_L, KC_L, KC_LALT)
        SMTD_MT_ON_MKEY(CKC_SCLN, KC_SCLN, KC_LGUI)

        // Right cluster
        SMTD_LT_ON_MKEY(CKC_BSPC, KC_BSPC, _NUM)
        SMTD_LT_ON_MKEY(CKC_DEL, KC_DEL, _SYM)
    }

    return SMTD_RESOLUTION_UNHANDLED;
}


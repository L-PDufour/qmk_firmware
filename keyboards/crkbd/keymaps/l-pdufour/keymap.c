#include QMK_KEYBOARD_H
#include "sm_td.h"

enum layer_names {
    _BASE,
    _GAM,
    _NAV,
    _NUM,
    _SYM,
    _FUN,
    _MSE,
};

#define WM_1 LGUI(KC_1)
#define WM_2 LGUI(KC_2)
#define WM_3 LGUI(KC_3)
#define WM_4 LGUI(KC_4)
#define WM_5 LGUI(KC_5)

// Custom keycodes for mod-tap behavior
enum custom_keycodes {
    HM_A = SAFE_RANGE,
    HM_S,
    HM_D,
    HM_F,
    HM_J,
    HM_K,
    HM_L,
    HM_SCLN,
    CKC_SPC,
    CKC_ESC,
    CKC_BSPC,
    CKC_DEL,
    HM_SLSH,
    HM_LBRC,
    HM_RBRC,
    HM_QUOT,
    HM_4,
    HM_5,
    HM_6,
    HM_MINS,

};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     TG(_GAM),    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LBRC,   HM_A,    HM_S,    HM_D,    HM_F,    KC_G,                         KC_H,    HM_J,    HM_K,    HM_L, HM_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_RBRC,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_GRV,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_ESC, CKC_SPC, KC_TAB,    KC_ENT, CKC_BSPC, CKC_DEL
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
        KC_NO, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, KC_VOLU,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT,KC_MUTE,                        KC_NO, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_VOLD,                        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_NO ,   KC_NO,   KC_NO,      KC_NO,   XXXXXXX,   KC_NO
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
        KC_NO, KC_PIPE, KC_LCBR, KC_RCBR,  KC_DQT,   KC_NO,                        KC_NO,    KC_7,    KC_8,    KC_9, KC_PAST,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, HM_SLSH, HM_LBRC, HM_RBRC, HM_QUOT,   KC_NO,                        KC_NO,    HM_4,    HM_5,    HM_6, HM_MINS,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_BSLS, KC_LPRN, KC_RPRN,  KC_GRV,   KC_NO,                        KC_NO,    KC_1,    KC_2,    KC_3, KC_PPLS,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_NO, XXXXXXX,   KC_NO,    KC_PEQL,    KC_0,  KC_DOT
                                      //`--------------------------'  `--------------------------'
    ),

    [_FUN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,                        KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,    WM_1,    WM_2,    WM_3,    WM_4,    WM_5,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_NO,OSM(MOD_RALT), CW_TOGG,      KC_NO,   KC_NO, XXXXXXX
                                      //`--------------------------'  `--------------------------'
    ),
 };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_smtd(keycode, record)) {
        return false;
    }

    // your code here

    return true;
}

smtd_resolution on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        // Left home row: GUI, Alt, Shift, Control
        SMTD_MT_ON_MKEY(HM_A, KC_A, KC_LGUI)
        SMTD_MT_ON_MKEY(HM_S, KC_S, KC_LALT)
        SMTD_MT_ON_MKEY(HM_D, KC_D, KC_LSFT)
        SMTD_MT_ON_MKEY(HM_F, KC_F, KC_LCTL)

        SMTD_MT_ON_MKEY(HM_SLSH, KC_SLSH, KC_LGUI)
        SMTD_MT_ON_MKEY(HM_LBRC, KC_LBRC, KC_LALT)
        SMTD_MT_ON_MKEY(HM_RBRC, KC_RBRC, KC_LSFT)
        SMTD_MT_ON_MKEY(HM_QUOT, KC_QUOT, KC_LCTL)
        // Left cluster
        SMTD_LT_ON_MKEY(CKC_SPC, KC_SPACE, _NUM)

        // Right row: Control, Shift, Alt, GUI
        SMTD_MT_ON_MKEY(HM_J, KC_J, KC_LCTL)
        SMTD_MT_ON_MKEY(HM_K, KC_K, KC_LSFT)
        SMTD_MT_ON_MKEY(HM_L, KC_L, KC_LALT)
        SMTD_MT_ON_MKEY(HM_SCLN, KC_SCLN, KC_LGUI)

        SMTD_MT_ON_MKEY(HM_4, KC_4, KC_LCTL)
        SMTD_MT_ON_MKEY(HM_5, KC_5, KC_LSFT)
        SMTD_MT_ON_MKEY(HM_6, KC_6, KC_LALT)
        SMTD_MT_ON_MKEY(HM_MINS, KC_MINS, KC_LGUI)

        // Right cluster
        SMTD_LT_ON_MKEY(CKC_BSPC, KC_BSPC, _NAV)
        SMTD_LT_ON_MKEY(CKC_DEL, KC_DEL, _FUN)


    }

    return SMTD_RESOLUTION_UNHANDLED;
}

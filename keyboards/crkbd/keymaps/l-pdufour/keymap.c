#include QMK_KEYBOARD_H
#include "oneshot.h"
enum layer_names {
    _BASE,
    _NAV,
    _MOUSE,
    _SYM,
    _NUM,
    _FUN,
};
/* enum combo_events { */
/*     LCTL, */
/*     LALT, */
/*     LGUI, */
/*     RCTL, */
/*     RALT, */
/*     RGUI, */
/*     RALTGR, */
/* }; */
/* const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END}; */
/* const uint16_t PROGMEM sf_combo[] = {KC_S, KC_F, COMBO_END}; */
/* const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END}; */
/* const uint16_t PROGMEM sdf_combo[] = {KC_S, KC_D, KC_F,  COMBO_END}; */
/* const uint16_t PROGMEM kj_combo[] = {KC_K, KC_J, COMBO_END}; */
/* const uint16_t PROGMEM lj_combo[] = {KC_L, KC_J, COMBO_END}; */
/* const uint16_t PROGMEM lk_combo[] = {KC_L, KC_K, COMBO_END}; */
/* const uint16_t PROGMEM lkj_combo[] = {KC_L, KC_K, KC_J, COMBO_END}; */
/**/
/* combo_t key_combos[] = { */
/*   [LCTL] = COMBO(df_combo, KC_LCTL), */
/*   [LALT] = COMBO(sf_combo, KC_LALT), */
/*   [LGUI] = COMBO(sd_combo, KC_LGUI), */
/*   [RCTL] = COMBO(kj_combo, KC_LCTL), */
/*   [RALT] = COMBO(lj_combo, KC_LALT), */
/*   [RGUI] = COMBO(lk_combo, KC_LGUI), */
/*   [RALTGR] = COMBO(lkj_combo, KC_RALT), */
/* }; */

enum custom_keycodes {
    SMTD_KEYCODES_BEGIN = SAFE_RANGE,
    CKC_SPC,
    CKC_TAB,
    CKC_ENT,
    CKC_BSPC,
    CKC_DEL,
    SMTD_KEYCODES_END,
};

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_LGUI,

    /* SW_WIN,  // Switch to next window         (cmd-tab) */
    /* SW_LANG, // Switch to next input language (ctl-spc) */
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
      KC_RBRC,   KC_A,   KC_S,   KC_D,   KC_F,    KC_G,                         KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_GRV,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_ESC, CKC_SPC, CKC_TAB,    CKC_ENT,  CKC_BSPC, CKC_DEL
                                      //`--------------------------'  `--------------------------'
    ),

    [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT,   KC_NO,                      KC_AGIN, KC_UNDO,  KC_CUT, KC_COPY, KC_PSTE, KC_VOLU,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, OS_LGUI, OS_ALT, OS_CTRL, OS_SHFT,   KC_NO,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, KC_NO, KC_VOLD,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                       KC_INS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_MUTE,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_NO ,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO
                                    //`--------------------------'  `--------------------------'
    ),
    [_MOUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_AGIN, KC_UNDO,  KC_CUT, KC_COPY, KC_PSTE,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, OS_LGUI, OS_ALT, OS_CTRL, OS_SHFT,   KC_NO,                      MS_LEFT, MS_DOWN,   MS_UP, MS_RGHT,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR,   KC_NO,    KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_NO,   KC_NO,  KC_NO,     MS_BTN3, MS_BTN1, MS_BTN2
                                    //`--------------------------'  `--------------------------'
    ),
    [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO, KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_SCLN,    KC_4,    KC_5,    KC_6,  KC_EQL,                        KC_NO, OS_SHFT, OS_CTRL, OS_ALT, OS_LGUI,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_GRV,   KC_1,    KC_2,    KC_3, KC_BSLS,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_DOT,   KC_0,  KC_MINS,      KC_NO,   KC_NO,  KC_RALT
                                      //`--------------------------'  `--------------------------'
    ),
    [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO, KC_LBRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RBRC,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_COLN,  KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,                        KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_TILD, KC_EXLM,   KC_AT, KC_HASH, KC_PIPE,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_LPRN,KC_RPRN,  KC_UNDS,      KC_NO,   KC_NO,  KC_RALT
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
        SMTD_LT(CKC_SPC, KC_SPACE, _NAV) // Space bar for number layer
        SMTD_LT(CKC_TAB, KC_TAB, _MOUSE) // Space bar for number layer
        SMTD_LT(CKC_DEL, KC_DEL, _FUN) // Space bar for number layer
        SMTD_LT(CKC_BSPC, KC_BSPC, _NUM) // Space bar for number layer
        SMTD_LT(CKC_ENT, KC_ENT, _SYM) // Space bar for number layer
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_LGUI:
        return true;
    default:
        return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

uint32_t get_smtd_timeout(uint16_t keycode, smtd_timeout timeout) {
    switch (keycode) {

        case CKC_TAB:
            if (timeout == SMTD_TIMEOUT_TAP) return 300;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 20;
            break;
        case CKC_SPC:
            if (timeout == SMTD_TIMEOUT_TAP) return 300;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 20;
            break;
        /* case CKC_LSFT: */
        /*     if (timeout == SMTD_TIMEOUT_TAP) return 300; */
        /*     if (timeout == SMTD_TIMEOUT_RELEASE) return 20; */
        /*     break; */

        case CKC_ENT:
            if (timeout == SMTD_TIMEOUT_TAP) return 300;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 20;
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
    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LGUI, OS_LGUI,
        keycode, record
    );
        return true;
}

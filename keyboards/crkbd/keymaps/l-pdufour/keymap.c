#include QMK_KEYBOARD_H
#include "oneshot.h"


enum layer_names {
    _BASE,
    _GAM,
    _NAV,
    _NUM,
    _SYM,
    _FUN,
    _MSE,
};

// Custom keycodes for Callum-style one-shot mods
enum custom_keycodes {
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_GUI,
};

#define WM_1 LGUI(KC_1)
#define WM_2 LGUI(KC_2)
#define WM_3 LGUI(KC_3)
#define WM_4 LGUI(KC_4)
#define WM_5 LGUI(KC_5)
#define WM_B LGUI(KC_TAB)

// Layer Taps for thumb keys
#define LT_SPC LT(_SYM, KC_SPC)
#define LT_BSPC LT(_NUM, KC_BSPC)
#define LT_TAB LT(_NAV, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
      KC_NO, KC_Q, KC_W, KC_E, KC_R, KC_T,     KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_NO,
      KC_NO, KC_A, KC_S, KC_D, KC_F, KC_G,     KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_NO,
      KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B,     KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO,
                   KC_ESC, LT_SPC, LT_TAB,     KC_ENT, LT_BSPC, KC_DEL
    ),
    [_NAV] = LAYOUT_split_3x6_3(
      KC_NO, KC_NO,  KC_CUT, KC_COPY, KC_PSTE, KC_NO,    KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, KC_VOLU, KC_NO,
      KC_NO, OS_GUI, OS_ALT, OS_SHFT, OS_CTRL, KC_NO,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_MUTE, KC_NO,
      KC_NO, WM_1,   WM_2,   WM_3,    WM_4,     WM_5,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_VOLD, KC_NO,
                           _______, _______, XXXXXXX,    KC_NO, KC_NO, KC_NO
    ),
    [_NUM] = LAYOUT_split_3x6_3(
      KC_NO, KC_NO,  KC_7, KC_8, KC_9,   KC_NO,    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
      KC_NO, KC_EQL, KC_4, KC_5, KC_6, KC_MINS,    KC_NO, OS_CTRL, OS_SHFT, OS_ALT,  OS_GUI, KC_NO,
      KC_NO, KC_NO,  KC_1, KC_2, KC_3,   KC_NO,    KC_NO, KC_NO,   KC_NO,   OS_RALT, KC_NO,  KC_NO,
                        _______, KC_0, _______,    _______, XXXXXXX, _______
    ),

    [_SYM] = LAYOUT_split_3x6_3(
      KC_NO, KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,     KC_NO, KC_QUOT, KC_GRV,  KC_BSLS, KC_NO, KC_NO,
      KC_NO, OS_GUI, OS_ALT, OS_SHFT, OS_CTRL, KC_NO,     KC_NO, KC_LBRC, KC_RBRC, KC_NO,   KC_NO, KC_NO,
      KC_NO, KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,     KC_NO, KC_LPRN, KC_RPRN, KC_NO,   KC_NO, KC_NO,
                           _______, XXXXXXX, _______,     _______, MO(_FUN), _______
    ),
    [_FUN] = LAYOUT_split_3x6_3(
      KC_NO, KC_NO,  KC_F7, KC_F8, KC_F9,   KC_NO,    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
      KC_NO, KC_NO,  KC_F4, KC_F5, KC_F6, CW_TOGG,    KC_NO, OS_CTRL, OS_SHFT, OS_ALT,  OS_GUI, KC_NO,
      KC_NO, KC_NO,  KC_F1, KC_F2, KC_F3, KC_CAPS,    KC_NO, KC_NO,   KC_NO,   OS_RALT, KC_NO,  KC_NO,
                           KC_F10, KC_F11, KC_F12,    _______,  _______, _______
    ),
};

// Callum-style one-shot mods implementation
bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case KC_ESC:
               return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case LT_SPC:
        case LT_BSPC:
        case LT_TAB:
        case OS_SHFT:
        case OS_CTRL:
        case OS_ALT:
        case OS_GUI:
            return true;
        default:
            return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_gui_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
        &os_gui_state, KC_LGUI, OS_GUI,
        keycode, record
    );

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_oneshot_layer(state, _SYM);
}

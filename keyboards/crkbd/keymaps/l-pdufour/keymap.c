#include QMK_KEYBOARD_H
enum layer_names {
    _BASE,
    _NAV,
    _NUM,
    _FUN,
};
enum custom_keycodes {
    PAREN_KEY = SAFE_RANGE
};
// Base home row
#define HM_A LGUI_T(KC_A)
#define HM_S LALT_T(KC_S)
#define HM_D LSFT_T(KC_D)
#define HM_F LCTL_T(KC_F)
#define HM_J RCTL_T(KC_J)
#define HM_K RSFT_T(KC_K)
#define HM_L LALT_T(KC_L)
#define HM_SCLN RGUI_T(KC_SCLN)
// Num home row
#define HM_SLSH LGUI_T(KC_SLSH)
#define HM_LBRC LALT_T(KC_LBRC)
#define HM_RBRC RSFT_T(KC_RBRC)
#define HM_QUOT LCTL_T(KC_QUOT)
#define HM_4 RCTL_T(KC_4)
#define HM_5 RSFT_T(KC_5)
#define HM_6 LALT_T(KC_6)
#define HM_MINS RGUI_T(KC_MINS)
// Window
#define WM_1 LGUI(KC_1)
#define WM_2 LGUI(KC_2)
#define WM_3 LGUI(KC_3)
#define WM_4 LGUI(KC_4)
#define WM_5 LGUI(KC_5)

#define CKC_LPRN RGUI_T(KC_SCLN)
#define CKC_SPC LT(_NUM, KC_SPC)
#define CKC_BSPC LT(_NAV, KC_BSPC)
#define CKC_DEL LT(_FUN, KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_LBRC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_RBRC,    HM_A,    HM_S,    HM_D,    HM_F,    KC_G,                         KC_H,    HM_J,    HM_K,    HM_L, HM_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    PAREN_KEY,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_GRV,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_ESC, CKC_SPC, KC_TAB,    KC_ENT, CKC_BSPC, CKC_DEL
                                      //`--------------------------'  `--------------------------'
    ),

    [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, KC_VOLU,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT,KC_MUTE,                        KC_NO, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_VOLD,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_NO ,   KC_NO,   KC_NO,      KC_NO,   XXXXXXX,   KC_NO
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
  /*   [_SYM] = LAYOUT_split_3x6_3( */
  /* //,-----------------------------------------------------.                    ,-----------------------------------------------------. */
  /*       KC_NO, KC_LBRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RBRC,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, */
  /* //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------| */
  /*       KC_NO, KC_COLN,  KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,                        KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,   KC_NO, */
  /* //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------| */
  /*       KC_NO, KC_TILD, KC_EXLM,   KC_AT, KC_HASH, KC_PIPE,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, */
  /* //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------| */
  /*                                          KC_LPRN,KC_RPRN,  KC_UNDS,      KC_NO,   KC_NO,  KC_RALT */
  /*                                     //`--------------------------'  `--------------------------' */
  /*   ), */
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
    switch (keycode) {
        case PAREN_KEY:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    SEND_STRING(")");
                } else {
                    SEND_STRING("(");
                }
            }
            return false;
        default:
            return true;
    }
}

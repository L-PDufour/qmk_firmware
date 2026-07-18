#include QMK_KEYBOARD_H
enum layer_names {
    _BASE,
    _SYM,
    _NAV,
    _NUM,
    _FUN,
    _GAMING,
};
// Combo definitions


const uint16_t PROGMEM dquote_combo[] = {KC_R, KC_E, COMBO_END};
const uint16_t PROGMEM quote_combo[] = {KC_R, KC_W, COMBO_END};
const uint16_t PROGMEM squote_combo[] = {KC_R, KC_Q, COMBO_END};
const uint16_t PROGMEM eql_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM mins_combo[] = {KC_U, KC_O, COMBO_END};
const uint16_t PROGMEM bsls_combo[] = {KC_U, KC_P, COMBO_END};

combo_t key_combos[] = {
    COMBO(quote_combo, KC_QUOT),
    COMBO(squote_combo, KC_GRV),
    COMBO(dquote_combo, KC_DQUO),
    COMBO(eql_combo, KC_EQL),
    COMBO(mins_combo, KC_MINS),
    COMBO(bsls_combo, KC_BSLS),
};

// Base home row
#define HM_A LGUI_T(KC_A)
#define HM_S LALT_T(KC_S)
#define HM_D LSFT_T(KC_D)
#define HM_F LCTL_T(KC_F)

#define HM_J RCTL_T(KC_J)
#define HM_K LSFT_T(KC_K)
#define HM_L LALT_T(KC_L)
#define HM_SCLN LGUI_T(KC_SCLN)

// Window
#define WM_1 LGUI(KC_1)
#define WM_2 LGUI(KC_2)
#define WM_3 LGUI(KC_3)
#define WM_4 LGUI(KC_4)
#define WM_5 LGUI(KC_5)

#define CKC_SPC LT(_NAV, KC_SPC)

#define CKC_ENT LT(_SYM, KC_ENT)
#define CKC_BSPC LT(_NUM, KC_BSPC)
#define CKC_DEL LT(_FUN, KC_DEL)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
          KC_NO,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_NO,
          KC_NO,    HM_A,    HM_S,    HM_D,    HM_F,    KC_G,    KC_H,    HM_J,    HM_K,    HM_L, HM_SCLN,   KC_NO,
          KC_NO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   KC_NO,
                                     KC_ESC, CKC_SPC, KC_TAB,    CKC_ENT, CKC_BSPC,  CKC_DEL
      ),
    [_SYM] = LAYOUT_split_3x6_3(
          KC_NO, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
          KC_NO, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,    KC_NO, OS_LCTL, OS_LSFT, OS_LALT, OS_LGUI, KC_NO,
          KC_NO, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,    KC_NO, KC_NO,   KC_NO,   OS_RALT, KC_NO,   KC_NO,
                                   KC_LPRN, KC_RPRN, KC_UNDS,    XXXXXXX, KC_NO, KC_NO
      ),
    [_NUM] = LAYOUT_split_3x6_3(
                   KC_NO, KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC,    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                   KC_NO, KC_SCLN, KC_4, KC_5, KC_6,  KC_EQL,    KC_NO, OS_LCTL, OS_LSFT, OS_LALT, OS_LGUI, KC_NO,
                   KC_NO, KC_GRV,  KC_1, KC_2, KC_3, KC_BSLS,    KC_NO, KC_NO,   KC_NO,   OS_RALT, KC_NO,   KC_NO,
                                       KC_DOT, KC_0, KC_MINS,    KC_NO, XXXXXXX, KC_NO
      ),
   [_FUN] = LAYOUT_split_3x6_3(
                 KC_NO, KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR,    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                 KC_NO, KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL,    KC_NO, OS_LCTL, OS_LSFT, OS_LALT, OS_LGUI, KC_NO,
                 KC_NO, KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS,    KC_NO, KC_NO,   KC_NO,   OS_RALT, KC_NO,   KC_NO,
                               TO(_GAMING), CW_TOGG, KC_CAPS,    KC_NO, KC_NO, XXXXXXX
      ),
   [_NAV] = LAYOUT_split_3x6_3(
             KC_NO, KC_UNDO, KC_CUT, KC_COPY, KC_PSTE, KC_NO,    KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, KC_VOLU, KC_NO,
             KC_NO, OS_LGUI,  OS_LALT, OS_LSFT, OS_LCTL, KC_NO,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_MUTE, KC_NO,
             KC_NO, WM_1,    WM_2,   WM_3,    WM_4,     WM_5,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_VOLD, KC_NO,
                                       KC_NO, XXXXXXX, KC_NO,    KC_NO, KC_NO, KC_NO
      ),
   [_GAMING] = LAYOUT_split_3x6_3(
          KC_NO,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_NO,
          KC_NO,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,   KC_NO,
          KC_NO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT,TO(_BASE),   KC_NO,
                                            KC_ESC, KC_SPC, KC_TAB,    KC_ENT, MO(_NUM),  MO(_FUN)
                                   ),
 };

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
                       '*', '*', '*',  '*', '*', '*'
    );

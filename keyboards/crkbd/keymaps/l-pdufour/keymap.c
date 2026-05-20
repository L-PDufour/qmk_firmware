#include QMK_KEYBOARD_H
enum layer_names {
    _BASE,
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
#define CKC_BSPC LT(_NUM, KC_BSPC)
#define CKC_ESC LT(_FUN, KC_ESC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
          KC_NO,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_NO,
          KC_NO,    HM_A,    HM_S,    HM_D,    HM_F,    KC_G,                         KC_H,    HM_J,    HM_K,    HM_L, HM_SCLN,   KC_NO,
          KC_NO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   KC_NO,
                                             CKC_ESC, CKC_SPC, KC_TAB,    KC_ENT, CKC_BSPC,  KC_DEL
      ),
    [_NAV] = LAYOUT_split_3x6_3(
          KC_NO,   KC_NO, KC_VOLD, KC_MUTE, KC_VOLU, KC_COPY,                        KC_NO, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT,   KC_NO,
          KC_NO, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_PSTE,                      KC_CAPS, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,   KC_NO,
          KC_NO,    WM_1,    WM_2,    WM_3,    WM_4,    WM_5,                       KC_INS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,   KC_NO,
                                             KC_NO,  XXXXXXX,   KC_NO,      KC_ENT, KC_BSPC,  KC_DEL
      ),
[_NUM] = LAYOUT_split_3x6_3(
  KC_NO, KC_NO,   KC_7, KC_8, KC_9, KC_NO,      KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
  KC_NO, KC_SLSH, KC_4, KC_5, KC_6, KC_ASTR,    KC_NO, OS_LGUI, OS_LALT, OS_LSFT, OS_LCTL, KC_NO,
  KC_NO, KC_MINS, KC_1, KC_2, KC_3, KC_PLUS,    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
                        KC_DOT, KC_0, KC_EQL,   KC_NO, XXXXXXX, KC_NO
                            ),
[_SYM] = LAYOUT_split_3x6_3(
  KC_NO, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_NO,
  KC_NO, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_PIPE,    KC_BSLS, OS_LGUI, OS_LALT, OS_LSFT, OS_LCTL, KC_NO,
  KC_NO, KC_GRV,  KC_TILD, KC_MINS, KC_EQL,  KC_PLUS,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                            KC_NO, XXXXXXX,   KC_NO,      KC_NO, XXXXXXX, KC_NO
),
   [_FUN] = LAYOUT_split_3x6_3(
           KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_NO,
          KC_NO, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL,   KC_NO,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_NO,
          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_F11,  KC_F12,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                           XXXXXXX,    KC_NO,   KC_NO,   TO(_GAMING), OSM(MOD_RALT), CW_TOGG
      ),
    [_GAMING] = LAYOUT_split_3x6_3(
          KC_NO,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_NO,
          KC_NO,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,   KC_NO,
          KC_NO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT,TO(_BASE),   KC_NO,
                                            CKC_ESC, CKC_SPC, KC_TAB,    KC_ENT, MO(_NUM),  MO(_FUN)
      ),
 };

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
                       '*', '*', '*',  '*', '*', '*'
    );

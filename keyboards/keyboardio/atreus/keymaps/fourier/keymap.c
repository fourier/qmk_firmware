// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

enum layer_names {
    _QW,
    _FN,
    _SU,
};

#define SU_ENT LT(_SU, KC_ENT) /* SU when pressed, enter when tapped */
#define ALT_QUO LALT_T(KC_QUOT) /* alt when pressed, minus when tapped */
#define FN_TAB LT(_FN, KC_TAB) /* FN when pressed, tab when tapped */
#define SU_ESC LT(_SU, KC_ESC) /* SU when pressed, tab when tapped */
#define C_LEFT C(KC_LEFT)
#define C_RIGHT C(KC_RIGHT)
#define A_LEFT A(KC_LEFT)
#define A_RIGHT A(KC_RIGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Moved: ENT->CTL_ENT, MINS->ALT_MIN, TAB->FN_TAB, SUPER<->TAB to combo-keys, Missing: KC_MIN */
  [_QW] = LAYOUT( /* Qwerty */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,     KC_P    ,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    /*`*/             KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN ,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_GRV,  KC_HYPR, KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH ,
  /*Su/Esc  Fn/Tab                               ctl      alt/-_            FN       (             )    Enter */
    SU_ESC, FN_TAB, KC_LGUI,  KC_LSFT, KC_BSPC,  KC_LCTL, ALT_QUO, KC_SPC,  MO(_FN), KC_LPRN, KC_RPRN,  SU_ENT),

  /*'In Dvorak layout keys'
   *  !       @   M-up     $   %          ||       [     pgup    up      pgdn   *
   *  (       [   M-down   ]   )          ||       ]     left    dn      right  +
   *  /       =     #      ?   +   ^      ||  &  c-left  home    c-right end    /|
   *  FN  fn/tab super shift bksp ctrl    || alt space   Fn      {        }     Enter
   */
  [_FN] = LAYOUT( /* [> FN <] */
    KC_EXLM, KC_AT,   A_LEFT,  KC_DLR,  KC_PERC,                   KC_MINS, KC_PGUP, KC_UP,      KC_PGDN,   KC_PAST,
    KC_LPRN, KC_MINS, A_RIGHT, KC_EQL,  KC_RPRN,                   KC_EQL,  KC_LEFT, KC_DOWN,    KC_RIGHT,  KC_RCBR,
    KC_LBRC, KC_RBRC, KC_HASH, KC_LCBR, KC_RCBR, KC_CIRC, KC_AMPR, C_LEFT,  KC_HOME, C_RIGHT,    KC_END,    KC_BSLS,
    QK_LLCK, KC_LGUI, KC_TRNS, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  MO(_SU), S(KC_MINS), S(KC_EQL), SU_ENT ),

  /*
   * insert 7     8    9     prscr      ||      up     F7    F8    F9   F10
   *  del   4     5    6     scrl       ||     down    F4    F5    F6   F11
   *        1     2    3     0          ||     \       F1    F2    F3   F12
   *        voldn  super shift bksp ctrl || alt space   Fn    [      ]   Enter
   */
  [_SU] = LAYOUT( /* [> SUPER <] */
    KC_INS,  KC_7, KC_8, KC_9, KC_PSCR,                   KC_VOLU,   KC_F7,   KC_F8,   KC_F9,   KC_F10  ,
    KC_DEL,  KC_4, KC_5, KC_6, KC_SCRL,                   KC_VOLD, KC_F4,   KC_F5,   KC_F6,   KC_F11  ,
    KC_NO,   KC_1, KC_2, KC_3, KC_0,    _______, _______, KC_MUTE,   KC_F1,   KC_F2,   KC_F3,   KC_F12  ,
    KC_NO,   KC_VOLD,    KC_LGUI,  KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  TO(_QW), KC_MINS, KC_EQL, KC_ENT )
};

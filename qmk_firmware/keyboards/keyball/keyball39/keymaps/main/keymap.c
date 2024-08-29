/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_universal(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                            KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
    KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                            KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  ,
    KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                            KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  ,
    KC_LSFT  , KC_LCTL  , KC_LALT  ,LCMD_T(KC_LNG2),LT(1,KC_LNG1),LT(3,KC_SPC),KC_ENT,LT(2,KC_BSPC),LSFT_T(KC_LNG2),_______,_______, KC_MS_BTN1
  ),

  [1] = LAYOUT_universal(
    KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                            KC_6     , KC_7     , KC_8     , KC_9     , KC_0     ,
    KC_TAB   , _______  , _______  , _______  , _______  ,                           KC_MINUS  , KC_EQUAL , _______  , KC_UP    , KC_QUOTE ,
    _______  , _______  , _______  , _______  , _______  ,                           KC_GRAVE  , KC_BSLS  , KC_LEFT  , KC_DOWN  , KC_RIGHT ,
    _______  , _______  , LCTL(KC_LALT) , _______  , _______  , _______  ,      KC_LBRC  , KC_RBRC  , _______  , _______  , _______  , KC_EQUAL
  ),

  [2] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , KC_BSPC  ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , SCMD(KC_V), SCMD(KC_B),                          _______  , _______  , LAG(KC_LEFT) , _______ , LAG(KC_RIGHT) ,
    _______  , _______  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , _______  , KC_LSFT
  ),

  [3] = LAYOUT_universal(
    KC_ESC   , _______  , SSNP_VRT , SSNP_HOR , SSNP_FRE ,                            _______  , _______  , _______  , _______  , KC_F12   ,
    _______  , _______  , CPI_I100 , SCRL_DVI , AML_I50  ,                            _______  , _______  , KC_MS_BTN1  , KC_MS_BTN3 , KC_MS_BTN2 ,
    _______  , _______  , CPI_D100 , SCRL_DVD , AML_D50  ,                            _______  , _______  , KC_MS_BTN4  , _______    , KC_MS_BTN5 ,
    KBC_RST  , KBC_SAVE , AML_TO   , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , _______  , QK_BOOT
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

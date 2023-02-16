#include QMK_KEYBOARD_H
//#include <stdlib.h>
//#include <time.h>
#include <stdbool.h>

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE
};

/*
bool is_poe_qwer_enable;
uint16_t poe_qwer_timer = false;
uint16_t poe_qwer_interval = 5000; // 5000ms
uint16_t poe_qwer_keys[] = {KC_Q, KC_W, KC_E, KC_R};
uint16_t poe_qwer_turn = 0;
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
		 * ,-----------------------------------------.,----------------------------------------.
		 * |      |      |      |      |      |      ||      |      |      |      |      |      |
		 * |------+------+------+------+------+------||------+------+------+------+------+------|
		 * | Tab  |   Q  |   W  |   E  |   R  |   T  ||   Y  |   U  |   I  |   O  |   P  | Bksp |
		 * |------+------+------+------+------+------||------+------+------+------+------+------|
		 * | Raise|   A  |   S  |   D  |   F  |   G  ||   H  |   J  |   K  |   L  |   ;  |  "   |
		 * |------+------+------+------+------+------||------+------+------+------+------+------|
		 * | Shift|   Z  |   X  |   C  |   V  |   B  ||   N  |   M  |   ,  |   .  |   /  |SftEnt|
		 * |------+------+------+------+------+------||------+------+------+------+------+------|
		 * | Ctrl | GUI  | Alt  |Lower |Space |Space ||Lower | RALT |      |      |      | rctrl|
		 * `-----------------------------------------'`-----------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,	\
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,	\
  RAISE,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,	\
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH,KC_SFTENT, \
  KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  LOWER,   KC_RALT, _______, _______, _______, KC_RCTL	\
),

/* Lower
		 * ,-----------------------------------------.,----------------------------------------.
		 * |      |      |      |      |      |      ||      |      |      |      |      |      |
		 * |------+------+------+------+------+------||------+------+------+------+------+------|
		 * |      |  F1  |  F2  |  F3  |  F4  |  F5  ||   -  |   =  |   \  |   [  |   ]  | Del  |
		 * |------+------+------+------+------+------||------+------+------+------+------+------|
		 * | Esc  |  F6  |  F7  |  F8  |  F9  |  F10 ||   ←  |   ↓  |   ↑  |   →  |Insert|      |
		 * |------+------+------+------+------+------||------+------+------+------+------+------|
		 * |      |  F11 |  F12 |  F13 |  F14 |  F15 || Home | PgDn | PgUp |  End |      |      |
		 * |------+------+------+------+------+------||------+------+------+------+------+------|
		 * |      |      |      |Lower |      |      ||Lower |hanja |      |      |      |      |
		 * `-----------------------------------------'`-----------------------------------------'
 */
[_LOWER] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,	\
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_MINS, KC_EQL,  KC_BSLS, KC_LBRC, KC_RBRC, KC_DEL,	\
  KC_ESC,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_INS,  _______,	\
  _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,   \
  _______, _______, _______, LOWER,   _______, _______, LOWER,   KC_LNG2, _______, _______, _______, _______	\
),

/* Raise
		 * ,-----------------------------------------.,----------------------------------------.
		 * |      |      |      |      |      |      ||      |      |      |      |      |      |
		 * |------+------+------+------+------+------||------+------+------+------+------+------|
		 * |   `  |   1  |   2  |   3  |   4  |   5  ||   6  |   7  |   8  |   9  |   0  | Del  |
		 * |------+------+------+------+------+------||------+------+------+------+------+------|
		 * | Raise|   6  |   7  |   8  |   9  |   0  ||      |   4  |   5  |   6  |      |      |
		 * |------+------+------+------+------+------||------+------+------+------+------+------|
		 * |      |      |      |      |      |      ||   0  |   1  |   2  |   3  |      |      |
		 * |------+------+------+------+------+------||------+------+------+------+------+------|
		 * |      |      |      |      |      |      ||      |      |      |      |      |      |
		 * `-----------------------------------------'`-----------------------------------------'
 */
[_RAISE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,	\
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,	\
  RAISE,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, KC_4,    KC_5,    KC_6,    _______, _______,	\
  _______, _______, _______, _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,    _______, _______,   \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______	\
),


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool pressed_left = false;
bool pressed_right = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
	// socd cleaner
	case KC_J:
		if (record->event.pressed) {
			pressed_left = true;
			if (pressed_right) {
				unregister_code(KC_L);
			}
			register_code(KC_J);

		} else {
			pressed_left = false;
			unregister_code(KC_J);
			if (pressed_right) {
				register_code(KC_L);
			}
		}

      return false;
      break;
	case KC_L:
		if (record->event.pressed) {
			pressed_right = true;
			if (pressed_left) {
				unregister_code(KC_J);
			}
			register_code(KC_L);

		} else {
			pressed_right = false;
			unregister_code(KC_L);
			if (pressed_left) {
				register_code(KC_J);
			}
		}

      return false;
      break;
	// socd cleaner end
	// shift + up arrow = ?
	// case KC_UP:
	// 	if ((get_mods() & MOD_BIT(KC_RSFT)) == MOD_BIT(KC_RSFT)) {
	// 		if (record->event.pressed) {
	// 			register_code(KC_SLASH);
	// 		} else {
	// 			unregister_code(KC_SLASH);
	// 		}
	// 	} else {
	// 		if (record->event.pressed) {
	// 			register_code(KC_UP);
	// 		} else {
	// 			unregister_code(KC_UP);
	// 		}
	// 	}
	// 	return false;
	// 	break;
	/*
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_dvorak);
        #endif
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;*/
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        //update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        //update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        //update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        //update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    /*
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;*/
	  /*
    case POE_QWER:
      if (record->event.pressed) {
		  //is_poe_qwer_enable ^= 1;
		  //poe_qwer_timer = timer_read();
		  //srand((unsigned int)time(NULL));
		  //tap_code_delay(KC_Q, 1000 + 100.0*(float)rand()/RAND_MAX);
		  //tap_code_delay(KC_W, 1500 + 100.0*(float)rand()/RAND_MAX);
		  //tap_code_delay(KC_E, 2000 + 100.0*(float)rand()/RAND_MAX);
		  //tap_code_delay(KC_R, 2500 + 100.0*(float)rand()/RAND_MAX);
      } else {

      }
      return false;
      break;
	  */
  }
  return true;
}

/*
void matrix_scan_user(void) {
  if (is_poe_qwer_enable && timer_elapsed(poe_qwer_timer) >= poe_qwer_interval) {
    srand((unsigned int)time(NULL));
    poe_qwer_timer = timer_read();
    tap_code_delay(poe_qwer_keys[poe_qwer_turn], 100 + 20.0*(float)rand()/RAND_MAX);
	poe_qwer_turn = (poe_qwer_turn + 1)%4;  // sizeof(poe_qwer_keys) might better than magic number 4
	poe_qwer_interval = 4500 + 1000 * rand()/RAND_MAX;
  }
}
*/

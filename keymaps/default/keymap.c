#include QMK_KEYBOARD_H
#include "keymap_german.h"

#define _QWERTZ     0
#define _SET        1

enum custom_keycodes {
    CM_WLGT = SAFE_RANGE,
    CM_TGDP
};

bool display_enabled = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CM_WLGT:
            if (record->event.pressed) {
                // when keycode is pressed
                SEND_STRING(SS_LGUI("l"));
            } else {
                // when keycode is released
            }
            return true;
        case CM_TGDP:
            if (record->event.pressed) {
                // when keycode is pressed
                display_enabled = !display_enabled;
                oled_clear();
            } else {
                // when keycode is released
            }
            return true;
        default:
            return true;
    }
};

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    if (display_enabled)
    {
        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);

        switch (get_highest_layer(layer_state)) {
            case _QWERTZ:
                oled_write_P(PSTR("Default\n"), false);
                break;
            case _SET:
                oled_write_P(PSTR("Settings\n"), false);
                break;
            default:
                // Or use the write_ln shortcut over adding '\n' to the end of your string
                oled_write_ln_P(PSTR("Undefined"), false);
        }

        oled_write_P(PSTR("Auto-Shift:\n"), false);
        if (get_autoshift_state())
        {
            //oled_write_P(PSTR("- Enabled\n"), false);

            char autoshift_timeout_str_ms[6];
            snprintf(autoshift_timeout_str_ms, 6, "%d", get_autoshift_timeout());

            oled_write_P(PSTR("- "), false);
            oled_write_P(PSTR(autoshift_timeout_str_ms), false);
            oled_write_P(PSTR(" ms\n"), false);
        }
        else
        {
            oled_write_P(PSTR("- Disabled\n"), false);
        }
    }
}
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTZ] = LAYOUT(
                                                                                             KC_VOLD, KC_MUTE, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT,
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,       KC_F5,   KC_F6,   KC_F7,   KC_F8,        KC_F9,   KC_F10,  KC_F11,  KC_F12,    KC_PSCR, KC_SLCK, KC_PAUS,   CM_WLGT, KC_CALC, KC_NO,   KC_NO,
        DE_CIRC, DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_SS,   DE_ACUT, KC_BSPC,            KC_INS,  KC_HOME, KC_PGUP,   KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB,      DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    DE_UDIA, DE_PLUS,   KC_ENT,       KC_DEL,  KC_END,  KC_PGDN,   KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        LT(_SET, KC_CAPS), DE_A, DE_S,   DE_D,    DE_F,    DE_G,    DE_H,    DE_J,    DE_K,    DE_L,    DE_ODIA, DE_ADIA, DE_HASH,                                            KC_P4,   KC_P5,   KC_P6,
        KC_LSFT,   DE_LABK, DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_MINS, KC_RSFT,                            KC_UP,              KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_LCTL,   KC_LGUI,   KC_LALT,                       KC_SPC,                              KC_RALT,   KC_RGUI,   KC_APP,    KC_RCTL,      KC_LEFT, KC_DOWN, KC_RIGHT,  KC_P0,            KC_PDOT
    ),
    [_SET] = LAYOUT(
                                                                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   RESET,   KC_TRNS, KC_TRNS,   KC_TRNS, CM_TGDP, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                            KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ASTG,                            KC_ASUP,            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,                       KC_TRNS,                             KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,      KC_TRNS, KC_ASDN, KC_TRNS,   KC_TRNS,          KC_TRNS
    ),
};

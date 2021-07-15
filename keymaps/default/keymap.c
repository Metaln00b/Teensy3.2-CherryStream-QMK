#include QMK_KEYBOARD_H
#include "keymap_german.h"

#define _QWERTZ     0
#define _SET        1

enum custom_keycodes {
    CM_WLGT = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case CM_WLGT:
        if (record->event.pressed) {
            // when keycode is pressed
            SEND_STRING(SS_LGUI("l"));
        } else {
            // when keycode is released
        }
        break;
    }
    return true;
};
/*
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}*/

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    //render_logo();
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
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTZ] = LAYOUT(
                                                                                             KC_VOLD, KC_MUTE, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT,
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,       KC_F5,   KC_F6,   KC_F7,   KC_F8,        KC_F9,   KC_F10,  KC_F11,  KC_F12,    KC_PSCR, KC_SLCK, KC_PAUS,   CM_WLGT, KC_WHOM, KC_MAIL, KC_CALC,
        DE_CIRC, DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_SS,   DE_ACUT, KC_BSPC,            KC_INS,  KC_HOME, KC_PGUP,   KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB,      DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    DE_UDIA, DE_PLUS,   KC_ENT,       KC_DEL,  KC_END,  KC_PGDN,   KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        LT(_SET, KC_CAPS), DE_A, DE_S,   DE_D,    DE_F,    DE_G,    DE_H,    DE_J,    DE_K,    DE_L,    DE_ODIA, DE_ADIA, DE_HASH,                                            KC_P4,   KC_P5,   KC_P6,
        KC_LSFT,   DE_LABK, DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_MINS, KC_RSFT,                            KC_UP,              KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_LCTL,   KC_LGUI,   KC_LALT,                       KC_SPC,                              KC_RALT,   KC_RGUI,   KC_APP,    KC_RCTL,      KC_LEFT, KC_DOWN, KC_RIGHT,  KC_P0,            KC_PDOT
    ),
    [_SET] = LAYOUT(
                                                                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   RESET,   KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                            KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ASTG,                            KC_ASUP,            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,                       KC_TRNS,                             KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,      KC_TRNS, KC_ASDN, KC_TRNS,   KC_TRNS,          KC_TRNS
    ),
};

#if 0
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
                                                                                             KC_VOLD, KC_MUTE, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT,
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,       KC_F5,   KC_F6,   KC_F7,   KC_F8,        KC_F9,   KC_F10,  KC_F11,  KC_F12,    KC_PSCR, KC_SLCK, KC_PAUS,   CM_WLGT, KC_WHOM, KC_MAIL, KC_CALC,
        DE_CIRC, DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_SS,   DE_ACUT, KC_BSPC,            KC_INS,  KC_HOME, KC_PGUP,   KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB,      DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    DE_UDIA, DE_PLUS,   KC_ENT,       KC_DEL,  KC_END,  KC_PGDN,   KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_CAPS,       DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    DE_H,    DE_J,    DE_K,    DE_L,    DE_ODIA, DE_ADIA, DE_HASH,                                            KC_P4,   KC_P5,   KC_P6,
        KC_LSFT,   DE_LABK, DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_MINS, KC_RSFT,                            KC_UP,              KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_LCTL,   KC_LGUI,   KC_LALT,                       KC_SPC,                              KC_RALT,   KC_RGUI,   KC_APP,    KC_RCTL,      KC_LEFT, KC_DOWN, KC_RIGHT,  KC_P0,            KC_PDOT
    ),
};
#endif
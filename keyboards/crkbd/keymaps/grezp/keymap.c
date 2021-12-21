#include QMK_KEYBOARD_H
#include "enums.h"
#include "layer.h"

// [Init Variables] ----------------------------------------------------------//
// Oled timer similar to Drashna's
static uint32_t oled_timer = 0;
// Boolean to store the master LED clear so it only runs once.
bool master_oled_cleared = false;

#define _____    KC_TRNS
#define XXXXX    KC_NO

// Layer defines
#define NUM_ENT  LT(_NUM, KC_ENT)
#define SYM_ESC  LT(_SYM, KC_ESC)
#define NAV_TAB  LT(_NAV, KC_TAB)
#define T_QWER   TG(_QWERTY)
#define T_NUM    TO(_NUM)
#define T_SYM    TG(_SYM)
#define T_NAV    TG(_NUM)
#define L_FUNC   MO(_FUN)

#define CTL_SFT LSFT(KC_LCTRL)

// [Keymaps] -----------------------------------------------------------------//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT( \
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_DEL,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSPC,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       NAV_TAB,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_LALT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, KC_LGUI,\
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_LCTRL, SYM_ESC, KC_LSFT,     KC_SPC, NUM_ENT, KC_LSFT \
                                        //`--------------------------'  `--------------------------'
    ),

    [_QWERTY] = LAYOUT( \
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         _____,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    _____,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         _____,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,   _____,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         _____,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   _____,\
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             _____,   _____,   _____,      _____,   _____,   _____ \
                                        //`--------------------------'  `--------------------------'
    ),

    [_NUM] = LAYOUT(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,                        XXXXX,    KC_7,    KC_8,    KC_9, KC_LCBR, KC_RCBR,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------|
         T_NUM,   XXXXX, KC_LGUI, KC_LALT, KC_LCTL,   XXXXX,                       KC_DOT,    KC_4,    KC_5,    KC_6, KC_LPRN, KC_RPRN,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---------|
         XXXXX,   XXXXX,   XXXXX,   XXXXX, KC_LSFT,   XXXXX,                         KC_0,    KC_1,    KC_2,    KC_3, KC_LBRC, KC_RBRC,\
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             XXXXX,  L_FUNC,  KC_SPC,      XXXXX,   _____,   XXXXX \
                                        //`--------------------------'  `--------------------------'
    ),

    [_SYM] = LAYOUT(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         XXXXX, KC_BSLS, KC_PERC, KC_AMPR, KC_HASH,  KC_DLR,                        XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         XXXXX, KC_PLUS,  KC_EQL, KC_ASTR, KC_UNDS, KC_CIRC,                        XXXXX, KC_LCTL, KC_LALT, KC_LGUI,   XXXXX,   T_SYM,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         XXXXX,  KC_GRV, KC_EXLM, KC_PIPE, KC_MINS,   KC_AT,                        XXXXX, KC_LSFT,   XXXXX,   XXXXX,   XXXXX,   XXXXX,\
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             XXXXX,   _____,   XXXXX,    KC_BSPC,  L_FUNC,   XXXXX \
                                        //`--------------------------'  `--------------------------'
    ),

    [_FUN] = LAYOUT(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,                        XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         XXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_CAPS,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        T_QWER,   XXXXX,   XXXXX,   XXXXX,   XXXXX,  KC_F11,                       KC_F12,   XXXXX,   XXXXX,   XXXXX,   XXXXX,  KC_INS,\
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             XXXXX,   _____,   XXXXX,      XXXXX,   _____,   XXXXX \
                                        //`--------------------------'  `--------------------------'
    ),

    [_NAV] = LAYOUT(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         XXXXX, KC_PGUP,   KC_UP, KC_PGDN, KC_VOLU,   XXXXX,                        XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         _____, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD,   XXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,   XXXXX,   T_NAV,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         XXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,   XXXXX,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END,   XXXXX, KC_LGUI,\
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           CTL_SFT, KC_LCTL, KC_LSFT,    KC_RSFT, KC_LALT,   XXXXX \
                                        //`--------------------------'  `--------------------------'
    )

};

// [Tapping Term Per Key] ----------------------------------------------------//
/* uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) { */
/*     switch (keycode) { */
/*         case A_GUI: */
/*         case O_GUI: */
/*             return TAPPING_TERM + 75; */
/*         case SYM_ENT: */
/*         case NUM_ESC: */
/*             return TAPPING_TERM + 25; */
/*         default: */
/*             return TAPPING_TERM; */
/*     } */
/* } */

// [Process User Input] ------------------------------------------------------//
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef  OLED_ENABLE
        oled_timer = timer_read();
#endif
    }
    return true;
}

// [OLED Configuration] ------------------------------------------------------//
#ifdef OLED_ENABLE
// Init Oled and Rotate....
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master())
      return OLED_ROTATION_180;  // flips the display 180 to see it from my side
    return rotation;
}

// Read logo from font file
const char *read_logo(void);

// {OLED helpers} -----------------------------------------------//
// Render Logo
void render_logo(void) {
    oled_write(read_logo(), false);
}

// Master OLED Screen (Left Hand )
void render_master_oled(void) {
    render_separator();
    render_lock_state();
    render_separator();
    render_layer_state();
}

// Slave OLED scren (Right Hand)
void render_slave_oled(void) {
    render_logo();
}

// {OLED Task} -----------------------------------------------//
bool oled_task_user(void) {
    // First time out switches to logo as first indication of iddle.
    // TODO: Fix sleep timer logic
    if (timer_elapsed(oled_timer) > 100000 && timer_elapsed(oled_timer) < 479999) {
        // Render logo on both halves before full timeout
        if (is_keyboard_master() && !master_oled_cleared) {
            // Clear master OLED once so the logo renders properly
            oled_clear();
            master_oled_cleared = true;
        }
        render_logo();
        return false;
    }
    // Drashna style timeout for LED and OLED Roughly 8mins
    else if (timer_elapsed(oled_timer) > 480000) {
        oled_off();
        return false;
    }
    else {
        oled_on();
        // Reset OLED Clear flag
        master_oled_cleared = false;
        // Show logo when USB dormant
        switch (USB_DeviceState) {
            case DEVICE_STATE_Unattached:
            case DEVICE_STATE_Powered:
            case DEVICE_STATE_Suspended:
                render_logo();
                break;
            default:
                if (is_keyboard_master()) {
                    render_master_oled();
                } else {
                    render_slave_oled();
                }
        }
    }
    return false;
}
#endif

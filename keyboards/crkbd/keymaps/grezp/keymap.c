#include QMK_KEYBOARD_H
#include "enums.h"
#include "layer.h"

// [Init Variables] ----------------------------------------------------------//
extern uint8_t is_master;
// Oled timer similar to Drashna's
static uint32_t oled_timer = 0;
// Boolean to store the master LED clear so it only runs once.
bool master_oled_cleared = false;

#define _____    KC_TRNS
#define XXXXX    KC_NO
#define M_NUM    MO(_NUM)
#define M_SYM    MO(_SYM)
#define M_ADJ    MO(_ADJ)
#define T_QWER   TG(_QWERTY)

// Layer defines
#define NAV_TAB  LT(_NAV, KC_TAB)
#define NUM_ESC  LT(_NUM, KC_ESC)
#define SYM_ENT  LT(_SYM, KC_ENT)
#define FUN_DEL  LT(_FUN, KC_DEL)

// Mod Tap defines
#define T_SFT   LSFT_T(KC_T)
#define S_CTL   LCTL_T(KC_S)
#define R_ALT   LALT_T(KC_R)
#define A_GUI   LGUI_T(KC_A)
#define N_SFT   LSFT_T(KC_N)
#define E_CTL   LCTL_T(KC_E)
#define I_ALT   LALT_T(KC_I)
#define O_GUI   LGUI_T(KC_O)

// Copy/paste mods
#define UNDO    LCTL(KC_Z)
#define CUT     LCTL(KC_X)
#define COPY    LCTL(KC_C)
#define PASTE   LCTL(KC_V)
 
// [Keymaps] -----------------------------------------------------------------//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT( \
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         XXXXX,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT,   XXXXX,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         XXXXX,   A_GUI,   R_ALT,   S_CTL,   T_SFT,    KC_G,                         KC_M,   N_SFT,   E_CTL,   I_ALT,   O_GUI,   XXXXX,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         XXXXX,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,   XXXXX,\
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           NAV_TAB, NUM_ESC,  KC_SPC,    KC_BSPC, SYM_ENT, FUN_DEL \
                                        //`--------------------------'  `--------------------------'
    ),

    [_QWERTY] = LAYOUT( \
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         _____,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    _____,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         _____,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT,   _____,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         _____,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   _____,\
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             _____,   _____,   _____,      _____,   _____,   _____ \
                                        //`--------------------------'  `--------------------------'
    ),

    [_NUM] = LAYOUT(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         _____,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,                      KC_LCBR,    KC_7,    KC_8,    KC_9, KC_RCBR,   _____,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         _____, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_BSPC,                      KC_LPRN,    KC_4,    KC_5,    KC_6, KC_RPRN,   _____,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         _____,    UNDO,     CUT,    COPY,   PASTE,  KC_DEL,                      KC_LBRC,    KC_1,    KC_2,    KC_3, KC_RBRC,   _____,\
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             XXXXX,   XXXXX,   XXXXX,     KC_DOT,    KC_0,  KC_GRV \
                                        //`--------------------------'  `--------------------------'
    ),

    [_SYM] = LAYOUT(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         _____,  KC_EQL, KC_AMPR, KC_ASTR, KC_LPRN, KC_PLUS,                        XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   _____,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         _____, KC_SCLN,  KC_DLR, KC_PERC, KC_CIRC, KC_COLN,                        XXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,   _____,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         _____, KC_PIPE, KC_EXLM,   KC_AT, KC_HASH, KC_TILD,                        XXXXX, KC_BSPC,  KC_DEL,  KC_ALGR,  XXXXX,   _____,\
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_BSLS, KC_MINS, KC_UNDS,      XXXXX,   XXXXX,   XXXXX \
                                        //`--------------------------'  `--------------------------'
    ),

    [_NAV] = LAYOUT(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         _____,   RESET,   XXXXX,   XXXXX,   XXXXX,   XXXXX,                        XXXXX, KC_VOLD, KC_MUTE, KC_VOLU,   XXXXX,   _____,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         _____, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,   XXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_CAPS,   _____,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         _____,   XXXXX, KC_ALGR,   XXXXX,   XXXXX,   XXXXX,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_INS,   _____,\
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             XXXXX,   XXXXX,   XXXXX,    KC_MPLY, KC_MPRV, KC_MNXT \
                                        //`--------------------------'  `--------------------------'
    ),

    [_FUN] = LAYOUT(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         _____,  T_QWER,   KC_F7,   KC_F8,   KC_F9,  KC_F12,                        XXXXX,   XXXXX,   XXXXX,   XXXXX,   RESET,   _____,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         _____, KC_SLCK,   KC_F4,   KC_F5,   KC_F6,  KC_F11,                        XXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,   _____,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         _____, KC_NLCK,   KC_F1,   KC_F2,   KC_F3,  KC_F10,                        XXXXX,   XXXXX,   XXXXX, KC_ALGR,   XXXXX,   _____,\
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             XXXXX,   XXXXX,  KC_APP,      XXXXX,   XXXXX,   XXXXX \
                                        //`--------------------------'  `--------------------------'
    )

};

// [Tapping Term Per Key] ----------------------------------------------------//
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case A_GUI:
        case O_GUI:
            return TAPPING_TERM + 75;
        case SYM_ENT:
        case NUM_ESC:
            return TAPPING_TERM + 25;
        default:
            return TAPPING_TERM;
    }
}

// [Process User Input] ------------------------------------------------------//
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
      #ifdef OLED_DRIVER_ENABLE
          oled_timer = timer_read32();
      #endif
    }
    return true;
}

// [OLED Configuration] ------------------------------------------------------//
#ifdef OLED_DRIVER_ENABLE
// Init Oled and Rotate....
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!has_usb())
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
void oled_task_user(void) {
    // First time out switches to logo as first indication of iddle.
    if (timer_elapsed32(oled_timer) > 100000 && timer_elapsed32(oled_timer) < 479999) {
        // Render logo on both halves before full timeout
        if (is_master && !master_oled_cleared) {
            // Clear master OLED once so the logo renders properly
            oled_clear();
            master_oled_cleared = true;
        }
        render_logo();
        return;
    }
    // Drashna style timeout for LED and OLED Roughly 8mins
    else if (timer_elapsed32(oled_timer) > 480000) {
        oled_off();
        return;
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
                if (is_master) {
                    render_master_oled();
                } else {
                    render_slave_oled();
                }
        }
    }
}
#endif

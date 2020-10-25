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
#define MED_TAB  LT(_MED, KC_TAB)
#define NUM_ESC  LT(_NUM, KC_ESC)
#define NAV_SPC  LT(_NAV, KC_SPC)
#define MOU_BSP  LT(_MOU, KC_BSPC)
#define SYM_ENT  LT(_SYM, KC_ENT)
#define FUN_DEL  LT(_FUN, KC_DEL)

// Colemak-DHm mods
#define GUI_A    LGUI_T(KC_A)
#define ALT_R    LALT_T(KC_R)
#define CTL_S    LCTL_T(KC_S)
#define SFT__T   LSFT_T(KC_T)
#define SFT_N    LSFT_T(KC_N)
#define CTL_E    LCTL_T(KC_E)
#define ALT_I    LALT_T(KC_I)
#define GUI_O    LGUI_T(KC_O)
#define RALT_X   ALGR_T(KC_X)
#define RALT_DT  ALGR_T(KC_DOT)

// QWERTY mods
#define ALT_S    LALT_T(KC_S)
#define CTL_D    LCTL_T(KC_D)
#define SFT_F    LSFT_T(KC_F)
#define SFT_J    LSFT_T(KC_J)
#define CTL_K    LCTL_T(KC_K)
#define ALT_L    LALT_T(KC_L)
#define GUI_QUO  LGUI_T(KC_QUOT)

// [Keymaps] -----------------------------------------------------------------//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT( \
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         XXXXX,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT,   XXXXX,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         XXXXX,   GUI_A,   ALT_R,   CTL_S,  SFT__T,    KC_G,                         KC_M,   SFT_N,   CTL_E,   ALT_I,   GUI_O,   XXXXX,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         XXXXX,    KC_Z,  RALT_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM, RALT_DT, KC_SLSH,   XXXXX,\
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           MED_TAB, NUM_ESC, NAV_SPC,    MOU_BSP, SYM_ENT, FUN_DEL \
                                        //`--------------------------'  `--------------------------'
    ),

    [_QWERTY] = LAYOUT( \
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         _____,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    _____,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         _____,   GUI_A,   ALT_S,   CTL_D,   SFT_F,    KC_G,                         KC_H,   SFT_J,   CTL_K,   ALT_L, GUI_QUO,   _____,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         _____,    KC_Z,  RALT_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM, RALT_DT, KC_SLSH,   _____,\
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             _____,   _____,   _____,      _____,   _____,   _____ \
                                        //`--------------------------'  `--------------------------'
    ),

    [_NUM] = LAYOUT(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         _____,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,                      KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,   _____,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         _____, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,   XXXXX,                       KC_EQL,    KC_4,    KC_5,    KC_6, KC_SCLN,   _____,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         _____,   XXXXX, KC_ALGR,   XXXXX,   XXXXX,   XXXXX,                      KC_BSLS,    KC_1,    KC_2,    KC_3,  KC_GRV,   _____,\
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             XXXXX,   XXXXX,   XXXXX,    KC_MINS,    KC_0,  KC_DOT \
                                        //`--------------------------'  `--------------------------'
    ),

    [_SYM] = LAYOUT(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         _____, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                        XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   _____,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         _____, KC_COLN,  KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,                        XXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,   _____,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         _____, KC_TILD, KC_EXLM,   KC_AT, KC_HASH, KC_PIPE,                        XXXXX,   XXXXX,   XXXXX,  KC_ALGR,  XXXXX,   _____,\
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_LPRN, KC_RPRN, KC_UNDS,      XXXXX,   XXXXX,   XXXXX \
                                        //`--------------------------'  `--------------------------'
    ),

    [_NAV] = LAYOUT(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         _____,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,                      KC_AGIN, KC_UNDO,  KC_CUT, KC_COPY, KC_PSTE,   _____,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         _____, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,   XXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_CAPS,   _____,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         _____,   XXXXX, KC_ALGR,   XXXXX,   XXXXX,   XXXXX,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_INS,   _____,\
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             XXXXX,   XXXXX,   XXXXX,     KC_ENT, KC_BSPC,  KC_DEL \
                                        //`--------------------------'  `--------------------------'
    ),

    [_MOU] = LAYOUT(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         _____,   XXXXX, KC_WH_U, KC_MS_U, KC_WH_D,   XXXXX,                        XXXXX,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   _____,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         _____, KC_WBAK, KC_MS_L, KC_MS_D, KC_MS_R, KC_WFWD,                        XXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,   _____,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         _____,   XXXXX, KC_WH_L,   XXXXX, KC_WH_R,   XXXXX,                        XXXXX,   XXXXX,   XXXXX,  KC_ALGR,  XXXXX,   _____,\
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_BTN2, KC_BTN3, KC_BTN1,      XXXXX,   XXXXX,   XXXXX \
                                        //`--------------------------'  `--------------------------'
    ),

    [_MED] = LAYOUT(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         _____,   RESET,   XXXXX,   XXXXX,   XXXXX,   XXXXX,                       T_QWER,   XXXXX,   XXXXX,   XXXXX,   XXXXX,   _____,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         _____, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,   XXXXX,                        XXXXX, KC_MNXT, KC_VOLD, KC_MPLY,   XXXXX,   _____,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         _____,   XXXXX, KC_ALGR,   XXXXX,   XXXXX,   XXXXX,                        XXXXX, KC_MPRV, KC_VOLU, KC_MUTE,   XXXXX,   _____,\
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             XXXXX,   XXXXX,   XXXXX,    KC_MSTP,   XXXXX,   XXXXX \
                                        //`--------------------------'  `--------------------------'
    ),

    [_FUN] = LAYOUT(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         _____,  KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_PSCR,                        XXXXX,   XXXXX,   XXXXX,   XXXXX,   RESET,   _____,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         _____,  KC_F11,   KC_F4,   KC_F5,   KC_F6, KC_SLCK,                        XXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,   _____,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         _____,  KC_F10,   KC_F1,   KC_F2,   KC_F3, KC_NLCK,                        XXXXX,   XXXXX,   XXXXX, KC_ALGR,   XXXXX,   _____,\
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             XXXXX,   XXXXX,  KC_APP,     KC_SPC,  KC_TAB,   XXXXX \
                                        //`--------------------------'  `--------------------------'
    )

};

// [Process User Input] ------------------------------------------------------//
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
      #ifdef OLED_DRIVER_ENABLE
          oled_timer = timer_read32();
      #endif
    }
    return true;
}

// [Matrix Scan] ------------------------------------------------------------//
void matrix_scan_user(void) {
     // Iddle timer to return to default layer if left on game layer
     if (timer_elapsed32(oled_timer) > 380000 && timer_elapsed32(oled_timer) < 479999) {
         return;
     }
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

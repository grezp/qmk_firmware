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
#define NAV_SPC  LT(_NAV, KC_SPC)
#define MOU_BSP  LT(_MOU, KC_BSPC)
#define SYM_ENT  LT(_SYM, KC_ENT)
#define FUN_DEL  LT(_FUN, KC_DEL)

// S = shift
// C = control
// A = alt
// G = gui
enum combos {
    L_xxxS,
    L_xxCx,
    L_xxCS,
    L_xAxx,
    L_xAxS,
    L_xACx,
    L_xACS,
    L_Gxxx,
    L_GxxS,
    L_GxCx,
    L_GxCS,
    L_GAxx,
    L_GAxS,
    L_GACx,
    L_GACS,
    
    R_xxxS,
    R_xxCx,
    R_xxCS,
    R_xAxx,
    R_xAxS,
    R_xACx,
    R_xACS,
    R_Gxxx,
    R_GxxS,
    R_GxCx,
    R_GxCS,
    R_GAxx,
    R_GAxS,
    R_GACx,
    R_GACS
};

const uint16_t PROGMEM l_xxxS[] = {KC_SPC, KC_T, COMBO_END};
const uint16_t PROGMEM l_xxCx[] = {KC_SPC, KC_S, COMBO_END};
const uint16_t PROGMEM l_xxCS[] = {KC_SPC, KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM l_xAxx[] = {KC_SPC, KC_R, COMBO_END};
const uint16_t PROGMEM l_xAxS[] = {KC_SPC, KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM l_xACx[] = {KC_SPC, KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM l_xACS[] = {KC_SPC, KC_R, KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM l_Gxxx[] = {KC_SPC, KC_A, COMBO_END};
const uint16_t PROGMEM l_GxxS[] = {KC_SPC, KC_A, KC_T, COMBO_END};
const uint16_t PROGMEM l_GxCx[] = {KC_SPC, KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM l_GxCS[] = {KC_SPC, KC_A, KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM l_GAxx[] = {KC_SPC, KC_A, KC_R, COMBO_END};
const uint16_t PROGMEM l_GAxS[] = {KC_SPC, KC_A, KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM l_GACx[] = {KC_SPC, KC_A, KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM l_GACS[] = {KC_SPC, KC_A, KC_R, KC_S, KC_T, COMBO_END};

const uint16_t PROGMEM r_xxxS[] = {KC_BSPC, KC_N, COMBO_END};
const uint16_t PROGMEM r_xxCx[] = {KC_BSPC, KC_E, COMBO_END};
const uint16_t PROGMEM r_xxCS[] = {KC_BSPC, KC_E, KC_N, COMBO_END};
const uint16_t PROGMEM r_xAxx[] = {KC_BSPC, KC_I, COMBO_END};
const uint16_t PROGMEM r_xAxS[] = {KC_BSPC, KC_I, KC_N, COMBO_END};
const uint16_t PROGMEM r_xACx[] = {KC_BSPC, KC_I, KC_E, COMBO_END};
const uint16_t PROGMEM r_xACS[] = {KC_BSPC, KC_I, KC_E, KC_N, COMBO_END};
const uint16_t PROGMEM r_Gxxx[] = {KC_BSPC, KC_O, COMBO_END};
const uint16_t PROGMEM r_GxxS[] = {KC_BSPC, KC_O, KC_N, COMBO_END};
const uint16_t PROGMEM r_GxCx[] = {KC_BSPC, KC_O, KC_E, COMBO_END};
const uint16_t PROGMEM r_GxCS[] = {KC_BSPC, KC_O, KC_E, KC_N, COMBO_END};
const uint16_t PROGMEM r_GAxx[] = {KC_BSPC, KC_O, KC_I, COMBO_END};
const uint16_t PROGMEM r_GAxS[] = {KC_BSPC, KC_O, KC_I, KC_N, COMBO_END};
const uint16_t PROGMEM r_GACx[] = {KC_BSPC, KC_O, KC_I, KC_E, COMBO_END};
const uint16_t PROGMEM r_GACS[] = {KC_BSPC, KC_O, KC_I, KC_E, KC_N, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [L_xxxS] = COMBO(l_xxxS, KC_LSFT),
    [L_xxCx] = COMBO(l_xxCx, KC_LCTL),
    [L_xxCS] = COMBO(l_xxCS, LCTL(KC_LSFT)),
    [L_xAxx] = COMBO(l_xAxx, KC_LALT),
    [L_xAxS] = COMBO(l_xAxS, LALT(KC_LSFT)),
    [L_xACx] = COMBO(l_xACx, LALT(KC_LCTL)),
    [L_xACS] = COMBO(l_xACS, LALT(LCTL(KC_LSFT))),
    [L_Gxxx] = COMBO(l_Gxxx, KC_LGUI),
    [L_GxxS] = COMBO(l_GxxS, LGUI(KC_LSFT)),
    [L_GxCx] = COMBO(l_GxCx, LGUI(KC_LCTL)),
    [L_GxCS] = COMBO(l_GxCS, LGUI(LCTL(KC_LSFT))),
    [L_GAxx] = COMBO(l_GAxx, LGUI(KC_LALT)),
    [L_GAxS] = COMBO(l_GAxS, LGUI(LALT(KC_LSFT))),
    [L_GACx] = COMBO(l_GACx, LGUI(LALT(KC_LCTL))),
    [L_GACS] = COMBO(l_GACS, LGUI(LALT(LCTL(KC_LSFT)))),

    [R_xxxS] = COMBO(r_xxxS, KC_LSFT),
    [R_xxCx] = COMBO(r_xxCx, KC_LCTL),
    [R_xxCS] = COMBO(r_xxCS, LCTL(KC_LSFT)),
    [R_xAxx] = COMBO(r_xAxx, KC_LALT),
    [R_xAxS] = COMBO(r_xAxS, LALT(KC_LSFT)),
    [R_xACx] = COMBO(r_xACx, LALT(KC_LCTL)),
    [R_xACS] = COMBO(r_xACS, LALT(LCTL(KC_LSFT))),
    [R_Gxxx] = COMBO(r_Gxxx, KC_LGUI),
    [R_GxxS] = COMBO(r_GxxS, LGUI(KC_LSFT)),
    [R_GxCx] = COMBO(r_GxCx, LGUI(KC_LCTL)),
    [R_GxCS] = COMBO(r_GxCS, LGUI(LCTL(KC_LSFT))),
    [R_GAxx] = COMBO(r_GAxx, LGUI(KC_LALT)),
    [R_GAxS] = COMBO(r_GAxS, LGUI(LALT(KC_LSFT))),
    [R_GACx] = COMBO(r_GACx, LGUI(LALT(KC_LCTL))),
    [R_GACS] = COMBO(r_GACS, LGUI(LALT(LCTL(KC_LSFT)))),
};

// [Keymaps] -----------------------------------------------------------------//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT( \
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         XXXXX,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT,   XXXXX,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         XXXXX,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,   XXXXX,\
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
         _____, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,   XXXXX,                      KC_LPRN,    KC_4,    KC_5,    KC_6, KC_RPRN,   _____,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         _____,   XXXXX, KC_ALGR,  KC_DEL, KC_BSPC,   XXXXX,                      KC_LBRC,    KC_1,    KC_2,    KC_3, KC_RBRC,   _____,\
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

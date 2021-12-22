#include QMK_KEYBOARD_H
#include "layer.h"
#include "enums.h"

// Render Blank Space
void render_space(void) {
    oled_write_ln_P((const char*) PSTR("     "), false);
}

// Render separator lines for oled display
void render_separator(void) {
    switch (get_highest_layer(layer_state)){
        default:
            //oled_write_ln_P((const char*) PSTR("++++++++++++++++++++"), false);
            oled_write_ln_P((const char*) PSTR("===================="), false);
    }
}

// Render current layer state
void render_layer_state(void){
	// If you want to change the display of OLED, you need to change here
    switch (get_highest_layer(layer_state)){
        case _COLEMAK:
            oled_write_ln_P((const char*) PSTR("[ MODE | COLEMAK   ]"), false);
            break;
        case _QWERTY:
            oled_write_ln_P((const char*) PSTR("[ MODE | QWRTY     ]"), false);
            break;
        case _NUM:
            oled_write_ln_P((const char*) PSTR("[ MODE | NUMBERS   ]"), false);
            break;
        case _SYM:
            oled_write_ln_P((const char*) PSTR("[ MODE | SYMBOLS   ]"), false);
            break;
        case _NAV:
            oled_write_ln_P((const char*) PSTR("[ MODE | NAVIGATE  ]"), false);
            break;
        case _FUN:
            oled_write_ln_P((const char*) PSTR("[ MODE | F-KEYS    ]"), false);
            break;
        case _AMOD:
            oled_write_ln_P((const char*) PSTR("[ MODE | ALT MODS  ]"), false);
            break;
        default:
            oled_write_ln_P((const char*) PSTR("[ MODE | UNDEF     ]"), false);
    }
}

// Render USB State
void render_lock_state(void) {
    led_t led_state = host_keyboard_led_state();
    if (led_state.caps_lock) {
        oled_write_ln_P((const char*) PSTR("[ LOCK | CAPSLOCK  ]"), false);
    }
    else if (led_state.scroll_lock) {
        oled_write_ln_P((const char*) PSTR("[ LOCK | SCROLL    ]"), false);
    }
    else if (led_state.num_lock) {
        oled_write_ln_P((const char*) PSTR("[ LOCK | NUMLOCK   ]"), false);
    }
    else {
        oled_write_ln_P((const char*) PSTR("[ LOCK | NONE      ]"), false);
    }
}

#ifndef _GREZP_ENUMS_H
#define _GREZP_ENUMS_H

// [CRKBD layers Init] -------------------------------------------------------//
typedef enum {
    _COLEMAK,
    _QWERTY,
    _AMOD,
    _NUM,
    _SYM,
    _NAV,
    _FUN
}CRKBD_LAYERS;

extern enum CRKBD_LAYERS crkbd_layers;

#endif


// S = shift
// C = control
// A = alt
// G = gui
enum combos {
    L_COLEMAK_xxxS,
    L_COLEMAK_xxCx,
    L_COLEMAK_xxCS,
    L_COLEMAK_xAxx,
    L_COLEMAK_xAxS,
    L_COLEMAK_xACx,
    L_COLEMAK_xACS,
    L_COLEMAK_Gxxx,
    L_COLEMAK_GxxS,
    L_COLEMAK_GxCx,
    L_COLEMAK_GxCS,
    L_COLEMAK_GAxx,
    L_COLEMAK_GAxS,
    L_COLEMAK_GACx,
    L_COLEMAK_GACS,
    
    R_COLEMAK_xxxS,
    R_COLEMAK_xxCx,
    R_COLEMAK_xxCS,
    R_COLEMAK_xAxx,
    R_COLEMAK_xAxS,
    R_COLEMAK_xACx,
    R_COLEMAK_xACS,
    R_COLEMAK_Gxxx,
    R_COLEMAK_GxxS,
    R_COLEMAK_GxCx,
    R_COLEMAK_GxCS,
    R_COLEMAK_GAxx,
    R_COLEMAK_GAxS,
    R_COLEMAK_GACx,
    R_COLEMAK_GACS,

    L_QWERTY_xxxS,
    L_QWERTY_xxCx,
    L_QWERTY_xxCS,
    L_QWERTY_xAxx,
    L_QWERTY_xAxS,
    L_QWERTY_xACx,
    L_QWERTY_xACS,
    L_QWERTY_Gxxx,
    L_QWERTY_GxxS,
    L_QWERTY_GxCx,
    L_QWERTY_GxCS,
    L_QWERTY_GAxx,
    L_QWERTY_GAxS,
    L_QWERTY_GACx,
    L_QWERTY_GACS,
    
    R_QWERTY_xxxS,
    R_QWERTY_xxCx,
    R_QWERTY_xxCS,
    R_QWERTY_xAxx,
    R_QWERTY_xAxS,
    R_QWERTY_xACx,
    R_QWERTY_xACS,
    R_QWERTY_Gxxx,
    R_QWERTY_GxxS,
    R_QWERTY_GxCx,
    R_QWERTY_GxCS,
    R_QWERTY_GAxx,
    R_QWERTY_GAxS,
    R_QWERTY_GACx,
    R_QWERTY_GACS
};

const uint16_t PROGMEM l_colemak_xxxS[] = {KC_SPC,                   KC_T, COMBO_END};
const uint16_t PROGMEM l_colemak_xxCx[] = {KC_SPC,             KC_S,       COMBO_END};
const uint16_t PROGMEM l_colemak_xxCS[] = {KC_SPC,             KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM l_colemak_xAxx[] = {KC_SPC,       KC_R,             COMBO_END};
const uint16_t PROGMEM l_colemak_xAxS[] = {KC_SPC,       KC_R,       KC_T, COMBO_END};
const uint16_t PROGMEM l_colemak_xACx[] = {KC_SPC,       KC_R, KC_S,       COMBO_END};
const uint16_t PROGMEM l_colemak_xACS[] = {KC_SPC,       KC_R, KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM l_colemak_Gxxx[] = {KC_SPC, KC_A,                   COMBO_END};
const uint16_t PROGMEM l_colemak_GxxS[] = {KC_SPC, KC_A,             KC_T, COMBO_END};
const uint16_t PROGMEM l_colemak_GxCx[] = {KC_SPC, KC_A,       KC_S,       COMBO_END};
const uint16_t PROGMEM l_colemak_GxCS[] = {KC_SPC, KC_A,       KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM l_colemak_GAxx[] = {KC_SPC, KC_A, KC_R,             COMBO_END};
const uint16_t PROGMEM l_colemak_GAxS[] = {KC_SPC, KC_A, KC_R,       KC_T, COMBO_END};
const uint16_t PROGMEM l_colemak_GACx[] = {KC_SPC, KC_A, KC_R, KC_S,       COMBO_END};
const uint16_t PROGMEM l_colemak_GACS[] = {KC_SPC, KC_A, KC_R, KC_S, KC_T, COMBO_END};

const uint16_t PROGMEM r_colemak_xxxS[] = {KC_BSPC,                   KC_N, COMBO_END};
const uint16_t PROGMEM r_colemak_xxCx[] = {KC_BSPC,             KC_E,       COMBO_END};
const uint16_t PROGMEM r_colemak_xxCS[] = {KC_BSPC,             KC_E, KC_N, COMBO_END};
const uint16_t PROGMEM r_colemak_xAxx[] = {KC_BSPC,       KC_I,             COMBO_END};
const uint16_t PROGMEM r_colemak_xAxS[] = {KC_BSPC,       KC_I,       KC_N, COMBO_END};
const uint16_t PROGMEM r_colemak_xACx[] = {KC_BSPC,       KC_I, KC_E,       COMBO_END};
const uint16_t PROGMEM r_colemak_xACS[] = {KC_BSPC,       KC_I, KC_E, KC_N, COMBO_END};
const uint16_t PROGMEM r_colemak_Gxxx[] = {KC_BSPC, KC_O,                   COMBO_END};
const uint16_t PROGMEM r_colemak_GxxS[] = {KC_BSPC, KC_O,             KC_N, COMBO_END};
const uint16_t PROGMEM r_colemak_GxCx[] = {KC_BSPC, KC_O,       KC_E,       COMBO_END};
const uint16_t PROGMEM r_colemak_GxCS[] = {KC_BSPC, KC_O,       KC_E, KC_N, COMBO_END};
const uint16_t PROGMEM r_colemak_GAxx[] = {KC_BSPC, KC_O, KC_I,             COMBO_END};
const uint16_t PROGMEM r_colemak_GAxS[] = {KC_BSPC, KC_O, KC_I,       KC_N, COMBO_END};
const uint16_t PROGMEM r_colemak_GACx[] = {KC_BSPC, KC_O, KC_I, KC_E,       COMBO_END};
const uint16_t PROGMEM r_colemak_GACS[] = {KC_BSPC, KC_O, KC_I, KC_E, KC_N, COMBO_END};

const uint16_t PROGMEM l_qwerty_xxxS[] = {KC_SPC,                   KC_F, COMBO_END};
const uint16_t PROGMEM l_qwerty_xxCx[] = {KC_SPC,             KC_D,       COMBO_END};
const uint16_t PROGMEM l_qwerty_xxCS[] = {KC_SPC,             KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM l_qwerty_xAxx[] = {KC_SPC,       KC_S,             COMBO_END};
const uint16_t PROGMEM l_qwerty_xAxS[] = {KC_SPC,       KC_S,       KC_F, COMBO_END};
const uint16_t PROGMEM l_qwerty_xACx[] = {KC_SPC,       KC_S, KC_D,       COMBO_END};
const uint16_t PROGMEM l_qwerty_xACS[] = {KC_SPC,       KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM l_qwerty_Gxxx[] = {KC_SPC, KC_A,                   COMBO_END};
const uint16_t PROGMEM l_qwerty_GxxS[] = {KC_SPC, KC_A,             KC_F, COMBO_END};
const uint16_t PROGMEM l_qwerty_GxCx[] = {KC_SPC, KC_A,       KC_D,       COMBO_END};
const uint16_t PROGMEM l_qwerty_GxCS[] = {KC_SPC, KC_A,       KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM l_qwerty_GAxx[] = {KC_SPC, KC_A, KC_S,             COMBO_END};
const uint16_t PROGMEM l_qwerty_GAxS[] = {KC_SPC, KC_A, KC_S,       KC_F, COMBO_END};
const uint16_t PROGMEM l_qwerty_GACx[] = {KC_SPC, KC_A, KC_S, KC_D,       COMBO_END};
const uint16_t PROGMEM l_qwerty_GACS[] = {KC_SPC, KC_A, KC_S, KC_D, KC_F, COMBO_END};

const uint16_t PROGMEM r_qwerty_xxxS[] = {KC_BSPC,                      KC_J, COMBO_END};
const uint16_t PROGMEM r_qwerty_xxCx[] = {KC_BSPC,                KC_K,       COMBO_END};
const uint16_t PROGMEM r_qwerty_xxCS[] = {KC_BSPC,                KC_K, KC_J, COMBO_END};
const uint16_t PROGMEM r_qwerty_xAxx[] = {KC_BSPC,          KC_L,             COMBO_END};
const uint16_t PROGMEM r_qwerty_xAxS[] = {KC_BSPC,          KC_L,       KC_J, COMBO_END};
const uint16_t PROGMEM r_qwerty_xACx[] = {KC_BSPC,          KC_L, KC_K,       COMBO_END};
const uint16_t PROGMEM r_qwerty_xACS[] = {KC_BSPC,          KC_L, KC_K, KC_J, COMBO_END};
const uint16_t PROGMEM r_qwerty_Gxxx[] = {KC_BSPC, KC_QUOT,                   COMBO_END};
const uint16_t PROGMEM r_qwerty_GxxS[] = {KC_BSPC, KC_QUOT,             KC_J, COMBO_END};
const uint16_t PROGMEM r_qwerty_GxCx[] = {KC_BSPC, KC_QUOT,       KC_K,       COMBO_END};
const uint16_t PROGMEM r_qwerty_GxCS[] = {KC_BSPC, KC_QUOT,       KC_K, KC_J, COMBO_END};
const uint16_t PROGMEM r_qwerty_GAxx[] = {KC_BSPC, KC_QUOT, KC_L,             COMBO_END};
const uint16_t PROGMEM r_qwerty_GAxS[] = {KC_BSPC, KC_QUOT, KC_L,       KC_J, COMBO_END};
const uint16_t PROGMEM r_qwerty_GACx[] = {KC_BSPC, KC_QUOT, KC_L, KC_K,       COMBO_END};
const uint16_t PROGMEM r_qwerty_GACS[] = {KC_BSPC, KC_QUOT, KC_L, KC_K, KC_J, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [L_COLEMAK_xxxS] = COMBO(l_colemak_xxxS,                            KC_LSFT    ),
    [L_COLEMAK_xxCx] = COMBO(l_colemak_xxCx,                   KC_LCTL             ),
    [L_COLEMAK_xxCS] = COMBO(l_colemak_xxCS,                      LCTL( KC_LSFT   )),
    [L_COLEMAK_xAxx] = COMBO(l_colemak_xAxx,          KC_LALT                      ),
    [L_COLEMAK_xAxS] = COMBO(l_colemak_xAxS,             LALT(          KC_LSFT   )),
    [L_COLEMAK_xACx] = COMBO(l_colemak_xACx,             LALT( KC_LCTL            )),
    [L_COLEMAK_xACS] = COMBO(l_colemak_xACS,             LALT(    LCTL( KC_LSFT  ))),
    [L_COLEMAK_Gxxx] = COMBO(l_colemak_Gxxx, KC_LGUI                               ),
    [L_COLEMAK_GxxS] = COMBO(l_colemak_GxxS,    LGUI(                   KC_LSFT   )),
    [L_COLEMAK_GxCx] = COMBO(l_colemak_GxCx,    LGUI(          KC_LCTL            )),
    [L_COLEMAK_GxCS] = COMBO(l_colemak_GxCS,    LGUI(             LCTL( KC_LSFT  ))),
    [L_COLEMAK_GAxx] = COMBO(l_colemak_GAxx,    LGUI( KC_LALT                     )),
    [L_COLEMAK_GAxS] = COMBO(l_colemak_GAxS,    LGUI(    LALT(          KC_LSFT  ))),
    [L_COLEMAK_GACx] = COMBO(l_colemak_GACx,    LGUI(    LALT( KC_LCTL           ))),
    [L_COLEMAK_GACS] = COMBO(l_colemak_GACS,    LGUI(    LALT(    LCTL( KC_LSFT )))),

    [R_COLEMAK_xxxS] = COMBO(r_colemak_xxxS,                            KC_LSFT    ),
    [R_COLEMAK_xxCx] = COMBO(r_colemak_xxCx,                   KC_LCTL             ),
    [R_COLEMAK_xxCS] = COMBO(r_colemak_xxCS,                      LCTL( KC_LSFT   )),
    [R_COLEMAK_xAxx] = COMBO(r_colemak_xAxx,          KC_LALT                      ),
    [R_COLEMAK_xAxS] = COMBO(r_colemak_xAxS,             LALT(          KC_LSFT   )),
    [R_COLEMAK_xACx] = COMBO(r_colemak_xACx,             LALT( KC_LCTL            )),
    [R_COLEMAK_xACS] = COMBO(r_colemak_xACS,             LALT(    LCTL( KC_LSFT  ))),
    [R_COLEMAK_Gxxx] = COMBO(r_colemak_Gxxx, KC_LGUI                               ),
    [R_COLEMAK_GxxS] = COMBO(r_colemak_GxxS,    LGUI(                   KC_LSFT   )),
    [R_COLEMAK_GxCx] = COMBO(r_colemak_GxCx,    LGUI(          KC_LCTL            )),
    [R_COLEMAK_GxCS] = COMBO(r_colemak_GxCS,    LGUI(             LCTL( KC_LSFT  ))),
    [R_COLEMAK_GAxx] = COMBO(r_colemak_GAxx,    LGUI( KC_LALT                     )),
    [R_COLEMAK_GAxS] = COMBO(r_colemak_GAxS,    LGUI(    LALT(          KC_LSFT  ))),
    [R_COLEMAK_GACx] = COMBO(r_colemak_GACx,    LGUI(    LALT( KC_LCTL           ))),
    [R_COLEMAK_GACS] = COMBO(r_colemak_GACS,    LGUI(    LALT(    LCTL( KC_LSFT )))),

    [L_QWERTY_xxxS] = COMBO(l_qwerty_xxxS,                            KC_LSFT    ),
    [L_QWERTY_xxCx] = COMBO(l_qwerty_xxCx,                   KC_LCTL             ),
    [L_QWERTY_xxCS] = COMBO(l_qwerty_xxCS,                      LCTL( KC_LSFT   )),
    [L_QWERTY_xAxx] = COMBO(l_qwerty_xAxx,          KC_LALT                      ),
    [L_QWERTY_xAxS] = COMBO(l_qwerty_xAxS,             LALT(          KC_LSFT   )),
    [L_QWERTY_xACx] = COMBO(l_qwerty_xACx,             LALT( KC_LCTL            )),
    [L_QWERTY_xACS] = COMBO(l_qwerty_xACS,             LALT(    LCTL( KC_LSFT  ))),
    [L_QWERTY_Gxxx] = COMBO(l_qwerty_Gxxx, KC_LGUI                               ),
    [L_QWERTY_GxxS] = COMBO(l_qwerty_GxxS,    LGUI(                   KC_LSFT   )),
    [L_QWERTY_GxCx] = COMBO(l_qwerty_GxCx,    LGUI(          KC_LCTL            )),
    [L_QWERTY_GxCS] = COMBO(l_qwerty_GxCS,    LGUI(             LCTL( KC_LSFT  ))),
    [L_QWERTY_GAxx] = COMBO(l_qwerty_GAxx,    LGUI( KC_LALT                     )),
    [L_QWERTY_GAxS] = COMBO(l_qwerty_GAxS,    LGUI(    LALT(          KC_LSFT  ))),
    [L_QWERTY_GACx] = COMBO(l_qwerty_GACx,    LGUI(    LALT( KC_LCTL           ))),
    [L_QWERTY_GACS] = COMBO(l_qwerty_GACS,    LGUI(    LALT(    LCTL( KC_LSFT )))),

    [R_QWERTY_xxxS] = COMBO(r_qwerty_xxxS,                            KC_LSFT    ),
    [R_QWERTY_xxCx] = COMBO(r_qwerty_xxCx,                   KC_LCTL             ),
    [R_QWERTY_xxCS] = COMBO(r_qwerty_xxCS,                      LCTL( KC_LSFT   )),
    [R_QWERTY_xAxx] = COMBO(r_qwerty_xAxx,          KC_LALT                      ),
    [R_QWERTY_xAxS] = COMBO(r_qwerty_xAxS,             LALT(          KC_LSFT   )),
    [R_QWERTY_xACx] = COMBO(r_qwerty_xACx,             LALT( KC_LCTL            )),
    [R_QWERTY_xACS] = COMBO(r_qwerty_xACS,             LALT(    LCTL( KC_LSFT  ))),
    [R_QWERTY_Gxxx] = COMBO(r_qwerty_Gxxx, KC_LGUI                               ),
    [R_QWERTY_GxxS] = COMBO(r_qwerty_GxxS,    LGUI(                   KC_LSFT   )),
    [R_QWERTY_GxCx] = COMBO(r_qwerty_GxCx,    LGUI(          KC_LCTL            )),
    [R_QWERTY_GxCS] = COMBO(r_qwerty_GxCS,    LGUI(             LCTL( KC_LSFT  ))),
    [R_QWERTY_GAxx] = COMBO(r_qwerty_GAxx,    LGUI( KC_LALT                     )),
    [R_QWERTY_GAxS] = COMBO(r_qwerty_GAxS,    LGUI(    LALT(          KC_LSFT  ))),
    [R_QWERTY_GACx] = COMBO(r_qwerty_GACx,    LGUI(    LALT( KC_LCTL           ))),
    [R_QWERTY_GACS] = COMBO(r_qwerty_GACS,    LGUI(    LALT(    LCTL( KC_LSFT ))))
};

#include QMK_KEYBOARD_H
#include <stdio.h>
#include <keymap_finnish.h>

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _NUMPAD,
    _STENO,
    _MOUSEK,
    _MOUSEK_R,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_NUMPAD,
    KC_NUMPAD_TEMP,
    KC_STENO,
    KC_MOUSEK,
    KC_MOUSEK_R,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE,
    KC_SEARCH,
    KC_SNIP,
    KC_SAVE,
    KC_000
};

char wpm_str[10];
bool steno_layer_active=false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   '  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |   Å  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   Ö  |   Ä  |
 * |------+------+------+------+------+------|  MUTE |    |  PLAY |------+------+------+------+------+------|
 * | LCTR |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   -  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |NUMPAD| LAlt | LCTR |SPACE | / LOWER /       \ RAISE\  |Enter |MOUSEK| RAltoo | RGUI |
 *            | temp |      |      |      |/ layer/          \ layer\ |      | RIGHT|      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT( \
  KC_ESC,    KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_NUHS, \
  KC_TAB,    KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     FI_ARNG, \
  KC_LSFT,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,     KC_J,     KC_K,     KC_L,     FI_ODIA,  FI_ADIA, \
  KC_LCTRL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  KC_MUTE,     KC_MPLY,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, \
            KC_NUMPAD_TEMP, KC_LALT, KC_LCTL, KC_SPC,  KC_LOWER,          KC_RAISE, KC_ENT, KC_MOUSEK_R,  KC_RALT,  KC_RGUI \
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  ESC |   !  |   "  |   #  |   =  |   %  |-------.    ,-------|   &  |   /  |   (  |   )  |   ?  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |  PLAY |------+------+------+------+------+------|
 * |      |  ~   |  @   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   <  |   >  |   \  |  *   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | / LOWER /       \ RAISE\  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT( \
  _______,  KC_F1,    KC_F2,   KC_F3,    KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,\
  _______,  KC_1,     KC_2,    KC_3,     KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12, \
  KC_ESC,   FI_EXLM,  FI_DQUO, FI_HASH,  FI_EQL,  FI_PERC,                         FI_AMPR, FI_SLSH, FI_LPRN, FI_RPRN, FI_QUES, FI_PIPE, \
  _______,  FI_TILD,   FI_AT,   FI_PLUS,  FI_LCBR, FI_RCBR, _______,       _______, FI_LBRC, FI_RBRC, FI_LABK, FI_RABK, FI_BSLS, FI_ASTR, \
                    _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______\
),

/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | Ins  | Pscr | Menu |      |                    |      | PWrd |  Up  | NWrd | DLine|  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | Save | Snip |Search| Caps |-------.    ,-------| PGup | Left | Down | Rigth| Bspc |  '   |
 * |------+------+------+------+------+------|  MUTE |    |  PLAY |------+------+------+------+------+------|
 * |      | Undo |  Cut | Copy | Paste|      |-------|    |-------| PGdn | LStr |  Del | LEnd |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | / LOWER /       \ RAISE\  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT( \
  _______, _______, _______, _______,  _______,   _______,                           _______,  _______,  _______, _______,  _______,  _______, \
  _______, _______, KC_INS,  KC_PSCR,  KC_APP,    _______,                           XXXXXXX, KC_PRVWD,  KC_UP,   KC_NXTWD, KC_DLINE, KC_PLUS, \
  _______,  _______, KC_SAVE, KC_SNIP,  KC_SEARCH, KC_CAPS,                           KC_PGUP,  KC_LEFT,  KC_DOWN, KC_RGHT,  KC_BSPC,   KC_NUHS, \
  _______, KC_UNDO, KC_CUT,  KC_COPY,  KC_PASTE,  _______,  _______,       _______,  KC_PGDN, KC_LSTRT,  KC_DEL, KC_LEND,  XXXXXXX,  _______, \
                       _______, _______, _______, KC_BSPC, _______,        _______, _______, _______, _______, _______ \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | RESET|      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |MACWIN|      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |STENO |NUMPAD|MOUSEK|QWERTY|      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |  PLAY |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | / LOWER /       \ RAISE\  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT( \
  RESET,   XXXXXXX, XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  CG_TOGG, XXXXXXX, XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, KC_STENO, KC_NUMPAD, KC_MOUSEK, KC_QWERTY, XXXXXXX,                        XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, _______,      _______, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, \
                   _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______ \
  ),
 /*
 * NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |   /  |  *   |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |   7  |   8  |  9   |  -   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |   4  |   5  |  6   |  +   |      |
 * |------+------+------+------+------+------|  MUTE |    |  PLAY |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   1  |   2  |  3   |  ,   |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | / LOWER /       \ RAISE\  |      |  0   |  000 |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_NUMPAD] = LAYOUT( \
  _______ , _______, _______, _______, _______, _______,                       XXXXXXX, XXXXXXX, KC_PSLS, KC_PAST, XXXXXXX, XXXXXXX, \
  _______ , _______, _______, _______, _______, _______,                       XXXXXXX, KC_7,    KC_8,    KC_9,    KC_PMNS, XXXXXXX, \
  _______ , _______, _______, _______, _______, _______,                       XXXXXXX, KC_4,    KC_5,    KC_6,    KC_PPLS, XXXXXXX, \
  _______ , _______, _______, _______, _______, _______, _______,    _______,  XXXXXXX, KC_1,    KC_2,    KC_3,    KC_COMM, XXXXXXX, \
                   _______, _______, _______, _______, _______,       _______, _______, KC_0,    KC_000,  _______ \
),
 /*
 * STENO
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  S   |  T   |   P  |  H   |      |                    |      |   F  |  P   |  L   |  T   |  D   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|  S   |  K   |   W  |  R   |      |-------.    ,-------|      |   R  |  B   |  G   |  S   |  Z   |
 * |------+------+------+------+------+------|  MUTE |    |  PLAY |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |  A   |  O   |  #   | / LOWER /       \ RAISE\  |  #   |  E   |  U    |      |
 *            |      |      |      |      |/       /         \      \ |      |      |       |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_STENO] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, KC_Q,    KC_W,     KC_E,    KC_R,    KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    FI_ARNG, \
  KC_LSFT, KC_A,    KC_S,     KC_D,    KC_F,    KC_G,                           KC_H,    KC_J,    KC_K,    KC_L,    FI_ODIA, FI_ADIA, \
  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, _______,      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                    _______,  KC_C,  KC_V,    KC_1,  _______,              _______, KC_1,  KC_N, KC_M, XXXXXXX \
),
/*
 * MOUSEK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | MWdn | Mup  | MWup |      |                    |      | MWdn | Mup  | MWup |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Spd2 |  M4  | Mleft| Mdown|Mright|      |-------.    ,-------|      | Mleft| Mdown|Mright|  M4  | Spd2 |
 * |------+------+------+------+------+------|  MUTE |    |  PLAY |------+------+------+------+------+------|
 * | Spd0 |  M5  | MWlft|      | MWrgt|      |-------|    |-------|      | MWlft|      | MWrgt|  M5  | Spd0 |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |  M3  |  M2  |  M1  | / LOWER /       \ RAISE\  |  M1  |  M2  |  M3  |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_MOUSEK] = LAYOUT( \
  _______ , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______ , XXXXXXX, KC_WH_U, KC_MS_U, KC_WH_D, XXXXXXX,                       XXXXXXX, KC_WH_D, KC_MS_U, KC_WH_U, XXXXXXX, XXXXXXX, \
  KC_ACL2 , KC_BTN4, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                       XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN4, KC_ACL2, \
  KC_ACL0 , KC_BTN5, KC_WH_L, XXXXXXX, KC_WH_R, XXXXXXX, _______,     _______, XXXXXXX, KC_WH_L, XXXXXXX, KC_WH_R, KC_BTN5, KC_ACL0, \
                   _______, KC_BTN3, KC_BTN2, KC_BTN1, _______,        _______, KC_BTN1, KC_BTN2, KC_BTN3, _______ \
),
/*
 * MOUSEK_R
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      | MWdn | Mup  | MWup |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      | Mleft| Mdown|Mright| M4   | Spd2 |
 * |------+------+------+------+------+------|  MUTE |    |  PLAY |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | MWlft|QWERTY| MWrgt| M5   | Spd0 |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | / LOWER /       \ RAISE\  |  M1  |  M2  | M3   |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_MOUSEK_R] = LAYOUT( \
  _______ , _______, _______, _______, _______, _______,                       XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, \
  _______ , _______, _______, _______, _______, _______,                       KC_ACL0, KC_WH_D, KC_MS_U,   KC_WH_U, XXXXXXX, XXXXXXX, \
  _______ , _______, _______, _______, _______, _______,                       KC_ACL1, KC_MS_L, KC_MS_D,   KC_MS_R, KC_BTN4, KC_ACL2, \
  _______ , _______, _______, _______, _______, _______, _______,     _______, KC_ACL2, KC_WH_L, KC_QWERTY, KC_WH_R, KC_BTN5, KC_ACL0, \
                   _______, _______, _______, _______, _______,        _______, KC_BTN1, KC_BTN2, KC_BTN3, _______ \
)  
};

//OLED Master
#ifdef OLED_DRIVER_ENABLE

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Qwrty"), false);
            break;
        case _NUMPAD:
            oled_write_ln_P(PSTR("Npad"), false);
            break;
        case _MOUSEK:
            oled_write_ln_P(PSTR("Mkey"), false);
            break;
        case _MOUSEK_R:
            oled_write_P(PSTR("MkeyR"), false);
            break;
        case _STENO:
            oled_write_P(PSTR("Steno"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("Npad\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    /*if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
    */
    return OLED_ROTATION_270;
}

// Oled Slave - WPM-responsive animation
#define IDLE_FRAMES 2
#define IDLE_SPEED 200

#define ANIM_FRAME_DURATION 1000 // how long each frame lasts in ms
#define SLEEP_TIMER 60000 // should sleep after this period of 0 wpm, needs fixing
#define ANIM_SIZE 512 // number of bytes in array, minimize for adequate firmware size, max is 1024

uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;
uint8_t current_idle_frame = 0;

static void render_anim(void) {
    static const char PROGMEM idle[IDLE_FRAMES][ANIM_SIZE] = {
        {
        // 'tinyzoid_1_fin', 32x128px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x60, 0x60, 0x60, 0x60, 0x60, 
        0x60, 0x60, 0x60, 0x60, 0xe0, 0x60, 0xe0, 0x60, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xfe, 0x07, 0x07, 0x06, 0x06, 0x06, 0x06, 0x06, 
        0x06, 0x86, 0x86, 0x86, 0x09, 0x00, 0x10, 0x10, 0x88, 0x1f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x80, 0x80, 0x60, 0x60, 0x60, 0x60, 0x7f, 0x7f, 0x60, 0x60, 0x80, 0x80, 0x80, 0x80, 0x00, 
        0x00, 0x87, 0x87, 0x07, 0x07, 0x80, 0x80, 0x07, 0x07, 0x98, 0xbf, 0xe0, 0xe0, 0x80, 0x80, 0x00, 
        0xf8, 0x27, 0x27, 0xb0, 0x90, 0x18, 0x18, 0xf8, 0x08, 0xf8, 0xf8, 0x01, 0x01, 0x07, 0x07, 0xc8, 
        0xc8, 0x07, 0x07, 0x08, 0x08, 0x07, 0x07, 0xf8, 0xf8, 0x0f, 0xf9, 0x91, 0x91, 0x11, 0x11, 0xfe, 
        0x07, 0x18, 0x18, 0x87, 0x87, 0xe6, 0xe6, 0x19, 0x18, 0x07, 0x0f, 0x08, 0x08, 0x88, 0x88, 0x88, 
        0x88, 0x88, 0x88, 0x08, 0x08, 0x08, 0x08, 0x0f, 0x07, 0x18, 0x19, 0xe7, 0x87, 0x18, 0x18, 0x07, 
        0x38, 0x24, 0x26, 0x23, 0x21, 0x21, 0x21, 0x22, 0x22, 0x22, 0x22, 0x3e, 0x1e, 0x01, 0x01, 0x01, 
        0x01, 0x01, 0x01, 0x02, 0x1e, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x21, 0x23, 0x22, 0x2c, 0x38
        },
        {
        // 'tinyzoid_2_fin', 32x128px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 
        0x60, 0x60, 0x60, 0xe0, 0x60, 0xe0, 0x60, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xfe, 0x07, 0x07, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 
        0x86, 0x86, 0x86, 0x89, 0x00, 0x10, 0x90, 0x88, 0x1f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xdf, 0xff, 0xe0, 0xe0, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 
        0x83, 0x87, 0x07, 0x07, 0x80, 0x80, 0x07, 0x07, 0x98, 0xbf, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 
        0xf0, 0x4f, 0x4f, 0x60, 0x20, 0x30, 0x30, 0xf0, 0x10, 0xd8, 0xf9, 0x01, 0x07, 0x07, 0x08, 0x88, 
        0x87, 0x07, 0x08, 0x08, 0x07, 0x07, 0x18, 0xf8, 0xef, 0xf1, 0x21, 0x23, 0x23, 0x27, 0xf8, 0x00, 
        0x0f, 0x30, 0x30, 0x8f, 0x8f, 0xec, 0xec, 0x13, 0x18, 0x07, 0x0f, 0x08, 0x08, 0x88, 0x88, 0x89, 
        0x89, 0x88, 0x88, 0x08, 0x08, 0x08, 0x08, 0x0f, 0x07, 0x1b, 0x1f, 0xef, 0xb0, 0x30, 0x0f, 0x00, 
        0x38, 0x24, 0x26, 0x23, 0x21, 0x21, 0x21, 0x22, 0x22, 0x22, 0x22, 0x3e, 0x1e, 0x01, 0x01, 0x01, 
        0x01, 0x01, 0x01, 0x1e, 0x1e, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x21, 0x23, 0x26, 0x24, 0x38
        }
    };

    void animation_phase(void) {
        if(get_current_wpm() <=IDLE_SPEED){
            current_idle_frame = (current_idle_frame + 1) % IDLE_FRAMES;
            oled_write_raw_P(idle[abs((IDLE_FRAMES-1)-current_idle_frame)], ANIM_SIZE);
         }
    }
    if(get_current_wpm() != 000) {
        oled_on(); // not essential but turns on animation OLED with any alpha keypress
        if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
            anim_timer = timer_read32();
            animation_phase();
        }
        anim_sleep = timer_read32();
    } else {
        if(timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
            oled_off();
        } else {
            if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
                anim_timer = timer_read32();
                animation_phase();
            }
        }
    }
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        oled_set_cursor(0,0);
        render_anim();
        oled_set_cursor((oled_max_chars()/2)-1,(oled_max_lines()/2)-2);
        oled_write_P(PSTR("WPM"), false);
        sprintf(wpm_str, "  %03d", get_current_wpm());
        oled_write(wpm_str, false);
    }
}

#endif

// Keypress Settings
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                default_layer_set(1UL << _QWERTY);
            }
            return false;
        case KC_MOUSEK:
            if (record->event.pressed) {
                default_layer_set(1UL << _MOUSEK);
            }
            return false;
        case KC_MOUSEK_R:
            if (record->event.pressed) {
                default_layer_set(1UL << _MOUSEK_R);
            }
            return false;  
        case KC_NUMPAD:
            if (record->event.pressed) {
                default_layer_set(1UL << _NUMPAD);
            }
            return false;    
        case KC_NUMPAD_TEMP:
            if (record->event.pressed) {
                layer_on(_NUMPAD);
            } else {
                layer_off(_NUMPAD);
            }
            return false;
        case KC_STENO:
            if (record->event.pressed) {
                if (steno_layer_active==true) {
                    register_code(KC_E);
                    register_code(KC_R);
                    register_code(KC_F);
                    register_code(KC_V);
                    register_code(KC_Y);
                    register_code(KC_U);
		            clear_keyboard_but_mods(); // quick way to depress all but modifiers
			        default_layer_set(1UL << _QWERTY);
			        steno_layer_active = false;
    		    } else {
                    register_code(KC_E);
                    register_code(KC_R);
                    register_code(KC_F);
                    register_code(KC_V);
                    register_code(KC_I);
                    register_code(KC_K);
                    clear_keyboard_but_mods();
	        		default_layer_set(1UL << _STENO);
			        steno_layer_active = true;
		        }
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_000:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_0)SS_TAP(X_0)SS_TAP(X_0));
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
        case KC_SEARCH:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_F);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_F);
            }
            return false;
        case KC_SNIP:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LSFT));
                register_mods(mod_config(MOD_LGUI));
                register_code(KC_S);
            } else {
                unregister_mods(mod_config(MOD_LSFT));
                unregister_mods(mod_config(MOD_LGUI));
                unregister_code(KC_S);
            }
            return false;
        case KC_SAVE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_S);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_S);
            }
            return false;      
    }
    return true;
}

#ifdef ENCODER_ENABLE

void encoder_update_user(uint8_t index, bool clockwise) {
    if(IS_LAYER_ON(_LOWER)) {    // LOWER layer - arrow keys
        if (index == 0) {
            if (clockwise) {
                tap_code(KC_UP);
            } else {
                tap_code(KC_DOWN);
            }
        } else if (index == 1) {
            if (clockwise) {
                tap_code(KC_RIGHT);
            } else {
                tap_code(KC_LEFT);
            }
        }
    } else if(IS_LAYER_ON(_RAISE)) {    // RAISE layer - history scrub & window tabbing
        if (index == 0) {
            if (clockwise) {
            tap_code16(C(KC_Y));
            } else {
            tap_code16(C(KC_Z));
            }
        } else if (index == 1) {
            if (clockwise) {
            tap_code16(C(KC_TAB));
            } else {
            tap_code16(S(C(KC_TAB)));
            }
        }
    } else if(IS_LAYER_ON(_NUMPAD) || get_highest_layer(default_layer_state) == _NUMPAD || get_highest_layer(default_layer_state) == _MOUSEK || get_highest_layer(default_layer_state) == _MOUSEK_R) {      // NUMPAD or MOUSEK or MOUSEK_R Layer - volume & Scroll wheel Up/Down
        if (index == 0) {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        } else if (index == 1) {
            if (clockwise) {
                tap_code(KC_WH_D);
            } else {
                tap_code(KC_WH_U);
            }
        }
    } else if(get_highest_layer(default_layer_state) == _QWERTY) {      // QWERTY Layer - volume & PGup/PGdown
        if (index == 0) {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        } else if (index == 1) {
            if (clockwise) {
                tap_code(KC_PGDOWN);
            } else {
                tap_code(KC_PGUP);
            }
        }
    }   
}

#endif

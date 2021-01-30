#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#define MOUSEKEY_INTERVAL 14
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_MAX_SPEED 7
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_WHEEL_DELAY 0
#define MOUSEKEY_WHEEL_MAX_SPEED 4
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40

// Disabled due to rules.mk setting EXTRAFLAGS += -flto disabling these functions anyway
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

// Force N-key roll over
#define FORCE_NKRO

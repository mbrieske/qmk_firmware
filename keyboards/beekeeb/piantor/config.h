// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define MASTER_RIGHT

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1

#define COMBO_COUNT 1

#define TAPPING_TERM 220
#define TAPPING_TERM_PER_KEY
//#define IGNORE_MOD_TAP_INTERRUPT    // makes it possible to do rolling combos with keys that convert to other keys on hold, by enforcing the TAPPING_TERM for both keys - needed for backspace
#define BILATERAL_COMBINATIONS 500
//#define QUICK_TAP_TERM 0            // disable auto-repeat, also needed for backspace / shift

#define HOLD_ON_OTHER_KEY_PRESS
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#define PS2_PIO_USE_PIO1

#define PS2_MOUSE_ROTATE 270

#define PS2_MOUSE_SCROLL_DIVISOR_H 8
#define PS2_MOUSE_SCROLL_DIVISOR_V 8
#define PS2_MOUSE_INIT_DELAY 5000
//#define PS2_MOUSE_SCROLL_BTN_SEND 0

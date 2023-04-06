// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once


#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1

#define COMBO_COUNT 1

#define TAPPING_TERM 220
#define TAPPING_TERM_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT    // makes it possible to do rolling combos with keys that convert to other keys on hold, by enforcing the TAPPING_TERM for both keys - needed for backspace
#define BILATERAL_COMBINATIONS 500
//#define QUICK_TAP_TERM 0            // disable auto-repeat, also needed for backspace / shift

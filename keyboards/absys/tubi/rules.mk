# MCU name
MCU = STM32F303
BOARD = QMK_PROTON_C
BOOTLOADER = stm32-dfu
# Build Options
#   change yes to no to disable
#
LTO_ENABLE			= no		# Not recommended for STM32 based MCU

BOOTMAGIC_ENABLE		= no		# Virtual DIP switch configuration
COMMAND_ENABLE			= yes	# Commands for debug and configuration

CONSOLE_ENABLE			= yes	# Console for debug
DEBUG_ENABLE			= no		# Print debug info

MOUSEKEY_ENABLE		= yes	# Mouse keys
EXTRAKEY_ENABLE		= yes	# Audio control and System control
NKRO_ENABLE			= yes	# USB Nkey Rollover

AUDIO_ENABLE			= yes
AUDIO_DRIVER			= dac_basic

ENCODER_ENABLE			= yes	# Enables the use of one or more encoders

OLED_ENABLE			= yes	# Enables the use of OLED displays
OLED_DRIVER			= SSD1306

RGBLIGHT_ENABLE		= yes		# Enable keyboard RGB underglow
WS2812_DRIVER			= pwm

SPLIT_KEYBOARD			= no		# Split keyboard support
SERIAL_DRIVE			= usart

TAP_TERM_KEYS_ENABLE	= no
AUTO_SHIFT_ENABLE		= yes
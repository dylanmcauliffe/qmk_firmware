MCU = STM32F303
BOOTLOADER = stm32-dfu

BOOTMAGIC_ENABLE = yes	# Enable Bootmagic Lite
COMMAND_ENABLE = yes	# Commands for debug and configuration
CONSOLE_ENABLE = yes	# Console for debug

ENCODER_ENABLE = yes	# Encoder support	
ENCODER_MAP_ENABLE = yes	# Encoder map support	
EXTRAKEY_ENABLE = yes	# Audio control and System control
MOUSEKEY_ENABLE = yes	# Mouse keys
NKRO_ENABLE = yes		# Enable N-Key Rollover

AUDIO_ENABLE = yes		# Audio output
AUDIO_DRIVER = dac_basic

RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
WS2812_DRIVER = pwm

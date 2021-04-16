BOOTMAGIC_ENABLE = no		# Virtual DIP switch configuration
COMMAND_ENABLE = yes		# Commands for debug and configuration
CONSOLE_ENABLE = no			# Console for debug
DEBUG_ENABLE = no			# Print debug info

MOUSEKEY_ENABLE = no		# Mouse keys
EXTRAKEY_ENABLE = yes		# Audio control and System control
NKRO_ENABLE = yes			# USB Nkey Rollover

OLED_DRIVER_ENABLE = yes		# Enables the use of OLED displays

ENCODER_ENABLE = yes		# Enables the use of one or more encoders

RGBLIGHT_ENABLE = yes		# Enable keyboard RGB underglow

TAP_TERM_KEYS_ENABLE = no

ifeq ($(strip $(CTPC)), yes)
	# Credit for the SERIAL and WS2812 settings belongs to:
	#	Drashna [https://github.com/drashna]
	#	ItsWaffIe [https://github.com/ItsWaffIe]

	SERIAL_DRIVER = usart

	WS2812_DRIVER = pwm
	# PWM needs patch to:
	#	qmk_firmware/platforms/chibios/QMK_PROTON_C/convert_to_proton_c.mk
	#	qmk_firmware/common_features.mk
	# See PR at https://github.com/qmk/qmk_firmware/pull/11864

	AUDIO_ENABLE = yes
	AUDIO_DRIVER = dac_basic
endif

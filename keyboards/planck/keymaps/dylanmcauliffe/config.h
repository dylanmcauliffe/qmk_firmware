#pragma once

#ifdef AUDIO_ENABLE
	#define STARTUP_SONG SONG(PLANCK_SOUND)

	#define DEFAULT_LAYER_SONGS { \
									SONG(COLEMAK_SOUND), \
									SONG(QWERTY_SOUND) \
								}
#endif

#define MIDI_BASIC

#ifdef ENCODER_ENABLE
	#define ENCODER_RESOLUTION 2 // ALPS encoders
	#define TAP_CODE_DELAY 10 // Needed for media keys
#endif

#define TAPPING_TOGGLE 2

// Home row mods helpers
#define TAPPING_TERM 300
#define TAPPING_TERM_PER_KEY

#define IGNORE_MOD_TAP_INTERRUPT

//#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY

//#define TAPPING_FORCE_HOLD
#define TAPPING_FORCE_HOLD_PER_KEY
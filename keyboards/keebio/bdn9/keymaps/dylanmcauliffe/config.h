#pragma once

#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_KEYPRESSES
#endif

#undef ENCODERS_PAD_A
#undef ENCODERS_PAD_B
#define ENCODERS_PAD_A { A4, A15, A9 }
#define ENCODERS_PAD_B { A8, B3, A10 }
#define ENCODER_RESOLUTION 2

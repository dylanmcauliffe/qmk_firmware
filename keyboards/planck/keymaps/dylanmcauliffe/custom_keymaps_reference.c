// Number Home Row Mods

#define LG_1		LGUI_T(KC_1)
#define LA_1		LALT_T(KC_1)
#define LS_1		LSFT_T(KC_1)
#define LC_1		LCTL_T(KC_1)

#define LG_2		LGUI_T(KC_2)
#define LA_2		LALT_T(KC_2)
#define LS_2		LSFT_T(KC_2)
#define LC_2		LCTL_T(KC_2)

#define LG_3		LGUI_T(KC_3)
#define LA_3		LALT_T(KC_3)
#define LS_3		LSFT_T(KC_3)
#define LC_3		LCTL_T(KC_3)

#define LG_4		LGUI_T(KC_4)
#define LA_4		LALT_T(KC_4)
#define LS_4		LSFT_T(KC_4)
#define LC_4		LCTL_T(KC_4)

#define RC_7		RCTL_T(KC_7)
#define RS_7		RSFT_T(KC_7)
#define RA_7		RALT_T(KC_7)
#define RG_7		RGUI_T(KC_7)

#define RC_8		RCTL_T(KC_8)
#define RS_8		RSFT_T(KC_8)
#define RA_8		RALT_T(KC_8)
#define RG_8		RGUI_T(KC_8)

#define RC_9		RCTL_T(KC_9)
#define RS_9		RSFT_T(KC_9)
#define RA_9		RALT_T(KC_9)
#define RG_9		RGUI_T(KC_9)

#define RC_0		RCTL_T(KC_0)
#define RS_0		RSFT_T(KC_0)
#define RA_0		RALT_T(KC_0)
#define RG_0		RGUI_T(KC_0)


// Colemak Home Row Mods
#define LG_Z		LGUI_T(KC_Z)
#define LA_Z		LALT_T(KC_Z)
#define LS_Z		LSFT_T(KC_Z)
#define LC_Z		LCTL_T(KC_Z)

#define LG_A		LGUI_T(KC_A)
#define LA_A		LALT_T(KC_A)
#define LS_A		LSFT_T(KC_A)
#define LC_A		LCTL_T(KC_A)

#define LG_R		LGUI_T(KC_R)
#define LA_R		LALT_T(KC_R)
#define LS_R		LSFT_T(KC_R)
#define LC_R		LCTL_T(KC_R)

#define LG_S		LGUI_T(KC_S)
#define LA_S		LALT_T(KC_S)
#define LC_S		LCTL_T(KC_S)
#define LS_S		LSFT_T(KC_S)

#define LG_T		LGUI_T(KC_T)
#define LA_T		LALT_T(KC_T)
#define LS_T		LSFT_T(KC_T)
#define LC_T		LCTL_T(KC_T)

#define RC_N		RCTL_T(KC_N)
#define RS_N		RSFT_T(KC_N)
#define RA_N		RALT_T(KC_N)
#define RG_N		RGUI_T(KC_N)

#define RC_E		RCTL_T(KC_E)
#define RS_E		RSFT_T(KC_E)
#define RA_E		RALT_T(KC_E)
#define RG_E		RGUI_T(KC_E)

#define RC_I		RCTL_T(KC_I)
#define RS_I		RSFT_T(KC_I)
#define RA_I		RALT_T(KC_I)
#define RG_I		RGUI_T(KC_I)

#define RC_O		RCTL_T(KC_O)
#define RS_O		RSFT_T(KC_O)
#define RA_O		RALT_T(KC_O)
#define RG_O		RGUI_T(KC_O)

#define RC_SLSH	RCTL_T(KC_SLSH)
#define RS_SLSH	RSFT_T(KC_SLSH)
#define RA_SLSH	RALT_T(KC_SLSH)
#define RG_SLSH	RGUI_T(KC_SLSH)

// QWERTY Home Row Mods
#define LG_D		LGUI_T(KC_D)
#define LA_D		LALT_T(KC_D)
#define LS_D		LSFT_T(KC_D)
#define LC_D		LCTL_T(KC_D)

#define LG_F		LGUI_T(KC_F)
#define LA_F		LALT_T(KC_F)
#define LS_F		LSFT_T(KC_F)
#define LC_F		LCTL_T(KC_F)

#define RC_J		RCTL_T(KC_J)
#define RS_J		RSFT_T(KC_J)
#define RA_J		RALT_T(KC_J)
#define RG_J		RGUI_T(KC_J)

#define RC_K		RCTL_T(KC_K)
#define RS_K		RSFT_T(KC_K)
#define RA_K		RALT_T(KC_K)
#define RG_K		RGUI_T(KC_K)

#define RC_L		RCTL_T(KC_L)
#define RS_L		RSFT_T(KC_L)
#define RA_L		RALT_T(KC_L)
#define RG_L		RGUI_T(KC_L)

#define RC_SCLN	RCTL_T(KC_SCLN)
#define RS_SCLN	RSFT_T(KC_SCLN)
#define RA_SCLN	RALT_T(KC_SCLN)
#define RG_SCLN	RGUI_T(KC_SCLN)

// Layer Triggers
#define DF_CLMK	DF(_COLEMAKDHm)
#define DF_QWTY	DF(_QWERTY)
#define DF_GAME	DF(_GAMEPAD)

#define TT_MEDI	TT(_MEDIA)
#define TG_QUAN	TG(_QUANTUM)
#define MO_QUAN	MO(_QUANTUM)
#define MO_FUNC	MO(_FUNCTION)

#define WP_ZERO	LT(_WEAPONS,KC_0)
#define ME_LALT	LT(_MEDIA,KC_LALT)

#define FN_ESC		LT(_FUNCTION,KC_ESC)
#define FN_P00		LT(_FUNCTION,KC_P00)
#define FN_ENT		LT(_FUNCTION,KC_ENT)
#define FN_BSPC	LT(_FUNCTION,KC_BSPC)
#define FN_DEL		LT(_FUNCTION,KC_DEL)
#define FN_TAB		LT(_FUNCTION,KC_TAB)
#define FN_RGUI	LT(_FUNCTION,KC_RGUI)

#define NM_BSPC	LT(_NUMBER,KC_BSPC)
#define NM_SPC		LT(_NUMBER,KC_SPC)

#define NV_BSPC	LT(_NAVIGATION,KC_BSPC)
#define NV_DEL		LT(_NAVIGATION,KC_DEL)
#define NV_TAB		LT(_NAVIGATION,KC_TAB)
#define NV_ENT		LT(_NAVIGATION,KC_ENT)
#define NV_ESC		LT(_NAVIGATION,KC_ESC)
#define NV_RGUI	LT(_NAVIGATION,KC_RGUI)

// Macro Shortcuts
#define M_RDESC	LCA(KC_HOME)
#define M_NDSKT	G(C(KC_RGHT))
#define M_PDSKT	G(C(KC_LEFT))

#define M_WNUP		G(S(KC_UP))
#define M_WNDWN	G(S(KC_DN))
#define M_WNRGT	G(S(KC_RGHT))
#define M_WNLFT	G(S(KC_LEFT))

#define M_UNDO		LCTL(KC_Z)
#define M_CUT		LCTL(KC_X)
#define M_COPY		LCTL(KC_C)
#define M_PASTE	LCTL(KC_V)
#define M_REDO		LCTL(KC_Y)
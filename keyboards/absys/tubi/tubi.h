// Copyright 2022 dylanmcauliffe (@dylanmcauliffe)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT_tubi( \
	L00,	L01,	L02,	L03,	L04,	L05,			R06,	R07,	R08,	R09,	R0A,	R0B,	\
	L10,	L11,	L12,	L13,	L14,	L15,			R16,	R17,	R18,	R19,	R1A,	R1B,	\
	L20,	L21,	L22,	L23,	L24,	L25,	L35,	R36,	R26,	R27,	R28,	R29,	R2A,	R2B,	\
	L30,		L31,		L32,	L33,	L34,	R37,	R38,	R39,		R3A,		R3B	\
) {	\
	{	L00,	L01,	L02,	L03,	L04,	L05	},	\
	{	R06, R07, R08, R09, R0A, R0B	},	\
	{	L10,	L11,	L12,	L13,	L14,	L15	},	\
	{	R16, R17, R18, R19, R1A, R1B	},	\
	{	L20,	L21,	L22,	L23,	L24,	L25	},	\
	{	R26, R27, R28, R29, R2A, R2B	},	\
	{	L30,	L31,	L32,	L33,	L34,	L35	},	\
	{	R36, R37, R38, R39, R3A, R3B	}	\
}

#define LAYOUT_tubi_idiot( \
	L00,	L01,	L02,	L03,	L04,	L05,			R06,	R07,	R08,	R09,	R0A,	R0B,	\
	L10,	L11,	L12,	L13,	L14,	L15,			R16,	R17,	R18,	R19,	R1A,	R1B,	\
	L20,	L21,	L22,	L23,	L24,	L25,	L35,	R36,	R26,	R27,	R28,	R29,	R2A,	R2B,	\
	L30,		L31,		L32,	L33,	L34,	R37,	R38,	R39,		R3A,		R3B	\
) {	\
	{	L00,	L01,	L02,	L03,	L04,	L05	},	\
	{	L10,	L11,	L12,	L13,	L14,	L15	},	\
	{	L20,	L21,	L22,	L23,	L24,	L25	},	\
	{	L30,	L31,	L32,	L33,	L34,	L35	},	\
	{	R0B, R0A, R09, R08, R07, R06	},	\
	{	R1B, R1A, R19, R18, R17, R16	},	\
	{	R2B, R2A, R29, R28, R27, R26	},	\
	{	R3B, R3A, R39, R38, R37, R36	},	\
}

#define LAYOUT_tubi_pcb( \
	L00,	L01,	L02,	L03,	L04,	L05,			R06,	R07,	R08,	R09,	R0A,	R0B,	\
	L10,	L11,	L12,	L13,	L14,	L15,			R16,	R17,	R18,	R19,	R1A,	R1B,	\
	L20,	L21,	L22,	L23,	L24,	L25,	L35,	R36,	R26,	R27,	R28,	R29,	R2A,	R2B,	\
	L30,		L31,		L32,	L33,	L34,	R37,	R38,	R39,		R3A,		R3B	\
) {	\
	{	L00,	L01,	L02,	L03,	L04,	L05	},	\
	{	R0B, R0A, R09, R08, R07, R06	},	\
	{	L10,	L11,	L12,	L13,	L14,	L15	},	\
	{	R1B, R1A, R19, R18, R17, R16	},	\
	{	L20,	L21,	L22,	L23,	L24,	L25	},	\
	{	R2B, R2A, R29, R28, R27, R26	},	\
	{	L30,	L31,	L32,	L33,	L34,	L35	},	\
	{	R3B, R3A, R39, R38, R37, R36	},	\
}

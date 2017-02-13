#ifndef __SN764INTF_H__
#define __SN764INTF_H__

#include "../EmuStructs.h"

// undefine one of the variables to disable the cores
#define EC_SN76496_MAME		// enable SN76496 core from MAME
#define EC_SN76496_MAXIM	// enable SN76489 core by Maxim (from in_vgm)


typedef struct sn76496_config
{
	DEV_GEN_CFG _genCfg;
	
	UINT16 noiseTaps;		// noise tap mask (usually 2 bits set)
	UINT8 shiftRegWidth;	// noise shift register width
	UINT8 negate;			// invert output
	UINT8 clkDiv;			// clock divider (1 or 8)
	UINT8 segaPSG;			// enable Sega PSG frequencies (frequency 0 is treated as 1)
	UINT8 stereo;			// enable Sega Game Gear stereo
	
	void* t6w28_tone;		// SN-chip that emulates the "tone" part of a T6W28
} SN76496_CFG;

// example configurations from MAME:
//	chip		taps	srWidth	negate	clkDiv	segaPSG	stereo
//	--------	----	----	----	----	----	----
//	SN76489		0x03	15		1		8		0		0
//	U8106		0x03	15		1		8		0		0
//	SN94624		0x03	15		1		1		0		0
//	SN76489A	0x0C	17		0		8		0		0
//	SN76496		0x0C	17		0		8		0		0
//	Y2404		0x0C	17		0		8		0		0
//	SN76494		0x0C	17		0		1		0		0
//	NCR7496		0x22	16		0		8		0		0
//	SEGA PSG	0x09	16		1		8		1		0
//	Game Gear	0x09	16		1		8		1		1

// The T6W28 consists of two SN76489A devices - tone and noise. The tone device is created first.
// The noise device needs cfg.t6w28_tone to be set to the dataPtr of the tone device.
// Both devices will then be linked together.

extern const DEV_DEF* devDefList_SN76496[];

#endif	// __SN764INTF_H__

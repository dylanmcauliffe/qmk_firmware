Readme goes here.

TLDR:
Basic changes:
Three pins need to be switched around to use the Proton-C optimally with the Kyria v1.3 PCB.
	
	*PIN[ProMicro/Proton-C] connects to PCB XX*
	
	PIN [D3/A9] connects to PCB D2
	PIN [D2/A10] connects to PCB B5
	PIN [B5/B0] connects to PCB D3
    
A pullup resistor needs to connect PCB D2 to VCC.
	
Changes have been made to the following files:

	rules.mk
	config.h
	halconf.h
	mcuconf.h

Command to compile with these changes:

	qmk compile -e CTPC=yes -kb kyria -km dm_ctpc

Profit!!!


Long version of changes:

	Add pictures and stuff

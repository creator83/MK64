#include "MK64F12.h"
#include "port.h"

#ifndef FLEXBUS_H
#define FLEXBUS_H


//FMC pins
/*
PTC0 - D14
PTC1 - D13
PTC2 - D12
PTC3 - CLK
PTC4 - D11
PTC5 - D10
PTC6 - D9
PTC7 - D8
PTC8 - D7
PTC9 - D6
PTC10- D5
PTC11- RW
PTD1 - CS
PTD2 - D4
PTD3 - D3
PTD4 - D2
PTD5 - D1
PTD6 - D0
PTB17- RS
PTB18- D15
*/


namespace flexbusdef
{
//
	const uint32_t cPins = 0xFFF;
	const uint32_t dPins = 1 << 1| 1 << 2| 1 << 3| 1 << 4| 1 << 5| 1 << 6;
	const uint32_t bPins = 1 << 17|1 << 18;
}

const uint32_t flexDcAddress = 0x60000000;
const uint32_t flexAdsressMask = 0x00010000;
const uint32_t flexIndexAddress = flexDcAddress;
const uint32_t flexDataAdsress = flexDcAddress + flexAdsressMask;


class Flexbus
{
//variables
public:

protected:
private:
	Port B, C, D;

public:
	Flexbus();

protected:
private:
	void initPins ();
	void data (uint16_t );
	void index (uint16_t);
	void writeReg (uint16_t, uint16_t);
};

#endif


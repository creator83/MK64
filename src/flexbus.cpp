#include "flexbus.h"


Flexbus::Flexbus()
:B (Gpio::Port::B, Gpio::mux::Alt5, flexbusdef::bPins), C (Gpio::Port::C, Gpio::mux::Alt5, flexbusdef::cPins),
D (Gpio::Port::D, Gpio::mux::Alt5, flexbusdef::dPins)
{
	FB->CS[0].CSAR = flexDcAddress;
	FB->CS[0].CSMR = flexAdsressMask| FB_CSMR_V_MASK;
	FB->CS[0].CSCR = FB_CSCR_BLS_MASK| FB_CSCR_AA_MASK| FB_CSCR_PS(2);
}

void Flexbus::data (uint16_t value)
{
	*((uint16_t*)flexDataAdsress) = value;
}

void Flexbus::index (uint16_t value)
{
	*((uint16_t*)flexIndexAddress) = value;
}

void Flexbus::writeReg (uint16_t reg, uint16_t val)
{
	*((uint16_t*)flexIndexAddress) = reg;
	*((uint16_t*)flexDataAdsress) = val;
}



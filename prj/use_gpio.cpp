#include "MK64F12.h"                 // Device header
#include "pin.h"
#include "port.h"

const char ledDef = 1;

int main ()
{
	Pin led (Gpio::Port::A, ledDef);
	led.set();
	led.direction(Gpio::mode::Input);
	bool state = led.state();
	Port flexBus (Gpio::Port::A, (uint32_t)0xF0);
	while (1)
	{
	}
}

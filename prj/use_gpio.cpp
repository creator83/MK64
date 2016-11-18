#include "MK64F12.h"                 // Device header
#include "pin.h"
#include "port.h"
#include "tact.h"

Tact frq;

const char ledDef = 1;

int main ()
{
	Pin led (Gpio::Port::A, ledDef, Gpio::out::PushPull);
	led.set();
	led.setIn(Gpio::PP::PullUp);
	led.setOut();
	bool state = led.state();
	Port flexBusPin (Gpio::Port::B, 0xFFF000);
	while (1)
	{
	}
}

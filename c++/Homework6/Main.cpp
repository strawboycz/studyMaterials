#include <iostream>

#include "Computer.h"
#include "Keyboard.h"
#include "PowerBank.h"

int main()
{
	Computer computer("PC","intel i7","NVIDIA 960");
	computer.printParameters();
	Keyboard keyboard("Logitech 14xr", 125, true);
	keyboard.printParameters();
	PowerBank powerBank(10,20,20000);
	powerBank.printParameters();
	return 0;
}

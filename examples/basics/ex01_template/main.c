
//** For new Project
// 1. Edit
// 2. Save
// 3. Right-Click on the main.c and choose Open in Integrated Terminal
// 4. Run the command ecc-pic24-cli -build
// 5. Open the Proteus (Run as administrator)
// 6. Open the circuit
// 7. Double-click on the MCU and browse to the firmware.hex
// 8. Run the simulator and check the result.

//** For Development
// 1. Edit
// 2. Save
// 3. Compile using ecc-pic24-cli -build
// 4. Restart the simulator

#include "bsp.h"

int main(void)
{
	System_Init();

	Uart1_Printf("Welcome to Event-Driven Embedded System Programming.\r\n");

	System_Start();
}

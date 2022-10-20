//

#include <bsp.h>
#include <rtl.h>


void read_analog_0() {
	float adc0 = Adc_GetVoltage(0);
	Uart1_Printf("ADC0: %f\r\n", adc0);
	if(adc0 > 50) {
		//
	}
}


int main()
{
	System_Init();

	Timer_Create(1000, read_analog_0);

	System_Start();
}

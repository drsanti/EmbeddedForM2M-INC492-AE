
#include <bsp.h>
#include <rtl.h>

void read_analog_0() {

	float adc3 = Adc_GetVoltage(3);
	Uart1_Printf("ADC3: %f\r\n", adc3);

	// uint16_t adc3 = Adc3_Get();
	// Uart1_Printf("adc3: 0x%.4X\r\n", adc3);

	if(adc3 > 1.5) {
		Led3_Inv();
	}
	
}


int main()
{
	System_Init();

	Adc_Init();

	Timer_Create(1000, read_analog_0);

	System_Start();
}
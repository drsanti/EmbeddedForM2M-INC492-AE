
#include <bsp.h>
#include <rtl.h>


void timer_tick() {
	Uart1_Printf("ticks\r\n");
}

void psw_0() {
	Uart1_Printf("PSW0 pressed!\r\n");
}

void led0_toggle() {
	Led0_Inv();
}

void led3_toggle() {
	Led3_Inv();
}

int main()
{
	System_Init();

	Timer_Create(10000, timer_tick);

	Timer_Create(500, led0_toggle);

	Timer_Create(800, led3_toggle);

	Psw_SetKeyDownCallback(PSW_ID_0, psw_0);

	System_Start();
}

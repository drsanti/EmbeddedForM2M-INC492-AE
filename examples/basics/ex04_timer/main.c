
#include <bsp.h>
#include <rtl.h>


void timer_tick() {
	Uart1_Printf("ticks\r\n");
}

int main()
{
	System_Init();

	Timer_Create(1000, timer_tick);

	System_Start();
}

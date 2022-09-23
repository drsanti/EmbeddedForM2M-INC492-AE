
#include <bsp.h>
#include <rtl.h>


// void system_tick(void *ticks) {
// 	static uint32_t cnt = 0;
// 	if(++cnt >= 1000) {
// 		cnt = 0;
// 		uint16_t x = *((uint16_t *)ticks);
// 		Uart1_Printf("ticks: %u\r\n",x);
// 	}
	
// }

void timer_tick() {
	Uart1_Printf("ticks\r\n");
	
}

int main()
{
	System_Init();

	//Sys_SetTickCallback(system_tick);
	Timer_Create(1000, timer_tick);

	System_Start();
}

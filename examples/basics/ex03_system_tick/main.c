
#include <bsp.h>


void system_tick(void *ticks) {
	static uint32_t cnt = 0;
	if(++cnt >= 1000) {
		cnt = 0;
		uint16_t x = *((uint16_t *)ticks);
		Uart1_Printf("ticks: %u\r\n",x);
	}
	
}

int main()
{
	System_Init();

	Sys_SetTickCallback(system_tick);

	System_Start();
}

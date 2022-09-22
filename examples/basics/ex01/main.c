
#include <bsp.h>

int main(void)
{
	Mcu_Init();

	Uart1_Init(115200, 64, 64);

	Uart1_Printf("Hello\r\n");

	while (1)
	{
	}
}

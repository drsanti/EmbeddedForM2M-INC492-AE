
#include <bsp.h>

void psw0()
{
	Uart1_Printf("PSW0 ON\r\n");
	// Led0_Inv();
	Led0_Set();
}

void psw3()
{
	Uart1_Printf("PSW3 OFF\r\n");
	// Led3_Inv();
	Led0_Clr();
}

int main()
{
	Mcu_Init();
	Uart1_Init(115200, 64, 64);

	Psw_SetKeyDownCallback(PSW_ID_0, psw0);
	Psw_SetKeyDownCallback(PSW_ID_3, psw3);

	while (1)
	{
		PSW_KeyTickedExecutor();
	}
	return 0;
}

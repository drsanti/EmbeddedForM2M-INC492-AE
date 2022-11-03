
#include <bsp.h>
#include <rtl.h>


// counter: 0,1,2,3,0,1,...
void ex01()  {

	static uint16_t cnt = 0;
	static uint16_t state = 1;

	Uart1_Printf("cnt: %d", cnt);
	if( state == 1) {
		cnt++;
		if(cnt > 3) {
			state = 2;
		}
	}
	Uart1_Printf(", state: %d\r\n", state);
	if(state == 2) {
		cnt = 0;
		state = 1;
	}
}


// PSW0: -1	 cnt: ...,4,3,2,5,4,...
// PSW1: +1  cnt: ...,4,5,2,3,4,... 
void ex02(void *swEvent)  {

	static uint16_t cnt   = 2;
	static uint16_t state = 0;
	switch_event_t *e = (switch_event_t *)swEvent;
	uint8_t id = e->id;
	Uart1_Printf("id: %d", id);

	if(id == PSW_ID_0) {
		state = 0;
	}
	if(id == PSW_ID_1) {
		state = 1;
	}

	Uart1_Printf(", cnt: %d\r\n", cnt);

	if(state == 0) {
		cnt--;
		if(cnt < 2) {
			cnt = 5;
		}
	}
	if(state == 1) {
		cnt++;
		if(cnt > 5) {
			cnt = 2;
		}
	}
}
//
int main()
{
	System_Init();

	// for ex01
	Psw_SetKeyDownCallback(PSW_ID_3, ex01);

	// for ex02
	Psw_SetKeyDownCallback(PSW_ID_0, ex02);
	Psw_SetKeyDownCallback(PSW_ID_1, ex02);

	System_Start();
}
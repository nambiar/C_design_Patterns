#include <stdio.h>
#include "timer_wheel.c"

static void timer_callback(void)
{
	printf("Timer callback\n");
}

int main(int argc, char **argv)
{
	uint32_t check_t;
	if(!timer_wheel_init(5))
		printf("timer wheel initialised\n");
	
	check_t = Add_timer_wheel(5,timer_callback,TIMER_ONE_SHOT_MODE);
	printf("timer 1 initialised, value is %d\n",check_t );
	check_t = Add_timer_wheel(5,timer_callback,TIMER_ONE_SHOT_MODE);
	printf("timer 2 initialised, value is %d\n",check_t );
	Stop_timer(check_t);
	check_t = Add_timer_wheel(6,timer_callback,TIMER_ONE_SHOT_MODE);
	printf("timer 3 initialised, value is %d\n",check_t );
	check_t = Add_timer_wheel(5,timer_callback,TIMER_ONE_SHOT_MODE);
	printf("timer 4 initialised, value is %x\n",check_t );
	Stop_timer(check_t);
	check_t = Add_timer_wheel(5,timer_callback,TIMER_ONE_SHOT_MODE);
	printf("timer 5 initialised, value is %x\n",check_t );
	Stop_timer(check_t);
	timer_overflow();
	return 0;
}

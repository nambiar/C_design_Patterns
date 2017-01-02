#include <stdint.h>
#include <stdio.h>
#include <stdint.h>
#include "AO_scheduler.c"

void layer1(void)
{
	printf("Executing layer1\n");
}

void layer2(void)
{
	printf("Executing layer2\n");
}

void layer3(void)
{
	printf("Executing layer3\n");
}

int main(int argc, char const *argv[])
{
	void startScheduler(void);
	void ConfigureScheduler(layer1, 0);
	void ConfigureScheduler(layer2, 1);
	void ConfigureScheduler(layer3, 2);
	SchedulerMain();
	/* code */
	return 0;
}
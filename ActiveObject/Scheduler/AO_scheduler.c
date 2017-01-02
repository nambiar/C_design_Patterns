/**************************** Includes ***************************************/
#include <stdint.h>
#include <stdio.h>
#include <stdint.h>
#include "AO_scheduler.h"
#include "interrupt.h"
#define time_interval 50
#define HIGH_PRIORITY_LAYER 0x00
static uint8_t layer_to_be_serviced = 0;
static task LAYER_TASK[MAX_NUMBER_OF_LAYERS];
void timerISR(void);
int static taskDispatch(task* layerTask);
void startScheduler(void)
{
	for (int i = 0; i < MAX_NUMBER_OF_LAYERS; ++i)
	{
		LAYER_TASK[i].task_layer = NULL;
		/* code */
	}
}

void timerISR(void)
{
    stop_timer();
	layer_to_be_serviced++;
	if(layer_to_be_serviced >= (MAX_NUMBER_OF_LAYERS + 1))
	{
		layer_to_be_serviced = HIGH_PRIORITY_LAYER;
                layer_to_be_serviced++;

	}
	taskDispatch(LAYER_TASK+(layer_to_be_serviced-1));
}

void ConfigureScheduler(taskLayer Layerfunc, int priority)
{
	//priority is from 0 and increases from 0 to layer
	//assert(priority);
	static int index = 0;
	LAYER_TASK[priority].task_layer = Layerfunc;
	//assert(index >= MAX_NUMBER_OF_LAYERS);
	index++;
}

int static taskDispatch(task* layerTask)
{
	//assert(layerTask->task_layer == NULL);
    start_timer(time_interval, timerISR);
	return(layerTask->task_layer());
}

void SchedulerMain()
{
	for (int i = 0; i < MAX_NUMBER_OF_LAYERS; ++i)
	{
		//assert(LAYER_TASK[i].task_layer == NULL);
		/* code */
	}
	//start timer with 50 msec interval
	if(start_timer(time_interval, timerISR))
	{
		printf("\n timer error\n");
		return(1);
	}
	while(1);
}

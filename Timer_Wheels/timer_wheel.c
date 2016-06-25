
#include <stdio.h>
#include "timer_wheel.h"
#include <stdint.h>
#include <assert.h>
#define MAX_SLOTS 8
#define TIME_INTERVAL_PER_SLOT 10
#define TIMER_NOT_USED 0
#define ALL_HANDLERS_UNASSIGNED 8
#define HANDLER_ASSSIGNED(x) (x << 24)
static timer_slot slot[8];
static uint8_t current_timer_slot = 0;
static uint8_t current_slots_used;
static uint8_t timer_overflow_task_handler_index = 0;

//During init the number of slot can be application specific

static uint8_t get_id(void)
{
	static int i = 0;
	if(i>255)
	{
		i = 0;
	}
	else
	{
		i++;
	}
	return i;
}

int timer_wheel_init(int number_of_slots)
{
	if(number_of_slots>MAX_SLOTS)
		return -1;
	uint8_t index;
	current_slots_used = number_of_slots;
	for(index = 0 ; index < number_of_slots; index++)
	{
		slot[index].id = TIMER_NOT_USED;
		uint8_t index_handlers;
		//single dimesion arrays, extend it to 2-D (undertsand memory constraints)
		for(index_handlers = 0 ; index_handlers < 7; index_handlers++)
		{
			slot[index].overflow[index_handlers] = (void *)0;
		}
	}
	return 0;
}

static timer_id add_timer_wheel(time_ms Time, Callback callback,timer_modes mode)
{
	//add handler to first if not used otherwise just search and add to not NULL one
	uint8_t slot_index = (current_timer_slot + (Time/TIME_INTERVAL_PER_SLOT))% MAX_SLOTS;
	uint8_t index = 0;

	if(slot[slot_index].id == TIMER_NOT_USED)
	{
		slot[slot_index].id = get_id();
		printf("Inside TIMER_NOT_USED\n");
		mode = ENABLE_TIMER_WITH_ONE_SHOT_MODE;
		if(mode == TIMER_REPEAT_MODE)
			mode = ENABLE_TIMER_WITH_REPEAT_MODE;
		slot[slot_index].mode = mode;
		slot[slot_index].overflow[0] = callback;
		return (((0x00000000|slot[slot_index].id)<<16)|mode);
	}
	else
	{
		printf("ïn Timer Used Scenario\n");
		while(slot[slot_index].overflow[index]!=NULL)
		{
			index++;
		}
		mode = ENABLE_TIMER_WITH_ONE_SHOT_MODE;
		if(mode == TIMER_REPEAT_MODE)
			mode = ENABLE_TIMER_WITH_REPEAT_MODE;
		timer_modes_specifier mode_id = (mode<<2*index);
		slot[slot_index].mode |= (mode<<2*index);
		slot[slot_index].overflow[index] = callback;
		return (HANDLER_ASSSIGNED(index)|(((0x00000000|slot[slot_index].id)<<16)|mode_id));
	}

}

timer_id Add_timer_wheel(time_ms time, Callback  callback, timer_modes mode)
{
	timer_id val = add_timer_wheel(time,callback,mode);
	return(val);
}

void timer_overflow(void)
{
	if(slot[current_timer_slot].id == TIMER_NOT_USED)
		return;
	uint16_t handler_index = slot[current_timer_slot].mode;
    uint8_t index;
    for(index=0;index<=8;index++)
    {
    	uint16_t temp_index = (handler_index & (0x0003 <<2 * index));
    	if(temp_index)
    	{
    		slot[current_timer_slot].overflow[index](); 

    	}
    }

}

uint8_t Stop_timer(timer_id id_handler)
{
	uint8_t handler_index = ((id_handler & 0xff000000)>>24);
	uint8_t id_slot = ((id_handler & 0x00ff0000)>>16);
	//search the array where the id is located and make it 0
	uint8_t index;
	for(index = 0 ; index < current_slots_used; index++)
	{
		uint8_t callback_index = 0;
		if(slot[index].id == id_slot)
		{
			while(slot[index].overflow[callback_index] == NULL)
			{
				callback_index++;

			}
			if(callback_index == 8)
			{
			slot[index].id = TIMER_NOT_USED;
			slot[index].mode = MODE_DEFAULT;	
			}
			slot[index].overflow[handler_index] = NULL;
			slot[index].mode &= (0xffff ^ (0x0003 <<2 * handler_index));
			return 0;
		}
	}
	return -1;// timer already stopped
}

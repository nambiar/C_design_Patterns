#include <stdint.h>
#define time_ms uint8_t
#define timer_id uint32_t
#define slot_id uint8_t
#define timer_modes_specifier uint16_t
#define ENABLE_TIMER 0x02
#define MODE_DEFAULT 0x00
typedef void (*task_handler_timer_overflow)(void);
typedef void (*Callback)(void);
#define mode_handler(x)
typedef enum
{
	TIMER_ONE_SHOT_MODE,
	TIMER_REPEAT_MODE
}timer_modes;

#define ENABLE_TIMER_WITH_ONE_SHOT_MODE (TIMER_ONE_SHOT_MODE | ENABLE_TIMER)
#define ENABLE_TIMER_WITH_REPEAT_MODE (TIMER_REPEAT_MODE | ENABLE_TIMER)
typedef struct 
{
	
	slot_id id;  // smae for all the entire 8 event handlers
	timer_modes_specifier mode;//each 16 bit becomes the mode calculator as well as it is enabled or not
	//10 : 1 means enabled , 0 means one shot mode, 1 means repeat mode
	//00, 01 means disabled event handler
	task_handler_timer_overflow overflow[8];
}timer_slot;

timer_id Add_timer_wheel(time_ms time,Callback callback,timer_modes mode);
void timer_overflow(void);
uint8_t Stop_timer(timer_id);

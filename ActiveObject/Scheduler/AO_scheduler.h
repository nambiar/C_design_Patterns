
#ifndef AO_SCHEDULER_H
#define AO_SCHEDULER_H
#ifdef __cplusplus
extern "C" {
#endif
#define  MAX_NUMBER_OF_LAYERS 3

#define STATUS 				uint8_t 
#define SUCCESSS 			0x00
#define FAILURE 			0x01
/* Task Structures*/
//All instance of this structure will have "_task"
typedef struct {
STATUS (*task_layer)(void);//this is function hook that connects the layers and the scheduler
}task;

typedef STATUS (*taskLayer)(void);

void startScheduler(void);
void ConfigureScheduler(taskLayer Layerfunc, int priority);
void SchedulerMain();
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum States
{
STATE_DOOR_OPEN,
STATE_DOOR_SHUT,
STATE_DOOR_OPEN_WITH_ITEM,
STATE_DOOR_SHUT_WITH_ITEM,
STATE_READY_TO_COOK,
STATE_COOKING
}states_e;
typedef enum Events
{
Event_DoorOpened,
Event_DoorClosed,
Event_ItemPlaced,
Event_ItemRemoved,
Event_Cancel,
Event_CookingTimeEntered,
Event_StopCooking,
Event_StartCooking,
Event_Stop,
Event_Start,
Event_TimerExpired,
}events_e;

typedef enum Conditions
{
Condition_Default,
Condition_TimeRemaining,
Condition_ZeroTime,
Condition_C,
Condition_D,
}conditions_e;
typedef enum command
{
    STATE,
    EVENTS,
    CONDITIONS,
}command_e;
typedef struct getenums
{
    states_e state;
    events_e event;
    conditions_e condition;
    command_e command;  
}getEnums;
void eventHandler_cookingtimeentered()
{
    printf("Display cooking time\n");
    printf("Display update time\n");
}
void eventHandler_canceltimer()
{
    printf("Cancel timer\n");

}
void eventHandler_starttimer()
{
    printf("Start timer\n");

}
void eventHandler_stoptimer()
{
   printf("Stop Cooking\n"); 
   printf("Stop timer\n");

}
typedef void (*func_pointer)(void);
typedef void (*funcPointer[])(void);
typedef struct 
{
    states_e state;
    events_e event;
    conditions_e condition;
    func_pointer action;
    states_e nextstate;
}stateMachineTables;
typedef struct 
{
    events_e* events;
    conditions_e* condition;
    states_e* nextstate;
    funcPointer action;
}contextstate;
typedef struct
{
    states_e state;
    contextstate context;

}stateMachineTablesNEW;/*
stateMachineTablesNEW stateTableNEW[2] =
{{STATE_DOOR_SHUT,{{Event_DoorOpened},{Condition_Default},{STATE_DOOR_OPEN},{NULL}}},
{STATE_DOOR_OPEN,{{Event_DoorClosed,Event_ItemPlaced},{Condition_Default,Condition_Default}{STATE_DOOR_SHUT,STATE_DOOR_OPEN_WITH_ITEM}}};*/
#define NO_OF_STATES 14
stateMachineTables stateTable[NO_OF_STATES] = 
{{STATE_DOOR_SHUT,Event_DoorOpened,Condition_Default,NULL,STATE_DOOR_OPEN},
{STATE_DOOR_OPEN,Event_DoorClosed,Condition_Default,NULL,STATE_DOOR_SHUT},
{STATE_DOOR_OPEN,Event_ItemPlaced,Condition_Default,NULL,STATE_DOOR_OPEN_WITH_ITEM},
{STATE_COOKING,Event_StopCooking,Condition_Default,NULL,STATE_DOOR_SHUT_WITH_ITEM},
{STATE_DOOR_OPEN_WITH_ITEM,Event_ItemRemoved,Condition_Default,NULL,STATE_DOOR_OPEN},
{STATE_DOOR_OPEN_WITH_ITEM,Event_DoorClosed,Condition_Default,NULL,STATE_DOOR_SHUT_WITH_ITEM},
{STATE_DOOR_SHUT_WITH_ITEM,Event_CookingTimeEntered,Condition_Default,eventHandler_cookingtimeentered,STATE_READY_TO_COOK},
{STATE_READY_TO_COOK,Event_Cancel,Condition_Default,eventHandler_canceltimer,STATE_DOOR_SHUT_WITH_ITEM},
{STATE_READY_TO_COOK,Event_CookingTimeEntered,Condition_Default,eventHandler_cookingtimeentered,STATE_READY_TO_COOK},
{STATE_READY_TO_COOK,Event_Start,Condition_Default,eventHandler_cookingtimeentered,STATE_COOKING},
{STATE_READY_TO_COOK,Event_DoorOpened,Condition_Default,NULL,STATE_DOOR_OPEN_WITH_ITEM},
{STATE_COOKING,Event_DoorOpened,Condition_Default,eventHandler_stoptimer,STATE_DOOR_OPEN_WITH_ITEM},
{STATE_COOKING,Event_TimerExpired,Condition_Default,NULL,STATE_DOOR_SHUT_WITH_ITEM},
{STATE_COOKING,Event_Cancel,Condition_Default,NULL,STATE_READY_TO_COOK}};

/*stateTable remains and table points to the present context of the table */

stateMachineTables* tablePtr = stateTable;
int state = STATE_DOOR_SHUT;

const char* getenums(getEnums* enums) 
{
    static const char* string;
    if(enums->command == STATE)
    {

        switch (enums->state)
        {
            case STATE_DOOR_OPEN: 
                   string =  "STATE_DOOR_OPEN";
                   break;
            case STATE_DOOR_SHUT: 
                   string = "STATE_DOOR_SHUT";
                   break;
            case STATE_DOOR_OPEN_WITH_ITEM: 
                   string =  "STATE_DOOR_OPEN_WITH_ITEM";
                   break;
            case STATE_DOOR_SHUT_WITH_ITEM: 
                   string = "STATE_DOOR_SHUT_WITH_ITEM";
                   break;  
            case STATE_READY_TO_COOK: 
                   string =  "STATE_READY_TO_COOK";
                   break;
            case STATE_COOKING: 
                   string = "STATE_COOKING";
                   break;                                     
        }
    }
    if (enums->command == EVENTS)
    {
        switch (enums->event)
        {
            case Event_DoorOpened: 
                   string =  "Event_DoorOpened";
                   break;
            case Event_DoorClosed: 
                   string = "Event_DoorClosed";
                   break;
            case Event_ItemPlaced: 
                   string =  "Event_ItemPlaced";
                   break;
            case Event_ItemRemoved: 
                   string = "Event_ItemRemoved";
                   break;  
            case Event_Cancel: 
                   string =  "Event_Cancel";
                   break;
            case Event_CookingTimeEntered: 
                   string = "Event_CookingTimeEntered";
                   break; 
            case Event_StopCooking: 
                   string = "Event_StopCooking";
                   break;  
            case Event_StartCooking: 
                   string =  "Event_StartCooking";
                   break;
            case Event_Stop: 
                   string = "Event_Stop";
                   break;   
            case Event_Start: 
                   string = "Event_Start";
                   break;  
            case Event_TimerExpired: 
                   string =  "Event_TimerExpired";
                   break;                                                      
        }
    }
    if (enums->command == CONDITIONS)
    {
        switch (enums->condition)
        {
            case Condition_Default: 
                   string =  "Condition_Default";
                   break;
            case Condition_TimeRemaining: 
                   string = "Condition_TimeRemaining";
                   break;
            case Condition_ZeroTime: 
                   string =  "Condition_ZeroTime";
                   break;
            case Condition_C: 
                   string = "Condition_C";
                   break;  
            case Condition_D: 
                   string =  "Condition_D";
                   break;                                     
        }       
        /* code */
    }   
    return string; 

}

int get_index_table(int state)
{
   int i = 0;
   while(stateTable[i].state != state)
   {
     i++;

   }
   return i;
}
int get_state()
{
    return tablePtr->state;
}
void do_state_transition(int event)
{
    //pointer pointing to the table index
    stateMachineTables* tableIndexPtr = stateTable;
    if (tablePtr == NULL)
    {
        printf("Pointer error\n");
    }
    //get the present state
    int state = tablePtr->state;
    //change from the present index
    int changeinIndex = 0;
    //to find the rollover if there is a condition not met
    bool statechange = false;

    //check if the present state exist
    while(state == tablePtr->state)
    {
        if(tablePtr->event != event)
        {
            tablePtr++;
            changeinIndex++;
            continue;
        }
        if(tablePtr->event == event)
        {

            //event matches check for the state 
            //call the event handler
            if (tablePtr->action != NULL)
            {
                tablePtr->action();
            }
            //get index for the next state
            int index = get_index_table(tablePtr->nextstate);
            //move the pointer to that index
            tablePtr = tableIndexPtr + index;
            statechange = true;
            //break from while loop
            break;
        }
    }
    //changed the state as event occured
    if (statechange == false)
    {
    // No event matching the state raise error and stay in same stat
        printf("Event not attached to the state\n");
        tablePtr -= changeinIndex;
    }

}

int getEvent()
{
    int event_recv;
    printf("Enter the event \n");
    scanf("%d",&event_recv);
    do_state_transition(event_recv);

}

int main(int argc, char const *argv[])
{
    int index =100;
    for (index = 0; index < 6; ++index)
    { 
        getEvent();
        getEnums enums;
        enums.state = get_state();
        enums.command = STATE;
        printf("state is %s\n", getenums(&enums));
    }

	return 0;
}


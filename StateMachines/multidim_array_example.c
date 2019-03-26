#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct d2
{
	char* name;
	int age;
}d2;

typedef union d1
{
	d2 d3;
	char mydatastring[9];
}d1;
typedef enum States
{
STATE_DOOR_OPEN,
STATE_DOOR_SHUT,
STATE_DOOR_OPEN_WITH_ITEM,
STATE_DOOR_SHUT_WITH_ITEM,
STATE_READY_TO_COOK,
STATE_COOKING
}states;
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
}events;

typedef enum Conditions
{
Condition_Default,
Condition_TimeRemaining,
Condition_ZeroTime,
Condition_C,
Condition_D,
}conditions;
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
typedef struct 
{
    states state;
    events event;
    conditions condition;
    func_pointer action;
    states nextstate;
}state_machine_tables;
state_machine_tables state_table[14] = 
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
state_machine_tables* table = state_table;
int state = STATE_DOOR_SHUT;
int get_index_table(int state)
{
   int i = 0;
   while(state_table[i].state != state)
   {
     i++;

   }
   return i;
}
int get_state()
{
    return table->state;
}
void do_state_transition(int event)
{
    if (table == NULL)
    {
        printf("Pointer error\n");
    }
    int state = table->state;
    int index_in_table = table - state_table;
    int present_index = index_in_table;
    bool iterations = false;
    //retrieve the event for the state;
    //the first condition in while is met for first time and next time
    //onwards it checks if the state and event doesnot match
    while(table-> state != state  &&  index_in_table != present_index && table->event != event)
    {
        //move to next state table lookup 
        if (present_index == 12)
        {
            table -= 12;
        }
        else
        {
            table++;
        }
        if((present_index == index_in_table) && (iterations == false))
        {
            iterations = true;
        }
        else
        {
            printf("Event not defined for this state\n");
            return;
        }
    }
    //call the event handler
    if (table->action != NULL)
    {
        //*state_table->action();
       *table->action();
    }
    //get index for the next state
    int index = get_index_table(table->nextstate);
    //move the pointer to that index
    table += index;
}
int get_event()
{
    int event_recv;
    printf("Enter the event \n");
    scanf("%d",&event_recv);
    do_state_transition(event_recv);

}

int main(int argc, char const *argv[])
{
    int index;
    for (index = 0; index < 6; ++index)
    {
        get_event();
        printf("state is %d\n", get_state());
    }
/*
	printf("enter the no of rows and coloums\n");
	int row, coloums,coloums1;
	scanf("%d",&row);
	scanf("%d",&coloums);
	scanf("%d",&coloums1);
	printf("row and coloums are %d & %d\n",row,coloums);
	int array[row][coloums][coloums1];//defined an array 
    int i,j,k;
    int (*ptr) [row][coloums][coloums1] = &array;
    int arr[5][7][6];
    int (*p)[row][coloums][coloums1] = &array;
    for (i = 0; i < row; i++) 
    { 
        for ( j = 0; j < coloums; j++) 
        { 
        	for (k = 0; k < coloums1; ++k)
        	{
        		array[i][j][k] = i+j+k;
        	}
        	 
        } 
    }
    for (i = 0; i < row; i++) 
    { 
        for ( j = 0; j < coloums; j++) 
        { 
        	for (k = 0; k < coloums1; ++k)
        	{
        		printf("%d\n",array[i][j][k]);
        	}
        	 
        } 
    }
    
    /*
    suppose int (*arr)[5][6][7] = k[5][6][7]
    translating the expression *( *( *(arr + 2) + 1) + 2) step-by-step makes it more clear.

	arr – An array of 5 two dimensional arrays, i.e. its type is “array of 5 two dimensional arrays”.
	arr + 2 – displacement for 3rd element in the array of 5 two dimensional arrays.
	*(arr + 2) – dereferencing, i.e. its type is now two dimensional array.
	*(arr + 2) + 1 – displacement to access 2nd element in the array of 7 one dimensional arrays.
	*( *(arr + 2) + 1) – dereferencing (accessing), now the type of expression “*( *(arr + 2) + 1)” is an array of integers.
	*( *(arr + 2) + 1) + 2 – displacement to get element at 3rd position in the single dimension array of integers.
	*( *( *(arr + 2) + 1) + 2) – accessing the element at 3rd position (the overall expression type is int now).
	*/
    /*printf("\n enter the index you want to retrieve\n");
    scanf("%d",&i);
    scanf("%d",&j);
    scanf("%d",&k);
	printf("%d\n", *(*(*(*(ptr + i)+j)+k)));*/
	return 0;
}


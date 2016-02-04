#include <stdio.h>
#include "State_Pattern_AtmStateWatch.h"
#include "State_Pattern_ATM.h"



int main(int argc, char **argv)
{
    ATMptr context = CreateATMmachineContext();
    if(context == NULL)
    {
        printf("Not allocated");
    }
    StartATMMachine(context);
    context->state.InsertCard(&(context->state));
    //printf("%ld", context->state)
	printf("hello world\n");
	return 0;
}

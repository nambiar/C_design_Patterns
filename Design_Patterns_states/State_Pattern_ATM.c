#include "State_Pattern_ATM.h"
#include <stdio.h>
#include <stdlib.h>

ATMptr CreateATMmachineContext(void)
{
    ATMptr instance = (ATMmachine*)malloc(sizeof(ATMmachine));
    
    while(NULL == instance)
    {
        printf("malloc failed");
    }
    return instance;
}

void DestroyATMmachineContext(ATMptr instance)
{
    free(instance);
}

void StartATMMachine(ATMptr instance)
{
    defaultImplementation(&(instance->state));
    transitionToSTATE_START(&(instance->state));
}

void StopATMMachine(ATMptr instance)
{
    instance->state.Stop(&(instance->state));
} 
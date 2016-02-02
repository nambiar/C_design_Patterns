#ifndef HEADER_STATE_PATTERN_ATM_H
#define HEADER_STATE_PATTERN_ATM_H
#include "State_Pattern_AtmStateWatch.h"

typedef struct ATMmachine* ATMptr;

typedef struct ATMmachine
{
   // ATMstateptr state;
    struct ATMmachineState state;
    int ATMInput;
    
}ATMmachine;

ATMptr CreateATMmachineContext(void);
void DestroyATMmachineContext(ATMptr instance);
void StartATMMachine(ATMptr instance);
#endif
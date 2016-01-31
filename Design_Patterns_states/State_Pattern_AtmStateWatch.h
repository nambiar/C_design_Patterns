#ifndef HEADER_STATE_PATTERN_ATM_H
#define HEADER_STATE_PATTERN_ATM_H


#include "State_Pattern_ATM_Staes.h"

typedef ATMmachineState* ATMstateptr;


typedef void (Event_InsertCard*)(ATMstateptr);
typedef void (Event_PinOk*)(ATMstateptr);
typedef void (Event_Deposit*)(ATMstateptr);
typedef void (Event_Withdrawl*)(ATMstateptr);
typedef void (Event_Account*)(ATMstateptr);
typedef void (Event_Amount*)(ATMstateptr);
typedef void (Event_InsertEnvelope*)(ATMstateptr);
typedef void (Event_WithdrawCard*)(ATMstateptr);
typedef void (Event_BadPin*)(ATMstateptr);
typedef void (Event_No*)(ATMstateptr);
typedef void (Event_Yes*)(ATMstateptr);


struct ATMmachineState
{
  Event_InsertCard InsertCard;
  Event_PinOk PinOk;
  Event_Deposit Deposit;
  Event_Withdrawl Withdrawl;
  Event_Account Account;
  Event_Amount Amount;
  Event_InsertEnvelope InsertEnvelope;
  Event_WithdrawCard WithdrawCard;
  Event_BadPin BadPin;
  EVENT_No No;
  Event_Yes Yes;
}

void defaultImplementation(ATMstateptr state);



#endif
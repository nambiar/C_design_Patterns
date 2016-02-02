#ifndef HEADER_STATE_PATTERN_ATMSTATEWATCH_H
#define HEADER_STATE_PATTERN_ATMSTATEWATCH_H


typedef struct ATMmachineState* ATMstateptr;

typedef void (*Event_Start)(ATMstateptr);
typedef void (*Event_InsertCard)(ATMstateptr);
typedef void (*Event_PinOk)(ATMstateptr);
typedef void (*Event_Deposit)(ATMstateptr);
typedef void (*Event_Withdrawl)(ATMstateptr);
typedef void (*Event_Account)(ATMstateptr);
typedef void (*Event_Amount)(ATMstateptr);
typedef void (*Event_InsertEnvelope)(ATMstateptr);
typedef void (*Event_WithdrawCard)(ATMstateptr);
typedef void (*Event_BadPin)(ATMstateptr);
typedef void (*Event_No)(ATMstateptr);
typedef void (*Event_Yes)(ATMstateptr);
typedef void (*Event_Stop)(ATMstateptr);

struct ATMmachineState
{
  Event_Start Start;
  Event_InsertCard InsertCard;
  Event_PinOk PinOk;
  Event_Deposit Deposit;
  Event_Withdrawl Withdrawl;
  Event_Account Account;
  Event_Amount Amount;
  Event_InsertEnvelope InsertEnvelope;
  Event_WithdrawCard WithdrawCard;
  Event_BadPin BadPin;
  Event_No No;
  Event_Yes Yes;
  Event_Stop Stop;
};

void defaultImplementation(ATMstateptr state);

void ChangeState(ATMstateptr newState);



#endif
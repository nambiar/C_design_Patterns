//#include "State_Pattern_ATM_States.h"
#include "State_Pattern_AtmStateWatch.h"
/*typedef struct ATMmachineState
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
}ATMmachine;*/
void transitionToSTATE_A(ATMstateptr);
void transitionToSTATE_B(ATMstateptr);
void transitionToSTATE_C(ATMstateptr );
void transitionToSTATE_D(ATMstateptr);
void transitionToSTATE_E(ATMstateptr);
void transitionToSTATE_F(ATMstateptr);
void transitionToSTATE_G(ATMstateptr);
void transitionToSTATE_H(ATMstateptr);
void transitionToSTATE_I(ATMstateptr);
void transitionToSTATE_J(ATMstateptr);

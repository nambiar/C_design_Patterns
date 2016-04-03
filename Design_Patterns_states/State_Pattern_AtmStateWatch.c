#include "State_Pattern_AtmStateWatch.h"
#include <stdio.h> 

static void  defaultStart(ATMstateptr state)
{
    printf("Inside Default start");
}

static void  defaultInsertCard(ATMstateptr state)
{
    printf("Insert Card Default");
}
/*static void  defaultStart(ATMstateptr);
static void defaultInsertCard(ATMstateptr);
static void  defaultPinOk(ATMstateptr);
static void  defaultDeposit(ATMstateptr);
static void  defaultWithdrawl(ATMstateptr);
static void  defaultAccount(ATMstateptr);
static void  defaultAmount(ATMstateptr);
static void  defaultInsertEnvelope(ATMstateptr);
static void  defaultWithdrawCard(ATMstateptr);
static void  defaultBadPin(ATMstateptr);
static void  defaultNo(ATMstateptr);
static void  defaultYes(ATMstateptr);State_Pattern_AtmStateWatch
static void  defaultStop(ATMstateptr);

*/
/*
static void default(ATMstateptr)
{
   // printf("In default");
}
*/
void defaultImplementation(ATMstateptr state)
{
  //state->Start = defaultStart;
   state->InsertCard = defaultInsertCard;
 /* state->PinOk = defaultPinOk;
  state->Deposit = defaultDeposit;
  state->Withdrawl = defaultWithdrawl;
  state->Account = defaultAccount;
  state->Amount = defaultAmount;
  state->InsertEnvelope = defaultInsertEnvelope;
  state->WithdrawCard = defaultWithdrawCard;
  state->BadPin = defaultBadPin;
  state->No = defaultNo;
  state->Yes = defaultYes;
  state->Stop = defaultStop;
  */
}

//void ChangeState(ATMptr instance, ATMstateptr newState)
void ChangeState(ATMstateptr newState)
{
  //  instance->state = newState;
}
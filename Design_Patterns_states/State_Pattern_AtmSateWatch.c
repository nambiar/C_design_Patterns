#include"State_Pattern_AtmStateWatch.h"



static void defaultInsertCard(void);
static void  defaultPinOk(void);
static void  defaultDeposit(void);
static void  defaultWithdrawl(void);
static void  defaultAccount(void);
static void  defaultAmount(void);
static void  defaultInsertEnvelope(void);
static void  defaultWithdrawCard(void);
static void  defaultBadPin(void);
static void  defaultNo(void);
static void  defaultYes(void);






static void defaultImplementation(ATMstateptr state)
{
  state->InsertCard = defaultInsertCard;
  state->PinOk = defaultPinOk;
  state->Deposit = defaultDeposit;
  state->Withdrawl = defaultWithdrawl;
  state->Account = defaultAccount;
  state->Amount = defaultAmount;
  state->InsertEnvelope = defaultInsertEnvelope;
  state->WithdrawCard = defaultWithdrawCard;
  state->BadPin = defaultBadPin;
  state->No = defaultNo;
  state->Yes = defaultYes;
}
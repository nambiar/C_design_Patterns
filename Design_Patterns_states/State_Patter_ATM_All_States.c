#include "State_Patter_ATM_All_States.h"
#include "State_Pattern_AtmStateWatch.h"

static void  InsertCard(void)
{
    printf("Inside InsertCard");
}

static void  BadPin(void)
{
    printf("Inside BadPin");
}

static void  PinOk(void)
{
    printf("Inside PinOk");
}
static void  Deposit(void)
{
    printf("Inside Deposit");
}
static void  Withdrawl(void)
{
    printf("Inside Withdrawl");
}
static void  Account(void)
{
    printf("Inside Account");
}
static void  Amount(void)
{
    printf("Inside Amount");
}
static void  InsertEnvelope(void)
{
    printf("Inside InsertEnvelope");
}
static void  WithdrawCard(void)
{
    printf("Inside InsertEnvelope");
}
static void  BadPin(void)
{
    printf("Inside InsertEnvelope");
}
static void  No(void)
{
    printf("Inside InsertEnvelope");
}
static void  Yes(void)
{
    printf("Inside Yes");
}







void transitionToSTATE_A(ATMstateptr state)
{
    defaultImplementation(state);
    state->InsertCard = InsertCard;
    
}

void transitionToSTATE_B(void)
{
    state->BadPin = BadPin;
    //change state 
}
void transitionToSTATE_C(void)
{
    state->BadPin = BadPin;
    //change state 
}

void transitionToSTATE_D(void)
{
    state->BadPin = BadPin;
    //change state 
}
void transitionToSTATE_E(void)
{
    state->BadPin = BadPin;
    //change state 
}
void transitionToSTATE_F(void)
{
    state->BadPin = BadPin;
    //change state 
}
void transitionToSTATE_G(void)
{
    state->BadPin = BadPin;
    //change state 
}
void transitionToSTATE_H(void)
{
    state->BadPin = BadPin;
    //change state 
}
void transitionToSTATE_I(void)
{
    state->BadPin = BadPin;
    //change state 
}
void transitionToSTATE_J(void)
{
    state->BadPin = BadPin;
    //change state 
}
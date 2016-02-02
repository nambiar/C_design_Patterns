#include "State_Pattern_ATM_All_States.h"

#include <stdio.h>/*
typedef struct ATMmachineState
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
//class defaultImplementation;
static void  Start(ATMstateptr state)
{
   printf("Inside Start"); 
}
static void  InsertCard(ATMstateptr state)
{
    printf("Inside InsertCard");
}

static void  BadPin(ATMstateptr state)
{
    printf("Inside BadPin");
}

static void  PinOk(ATMstateptr state)
{
    printf("Inside PinOk");
}
static void  Deposit(ATMstateptr state)
{
    printf("Inside Deposit");
}
static void  Withdrawl(ATMstateptr state)
{
    printf("Inside Withdrawl");
}
static void  Account(ATMstateptr state)
{
    printf("Inside Account");
}
static void  Amount(ATMstateptr state)
{
    printf("Inside Amount");
}
static void  InsertEnvelope(ATMstateptr state)
{
    printf("Inside InsertEnvelope");
}
static void  WithdrawCard(ATMstateptr state)
{
    printf("Inside WithdrawCard");
}
static void  No(ATMstateptr state)
{
    printf("Inside No");
}
static void  Yes(ATMstateptr state)
{
    printf("Inside Yes");
}

static void  Stop(ATMstateptr state)
{
    printf("Inside Stop");
}


void transitionToSTATE_START(ATMstateptr state)
{
    defaultImplementation(state);
    state->Start = Start;
    
}


void transitionToSTATE_A(ATMstateptr state)
{
    defaultImplementation(state);
    state->InsertCard = InsertCard;
    
}

void transitionToSTATE_B(ATMstateptr state)
{
    state->BadPin = BadPin;
    //change state with condition
}
void transitionToSTATE_C(ATMstateptr state)
{
    state->BadPin = BadPin;
   //change state with condition 
}

void transitionToSTATE_D(ATMstateptr state)
{
    state->BadPin = BadPin;
    //change state 
}
void transitionToSTATE_E(ATMstateptr state)
{
    state->BadPin = BadPin;
    //change state 
}
void transitionToSTATE_F(ATMstateptr state)
{
    state->BadPin = BadPin;
    //change state 
}
void transitionToSTATE_G(ATMstateptr state)
{
    state->BadPin = BadPin;
    //change state 
}
void transitionToSTATE_H(ATMstateptr state)
{
    state->BadPin = BadPin;
    //change state 
}
void transitionToSTATE_I(ATMstateptr state)
{
    state->BadPin = BadPin;
    //change state 
}
void transitionToSTATE_J(ATMstateptr state)
{
    state->BadPin = BadPin;
    //change state 
}

void transitionToSTATE_STOP(ATMstateptr state)
{
    defaultImplementation(state);
    state->Stop = Stop;
    
}


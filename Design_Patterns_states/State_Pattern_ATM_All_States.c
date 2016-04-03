#include "State_Pattern_ATM_All_States.h"
#include "State_Pattern_ATM_States.h"

#include <stdio.h>
static void  Start(ATMstateptr state)
{
   printf("Inside Start"); 
   printf("Inside Start Enter which state you want to go");
   int input_to_next_state;
   scanf("%d", &input_to_next_state);
   if(input_to_next_state == INSERT_CARD)
   {
       state->InsertCard(state);
       transitionToSTATE_A(state);
   }
   
}
static void  InsertCard(ATMstateptr state)
{
    printf("Inside InsertCard \n");

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
    state->Start = Start;
    state->BadPin = BadPin;
    state->InsertCard = InsertCard;
    state->Start(state);
    
}


void transitionToSTATE_A(ATMstateptr state)
{
    //defaultImplementation(state);
     state->BadPin = BadPin;
     state->PinOk = PinOk;
   int input_to_next_state;
   printf("Enter next state input event");
   scanf("%d", &input_to_next_state);
   if(input_to_next_state == PIN_OK)
   {
       state->PinOk(state);
       transitionToSTATE_B(state);
   }
   if(input_to_next_state == BAD_PIN)
   {
       state->BadPin(state);
       transitionToSTATE_START(state);
   }
}

void transitionToSTATE_B(ATMstateptr state)
{
    state->Withdrawl = Withdrawl;
    state->Deposit = Deposit;
   int input_to_next_state;
   printf("Enter next state input event");
   scanf("%d", &input_to_next_state);
    //change state with condition
   if(input_to_next_state == WITHDRAWL)
   {
       state->Withdrawl(state);
       transitionToSTATE_C(state);
   }
   if(input_to_next_state == DEPOSIT)
   {
       state->Deposit(state);
       transitionToSTATE_G(state);
   }
}
void transitionToSTATE_C(ATMstateptr state)
{
    state->Account = Account;
       int input_to_next_state;
   printf("Enter next state input event");
   scanf("%d", &input_to_next_state);
   if(input_to_next_state == ACCOUNT)
   {
       state->Account(state);
       transitionToSTATE_D(state);
   }
   //change state with condition 
}

void transitionToSTATE_D(ATMstateptr state)
{
    state->Amount = Amount;
    state->No = No;
   int input_to_next_state;
   printf("Enter next state input event");
   scanf("%d", &input_to_next_state);
    if(input_to_next_state == AMOUNT)
   {
       state->Amount(state);
       transitionToSTATE_E(state);
   }
   if(input_to_next_state == NO)
   {
       state->No(state);
       transitionToSTATE_D(state);
   }
    //change state 
}
void transitionToSTATE_E(ATMstateptr state)
{
    state->Yes = Yes;
   int input_to_next_state;
   printf("Enter next state input event");
   scanf("%d", &input_to_next_state);
    if(input_to_next_state == YES)
   {
       state->Yes(state);
       transitionToSTATE_F(state);
   }
    //change state 
}
void transitionToSTATE_F(ATMstateptr state)
{
    state->WithdrawCard = WithdrawCard;
   int input_to_next_state;
   printf("Enter next state input event");
   scanf("%d", &input_to_next_state);
   if(input_to_next_state == WITHDRAW_CARD)
   {
       state->WithdrawCard(state);
       transitionToSTATE_START(state);
   }
}
void transitionToSTATE_G(ATMstateptr state)
{
    state->Account = Account;
   int input_to_next_state;
   printf("Enter next state input event");
   scanf("%d", &input_to_next_state);
   if(input_to_next_state == ACCOUNT)
   {
       state->Account(state);
       transitionToSTATE_H(state);
   } 
}
void transitionToSTATE_H(ATMstateptr state)
{
    state->InsertEnvelope = InsertEnvelope;
   int input_to_next_state;
   printf("Enter next state input event");
   scanf("%d", &input_to_next_state);
   if(input_to_next_state == INSERT_ENVELOPE)
   {
       state->InsertEnvelope(state);
       transitionToSTATE_I(state);
   }
    //change state 
}
void transitionToSTATE_I(ATMstateptr state)
{
    state->WithdrawCard = WithdrawCard;
   int input_to_next_state;
   printf("Enter next state input event");
   scanf("%d", &input_to_next_state);
    if(input_to_next_state == WITHDRAW_CARD)
   {
       state->WithdrawCard(state);
       transitionToSTATE_START(state);
   }
    //change state 
}
void transitionToSTATE_J(ATMstateptr state)
{
    state->BadPin = BadPin;
    //change state 
}
//just implemented in case of each set having to 
void transitionToSTATE_STOP(ATMstateptr state)
{
    defaultImplementation(state);
    state->Stop = Stop;
    
}


#ifndef HEADER_STATE_PATTERN_ATM_H
#define HEADER_STATE_PATTERN_ATM_H

typedef enum
{
 INSERT_CARD,
 PIN_OK,
 DEPOSIT,
 WITHDRAWL,
 ACCOUNT,
 AMOUNT,
 INSERT_ENVELOPE,
 WITHDRAW_CARD,
 BAD_PIN,
 NO,
 YES
}atmEvents;

typedef enum
{
    STATE_A,
    STATE_B,
    STATE_C,
    STATE_D,
    STATE_E,
    STATE_F,
    STATE_G,
    STATE_H,
    STATE_I,
    STATE_J
}atmStates;

#endif
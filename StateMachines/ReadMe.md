#### State Machines in C 

A state machine makes the event handling explicitly dependent on both the nature of the event and on the context (state) of the system.

The following are the problems with generic implementation of state with switch statements

------

Convoluted buggy code, hard to maintain and has static states which do not capture all the events which are reactive.

Array Based technique which captures the event and the state in a static array

------

Memory Consumption high and not scalable but easy to maintain for smaller number of states. As shown n example stateMachineArray.c

But in order to write such state machines which take care of events and
state of the system we require, at a minimum, an execution context (thread) and an event-dispatching mechanism.
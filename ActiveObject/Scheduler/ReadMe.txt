This will be a co-operative scheduler

The scenario is as follows
Timer fires at a certain interval (tasks should be completed by / before that interval).
Assumption is that after each interval, the scheduler takes charge and gives the control
to the next layer.
L1, L2 , L3
Each has an execution interval of 500ms,
L3 will have prioritry 0 and will decrease as it will reach L1.

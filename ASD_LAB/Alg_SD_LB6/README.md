Description
====
 - Fifo files contain the implementation of a queue in which the "head" is the first element of the queue, and the "tail" is the last element
 - Files with the name Stack - contain the implementation of the stack in which the top of the stack is the first element of the OLS.
 - Files with the name Task: contain the structure in which the task is stored, and the function for generating it. 
>  The task is as follows. The system can receive requests to perform tasks of three types — T1, T2, T3. A task of type T1 can only be performed by a processor P1. 
A task of type T2 can only be performed by a processor P2. 
A task of type T3 can be performed by any processor. 
The request can be represented by a record Incoming requests are put in the corresponding types of tasks of the description. 
If queue F1 is not empty and processor P1 is free, then the task from queue F1 goes to processor P1 for processing. 
If processor P1 processes a task of type T3, and processor P2 is free and queue F2 is empty, then the task from processor P1 goes to processor P2, 
and the task from queue F1 goes to processor P1, if processor P2 is busy or queue F2 is not empty, then the task from processor P1 is placed on the stack.
If queue F2 is not empty and processor P2 is free, then the task from queue F2 goes to processor P2 for processing. If the P2 processor processes a task of type T3,
and the P1 processor is free and the F1 queue is empty, then the task from the P2 processor goes to the P1 processor, 
and the task from the F2 queue goes to the P2 processor, if the P1 processor is busy or the F1 queue is not empty, 
then the task from the P1 processor is placed on the stack.
If queue F3 is not empty and processor P1 is free and queue F1 is empty or processor P2 is free and queue F2 is empty, 
then the task from queue F3 goes to the free processor for processing. 
The task from the stack goes to the free processor P1 for processing if the queue F1 is empty, 
or to the free processor P2 if the queue F2 is empty.

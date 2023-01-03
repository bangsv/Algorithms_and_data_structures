# Algorithms_and_data_structures

- Alg_SD_LB_8/Alg_LB_8

  Implementation of a table on a binary tree + implementation of the task.
    Task:
Write an interpreter of the arithmetic computing language. The language contains commands for entering and outputting values of real variables, a command for transferring a constant or variable value to another variable, arithmetic commands for addition, subtraction, multiplication and division. The input (IN) and output (OUT) commands have one operand, the forwarding command (MOV) has two operands, the first of which is the name of the variable to which the second operand is forwarded, arithmetic commands (ADD, SUB, MUL, DIV) have two operands, the result is stored in the first. There is one command in each line of the program. Commands and operands are separated by spaces. The program text is in a text file. The values of variables are stored in a table. The key of the table element is the name of the variable, the information part is the value of the variable. If the operand of the input command or the first operand of arithmetic commands and the forwarding command is not in the table, then determine its value and enter it in the table. If the output command operand or the second operand of arithmetic commands and the forwarding command are not in the table, then an error message is displayed.
Example of the program text in the language of arithmetic calculations:
IN a
IN b
IN c
MOV d a
MUL d b
DIV c a
SUB b c
MUL b 3.7
ADD d b
OUT d

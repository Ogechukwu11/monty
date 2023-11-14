Monty ByteCode Interpreter
Authors
Adedayo Adeniji
Ogechukwu Kanu
Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

General
Understand the concepts of LIFO and FIFO
Recognize the use cases for stacks and queues
Implement common implementations of stacks and queues
Identify the most common use cases for stacks and queues
Properly use global variables
Understand and implement the Betty style
Utilize the C standard library
Properly use header files and include guards
Implement an interpreter for Monty ByteCodes
Requirements
Allowed editors: vi, vim, emacs
All files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=c89
All files should end with a new line
A README.md file at the root of the folder is mandatory
Code should use the Betty style (checked using betty-style.pl and betty-doc.pl)
Use a maximum of one global variable
No more than 5 functions per file
Allowed to use the C standard library
Prototypes of all functions should be included in the header file called monty.h
Push the header file
Include guards should be used in all header files
Do the tasks in the order shown in the project description
Only one project repository per group
Data Structures
Use the following data structures for this project:

c
Copy code
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
Compilation & Output
Code will be compiled using the following command:

bash
Copy code
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
Any output must be printed on stdout, and any error messages must be printed on stderr.

Tests
Collaborate on a set of tests to ensure the correctness of your code.

The Monty Language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes. It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

Monty Byte Code Files
Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard, but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument.

Example:

monty
Copy code
push 0
push 1
push 2
  push 3
pall
push 4
  push 5
    push 6
pall
Monty byte code files can contain blank lines (empty or made of spaces only), and any additional text after the opcode or its required argument is not taken into account.

Example:

monty
Copy code
push 0 Push 0 onto the stack
push 1 Push 1 onto the stack

push 2
  push 3
pall
The Monty Program
Usage
bash
Copy code
$ monty file
file is the path to the file containing Monty byte code.
Error Handling
If no file is provided or more than one argument is given, print the error message USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE.
If it's not possible to open the file, print the error message Error: Can't open file <file>, followed by a new line, and exit with the status EXIT_FAILURE.
If the file contains an invalid instruction, print the error message L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE, where <line_number> is the line number where the instruction appears.
If malloc fails, print the error message Error: malloc failed, followed by a new line, and exit with status EXIT_FAILURE.
Guidelines
You have to use malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …).
Implement the tasks in the specified order.

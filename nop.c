/* nop.c */
#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number where the opcode appears.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* Do nothing */
}
#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		stack_t *last = *stack;
		stack_t *secondLast = NULL;

		while (last->next != NULL)
		{
			secondLast = last;
			last = last->next;
		}

		secondLast->next = NULL;
		last->prev = NULL;

		last->next = *stack;
		(*stack)->prev = last;

		*stack = last;
	}
}


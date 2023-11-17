#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		stack_t *first = *stack;
		stack_t *second = (*stack)->next;

		while (second->next != NULL)
		{
			first = first->next;
			second = second->next;
		}

		first->next = NULL;
		second->prev = NULL;

		second->next = *stack;
		(*stack)->prev = second;

		*stack = second;
	}
}

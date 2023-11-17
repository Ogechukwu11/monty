#include "monty.h"

/**
 * stack - Sets the format of the data to a stack (LIFO).
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * queue - Sets the format of the data to a queue (FIFO).
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */
void queue(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *temp;

	(void)line_number;

	while (current != NULL && current->next != NULL)
	{
		temp = current->next;
		current->next = temp->next;
		if (temp->next != NULL)
			temp->next->prev = current;

		temp->prev = NULL;
		temp->next = *stack;

		(*stack)->prev = temp;
		*stack = temp;
	}
}


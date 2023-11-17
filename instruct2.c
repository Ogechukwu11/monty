#include "monty.h"

/**
 * swap - To two element of the stack.
 * @top: A pointer to the pointer of the head.
 * @line_number: Keeps track of the lines in the list.
 * Return: void
 */
void swap(stack_t **top, unsigned int line_number)
{
	stack_t *element1, *element2;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	element1 = *top;
	element2 = (*top)->next;

	element1->prev = element2;
	element1->next = element2->next;

	if (element2->next != NULL)
	{
		element2->next->prev = element1;
	}
	element2->prev = NULL;
	element2->next = element1;

	*top = element2;
}
/**
 * add - Add the top two elements of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number where the opcode appears.
 */
void add(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;
    pop(stack, line_number);
}


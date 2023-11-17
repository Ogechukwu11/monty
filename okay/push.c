#include <ctype.h>
#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * push - Pushes an element to the stack.
 * @stack: A pointer to the top of the stack.
 * @arg: The argument passed to the push opcode.
 * @line_number: The current line number in the Monty bytecode file.
 *
 * Description: If @arg is not an integer or if there is no argument given to
 * push, it prints the error message "L<line_number>: usage: push integer",
 * followed by a new line, and exits with the status EXIT_FAILURE.
 * It uses the atoi function to convert the string argument to an integer.
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n;
	char *arg = get_global_argument(2);
	stack_t *new_node = malloc(sizeof(stack_t));

	if (arg == NULL || !is_number(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = atoi(arg);

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
/**
 * is_number - Checks if a string is a valid integer.
 * @str: The string to be checked.
 *
 * Return: 1 if @str is a valid integer, 0 otherwise.
 */
int is_number(char *str)
{
	int i = 0;

	if (str == NULL)
		return 0;

	while (str[i] != '\0')
	{
		if (str[i] == '-' && i == 0)
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return 0;
		i++;
	}

	return 1;
}

/**
 * pall - Prints all the values on the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 *
 * Description: If the stack is empty, it does not print anything.
 * Otherwise, it prints all the values on the stack, starting from the top.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

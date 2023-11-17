#include "monty.h"

const instruction_t cmd[] = {
	{"push", push},
	{"pall", pall},
	{"pop", pop},
	{"swap", swap},
	{"pint", pint},
	{"add", add},
	{"nop", nop},
	{"sub", sub},
	{"div", div_op},
	{"mul", mul_op},
	{"mod", mod_op},
	{NULL, NULL}
};

/**
 * freeTop - To free the allocated memory
 * @top: Pointer to the first element
 * Return: void
 */
void freeTop(stack_t *top)
{
	stack_t *temporal;

	while (top != NULL)
	{
		temporal = top;
		top = top->next;
		free(temporal);
	}
}

/**
 * find_opcode - To find the instructions
 * @instruct: The instructions
 * Return: -1 on failure
 */
int find_opcode(const char *instruct)
{
	int c = 0;

	while (cmd[c].opcode != NULL)
	{
		if (strcmp(instruct, cmd[c].opcode) == 0)
			return (c);
		c++;
	}
	return (-1);
}

/**
 * inPro - To process the instructions
 * @top: A pointer that points to the head pointer
 * @instruct: The instructions
 * @line: Keeps track of the lines in the list.
 * Return: void
 */
void inPro(stack_t **top, const char *instruct, unsigned int line)
{
	int index;

	index = find_opcode(instruct);
	if (index != -1)
		cmd[index].f(top, line);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, instruct);
		freeTop(*top);
		exit(EXIT_FAILURE);
	}
}

/**
 * main - Entry point
 * @ac: Number of argument
 * @av: Array containing the argument
 * Return: 0
 */
int main(int ac, char **av)
{
	stack_t *head = NULL;
	char *opcode, *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	FILE *file;

	if (ac != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", av[0]);
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	do {
		line_number++;
		read = getline(&line, &len, file);
		if (read != -1)
		{
			opcode = strtok(line, " \t\n");
			if (opcode != NULL)
				inPro(&head, opcode, line_number);
		}
	} while (read != -1);
	free(line);
	fclose(file);
	freeTop(head);
	return (0);
}

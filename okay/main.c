#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * main - Entry point for Monty ByteCode Interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, len, file) != NULL)
	{
		line_number++;
		parse_line_and_execute_opcode(&stack, instructions, line, line_number);
	}

	fclose(file);
	free(line);
	free_stack(&stack);
	return EXIT_SUCCESS;
}

/**
 * parse_line_and_execute_opcode - Parse a line and execute the corresponding opcode.
 * @stack: Pointer to the stack.
 * @line: Line to parse.
 * @line_number: Line number.
 */
void parse_line_and_execute_opcode(stack_t **stack, instruction_t *instructions, char *line, unsigned int line_number)
{
	char *opcode;

	opcode = strtok(line, " \t\n");

	execute_opcode(stack, instructions, opcode, line_number);
}
/**
 * execute_opcode - Execute the corresponding opcode.
 * @stack: Pointer to the stack.
 * @opcode: Opcode to execute.
 * @line_number: Line number.
 */
void execute_opcode(stack_t **stack, instruction_t *instructions, char *opcode, unsigned int line_number)
{
	int i = 0;

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}


#include "monty.h"

char **global_argv;

/**
 * get_global_argument - Get the argument at the specified index from global_argv.
 * @index: The index of the argument to retrieve.
 * 
 * Return: The argument at the specified index.
 */
char *get_global_argument(int index)
{
    if (index < 0 || global_argv[index] == NULL) {
        fprintf(stderr, "Error: Invalid argument index\n");
        exit(EXIT_FAILURE);
    }

    return global_argv[index];
}

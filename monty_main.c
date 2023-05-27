#include "monty.h"

doit free_mem;

/**
 * main - function that opens amonty script file parsing.
 * ac: argument count
 * av: array arguments.
 *
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE on failure.
 */
int main(int ac, char **av)
{
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	size_t length = 0;
	ssize_t size_line;
	char *namefile;
	namefile = av[1];

	free_mem.stream = fopen(namefile, "r");
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (!free_mem.stream)
	{
		fprintf(stderr, "Error, Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	size_line = getline(&free_mem.line, &length, free_mem.stream);

	while (size_line >= 0)
	{
		line_number++;
		opcode_select(&stack,line_number);
		size_line = getline(&free_mem.line, &length, free_mem.stream);
	}

	free(free_mem.line);
	free_stack(&stack);
	fclose(free_mem.stream);

	return (EXIT_SUCCESS);
}

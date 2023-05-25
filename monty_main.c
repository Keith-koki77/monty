#include "monty.h"

/**
 * main - function that opens amonty script file parsing.
 * ac: argument count
 * av: array arguments.
 *
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE on failure.
 */
int main(int ac, char **av)
{
	FILE *stream = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	stream = fopen(av[1], "r");
	fclose(stream);

	return (EXIT_SUCCESS);
}

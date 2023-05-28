#include "monty.h"

/**
 * monty_in - initialises the global variable
 * called monty
 */

void monty_in(void)
{
	monty.arg = NULL;
	monty.line = 0;
	monty.stack = NULL;
}

/**
 * args_check - opens the bytecode file
 * @ac: argument count
 * @av: argument vector
 * Return: file pointer to the corresponding bytecode
 */

FILE *args_check(int ac, char **av)
{
	FILE *STREAM;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	STREAM = fopen(av[1], "r");
	if (!STREAM)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	return (STREAM);
}

/**
 * is_digit - checks if string is a number
 * @str: pointer to the string
 * Return: 1 if string is a num, otherwise -1
*/

int is_digit(char *str)
{
	int x = 0;

	while (str[x])
	{
		if (!(isdigit(str[x])))
			return (-1);
		x++;
	}
	return (1);
}

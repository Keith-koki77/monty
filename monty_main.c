#include "monty.h"

/**
 * main - function that opens amonty script file parsing.
 *@ac: argument count
 *@av: array arguments.
 *
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE on failure.
 */

int main(int ac, char **av)
{
	FILE *STREAM;
	char *lnptr = NULL;
	char *opcode;
	const char DELIM[4] = " \t\n$";
	size_t x = 0;
	ssize_t flags;
	void (*funx)(stack_t **, unsigned int);

	STREAM = args_check(ac, av);

	while ((flags = getline(&lnptr, &x, STREAM) != -1))
	{
		monty.line++;
		opcode = strtok(lnptr, DELIM);
		if (opcode)
		{
			funx = opcode_select(opcode);

			if (!funx)
			{
				dprintf(2, "L%d: unknown instruction %s\n", monty.line, opcode);
				exit(EXIT_FAILURE);
			}

			monty.arg = strtok(NULL, DELIM);
			funx(&monty.stack, monty.line);
		}
	}

	free(lnptr);
	fclose(STREAM);
	return (0);
}

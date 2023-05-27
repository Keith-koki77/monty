#include "monty.h"

/**
 * opcode_select - selects opcodes
 * @stack: stack
 * @line_number: number of lines in file
 * Return: nothing
 */

void opcode_select(stack_t **stack, unsigned int line_number)
{
	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", divd},
		{"mul", mul},
		{"nop", nop},
		{NULL, NULL}};

	int tgt = 0;
	int x = 0;
	char *tkn = strdup(free_mem.line);
	char *newline = strchr(tkn, '\n');

	while (isspace(*tkn))
		tkn++;

	if (newline != NULL)
		*newline = '\0';

	if (tkn == NULL)
	{
		free(free_mem.temp);
		return;
	}
	free_mem.temp = tkn;

	if (tkn[0] != '\0' && tkn[0] == '#')
	{
		free(free_mem.temp);
		return;
	}

	while (op[x].opcode != NULL)
	{
	if (strcasecmp(tkn, op[x].opcode) == 0)
	{
		tgt = 1;
		(op[x].f)(stack, line_number);
		break;
	}
		x++;
	}

	if (tgt == 0)
	{
		fprintf(stderr, "L%u: unkown instructions %s\n", line_number, tkn);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	free(free_mem.temp);
}



#include "monty.h"

/**
 * opcode_select - gets the corresponding func of opcode
 * @opcode: The opcode
 * Return: NULL if function is not found in bytecode file
*/

void (*opcode_select(char *opcode))(stack_t **, unsigned int)
{
	int x = 0;

	instruction_t op_list[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"nop", nop}, {"add", add},
		{"swap", swap}, {"sub", sub}, {"div", divd},
		{"mul", mul}, {"pchar", pchar}, {"pstr", pstr},
		{"rotl", rotl}, {"rotr", rotr}, {"queue", addqu},
		{"stack", addst},
		{NULL, NULL},
	};

	while (op_list[x].opcode)
	{
		if (strcmp(opcode, op_list[x].opcode) == 0)
			return (op_list[x].f);
		x++;
	}
	return (NULL);
}

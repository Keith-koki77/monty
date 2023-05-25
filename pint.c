#include "monty.h"

/**
 * pint - prints the element at the top of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of file
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
    {
		fprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
    }
	printf("%d\n", (*stack)->n);
}

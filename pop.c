#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack- double pointer to the top of the stack
 * @line_number- line number of file
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!(*stack))
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	if (!(*stack)->next)
		*stack = NULL;
	else
		*stack = (*stack)->next, (*stack)->prev = NULL;

	free(tmp);
}

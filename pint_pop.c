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

/**
 * pop - removes the top element of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number of file
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

/**
 * nop - a function code that does nothing at all.
 * @stack: pointer to the head node of stack.
 * @line_number: the linumber in file.
 * Return: void.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

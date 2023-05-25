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
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to head node of the stack
 * @line_number: line number of file
*/

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!(*stack) || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;

	if (tmp->next)
	{
		(*stack)->next = tmp->next;
		tmp->next->prev = *stack;
	}
	else
		(*stack)->next = NULL;
		(*stack)->prev = tmp;
		tmp->next = *stack;
		tmp->prev = NULL;
		*stack = tmp;
}

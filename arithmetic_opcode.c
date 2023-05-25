#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: double pointer to the head node of the stack
 * @line_number: the line number
 * Return: Nothing
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		return;
	}


	(*stack)->next->n += (*stack)->n;
	*stack = (*stack)->next;
	free(temp);
}


/**
 * sub - subtracts the top elements of the stack from the second
 * top element
 * @stack: double pointer to the head node of the stack
 * @line_number: the line number
 * Return: Nothing
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 * divd - divides the second top element of stack by the top element
 * @stack: double pointer to the head node of stack
 * @line_number: the line number
 * Return: Nothing
 */

void divd(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	if (!(*stack) || !(*stack)->next)
	{
	fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
	fprintf(stderr, "L%d: division by zero\n", line_number);
	exit(EXIT_FAILURE);
	}

	
	(*stack)->next->n /= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 * mul - multiplies the second top element of the stack with the
 * top element
 * @stack: double pointer to the head node of stack
 * @line_number: the line number
 * Return: Nothing
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!(*stack) || !(*stack)->next)
	{
	fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

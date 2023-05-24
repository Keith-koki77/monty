#include "monty.h"

/**
 * push - function that pusdhes an element to the top of the stack.
 * @stack: pointer to pointer to the head node of the stack.
 * @line_number: the line number.
 * Return: void.
 */

void push(stack_t **stack, int line_number)
{
	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error, malloc failed\n");

		while (stack != NULL)
		{
			stack_t *temp = *stack;
			*stack = (*stack)->next;
			free(temp);
		}
		exit(EXIT_FAILURE);
	}

	new_node->data = data;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}

/**
 * pall - function that prints the data of all nodes in the stack
 * @stack: pointer to pointer of the head of stack.
 * @line_number: the line number.
 * Return: void.
 */
void pall(stack_t **stack, int line_number)
{
	stack_t *temp = *stack;
	(void)nline;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

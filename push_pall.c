#include "monty.h"

/**
 * push - function that pusdhes an element to the top of the stack.
 * @stack: pointer to pointer to the head node of the stack.
 * @line_number: the line number.
 * Return: void.
 */

void push(stack_t **stack, unsigned int line_number)
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
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)nline;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * free_stack - function that frees the stack.
 * @stack: pointer to pointer to head of stack.
 * Return: void.
 */
void free_stack(stack_t **stack)
{
	if (stack == NULL || *stack == NULL)
		return;

	stack_t *current = *stack;
	stack_t *node = NULL;

	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}

	*stack = NULL;
}

/**
 * atoi_int -  function that converts a string into an integer
 * @n: instruction line number.
 * @check_0: checks if the string has integer value.
 * Return: integer value if success or 0 in failure.
 */
int atoi_int(int n, int check_0)
{
	int int_atoi = 0;

	if (token[1])
	{
		int atoi = atoi(token[1]);
	}
	if (!int_atoi && check_0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", n);
		flag = 1;
	}

	return (int_atoi);
}

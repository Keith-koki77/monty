#include "monty.h"

/**
 * push - function that pusdhes an element to the top of the stack.
 * @stack: pointer to pointer to the head node of the stack.
 * @line_number: the line number.
 * Return: void.
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *tok;
	stack_t *new_node = NULL;
	int no = 0;

	tok = strtok(free_mem.line, DELIMS);
	if (tok == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	tok = strtok(NULL, DELIMS);
	if (tok == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (tok[no] != '\0')
	{
		if ((tok[no] < '0' || tok[no] > '9') && tok[no] != '-')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		no++;
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(tok);
	new_node->prev = NULL;
	new_node->next = *stack;

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
	(void)line_number;

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
	stack_t *current = *stack;
	stack_t *next_node;

	if (stack == NULL || *stack == NULL)
		return;

	

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
int atoi_int(int n, int check_0, char **token)
{
	int int_atoi = 0;

	if (token[1])
	{
		int_atoi = atoi(token[1]);
	}
	if (!int_atoi && check_0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", n);
	}

	return (int_atoi);
}

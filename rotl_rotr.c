#include "monty.h"

/**
 * rotl - function that rotates the stack to the top
 * @stack: pointer to pointer to head of stack
 * @line_number: line number of the file
 * Return: void.
 */
void rotl(stack_t **stack, unsigned int line_number __attribute__((unused)))
{

	if (*stack && (*stack)->next)
	{
		stack_t *temp = *stack;

		while (temp->next)
			temp = temp->next;

		temp->next = *stack;
		(*stack)->prev = temp;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		temp->next = NULL;
	}
}

/**
 * rotr - function that rotates the stack to the bottom.
 * @stack: pointer to pointer to head of stack.
 * @line_number: line number of the file.
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{


	if (*stack && (*stack)->next)
	{
		stack_t *temp = *stack;

		while (temp->next)
			temp = temp->next;

		temp->next = *stack;
		(*stack)->prev = temp;
		temp->prev->next =  NULL;
		temp->prev = NULL;
		*stack = temp;
	}
}

/**
 * queue_push - function pushes queue instead of stack
 * @stack: pointer to pointer to head of stack.
 * @line_number: line number of file.
 * @arg: arguments
 * Return: void.
 */
void queue_push(stack_t **stack, unsigned int line_number, int arg)
{
	stack_t *new_node;
	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", line_number);
		exit(EXIT_FAILURE);
	}

	
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = arg;
	new_node->next = NULL;

	if (*stack)
	{
		stack_t *last = *stack;

		while (last->next)
			last = last->next;
		last->next = new_node;
		new_node->prev = last;
	}

	else
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
}


/**
 * addst - function that changes mode of push to stack
 * @stack: pointer to stack
 * @line_number: line number of the file.
 *
 * Return: Nothing.
 */
void addst(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}

/**
 * addqu - function that changes mode of push to queue
 * @stack: pointer to stack
 * @line_number: line number of the file.
 *
 * Return: Nothing.
 */
void addqu(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}

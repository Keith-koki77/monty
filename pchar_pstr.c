#include "monty.h"

/**
 * pchar - a function that prints character at the
 * top of the stack
 * @stack: pointer to pointer to head of the stack
 * @line_number: line number of the file.
 * Return: void.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	char c;
	int value;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	

	while (temp->prev != NULL)
	{
		temp = temp->prev;
	}

	value = temp->n;

	if (!isalpha(value))
	{
		fprintf(stderr, "L%d: can't pthar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	c = (char)value;

	printf("%c\n", c);
}

/**
 * pstr - a function that a string from ASCII starting from the top
 * @stack: pointer to pointer of the head node of stack
 * @line_number: line number of file.
 * Return: void.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	char *res = malloc(1024 *sizeof(char)); /*Assuming maximum length of string*/
	int index = 0;
	stack_t *temp = *stack;
	(void)line_number;

	while (temp != NULL && temp->n != 0 && isalpha(temp->n))
	{
		char c = (char)temp->n;

		printf("%c", c);
		res[index] = c;
		temp = temp->next;
		index++;
	}

	printf("\n");
	free(res);
}

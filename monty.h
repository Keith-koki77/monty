#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct monty_s - global variable for monty interpretr
 * @line: line number of byte code file
 * @arg: opcode argument
 * @stack: stack
*/

typedef struct monty_s
{
	unsigned int line;
	char *arg;
	stack_t *stack;
} monty_t;

extern monty_t monty;
monty_t monty;


/* functions.c */
FILE *args_check(int, char **);
void monty_in(void);
int is_digit(char *);

/* opcode_select.c */
void (*opcode_select(char *))(stack_t **, unsigned int);

/* opcode operations */
void push(stack_t **, unsigned int line_number);
void pall(stack_t **, unsigned int line_number);
void pint(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void nop(stack_t **stack, unsigned int line_number);
void swap(stack_t **, unsigned int);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divd(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number __attribute__((unused)));
void rotr(stack_t **stack, unsigned int line_number __attribute__((unused)));
void queue_push(stack_t **stack, unsigned int line_number, int arg);
void addst(stack_t **stack, unsigned int line_number);
void addqu(stack_t **stack, unsigned int line_number);

#endif

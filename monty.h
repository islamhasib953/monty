#ifndef MONTY_H
#define MONTY_H

#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct head_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */

typedef struct head_s
{
	char *arg;
	FILE *file;
	char *content;
	int check;
}  head_t;

extern head_t heads;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct shared_s - shared data acroos all files
 * @type: type of data structure 0: stack, 1: queue
 * @tokens: tokens
 * @tokens_len: length of tokens
 * @file: file
 * Description: shared data acroos all files
 */
typedef struct shared_s
{
	int type;
	char *tokens[BUFSIZ];
	unsigned int tokens_len;
	FILE *file;
	char *line;
} shared;

shared common;


/*Functions*/
void re_pop(stack_t **stack_head, unsigned int line_number);
void re_swap(stack_t **stack, unsigned int line_number);
void re_add(stack_t **stack_head, unsigned int line_number);
void re_nop(stack_t **stack, unsigned int line_number);
void re_sub(stack_t **stack_head, unsigned int line_number);
void re_div(stack_t **stack, unsigned int line_number);
void re_mul(stack_t **stack_head, unsigned int line_number);
void re_mod(stack_t **stack, unsigned int line_number);
void re_push(stack_t **head, unsigned int line_number);
void re_pall(stack_t **stack_head, unsigned int line_number);
void re_pint(stack_t **stack, unsigned int line_number);
void re_pchar(stack_t **stack_head, unsigned int line_number);
void execute_opcode(int line_number, stack_t **stack);
void rotl(stack_t **stack, unsigned int top);
void print_string(stack_t **stack_head, unsigned int line_number);

void re_rotr(stack_t **stack_head, unsigned int line_number);

/*Add Func*/
void add_node(stack_t **stack_head, int new_value);
void set_queue_mode(stack_t **stack_head, unsigned int line_number);
void add_queue(stack_t **stack_head, int new_value);
void set_stack_mode(stack_t **stack_head, unsigned int line_number);

/*Free Func*/
void free_stack(stack_t *head);
void free_all(stack_t **head, int exit_code);
#endif

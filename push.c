#include "monty.h"

/**
 * push - push integer to stack
 * @stack: stack
 * @line_number: line number
 * Return: NONE
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL, *last = *stack;

	if (common.tokens[1] == NULL || !is_number(common.tokens[1]))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		quit(stack, EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		quit(stack, EXIT_FAILURE);
	}

	new_node->n = atoi(common.tokens[1]);
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*stack == NULL)
	{
		*stack = new_node;
		return;
	}

	if (common.type == QUEUE)
	{
		while (last->next != NULL)
			last = last->next;

		new_node->prev = last;
		last->next = new_node;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}

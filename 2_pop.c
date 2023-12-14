#include "monty.h"
/**
 * pop - prints the top
 * @stack_head: stack head
 * @line_number: number of line
 * Return: no return
*/
void pop(stack_t **stack_head, unsigned int line_number)
{
	stack_t *top_node;

	if (*stack_head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_all(stack_head);
	}
	top_node = *stack_head;
	*stack_head = top_node->next;
	free(top_node);
}

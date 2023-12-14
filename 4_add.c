#include "monty.h"
/**
 * re_add - adds the top two elements of the stack.
 * @stack_head: stack head
 * @line_number: number of line
 * Return: no return
*/
void re_add(stack_t **stack_head, unsigned int line_number)
{
	stack_t *current_node;
	int addition, count = 0;

	current_node = *stack_head;
	while (current_node)
	{
		current_node = current_node->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_all(stack_head);
	}
	current_node = *stack_head;
	addition = current_node->n + current_node->next->n;
	current_node->next->n = addition;
	*stack_head = current_node->next;
	free(current_node);
}

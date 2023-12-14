#include "monty.h"
/**
 * handle_add - adds the top two elements of the stack.
 * @head: stack head
 * @cnt: number of line
 * Return: no return
*/
void add(stack_t **head, unsigned int cnt)
{
	stack_t *new_node;
	int add, ln = 0;

	new_node = *head;
	while (new_node)
	{
		new_node = new_node->next;
		ln++;
	}
	if (ln < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", cnt);
		free_all(head);
	}
	new_node = *head;
	add = new_node->n + new_node->next->n;
	new_node->next->n = add;
	*head = new_node->next;
	free(new_node);
}
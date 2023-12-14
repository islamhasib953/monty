#include "monty.h"
/**
 * handle_pop - prints the top
 * @head: stack head
 * @cnt: number of line
 * Return: no return
*/
void pop(stack_t **head, unsigned int cnt)
{
	stack_t *st;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", cnt);
		free_all(head);
	}
	st = *head;
	*head = st->next;
	free(st);
}
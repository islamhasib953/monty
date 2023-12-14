#include "monty.h"

/**
 * re_push - add node to the stack
 * @head: stack head
 * @line_number: line_number (unused)
 * Return: no return
*/

void re_push(stack_t **head, unsigned int line_number)
{
	int n, j = 0, flag = 0;

	if (heads.arg)
	{
		if (heads.arg[0] == '-')
			j++;
		for (; heads.arg[j] != '\0'; j++)
		{
			if (heads.arg[j] > 57 || heads.arg[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_all(head);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_all(head);
	}
	n = atoi(heads.arg);
	if (heads.check == 0)
		add_node(head, n);
	else
		add_queue(head, n);
}

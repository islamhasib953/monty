#include "monty.h"

/**
 * pall - print the content of stack
 * @stack: stack
 * @line_number: line number
 * Return: NONE
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *pointer = *stack;

	while (pointer != NULL)
	{
		printf("%d\n", pointer->n);
		pointer = pointer->next;
	}
}

#include "monty.h"

/**
 * re_pall - prints the stack
 * @stack_head: stack head
 * @line_number: line_number (unused)
 * Return: no return
 */
void re_pall(stack_t **stack_head, unsigned int line_number)
{
    stack_t *current_node;
    (void)line_number;

    current_node = *stack_head;
    if (current_node == NULL)
        return;

    while (current_node)
    {
        printf("%d\n", current_node->n);
        current_node = current_node->next;
    }
}

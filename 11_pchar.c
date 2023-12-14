#include "monty.h"

/**
 * re_pchar - prints the character at the top of the stack
 * @stack_head: stack head
 * @line_number: line_number
 * Return: no return
 */
void re_pchar(stack_t **stack_head, unsigned int line_number)
{
    stack_t *top_node = *stack_head;

    if (*stack_head == NULL)
    {
        fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
        free_all(stack_head);
    }

    if (top_node->n < 0 || top_node->n > 127)
    {
        fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
        free_all(stack_head);
    }

    printf("%c\n", top_node->n);
}

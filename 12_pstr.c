#include "monty.h"

/**
 * print_string - Prints the string starting at the top of the stack.
 * @stack_head: Pointer to the stack head.
 * @line_number: Line number.
 * Return: No return.
 */
void print_string(stack_t **stack_head, unsigned int line_number)
{
    stack_t *current_node = *stack_head;
    (void)line_number;  // Unused parameter

    while (current_node && current_node->n != 0 && isprint(current_node->n))
    {
        printf("%c", current_node->n);
        current_node = current_node->next;
    }

    printf("\n");
}

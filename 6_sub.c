#include "monty.h"

/**
 * sub - subtraction operation
 * @stack_head: Pointer to the stack head.
 * @line_number: Line number.
 * Return: no return
 */
void sub(stack_t **stack_head, unsigned int line_number)
{
    stack_t *current_node = *stack_head;
    int result, node_count = 0;

    // Count the number of nodes in the stack
    while (current_node != NULL)
    {
        node_count++;
        current_node = current_node->next;
    }

    // Check if there are at least two elements in the stack for subtraction
    if (node_count < 2)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        free_all(stack_head);
        return;
    }

    // Perform the subtraction operation
    current_node = *stack_head;
    result = current_node->next->n - current_node->n;
    current_node->next->n = result;
    *stack_head = current_node->next;

    // Free the node that was subtracted
    free(current_node);
}

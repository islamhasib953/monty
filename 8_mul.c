#include "monty.h"

/**
 * mul - multiplication operation
 * @stack_head: Pointer to the stack head.
 * @line_number: Line number.
 * Return: No return.
 */
void mul(stack_t **stack_head, unsigned int line_number)
{
    stack_t *current_node = *stack_head;
    int stack_size = 0, result;

    // Count the number of nodes in the stack
    while (current_node)
    {
        current_node = current_node->next;
        stack_size++;
    }

    // Check if there are at least two elements in the stack for multiplication
    if (stack_size < 2)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
        free_all(stack_head);
        return;
    }

    // Perform the multiplication operation
    current_node = *stack_head;
    result = current_node->next->n * current_node->n;
    current_node->next->n = result;
    *stack_head = current_node->next;

    // Free the node that was multiplied
    free(current_node);
}

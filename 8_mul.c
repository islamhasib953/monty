#include "monty.h"

/**
 * Multiplies the top two elements of the stack.
 * @param head: Pointer to the stack head.
 * @param counter: Line number.
 * Return: No return.
 */
void mul(stack_t **head, unsigned int counter)
{
    stack_t *current = *head;
    int stack_length = 0, result;

    // Count the number of nodes in the stack
    while (current)
    {
        current = current->next;
        stack_length++;
    }

    // Check if there are at least two elements in the stack for multiplication
    if (stack_length < 2)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
        free_all(head);
        return;
    }

    // Perform the multiplication operation
    current = *head;
    result = current->next->n * current->n;
    current->next->n = result;
    *head = current->next;

    // Free the node that was multiplied
    free(current);
}

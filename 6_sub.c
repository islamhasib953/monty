#include "monty.h"

/**
 * handle_sub- sustration
 * @param head: Pointer to the stack head.
 * @param cnt: Line number.
 * Return: no return
 */
void sub(stack_t **head, unsigned int cnt)
{
    stack_t *current = *head;
    int result, node_count = 0;

    // Count the number of nodes in the stack
    while (current != NULL)
    {
        node_count++;
        current = current->next;
    }

    // Check if there are at least two elements in the stack for subtraction
    if (node_count < 2)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", cnt);
        free_all(head);
        return;
    }

    // Perform the subtraction operation
    current = *head;
    result = current->next->n - current->n;
    current->next->n = result;
    *head = current->next;

    // Free the node that was subtracted
    free(current);
}

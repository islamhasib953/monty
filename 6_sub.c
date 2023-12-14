#include "monty.h"

/**
 * re_sub - subtraction operation
 * @stack_head: Pointer to the stack head.
 * @line_number: Line number.
 * Return: no return
 */
void re_sub(stack_t **stack_head, unsigned int line_number)
{
    stack_t *current_node = *stack_head;
    int result, node_count = 0;

    while (current_node != NULL)
    {
        node_count++;
        current_node = current_node->next;
    }

    if (node_count < 2)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        free_all(stack_head);
        return;
    }
    
    current_node = *stack_head;
    result = current_node->next->n - current_node->n;
    current_node->next->n = result;
    *stack_head = current_node->next;

    free(current_node);
}

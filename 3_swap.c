#include "monty.h"
/**
 * re_swap - swaps the top two elements of the stack.
 * @stack_head: stack head
 * @line_number: line_number
 * Return: no return
*/
void re_swap(stack_t **stack_head, unsigned int line_number)
{
    stack_t *current_node;
    int stack_length = 0, temp_value;

    current_node = *stack_head;

    while (current_node)
    {
        current_node = current_node->next;
        stack_length++;
    }

    if (stack_length < 2)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        free_all(stack_head);
    }

    current_node = *stack_head;
    temp_value = current_node->n;
    current_node->n = current_node->next->n;
    current_node->next->n = temp_value;
}

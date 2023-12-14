#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack_head: stack head
 * @line_number: line_number
 * Return: no return
 */
void rotr(stack_t **stack_head, unsigned int line_number)
{
    stack_t *current_node = *stack_head;

    (void)line_number;

    if (*stack_head == NULL || (*stack_head)->next == NULL)
        return;

    while (current_node->next != NULL)
    {
        current_node = current_node->next;
    }

    current_node->prev->next = NULL;
    current_node->prev = NULL;
    current_node->next = *stack_head;
    (*stack_head)->prev = current_node;
    *stack_head = current_node;
}

#include "monty.h"

<<<<<<< HEAD
/**
 * re_rotl - rotates the stack to the top.
 * @stack_head: stack head
 * @line_number: line_number
 * Return: no return
 */
void re_rotl(stack_t **stack_head, unsigned int line_number)
{
    stack_t *first, *second, *last_node;

    (void)line_number;

    if (*stack_head && (*stack_head)->next)
    {
        first = *stack_head;
        second = first->next;
        last_node = first;

        while (last_node->next)
        {
            last_node = last_node->next;
        }

        *stack_head = second;
        second->prev = NULL;

        first->next = NULL;
        first->prev = last_node;
        last_node->next = first;
=======
void rotl(stack_t **stack, unsigned int top) {
    if (top >= 1) {
        int temp = (*stack)[top].n;
	int i;
        for (i = 1; i <= top; ++i) {
            (*stack)[i].n = (*stack)[i - 1].n;
        }
        (*stack)[0].n = temp;
>>>>>>> b6d0fa68a6307e0dfeb81c73c3ca5a3947eff0f0
    }
}

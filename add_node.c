#include "monty.h"
/**
 * add_node - adds a node to the head of the stack
 * @stack_head: head of the stack
 * @new_value: new value to be added
 * Return: no return
 */
void add_node(stack_t **stack_head, int new_value)
{
    stack_t *new_node, *current_node;

    current_node = *stack_head;
    new_node = malloc(sizeof(stack_t));

    if (new_node == NULL)
    {
        fprintf(stderr, "Error: Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    if (current_node)
        current_node->prev = new_node;

    new_node->n = new_value;
    new_node->next = *stack_head;
    new_node->prev = NULL;

    *stack_head = new_node;
}

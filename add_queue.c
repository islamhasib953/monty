#include "monty.h"
/**
 * set_queue_mode - sets the queue mode
 * @stack_head: stack head
 * @line_number: line_number
 * Return: no return
 */
void add_queue(stack_t **stack_head, unsigned int line_number)
{
    (void)stack_head;
    (void)line_number;
    heads.check = 1;
}

/**
<<<<<<< HEAD
 * addQueue - adds a node to the tail of the stack
 * @new_value: new value
=======
 * add_queue - adds a node to the tail of the stack
>>>>>>> b6d0fa68a6307e0dfeb81c73c3ca5a3947eff0f0
 * @stack_head: head of the stack
 * @new_value: new value
 * Return: no return
 */
<<<<<<< HEAD
void addQueue(stack_t **stack_head, unsigned int line_number)
=======
void add_queue(stack_t **stack_head, int new_value)
>>>>>>> b6d0fa68a6307e0dfeb81c73c3ca5a3947eff0f0
{
    stack_t *new_node, *current_node;

    current_node = *stack_head;
    new_node = malloc(sizeof(stack_t));

    if (new_node == NULL)
    {
        fprintf(stderr, "Error: Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = line_number;
    new_node->next = NULL;

    if (current_node)
    {
        while (current_node->next)
            current_node = current_node->next;
    }

    if (!current_node)
    {
        *stack_head = new_node;
        new_node->prev = NULL;
    }
    else
    {
        current_node->next = new_node;
        new_node->prev = current_node;
    }
}

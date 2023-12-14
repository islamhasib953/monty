#include "monty.h"

/**
 * Prints the string starting at the top of the stack.
 * @param head: Pointer to the stack head.
 * @param cnt: Line number.
 * Return: No return.
 */
void pstr(stack_t **head, unsigned int cnt)
{
    stack_t *current = *head;
    (void)cnt;  // Unused parameter

    while (current && current->n != 0 && isprint(current->n))
    {
        printf("%c", current->n);
        current = current->next;
    }

    printf("\n");
}

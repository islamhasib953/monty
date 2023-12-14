#include "monty.h"

/**
* free_all - frees all.
* @head: head of the stack
*/

void free_all(stack_t **head, int exit_code)
{
	fclose(heads.file);
	free(heads.content);
	free_stack(*head);
	exit(exit_code);
}

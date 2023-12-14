#include "monty.h"


void pchar()
{
	int ascii_value = stack[top];
       	if (top == -1)
	{
		fprintf(stderr, "Error: can't pchar, stack empty\n");
		exit(EXIT_FAILURE);
	}

	if (ascii_value < 0 || ascii_value > 127)
	{
		fprintf(stderr, "Error: can't pchar, value out of range\n");
		exit(EXIT_FAILURE);
	}

	putchar((char)ascii_value);
	putchar('\n');
}

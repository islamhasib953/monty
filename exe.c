#include "monty.h"

/**
 * excute_command - excute the command
 * @line_number: line number
 * @stack: stack
 * Return: NONE
 */
void excute_opcode(int line_number, stack_t **stack)
{
	int i, ln;
	instruction_t opcodes[] = {
        {"push", re_push}, {"pall", re_pall},
        {"pint", re_pint},
        {"pop", re_pop},
        {"swap", re_swap},
        {"add", re_add},
        {"nop", re_nop},
        {"sub", re_sub},
        {"div", re_div},
        {"mul", re_mul},
        {"mod", re_mod}, {"rotr", re_rotr},
	{"queue", add_queue}, {"rotl", rotl},
        {"stack", add_stack}, {"pchar", re_pchar}, {"pstr", print_string},
        {NULL, NULL}
    };

	if (common.tokens_len == 0)
		return;

	for (i = 0; opcodes[i].opcode; i++)
	{
		if (strcmp(common.tokens[0], opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_number);
			return;
		}
	}

	ln = line_number;
	fprintf(stderr, "L%d: unknown instruction %s\n", ln, common.tokens[0]);
	free_all(stack, EXIT_FAILURE);
}

#include "monty.h"

/**
<<<<<<< HEAD
 * exe - executes the opcode
 * @line_content: content of the current line
 * @stack_head: head of the linked list - stack
 * @line_number: line number in the Monty file
 * @monty_file: pointer to the Monty file
 * Return: no return
 */
int exe(char *line_content, stack_t **stack_head, unsigned int line_number, FILE *monty_file)
=======
 * excute_command - excute the command
 * @line_number: line number
 * @stack: stack
 * Return: NONE
 */
void excute_opcode(int line_number, stack_t **stack)
>>>>>>> b6d0fa68a6307e0dfeb81c73c3ca5a3947eff0f0
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
<<<<<<< HEAD
        {"queue", add_queue}, {"rotl", re_rotl},
        {"stack", add_stack}, {"pchar", re_pchar}, {"pstr", re_pstr},
=======
	{"queue", add_queue}, {"rotl", rotl},
        {"stack", add_stack}, {"pchar", re_pchar}, {"pstr", print_string},
>>>>>>> b6d0fa68a6307e0dfeb81c73c3ca5a3947eff0f0
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

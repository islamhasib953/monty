#include "monty.h"

/**
 * custom_execute_opcode - executes the opcode
 * @line_content: content of the current line
 * @stack_head: head of the linked list - stack
 * @line_number: line number in the Monty file
 * @monty_file: pointer to the Monty file
 * Return: no return
 */
int custom_execute_opcode(char *line_content, stack_t **stack_head, unsigned int line_number, FILE *monty_file)
{
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
     /*   {"queue", add_queue}, {"rotl", rotl},
        {"stack", add_stack}, {"pchar", handle_pchar}, {"pstr", custom_handle_pstr},*/
        {NULL, NULL}
    };
    unsigned int i = 0;
    char *opcode;

    opcode = strtok(line_content, " \n\t");
    if (opcode && opcode[0] == '#')
        return (0);
    
    heads.arg = strtok(NULL, " \n\t");

    while (opcodes[i].opcode && opcode)
    {
        if (strcmp(opcode, opcodes[i].opcode) == 0)
        {
            opcodes[i].f(stack_head, line_number);
            return (0);
        }
        i++;
    }

    if (opcode && opcodes[i].opcode == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
        fclose(monty_file);
        free(line_content);
        free_stack(*stack_head);
        exit(EXIT_FAILURE);
    }

    return (1);
}

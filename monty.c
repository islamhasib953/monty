#include "monty.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: arguments
 * Return: EXIT_SUCCESS on success.
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;

	/* initialize stack */
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	common.file = fopen(argv[1], "r");
	if (common.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&(common.line), &len, common.file) != -1)
	{
		line_number++;
		line = common.line;
		common.tokens[common.tokens_len] = strtok(line, " \n\t");
		while (common.tokens[common.tokens_len] != NULL)
		{
			if (common.tokens[common.tokens_len][0] == '#')
				break;

			common.tokens_len++;
			common.tokens[common.tokens_len] = strtok(NULL, " \n\t");
		}
		execute_opcode(line_number, &stack);
		common.tokens_len = 0;
	}
	free_all(&stack, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}


#include "monty.h"

/**
 * get_op_fn - Gets corresponding operator function.
 * @token1: 1st bytecode input.
 * Return: Pointer to the correct operation function.
 */
void (*get_op_fn(char *token1))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruction_s[] = {
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"pchar", pchar},
		{"pstr", pstr},
		{"nop", nop},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	int x;

	for (x = 0; instruction_s[x].op != NULL; x++)
	{
		if (strcmp(token1, instruction_s[x].op) == 0)
			return (instruction_s[x].f);
	}

	return (NULL);
}

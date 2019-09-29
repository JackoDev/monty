#include "monty.h"
/**
 * select_function - select function to work
 * @stack: pointer to head of the stack
 * @num_line: number of the ine to work
 * @opcode: opcode to review
 * Return: its a void fucntion
**/
void select_function(stack_t** stack, unsigned int num_line, char* opcode)
{
	int i = 0;
	instruction_t ops[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},	{"pop", pop}, 
		{"swap", swap}, {"add", add}, {"nop", nop}, {"sub", sub}, 
		{"div", divide}, {"mul", mul}, {"mod", mod}, {"pchar", pchar},
		{NULL, NULL}
		};

	while (ops[i].opcode != NULL)
	{
		if (_strcmp(opcode, ops[i].opcode) == 0)
		{
			ops[i].f(stack, num_line);
			return;
		}
		i++;
	}

	printf("L%u: unknown instruction %s\n", num_line, opcode);
	exit(EXIT_FAILURE);
}

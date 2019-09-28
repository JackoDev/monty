#include "monty.h"

/**
 * free_all - free the all stacks
 * @stack: pointer to head of the stack
 * Return: its a void function
 */
void free_all(stack_t *stack)
{
	stack_t *tempo;

	if (stack == NULL)
		return;
	tempo = stack->next;
	while (tempo != NULL)
	{
		free(stack);
		stack = tempo;
		tempo = tempo->next;
	}
	free(stack);
}

#include "monty.h"
/**
 * *push - push a val to the stack
 *@stack: pointer to head of the stack
 *@num_line: number of line to work
 *Return: its a void function
*/
void push(stack_t** stack, unsigned int num_line)
{
	stack_t* new;
	char* str;
	int i = 0, j = 0;

	str = malloc(sizeof(char) * 12);
	if (str == NULL)
		return;
	while (ex_line[i] < '0' || ex_line[i] > '9')
	{
		if (ex_line[i] == '\0')
		{
			printf("L%u: usage: push integer\n", num_line);
			free_all(*stack);
			exit(EXIT_FAILURE);
		}
		if (ex_line[i] == '-')
		{
			str[j] = ex_line[i];
			j++;
		}
		i++;
	}
	while (ex_line[i] != ' ' && ex_line[i] != '\0'
		&& ex_line[i] >= '0' && ex_line[i] <= '9')
	{
		str[j] = ex_line[i];
		i++;
		j++;
	}
	if (ex_line[i] != ' ' && ex_line[i] != '\0')
	{
		printf("L%u: usage: push integer\n", num_line);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	str[j] = '\0';
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	new->n = atoi(str);
	new->prev = NULL;
	if (*stack == NULL)
		new->next = NULL;
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	*stack = new;
	free(str);
}

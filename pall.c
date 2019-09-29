/**
 * pall - prints all the stack
 * @stack: pointer to head of the stack
 * @num_line: number of the line to work
 * Return: void
 */
void pall(stack_t** stack, unsigned int num_line)
{
	stack_t* new;

	(void)num_line;
	new = *stack;
	if (*stack == NULL)
		return;
	while (new != NULL)
	{
		printf("%d\n", new->n);
		new = new->next;
	}
}

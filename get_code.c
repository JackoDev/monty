#include "monty.h"
/**
 * get_code - atore the opcode in a buffer
 * Return: pointer to the string
**/
char *get_code(void)
{
	int i = 0, j = 0;
	char *opcodebuffer;

	opcodebuffer = malloc(sizeof(char) * 10);
	if (opcodebuffer == NULL)
		return (NULL);

	while (line[i] == ' ')
		i++;
	while (line[i] != ' ' && line[i] != '\0')
	{
		opcodebuffer[j] = line[i];
		i++;
		j++;
	}
	opcodebuffer[j] = '\0';
	return (opcodebuffer);
}

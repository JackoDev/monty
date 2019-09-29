#include "monty.h"
char* ex_line;
/**
 * main - main function or entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0
*/
int main(int argc, char** argv)
{
	size_t size;
	ssize_t readed = 0;
	FILE* archivo;
	stack_t* stack = NULL;
	int c1 = 0, c2 = 0;
	unsigned int num_line = 0;
	char* op_code;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	archivo = fopen(argv[1], "r");
	if (archivo == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (readed != -1)
	{
		ex_line = NULL;
		size = 0;
		c1 = 0;
		c2 = 0;
		readed = getline(&ex_line, &size, archivo);
		num_line++;
		while (ex_line[c2] == ' ')
			c2++;
		if (ex_line[c2] == '\n' || ex_line[c2] == '#')
			continue;
		while (ex_line[c1] != '\n' && ex_line[c1] != '\0')
			c1++;
		ex_line[c1] = '\0';
		if (ex_line[0] == '\0')
			break;
		op_code = getopcode();
		opcodecompare(&stack, num_line, op_code);
		free(op_code);
		free(ex_line);
	}
	fclose(archivo);
	free(ex_line);
	free_all(stack);
	return (0);
}

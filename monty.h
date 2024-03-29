#ifndef _MONTY_H_
#define _MONTY_H_
/*LIBRARIES*/
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
/* STRUCTURES FOR THE PROJECT */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s* prev;
	struct stack_s* next;
} stack_t;
/**
* struct instruction_s - opcoode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO Holberton project
*/
typedef struct instruction_s
{
	char* opcode;
	void (*f)(stack_t** stack, unsigned int line_number);
} instruction_t;
/*GLOBAL VARIABLES*/
extern char* ex_line;
/*FUNCTION PROTOTYPES*/
void push(stack_t** stack, unsigned int num_line);
void pall(stack_t** stack, unsigned int num_line);
void free_all(stack_t* stack);
char *get_code(void);
void select_function(stack_t** stack, unsigned int num_line, char* opcode);
int _strcmp(char *s1, char *s2);

#endif

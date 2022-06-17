#include "monty.h"
#include <ctype.h>


static int check_for_digit(char *arg)
{
	int i;

	for (i = 0; arg[i]; i++)
	{
		if (arg[i] == '-' && i == 0)
			continue;
		if (isdigit(arg[i]) == 0)
			return (1);
	}
	return (0);
}


void m_push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int a;

	arg = strtok(NULL, "\n\t\r ");
	if (arg == NULL || check_for_digit(arg))
	{
		dprintf(STDOUT_FILENO,
			"L%u: usage: push integer\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	a = atoi(arg);
	if (!add_node(stack, a))
	{
		dprintf(STDOUT_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	var.stack_len++;
}

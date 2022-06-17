#include "monty.h"

void m_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	(void)(line_number);

	head = *stack;
	while (head != NULL)
	{
		printf("%d\n", head->a);
		head = head->next;
		if (head == *stack)
		{
			return;
		}
	}
}

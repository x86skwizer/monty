#include "monty.h"

/**
 * ft_push - push instruction
 * @stack: stack
 * @line_number: line
 */
void ft_push(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	int n;

	if (!op[1] || !op[1][0])
	{
		free_dlistint(*stack);
		err_msg("L%u: usage: push integer", line_number);
	}
	if (op[1][i] == '-')
		i++;
	while (op[1][i])
	{
		if (op[1][i] < '0' || op[1][i] > '9')
		{
			free_dlistint(*stack);
			err_msg("L%u: usage: push integer", line_number);
		}
		i++;
	}
	n = atoi(op[1]);
	add_dnodeint(stack, n);
}

/**
 * ft_pall - pall instruction
 * @stack: stack
 * @line_number: line
 */
void ft_pall(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	if (!stack || !*stack)
		return;
	print_dlistint(*stack);
}

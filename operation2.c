#include "monty.h"

/**
 * ft_add - adds top 2 elements of stack
 * @stack: stack
 * @line_number: line
 */
void ft_add(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
		err_msg("L%u: can't add, stack too short\n", line_number);
	(*stack)->next->n += (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
}

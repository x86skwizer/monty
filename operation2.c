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

/**
 * ft_sub - subs top 2 elements of stack
 * @stack: stack
 * @line_number: line
 */
void ft_sub(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
		err_msg("L%u: can't sub, stack too short\n", line_number);
	(*stack)->next->n -= (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
}

/**
 * ft_div - div top 2 elements of stack
 * @stack: stack
 * @line_number: line
 */
void ft_div(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
		err_msg("L%u: can't div, stack too short\n", line_number);
	if (!(*stack)->n)
		err_msg("L%u: division by zero\n", line_number);
	(*stack)->next->n /= (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
}

/**
 * ft_mul - mul top 2 elements of stack
 * @stack: stack
 * @line_number: line
 */
void ft_mul(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
		err_msg("L%u: can't mul, stack too short\n", line_number);
	(*stack)->next->n *= (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
}

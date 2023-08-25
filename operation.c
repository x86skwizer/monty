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

	if (!glb.op[1] || !glb.op[1][0])
	{
		free_dlistint(*stack);
		err_msg("L%u: usage: push integer\n", line_number);
	}
	if (glb.op[1][i] == '-' || glb.op[1][i] == '+')
		i++;
	while (glb.op[1][i])
	{
		if (glb.op[1][i] < '0' || glb.op[1][i] > '9')
		{
			free_dlistint(*stack);
			err_msg("L%u: usage: push integer\n", line_number);
		}
		i++;
	}
	n = atoi(glb.op[1]);
	if (glb.mode == 1)
		add_dnodeint(stack, n);
	else
		add_dnodeint_end(stack, n);

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

/**
 * ft_pint - print stack's top value
 * @stack: stack
 * @line_number: line
 */
void ft_pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
		err_msg("L%u: can't pint, stack empty\n", line_number);
	printf("%d\n", (*stack)->n);
}

/**
 * ft_pop - remove stack's top
 * @stack: stack
 * @line_number: line
 */
void ft_pop(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
		err_msg("L%u: can't pglb.op an empty stack\n", line_number);
	delete_dnodeint_at_index(stack, 0);
}

/**
 * ft_swap - swap stack's top 2 elements
 * @stack: stack
 * @line_number: line
 */
void ft_swap(stack_t **stack, unsigned int line_number)
{
	int n;

	if (!stack || !*stack || !(*stack)->next)
		err_msg("L%u: can't swap, stack too short\n", line_number);
	n = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = n;
}

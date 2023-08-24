#include "monty.h"

/**
 * ft_pchar - print stack's top value
 * @stack: stack
 * @line_number: line
 */
void ft_pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
		err_msg("L%u: can't pchar, stack empty\n", line_number);
	if ((*stack)->n < 0 || (*stack)->n > 127)
		err_msg("L%u: can't pchar, value out of range\n", line_number);
	printf("%c\n", (char)(*stack)->n);
}

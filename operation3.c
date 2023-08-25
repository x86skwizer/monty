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

/**
 * ft_pstr - print string from top
 * @stack: stack
 * @line_number: line
 */
void ft_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;
	for ( ; tmp && tmp->n > 0 && tmp->n < 128; tmp = tmp->next)
		printf("%c", (char)tmp->n);
	printf("\n");
}

/**
 * ft_rotl - rotates the stack
 * @stack: stack
 * @line_number: line
 */
void ft_rotl(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (!stack || !*stack || !(*stack)->next)
		return;
	add_dnodeint_end(stack, (*stack)->n);
	delete_dnodeint_at_index(stack, 0);
}

/**
 * ft_rotr - reverse rotate stack
 * @stack: stack
 * @line_number: line
 */
void ft_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	stack_t *tail;

	(void)line_number;
	if (!stack || !*stack || !(*stack)->next)
		return;
	tmp = *stack;
	while (tmp->next)
	{
		tail = tmp;
		tmp = tmp->next;
	}
	tail->next = NULL;
	add_dnodeint(stack, tmp->n);
	free(tmp);
}

/**
 * print_msg - print msg and exit
 * @av: string
 */
void print_msg(char *av)
{
	fprintf(stderr, "Error: Can't glb.open file %s\n", av);
	exit(EXIT_FAILURE);
}

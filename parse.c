#include "monty.h"
#include <stdio.h>

/**
 * err_msg - print err msg
 * @msg: string
 * @l: line
 */
void err_msg(const char *msg, unsigned int l)
{
	fprintf(stderr, msg, l);
	exit(EXIT_FAILURE);
}

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

/**
 * unknow_ins - handle unknow instruction
 * @stack: stack
 * @buf: buffer
 * @l: line num
 */
void unknow_ins(stack_t **stack, char *buf, unsigned int l)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", l, op[0]);
	free(buf);
	free_dlistint(*stack);
	exit(EXIT_FAILURE);
}

/**
 * check_instruc - check instruction
 * @opcode: string
 *
 * Return: pointer to function or NULL
 */
void check_instruc(stack_t **stack, char *buf, unsigned int l)
{
	instruction_t func[] = {
		{"push", ft_push},
		{"pall", ft_pall},
		{NULL, NULL}
	};
	int i;

	i = 0;
	if (!op[0])
		return;
	while (func[i].opcode)
	{
		if (!strcmp(func[i].opcode, op[0]))
		{
			func[i].f(stack, l);
			return;
		}
		i++;
	}
	unknow_ins(stack, buf, l);
}


/**
 * main - main function
 * @ac: nmb of args
 * @av: list of args
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	size_t nb = 0;
	unsigned int l = 0;
	int n;
	char *buf = NULL;
	FILE *file;
	stack_t *stack = NULL;

	if (ac != 2)
		err_msg("USAGE: monty file\n", 0);
	file = fopen(av[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		n = getline(&buf, &nb, file);
		if (n <= 0)
		{
			if (buf)
				free(buf);
			break;
		}
		op[0] = strtok(buf, " \t\n\v\f\r");
		if (!op[0])
		{
			free(buf);
			continue;
		}
		l++;
		op[1] = strtok(NULL, " \t\n\v\f\r");
		check_instruc(&stack, buf, l);
	}
	return (0);
}

#include "monty.h"

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
 * @stack: stack
 * @buf: buffer
 * @l: line number
 */
void check_instruc(stack_t **stack, char *buf, unsigned int l)
{
	instruction_t func[] = {
		{"push", ft_push},
		{"pall", ft_pall},
		{"pint", ft_pint},
		{"pop", ft_pop},
		{"swap", ft_swap},
		{"add", ft_add},
		{"sub", ft_sub},
		{"div", ft_div},
		{"mul", ft_mul},
		{"nop", NULL},
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
			if (func[i].f)
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
		if (ft_getline(&buf, &nb, file) <= 0)
		{
			if (buf)
				free(buf);
			break;
		}
		op[0] = strtok(buf, " \t\n\v\f\r");
		if (!op[0])
		{
			free(buf);
			buf = NULL;
			continue;
		}
		l++;
		op[1] = strtok(NULL, " \t\n\v\f\r");
		check_instruc(&stack, buf, l);
		if (buf)
			free(buf);
		buf = NULL;
	}
	fclose(file);
	if (stack)
		free_dlistint(stack);
	return (0);
}

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
	fprintf(stderr, "L%u: unknown instruction %s\n", l, glb.op[0]);
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
		{"mod", ft_mod},
		{"pchar", ft_pchar},
		{"pstr", ft_pstr},
		{"rotl", ft_rotl},
		{"rotr", ft_rotr},
		{"stack", NULL},
		{"queue", NULL},
		{"nop", NULL},
		{NULL, NULL}
	};
	int i;

	i = 0;
	if (!glb.op[0] || glb.op[0][0] == '#')
		return;
	while (func[i].opcode)
	{
		if (!strcmp(func[i].opcode, glb.op[0]))
		{
			if (i == 14)
				glb.mode = 1;
			else if (i == 15)
				glb.mode = 2;
			else if (func[i].f)
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
		print_msg(av[1]);
	glb.mode = 1;
	while (1)
	{
		if (ft_getline(&buf, &nb, file) <= 0)
		{
			if (buf)
				free(buf);
			break;
		}
		glb.op[0] = strtok(buf, " \t\n\v\f\r");
		if (!glb.op[0])
		{
			free(buf);
			buf = NULL;
			continue;
		}
		l++;
		glb.op[1] = strtok(NULL, " \t\n\v\f\r");
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

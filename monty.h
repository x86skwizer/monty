#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct data_s - global data
 * @op: the opocodes and parms
 * @mode: 1 for stack 2 for queue
 */
typedef struct data_s
{
	char *op[2];
	int mode;
} data_t;

extern data_t glb;

void ft_rotr(stack_t **stack, unsigned int line_number);
void ft_pstr(stack_t **stack, unsigned int line_number);
void ft_rotl(stack_t **stack, unsigned int line_number);
void ft_pchar(stack_t **stack, unsigned int line_number);
void ft_mod(stack_t **stack, unsigned int line_number);
void ft_mul(stack_t **stack, unsigned int line_number);
void ft_sub(stack_t **stack, unsigned int line_number);
void ft_div(stack_t **stack, unsigned int line_number);
void ft_add(stack_t **stack, unsigned int line_number);
void ft_swap(stack_t **stack, unsigned int line_number);
void ft_pop(stack_t **stack, unsigned int line_number);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
stack_t *add_dnodeint(stack_t **head, const int n);
size_t print_dlistint(const stack_t *h);
void free_dlistint(stack_t *head);
int ft_getline(char **buf, size_t *nb, FILE *stream);
void ft_push(stack_t **stack, unsigned int line_number);
void ft_pall(stack_t **stack, unsigned int line_number);
void err_msg(const char *msg, unsigned int l);
void ft_pint(stack_t **stack, unsigned int line_number);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void print_msg(char *av);

#endif

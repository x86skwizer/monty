#include "monty.h"

/**
 * delete_dnodeint_at_index - deletes node at index index of stack_t
 * @head: head of stack_t
 * @index: index of node
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *current;
	unsigned int i;

	if (!head || !(*head))
		return (-1);
	current = *head;
	if (index == 0)
	{
		*head = (*head)->next;
		if (*head)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}
	for (i = 0; current && i < index; i++)
		current = current->next;
	if (!current)
		return (-1);
	if (current->prev)
		current->prev->next = current->next;
	if (current->next)
		current->next->prev = current->prev;
	free(current);
	return (1);
}

/**
 * free_dlistint - frees a stack_t list
 * @head: head of stack_t
 */
void free_dlistint(stack_t *head)
{
	stack_t *curr;

	curr = head;
	while (curr != NULL)
	{
		head = head->next;
		free(curr);
		curr = head;
	}
}

/**
 * add_dnodeint_end - adds new node at end of a stack_t
 * @head: head of stack_t
 * @n: content of new node
 *
 * Return: address of new element
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new;
	stack_t *curr;

	if (!head)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (!new)
		err_msg("Error: malloc failed\n", 0);
	new->n = n;
	new->next = NULL;
	if (!(*head))
	{
		new->prev = NULL;
		*head = new;
	}
	else
	{
		curr = *head;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = new;
		new->prev = curr;
	}
	return (new);
}

/**
 * add_dnodeint - adds new node at beginning of stack_t
 * @head: head of stack_t
 * @n: content of new node
 *
 * Return: address of the new element
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *node;

	if (!head)
		return (NULL);
	node = malloc(sizeof(stack_t));
	if (!node)
		err_msg("Error: malloc failed\n", 0);
	node->n = n;
	node->prev = NULL;
	if (*head == NULL)
	{
		*head = node;
		node->next = NULL;
	}
	else
	{
		node->next = *head;
		(*head)->prev = node;
	}
	*head = node;
	return (node);
}

/**
 * print_dlistint - prints all the elements of a stack_t list
 * @h: head of stack_t list
 *
 * Return: number of nodes
 */
size_t print_dlistint(const stack_t *h)
{
	size_t	i;

	i = 0;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		i++;
	}
	return (i);
}

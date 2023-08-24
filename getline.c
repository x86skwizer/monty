#include "monty.h"
/**
 * ft_strdup - duplicate string
 * @s: string
 *
 * Return: duplicated string
 */
char *ft_strdup(char *s)
{
	char *str;
	int i;

	if (!s)
		return (NULL);
	str = malloc((strlen(s) + 1) * sizeof(char));
	if (!str)
		err_msg("Error: malloc failed\n", 0);
	for (i = 0; s[i]; i++)
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}

/**
 * find_nl - find newline character
 * @s: string
 *
 * Return: 1 on success, 0 on failure
 */
int find_nl(char *s)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/**
 * _strjoin - join 2 strings
 * @first: string
 * @last: string
 *
 * Return: joined strings
 */
char *_strjoin(char *first, char *last)
{
	int size;
	int i;
	int j;
	char *new;

	size = strlen(first) + strlen(last);
	new = malloc(sizeof(char) * (size + 1));
	if (!new)
		err_msg("Error: malloc failed\n", 0);
	for (i = 0; first[i]; i++)
		new[i] = first[i];
	for (j = 0; last[j]; j++)
		new[i + j] = last[j];
	new[i + j] = '\0';
	return (new);
}

/**
 * ft_getline - getline alternative
 * @buf: buffer
 * @nb: buffer size
 * @stream: pointer to file
 *
 * Return: size of buffer, otherwise -1
 */
int ft_getline(char **buf, size_t *nb, FILE *stream)
{
	char *line, *tmp;

	line = malloc(sizeof(char) * 10);
	if (!line)
		err_msg("Error: malloc failed\n", 0);
	if (fgets(line, 10, stream) == NULL)
	{
		if (line)
			free(line);
		return (-1);
	}
	*buf = ft_strdup(line);
	*nb = strlen(*buf);
	while (line && !find_nl(line))
	{
		if (!line || !*line || fgets(line, 10, stream) == NULL)
			break;
		tmp = ft_strdup(*buf);
		free(*buf);
		*buf = _strjoin(tmp, line);
		free(tmp);
	}
	*nb = strlen(*buf);
	if (line)
		free(line);
	return (*nb);
}

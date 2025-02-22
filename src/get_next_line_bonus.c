/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:29:31 by jowagner          #+#    #+#             */
/*   Updated: 2025/02/22 01:23:36 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * @brief Create a new string containing the remaining characters in the stack
 * after the first line.
 *
 * @param stack The string to create the new line from.
 * @return A pointer to the new string, or NULL if an error occurred.
 */
static char	*new_line(char *stack)
{
	char	*new_line;
	size_t	i;
	size_t	j;

	i = 0;
	while (stack[i] != '\0' && stack[i] != '\n')
		i++;
	new_line = malloc(ft_strlen(stack) - i + 1);
	if (!new_line)
		return (NULL);
	if (stack[i] == '\n')
		i++;
	j = 0;
	while (stack[i])
	{
		new_line[j] = stack[i];
		i++;
		j++;
	}
	new_line[j] = '\0';
	free(stack);
	return (new_line);
}

/**
 * @brief Extract the first line from the stack.
 *
 * @param stack The string to extract the line from.
 * @return A pointer to the extracted line, or NULL if an error occurred.
 */
static char	*extract_line(char *stack)
{
	char	*line;
	size_t	i;

	line = NULL;
	i = 0;
	while (stack[i] != '\0' && stack[i] != '\n')
		i++;
	line = malloc(i + 1 + (stack[i] == '\n'));
	if (!line)
		return (NULL);
	i = 0;
	while (stack[i] != '\0' && stack[i] != '\n')
	{
		line[i] = stack[i];
		i++;
	}
	if (stack[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

/**
 * @brief Read data from the file descriptor and appends it to the stack.
 *
 * @param fd The file descriptor to read from.
 * @param stack The current stack of characters read so far.
 * @return A pointer to the updated stack, or NULL if an error occurred.
 */
char	*read_files(int fd, char *stack)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (1)
	{
		if (ft_strchr(stack, '\n') != NULL)
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_strs(buffer, stack), NULL);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		stack = ft_strjoin(stack, buffer);
		if (NULL == stack)
		{
			free_strs(stack, buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (stack);
}

/**
 * @brief Read a line from a file descriptor.
 *
 * @param fd The file descriptor to read from (0 <= fd < FD_MAX).
 * @return The read line, including the newline character if present,
 * or NULL if there is nothing more to read or an error occurred.
 */
char	*get_next_line(int fd)
{
	static char	*stack[FD_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FD_MAX)
		return (NULL);
	stack[fd] = read_files(fd, stack[fd]);
	if (!stack[fd] || *stack[fd] == '\0')
	{
		free(stack[fd]);
		return (NULL);
	}
	line = extract_line(stack[fd]);
	stack[fd] = new_line(stack[fd]);
	return (line);
}

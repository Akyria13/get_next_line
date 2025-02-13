/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:29:31 by jowagner          #+#    #+#             */
/*   Updated: 2025/02/13 16:27:36 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	if (stack[i] == '\n') // Yves
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*new_line(char *stack)
{
	char	*new_line;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (stack[i] && stack[i] != '\n')
		i++;
	new_line = malloc(ft_strlen(stack) - i + 1);
	if (!new_line)
		return (NULL);
	if (stack[i] == '\n') // Yves
		i++;
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

char	*read_me(int fd, char *stack)
{
	char	*buffer;
	ssize_t	bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FD_MAX)
		return (NULL);
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
		if (!stack)
			return (free_strs(buffer, stack), NULL);
	}
	free(buffer);
	return (stack);
}

char	*get_next_line(int fd)
{
	static char	*stack[FD_MAX];
	char		*line;

	stack[fd] = read_me(fd, stack[fd]);
	if (!stack[fd] || *stack[fd] == '\0')
		return (free_strs(NULL, stack[fd]), NULL);
	line = extract_line(stack[fd]);
	stack[fd] = new_line(stack[fd]);
	return (line);
}

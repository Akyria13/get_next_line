/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:29:31 by jowagner          #+#    #+#             */
/*   Updated: 2025/02/05 19:51:56 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (s != NULL && *s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*new_line(char *stack)
{
	char	*new_line;
	size_t	i;
	size_t	j;

	i = 0;
	while (stack[i] && stack[i] != '\n')
		i++;
	new_line = malloc(ft_strlen(stack) - i + 1);
	// Leak pas loin /asdasdas\nadadadasdasd
	if (!new_line)
		return (NULL);
	i++;
	j = 0;
	while (stack[i])
		new_line[j++] = stack[i++];
	new_line[j] = '\0';
	free(stack); // Essaye avec char** stack
	return (new_line);
}

char	*extract_line(const char *stack)
{
	char	*line;
	size_t	i;

	line = NULL;
	i = 0;
	while (stack[i] && stack[i] != '\0')
		i++;
	if (stack[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stack[i] && stack[i] != '\n')
	{
		line[i] = stack[i];
		i++;
	}
	if (stack[i] == '\n')
		line[i] = '\n';
	line[++i] = '\0';
	return (line);
}

void	clear_memory(char *stack)
{
	if (ft_strlen(stack) == 0)
	{
		ft_memset(stack, 0, ft_strlen(stack)); // +1 ?
		stack = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*stack;
	char		*line;
	char		*buffer;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (1)
	{
		if (ft_strchr(stack, '\n') != NULL || ft_strchr(stack, ' \0') != NULL)
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (free(buffer), NULL);
		buffer[bytes_read] = '\0';
		stack = ft_strjoin(stack, buffer);
	}
	free(buffer);
	line = extract_line(stack);
	stack = new_line(stack);
	clear_memory(stack);
	return (line);
}

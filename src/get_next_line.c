/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:29:31 by jowagner          #+#    #+#             */
/*   Updated: 2025/02/03 22:09:49 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	// printf("strchr = %s\n", s);
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
	// printf("stack = %s\n", stack);
	while (stack[i] && stack[i] != '\n')
		i++;
	// if (!stack[i])
	//	return (free(stack), NULL);
	new_line = malloc(ft_strlen(stack) - i + 1);
	if (!new_line)
		return (NULL);
	i++;
	j = 0;
	while (stack[i])
		new_line[j++] = stack[i++];
	new_line[j] = '\0';
	free(stack);
	return (new_line);
}

char	*extract_line(const char *stack)
{
	char	*line;
	size_t	i;

	line = NULL;
	i = 0;
	// printf("--EXTRACT LINE---\n");
	// printf("stack = %s\n", stack);
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
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	// printf("line = %s\n", line);
	// printf("---FIN EXTRACT LINE----\n");
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stack;
	char		*line;
	char		*buffer;
	ssize_t		bytes_read;

	// int			i;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	//	bytes_read = 1;
	//	while (!ft_strchr(stack, '\n') && bytes_read > 0
	// i = 0;
	while (1)
	{
		//	i++;
		if (ft_strchr(stack, '\n') != NULL)
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		// printf("%ld\n", bytes_read);
		if (bytes_read <= 0)
			return (free(buffer), NULL);
		buffer[bytes_read] = '\0';
		stack = ft_strjoin(stack, buffer);
		// printf("stack = %s\n", stack);
	}
	free(buffer);
	if (!stack)
		return (NULL);
	line = extract_line(stack);
	// printf("line = %s\n", line);
	stack = new_line(stack);
	if (ft_strlen(stack) == 0)
	{
		free(stack);
		stack = NULL;
	}
	// printf("stack = %s\n", stack);
	return (line);
}

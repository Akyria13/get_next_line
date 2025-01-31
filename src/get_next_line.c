/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:29:31 by jowagner          #+#    #+#             */
/*   Updated: 2025/01/31 20:40:34 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

ssize_t	ft_linelen(const char *str)
{
	ssize_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

static char	*str_extract(const char *buffer)
{
	char	*output;
	size_t	len;

	if (!buffer || !ft_strchr(buffer, '\n'))
		return (NULL);
	len = ft_linelen(buffer) + 1;
	output = malloc(sizeof(char) * (len + 1));
	if (!output)
		return (NULL);
	ft_memmove(output, buffer, len);
	output[len] = '\0';
	return (output);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*output;
	ssize_t		bytes_read;
	size_t		line_length;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			// output = ft_strdup(buffer);
			// buffer[0] = '\0';
			return (output);
		}
		buffer[bytes_read + ft_strlen(buffer)] = '\0';
	}
	// line_length = ft_linelen(buffer);
	// output = str_extract(buffer);
	// ft_memmove(buffer, buffer + line_length, BUFFER_SIZE);
	// buffer[BUFFER_SIZE] = '\0';
	return (output);
}

// char	*get_next_line(int fd)
// {
// 	static char	buffer[BUFFER_SIZE + 1];
// 	char		*output;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	output = read_and_extract(fd, buffer);
// 	if (!output)
// 		return (NULL);
// 	return (output);
// }

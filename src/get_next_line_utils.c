/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:37:01 by jowagner          #+#    #+#             */
/*   Updated: 2025/01/31 20:13:19 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_data;
	unsigned const char	*src_data;

	dest_data = (unsigned char *)dest;
	src_data = (unsigned const char *)src;
	if (!src_data && !dest_data)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest_data[i] = src_data[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char	*dest_data;
	unsigned char	*src_data;
	size_t			i;

	if (!src || !dest)
		return (NULL);
	dest_data = (unsigned char *)dest;
	src_data = (unsigned char *)src;
	i = -1;
	if (src_data > dest_data)
	{
		while (++i < size)
			dest_data[i] = src_data[i];
	}
	else
	{
		while (size > 0)
		{
			size--;
			dest_data[size] = src_data[size];
		}
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	int		s_len;
	char	*copy;

	s_len = ft_strlen(s);
	copy = malloc(sizeof(char) * (s_len + 1));
	if (!copy)
		return (NULL);
	ft_memcpy(copy, s, s_len);
	copy[s_len] = '\0';
	return (copy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (strdup(s2));
	if (!s2)
		return (strdup(s1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!result)
		return (NULL);
	ft_memcpy(result, s1, len_s1);
	ft_memmove(result + len_s1, s2, len_s2);
	result[len_s1 + len_s2] = '\0';
	return (result);
}

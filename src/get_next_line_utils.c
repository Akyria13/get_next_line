/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:37:01 by jowagner          #+#    #+#             */
/*   Updated: 2025/02/04 22:22:25 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	j;
	size_t	tmp;

	if (!s1 && !s2)
		return (NULL);
	if (s1 != NULL)
		tmp = ft_strlen(s1);
	else
		tmp = 0;
	result = malloc(tmp + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 != NULL && s1[i] != '\0')
		result[j++] = s1[i++];
	i = 0;
	while (s2 != NULL && s2[i] != '\0')
		result[j++] = s2[i++];
	result[j] = '\0';
	// free((void *)s1);
	return (result);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// char	*ft_strdup(const char *s)
// {
// 	int		s_len;
// 	char	*copy;

// 	s_len = ft_strlen(s);
// 	copy = malloc(sizeof(char) * (s_len + 1));
// 	if (!copy)
// 		return (NULL);
// 	ft_memcpy(copy, s, s_len);
// 	copy[s_len] = '\0';
// 	return (copy);
// }

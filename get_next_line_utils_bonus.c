/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:37:01 by jowagner          #+#    #+#             */
/*   Updated: 2025/02/13 14:52:22 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

void	free_strs(char *str1, char *str2)
{
	if (str1)
		free(str1);
	if (str2)
	{
		free(str2);
		str2 = NULL;
	}
}

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
	while (s1 != NULL && s1[i])
		result[j++] = s1[i++];
	i = 0;
	while (s2 != NULL && s2[i])
		result[j++] = s2[i++];
	free((void *)s1);
	result[j] = '\0';
	return (result);
}

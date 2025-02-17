/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:37:01 by jowagner          #+#    #+#             */
/*   Updated: 2025/02/17 18:15:03 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Calculates the length of the string str.
 *
 * @param str The string to measure.
 * @return The number of characters in str, excluding the null terminator.
 */
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/**
 * @brief Locates the first occurrence of the character c in the string s.
 *
 * @param s The string to be searched.
 * @param c The character to locate (converted to a char).
 * @return A pointer to the first occurrence of c in s,
 * or NULL if c is not found.
 */
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

/**
 * @brief Concatenates two strings into a newly allocated string.
 *
 * @param s1 The first string to concatenate. Will be freed.
 * @param s2 The second string to concatenate.
 * @return A pointer to the newly allocated string containing
 * the concatenation of s1 and s2, or NULL if the allocation fails.
 */
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

/**
 * @brief Frees the memory pointed to by two strings.
 *
 * @param str1 The first string to free (buffer).
 * @param str2 The second string to free (stack).
 */
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

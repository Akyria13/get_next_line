/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:37:01 by jowagner          #+#    #+#             */
/*   Updated: 2025/01/27 14:23:01 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Locates the first occurrence of the character c in the string s.
 *
 * @param s The string to be searched.
 * @param c The character to locate (converted to a char).
 * @return A pointer to the first occurrence of c in s,
 * or NULL if c is not found.
 */
char	*strchr(const char *s, int c)
{
	int		i;
	char	*occur;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char)s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char)s[i]);
	return (NULL);
}

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
 * @brief Copies up to size - 1 characters from src to dst,
 * NUL-terminating the result.
 *
 * @param dst Pointer to the destination buffer.
 * @param src Pointer to the source string.
 * @param size Size of the destination buffer.
 * @return The total length of the string it tried to create (length of src).
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while ((i < (size - 1)) && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

/**
 * @brief Appends src to dst, ensuring NULL-termination and
 * not exceeding size bytes in dst.
 *
 * @param dst Pointer to the destination buffer.
 * @param src Pointer to the source string to append.
 * @param size Size of the destination buffer.
 * @return The total length of the string it tried to create
 * (initial length of dst plus length of src).
 */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = 0;
	while (dest_len < size && dest[dest_len])
		dest_len++;
	src_len = ft_strlen(src);
	if (dest_len == size)
		return (size + src_len);
	i = 0;
	while (dest_len + i + 1 < size && src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

/**
 * @brief Concatenates two strings into a newly allocated string.
 *
 * @param s1 The first string to concatenate.
 * @param s2 The second string to concatenate.
 * @return A pointer to the newly allocated string containing
 * the concatenation of s1 and s2, or NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*result;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, len_s1 + 1);
	ft_strlcat(result + len_s1, s2, len_s2 + 1);
	return (result);
}

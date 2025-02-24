/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowagner <jowagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:57:14 by jowagner          #+#    #+#             */
/*   Updated: 2025/02/24 23:54:06 by jowagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

//-- The main function --//
char	*get_next_line(int fd);

//-- Utils functions --//
//--- --- --- --- ---//
// Calculates the length of the string str.
size_t	ft_strlen(const char *str);

// Locates the first occurrence of the character c in the string s.
char	*ft_strchr(const char *s, int c);

// Concatenates two strings into a newly allocated string.
char	*ft_strjoin(char const *s1, char const *s2);

// Frees the memory pointed to by two strings.
void	free_strs(char *str1, char *str2);
//--- --- --- --- ---//

#endif

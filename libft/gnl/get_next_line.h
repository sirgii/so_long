/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:44:21 by ssurilla          #+#    #+#             */
/*   Updated: 2023/04/29 16:40:09 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5

# endif

void	*ft_calloc2(size_t nmemb, size_t size);
char	*ft_strchr2(const char *s, int c);
size_t	len(const char *s);
char	*ft_strjoin2(char const *s1, char const *s2);
char	*get_next_line(int fd);

#endif
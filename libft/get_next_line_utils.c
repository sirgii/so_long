/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:08:58 by ssurilla          #+#    #+#             */
/*   Updated: 2023/03/13 19:10:53 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*cal_memset(void *s, int c, size_t n)
{
	char	*src;

	src = s;
	while (n--)
		*src++ = (char)c;
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*newstr;
	size_t	total;

	total = nmemb * size;
	newstr = malloc(total);
	if (newstr == NULL)
		return (0);
	cal_memset(newstr, 0, total);
	return ((void *)newstr);
}

char	*ft_strchr(const char *s, int c)
{
	int	counter;

	counter = 0;
	while (c > 128)
		c -= 128;
	while (s[counter])
	{
		if (s[counter] == c)
			return ((char *)s + counter);
		counter++;
	}
	if (s[counter] == c)
		return ((char *)s + counter);
	if (c == '\0')
		return ((char *)s);
	return (0);
}

size_t	len(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter] != '\0')
		counter++;
	return (counter);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		leftcount;
	int		rightcount;

	leftcount = 0;
	rightcount = 0;
	newstr = malloc(sizeof(char) * ((len(s1) + len(s2)) + 1));
	if (newstr == NULL)
		return (NULL);
	while (s1[leftcount])
	{
		newstr[leftcount] = s1[leftcount];
		leftcount++;
	}
	while (s2[rightcount])
	{
		newstr[leftcount] = s2[rightcount];
		leftcount++;
		rightcount++;
	}
	newstr[leftcount] = '\0';
	return (newstr);
}

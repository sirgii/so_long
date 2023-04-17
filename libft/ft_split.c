/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:43:10 by ssurilla          #+#    #+#             */
/*   Updated: 2022/12/10 21:34:35 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getlen(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*s && *s != c)
				s++;
			len++;
		}
		else
			s++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	leng;

	if (!s)
		return (0);
	i = 0;
	result = (char **)malloc(sizeof(char *) * (ft_getlen(s, c) + 1));
	if (!result)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			leng = 0;
			while (*s && *s != c && ++leng)
				++s;
			result[i++] = ft_substr(s - leng, 0, leng);
		}
		else
			++s;
	}
	result[i] = '\0';
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:32:14 by ssurilla          #+#    #+#             */
/*   Updated: 2022/12/10 19:21:44 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*p;
	int		i;

	i = 0;
	while (s[i])
		i++;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	p = str;
	while (*s)
		*p++ = *s++;
	*p = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:33:26 by ssurilla          #+#    #+#             */
/*   Updated: 2022/12/10 19:40:58 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*sstr;

	if (s == 0 && n == 0)
		return (NULL);
	sstr = (char *)s;
	while (n > 0)
	{
		if (*sstr == (char)c)
			return ((void *)sstr);
		sstr++;
		n--;
	}
	return (NULL);
}

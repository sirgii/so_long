/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:32:02 by ssurilla          #+#    #+#             */
/*   Updated: 2022/12/05 20:41:56 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*cstr;

	cstr = (char *) s;
	i = 0;
	while (i < n)
	{
		cstr[i] = c;
		i++;
	}
	return (cstr);
}

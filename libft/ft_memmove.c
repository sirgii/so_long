/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:02:39 by ssurilla          #+#    #+#             */
/*   Updated: 2022/12/10 19:11:47 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*csrc;
	char	*cdest;
	size_t	i;

	csrc = (char *)src;
	cdest = (char *)dest;
	i = 0;
	if (cdest == csrc)
		return (cdest);
	if (cdest > csrc)
	{
		i = n;
		while (i--)
			cdest[i] = csrc[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			cdest[i] = csrc[i];
			i++;
		}
	}
	return (cdest);
}

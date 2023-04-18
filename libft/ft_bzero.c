/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:16:14 by ssurilla          #+#    #+#             */
/*   Updated: 2022/12/05 20:52:40 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*sfill;

	i = 0;
	sfill = (char *)s;
	while (i < n)
	{
		sfill[i] = '\0';
		i++;
	}
}
/*
int	main(void)
{
	char	lo;

	lo = "null";
	printf("This is %s ft_bzero \n", ft_bzero(lo, 2));
	printf("This is %s bzero \n", bzero(lo, 2));
	return (0);	
}
*/
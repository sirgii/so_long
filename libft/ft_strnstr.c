/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:33:49 by ssurilla          #+#    #+#             */
/*   Updated: 2022/12/05 20:16:21 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (big == 0 && len == 0)
		return (0);
	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0')
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len && big[i + j] != '\0')
		{
			if (little[j + 1] == '\0')
			{
				return ((char *)&big[i]);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	*s1[];
	const char	*s2[];

    s1[] = "Bgi Big Dig";
    s2[] = "Big";
    printf("Return this %s \n", ft_strnstr(s1, s2, 4));
    return (0);
}
*/
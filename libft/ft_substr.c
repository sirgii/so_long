/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:23:55 by ssurilla          #+#    #+#             */
/*   Updated: 2022/12/10 21:31:36 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		len = 0;
	else if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	if (len != 0)
	{
		while (s[start] != '\0' && i < len)
		{
			sub[i] = s[start + i];
			i++;
		}
	}
	sub[i] = '\0';
	return (sub);
}

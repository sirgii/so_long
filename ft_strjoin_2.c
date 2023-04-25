/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:29:24 by ssurilla          #+#    #+#             */
/*   Updated: 2023/04/25 18:45:24 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin_2(char *s1, char *s2)
{
	char *ptr;
	unsigned long size;
	char *temp;

	temp = ft_strndup(s1, ft_strlen(s1));
	free(s1);
	if (!s1 || !s2)
		return (0);
	size = ft_strlen(temp) + ft_strlen(s2);
	ptr = malloc(size + 1);
	if (!ptr)
		return (0);
	ft_memcpy(ptr, temp, ft_strlen(temp));
	ft_memcpy(&ptr[ft_strlen(temp)], s2, ft_strlen(s2));
	ptr[size] = '\0';
	free(temp);
	return (ptr);
}
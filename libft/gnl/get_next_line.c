/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:53:15 by ssurilla          #+#    #+#             */
/*   Updated: 2023/05/05 18:09:55 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_dict2(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin2(buffer, buf);
	free(buffer);
	return (temp);
}

char	*print_line(char *dict)
{
	char	*newstr;
	int		counter;

	counter = 0;
	if (!dict[counter])
		return (NULL);
	while (dict[counter] && dict[counter] != '\n')
		counter++;
	newstr = ft_calloc2(counter + 2, sizeof(char));
	counter = 0;
	while (dict[counter] && dict[counter] != '\n')
	{
		newstr[counter] = dict[counter];
		counter++;
	}
	if (dict[counter] == '\n')
		newstr[counter++] = '\n';
	newstr[counter] = 0;
	return (newstr);
}

char	*set_to_next_newline(char *dict)
{
	char	*newstr;
	int		counter;
	int		counter2;

	counter = 0;
	counter2 = 0;
	while (dict[counter] && dict[counter] != '\n')
		counter++;
	if (!dict[counter])
	{
		free(dict);
		return (NULL);
	}
	newstr = (char *)malloc(sizeof(char) * (len(dict) - counter + 1));
	if (!newstr)
	{
		free(newstr);
		return (NULL);
	}
	counter++;
	while (dict[counter])
		newstr[counter2++] = dict[counter++];
	newstr[counter2] = 0;
	free(dict);
	return (newstr);
}

char	*get_dict_input(int fd, char *dict)
{
	char	*buffer;
	int		byte_read;

	if (!dict)
		dict = ft_calloc2(1, 1);
	buffer = ft_calloc2(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			free(dict);
			return (NULL);
		}
		buffer[byte_read] = 0;
		dict = free_dict2(dict, buffer);
		if (ft_strchr2(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (dict);
}

char	*get_next_line(int fd)
{
	static char	*dict;
	char		*newstr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	dict = get_dict_input(fd, dict);
	if (!dict)
		return (NULL);
	newstr = print_line(dict);
	dict = set_to_next_newline(dict);
	return (newstr);
}

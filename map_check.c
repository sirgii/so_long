/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssurilla <ssurilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:01:02 by ssurilla          #+#    #+#             */
/*   Updated: 2023/05/05 18:00:59 by ssurilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// concatenate arrays and free first array before returning
char	*free_dict(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

// read file and return content
char	*loadmap(int fd)
{
	static char	*dict;
	char		*buffer;
	int			byte_read;

	if (!dict)
		dict = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = 0;
		dict = free_dict(dict, buffer);
	}
	free(buffer);
	return (dict);
}

// count number of lines in map
int	get_newline(char *map)
{
	int	count;
	int	pos;

	count = 0;
	pos = 0;
	while (map[pos])
	{
		if (map[pos] == '\n' && (map[pos + 1] != '\0' && map[pos + 1] != '\n'))
			count++;
		pos++;
	}
	return (count);
}

// check ascii symbols
int	ascii_check(char *map, int symb)
{
	int	found;
	int	pos;

	found = 0;
	pos = 0;
	while (map[pos])
	{
		if (map[pos] == symb)
			found++;
		pos++;
	}
	return (found);
}

// check if map is surrounded by walls
int	fill_walls(char *map, int lines, int passed, int valid)
{
	int	count;

	count = 0;
	while (map[count])
	{
		if (map[count] == '\n')
		{
			if (passed < lines - 1)
			{
				if (map[count + 1] != '1' || map[count - 1] != '1')
					valid = 0;
			}
			passed++;
			count++;
		}
		if (passed == 0 || passed == lines - 1)
		{
			if (map[count] != '1')
				valid = 0;
		}
		count++;
	}
	return (valid);
}

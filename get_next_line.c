/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:04:32 by aneitenb          #+#    #+#             */
/*   Updated: 2023/12/14 15:54:10 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*save_remainder(char *buffer)
{
	int		i;
	int		j;
	char	*string;

	j = 0;
	i = strlentn(buffer);
	i++;
	string = malloc((ft_strlen(buffer) - i) + 1);
	if (!string)
		return (NULL);
	while (buffer[i] != '\0')
	{
		string[j] = buffer[i];
		i++;
		j++;
	}
	string[j] = '\0';
	return (string);
}

static char	*get_line(char *buffer)
{
	int		len1;
	int		i;
	char	*string;

	i = 0;
	len1 = strlentn(buffer);
	string = malloc(len1 + 1);
	if (!string)
		return (NULL);
	while (i <= len1)
	{
		string[i] = buffer[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

static char	*read_line(int fd, char *buffer)
{
	char	string[BUFFER_SIZE + 1];
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, string, BUFFER_SIZE);
		string[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, string);
		if (ft_strchr(string, '\n') != 0)
			break ;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*string;

	string = ((void *)0);
	if (!buffer)
		buffer = "";
	if (!fd || fd < 0)
		return (NULL);
	buffer = read_line(fd, buffer);
	if (buffer == NULL)
	{
		free(string);
		return (NULL);
	}
	string = get_line(buffer);
	if (string == NULL)
	{
		free(string);
		return (NULL);
	}
	buffer = save_remainder(buffer);
	return (string);
}

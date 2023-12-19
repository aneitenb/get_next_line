/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:04:32 by aneitenb          #+#    #+#             */
/*   Updated: 2023/12/19 16:18:45 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*save_remainder(char *buffer)
{
	int		i;
	int		j;
	char	*string;

	j = 0;
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == 0)
	{
		free(buffer);
		return (NULL);
	}
	i++;
	string = buffer;
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
	int		i;
	char	*string;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	string = malloc(i + 1);
	if (!string)
	{
		free(buffer);
		return (NULL);
	}
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		string[i] = buffer[i];
		i++;
	}	
	if (buffer[i] && buffer[i] == '\n')
		string[i++] = '\n';
	string[i] = '\0';
	return (string);
}

static char	*ft_join(char *buffer, char *string)
{
	char	*temp;

	temp = ft_strjoin(buffer, string);
	free(buffer);
	return (temp);
}

static char	*read_line(int fd, char *buffer)
{
	char	string[BUFFER_SIZE + 1];
	int		bytes_read;

	bytes_read = 1;
	if (!buffer)
		buffer = ft_calloc(sizeof(char), 1);
	if (buffer == NULL)
		return (NULL);
	while (bytes_read != 0)
	{
		bytes_read = read(fd, string, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		string[bytes_read] = '\0';
		buffer = ft_join(buffer, string);
		if (buffer == NULL)
			return (NULL);
		if (ft_strchr(string, '\n') != 0)
			break ;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*string;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = read_line(fd, buffer);
	if (buffer == NULL || buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	string = get_line(buffer);
	if (string == NULL)
	{
		buffer = NULL;
		return (NULL);
	}
	buffer = save_remainder(buffer);
	return (string);
}

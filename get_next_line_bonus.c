/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:30:55 by aneitenb          #+#    #+#             */
/*   Updated: 2024/01/02 10:08:45 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*save_remainder(char *buffer)
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

char	*get_lines(char *buffer)
{
	int		i;
	char	*string;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	string = ft_calloc(sizeof(char), i + 1);
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
	return (string);
}

char	*ft_free(char *string)
{
	free(string);
	string = NULL;
	return (NULL);
}

char	*read_line(int fd, char *buffer)
{
	char	*string;
	int		bytes_read;

	bytes_read = 1;
	string = ft_calloc(sizeof(char), 1);
	if (string == NULL)
		return (ft_free(buffer));
	if (!buffer)
		buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (ft_free(string));
	string = ft_join(string, buffer);
	if (string == NULL)
		return (ft_free(buffer));
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		buffer[bytes_read] = '\0';
		string = ft_join(string, buffer);
		if (string == NULL)
			return (ft_free(buffer));
		if (ft_strchr(string, '\n') != 0)
			break ;
	}
	ft_free(buffer);
	return (string);
}

char	*get_next_line(int fd)
{
	static char		*buffer[3000];
	char			*string;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = read_line(fd, buffer[fd]);
	if (buffer[fd] == NULL || buffer[fd][0] == '\0')
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	string = get_lines(buffer[fd]);
	if (string == NULL)
	{
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = save_remainder(buffer[fd]);
	return (string);
}

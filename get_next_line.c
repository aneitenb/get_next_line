/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:04:32 by aneitenb          #+#    #+#             */
/*   Updated: 2023/12/19 10:11:13 by aneitenb         ###   ########.fr       */
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
	free(buffer);
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
	while (bytes_read != 0 || (ft_strchr(string, '\n') != 0))
	{
		bytes_read = read(fd, string, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		string[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, string);
		if (buffer == NULL)
			return (NULL);
	}
	return (buffer);
}

static void	*ft_free(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*string;

	if (fd < 0 || !fd || BUFFER_SIZE <= 0)
		return (NULL);
	string = NULL;
	if (!buffer)
		buffer = "";
	buffer = read_line(fd, buffer);
	if (buffer == NULL || buffer[0] == '\0')
		return (ft_free(buffer));
	string = get_line(buffer);
	if (string == NULL)
		return (ft_free(buffer));
	buffer = save_remainder(buffer);
	if (buffer == NULL)
		return (ft_free(buffer));
	return (string);
}

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int    main(void)
{
    char    *str;
    int        fd;
    int        i;

    i = 1;
    fd = open("tester.txt", O_RDONLY);
    if (fd == -1)
        return (-1);
    str = get_next_line(fd);
    printf("String[%d]: %s", i, str);
        free(str);
	i++;
    while ((str = get_next_line(fd)) != NULL)
    {
        printf("String[%d]: %s", i, str);
        free(str);
        i++;
    }
    close (fd);
    return (0);
}
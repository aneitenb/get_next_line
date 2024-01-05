/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:04:56 by aneitenb          #+#    #+#             */
/*   Updated: 2024/01/02 15:06:22 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i])
			i++;
	}
	return (i);
}

char	*ft_strjoin(char *string, char *buffer)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!string || !buffer)
		return (NULL);
	new = malloc(ft_strlen(string) + ft_strlen(buffer) + 1);
	if (new == NULL)
		return (ft_free(string));
	while (string[i] != '\0')
	{
		new[i] = string[i];
		i++;
	}
	while (buffer[j] != '\0')
	{
		new[i] = buffer[j];
		i++;
		j++;
	}
	new[i] = '\0';
	free(string);
	return (new);
}

char	*ft_strchr(const char *str, int c)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (0);
}

char	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	max;
	size_t	i;

	max = 0 - 1;
	i = 0;
	if (count != 0)
		if (max / count < size)
			return (NULL);
	ptr = (void *)malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	while (i < (count * size))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_free(char *string)
{
	free(string);
	string = NULL;
	return (NULL);
}

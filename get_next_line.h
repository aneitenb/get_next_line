/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:05:16 by aneitenb          #+#    #+#             */
/*   Updated: 2024/01/02 15:06:15 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h> 

char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
char	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *string, char *buffer);
char	*ft_free(char *string);

#endif

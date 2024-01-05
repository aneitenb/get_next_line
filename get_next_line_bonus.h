/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:27:21 by aneitenb          #+#    #+#             */
/*   Updated: 2024/01/02 15:06:34 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h> 

char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *string, char *buffer);
char	*ft_free(char *string);

#endif

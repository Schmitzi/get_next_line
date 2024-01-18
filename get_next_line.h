/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:22:25 by mgeiger-          #+#    #+#             */
/*   Updated: 2023/10/19 08:28:56 by mgeiger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*from_file(int fd, char *buffer);
char	*ft_strchr(char *s, int c);
void	tl_copy(char *res, char *buffer);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *buffer, char *ff_buf);
char	*trim_line(char *buffer);
char	*save_line(char *buffer);

#endif
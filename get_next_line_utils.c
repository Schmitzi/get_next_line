/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:03:10 by mgeiger-          #+#    #+#             */
/*   Updated: 2023/10/18 17:44:27 by mgeiger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *buffer, char *ff_buf)
{
	int		i;
	int		j;
	char	*res;

	if (!buffer)
	{
		buffer = (char *)malloc(1 * sizeof(char));
		if (!buffer)
			return (free(ff_buf), NULL);
		buffer[0] = '\0';
	}
	if (!buffer || !ff_buf)
		return (free(buffer), buffer = NULL, free(ff_buf), NULL);
	res = malloc(sizeof(char) * ((ft_strlen(buffer) + ft_strlen(ff_buf)) + 1));
	if (res == NULL)
		return (free(buffer), buffer = NULL, free(ff_buf), NULL);
	i = -1;
	j = 0;
	if (buffer)
		while (buffer[++i] != '\0')
			res[i] = buffer[i];
	while (ff_buf[j] != '\0')
		res[i++] = ff_buf[j++];
	res[ft_strlen(buffer) + ft_strlen(ff_buf)] = '\0';
	return (free(buffer), buffer = NULL, res);
}

char	*trim_line(char *buffer)
{
	int		i;
	char	*res;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (free(buffer), buffer = NULL, NULL);
	tl_copy(res, buffer);
	return (res);
}

void	tl_copy(char *res, char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		res[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		res[i] = buffer[i];
		i++;
	}
	res[i] = '\0';
}

char	*save_line(char *buffer)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), buffer = NULL, NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!res)
		return (free(res), free(buffer), buffer = NULL, NULL);
	i++;
	j = 0;
	while (buffer[i])
		res[j++] = buffer[i++];
	res[j] = '\0';
	return (free(buffer), buffer = NULL, res);
}

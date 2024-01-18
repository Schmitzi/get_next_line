/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeiger- <mgeiger-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:01:41 by mgeiger-          #+#    #+#             */
/*   Updated: 2023/12/05 14:37:56 by mgeiger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == c)
		return (&s[i]);
	else
		return (NULL);
}

char	*from_file(int fd, char *buffer)
{
	int		bytes_read;
	char	*ff_buf;

	bytes_read = 1;
	ff_buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!ff_buf)
		return (free(buffer), buffer = NULL, NULL);
	while (!ft_strchr(buffer, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, ff_buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(ff_buf), free(buffer), buffer = NULL, NULL);
		ff_buf[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, ff_buf);
		if (!buffer)
			return (NULL);
	}
	return (free(ff_buf), buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	buffer = from_file(fd, buffer);
	if (!buffer)
		return (free(buffer), buffer = NULL, NULL);
	line = trim_line(buffer);
	buffer = save_line(buffer);
	return (line);
}

int	main(void)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening file");
		return (close(fd), 1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf(">>%s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (!close(fd))
		return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:34:51 by frocha-b          #+#    #+#             */
/*   Updated: 2025/05/19 12:21:34 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buff[1024][BUFFER_SIZE + 1];
	char		*line;
	int			bytes_readed;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	line = ft_join_buff(line, buff[fd]);
	while (!ft_strchr(buff[fd], '\n'))
	{
		bytes_readed = read (fd, buff[fd], BUFFER_SIZE);
		if (bytes_readed < 0 || buff[fd][0] == 0)
		{
			shift_buff(buff[fd]);
			free(line);
			return (NULL);
		}
		if (!bytes_readed)
			break ;
		buff[fd][bytes_readed] = '\0';
		line = ft_join_buff(line, buff[fd]);
	}
	shift_buff(buff[fd]);
	return (line);
}
/* 
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int 	fd = open("teste.txt", O_RDONLY);
	int		fd1 = open("teste1.txt", O_RDONLY);
	char	*str;

	while((str = get_next_line(fd)))
	{
		printf ("%s",str);
		free(str);
	}
	while((str = get_next_line(fd1)))
	{
		printf ("%s",str);
		free(str);
	}
	while ((str = get_next_line(fd)))
	{
		printf ("%s",str);
		free(str);
	}
	return (0);
} */
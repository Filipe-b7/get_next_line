/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:32:25 by frocha-b          #+#    #+#             */
/*   Updated: 2025/05/13 11:28:32 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		buff_segment[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 )
		return (NULL);	

	line = NULL;	
	while(1)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free (line);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		if (bytes_read == 0)
			return line;
		if (str_srch(buff, '\0', bytes_read) == 1 || str_srch(buff, '\n', bytes_read) == 1)
		{
			copy_buff(buff_segment, buff, bytes_read);
			line = ft_strjoin(line, buff_segment);
			shift_buffer(buff, bytes_read);	
			return (line);
		}
			else
		{
			temp = line;
			line = ft_strjoin(buff, line);
			free (temp);
			if (!line)
				return (NULL);
		}
	}
}

#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int	fd = open("teste.txt",O_RDONLY);

	if (fd == -1)
		return 1;
	printf("%s",get_next_line(fd));
	close(fd);
	return (0);
}

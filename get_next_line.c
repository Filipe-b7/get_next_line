/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:32:25 by frocha-b          #+#    #+#             */
/*   Updated: 2025/05/07 17:32:25 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;
	char		*temp;
	char		*buff_resized;

	if (!fd || BUFFER_SIZE <= 0 )
		return (NULL);
	line[0] = '\0';
	
	while(1)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		buff[bytes_read] = '\0'
		if (bytes_read < 0)
		{
			free (line);
			return (NULL);
		}
		if (bytes_read == 0)
			return line;
		if (str_srch(buff, "\0", bytes_read) || str_srch(buff, "\n", bytes_read))
		{
			buff_resized = copy_buff(buff, bytes_read);
			ft_strjoin(line, buff_resized);
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
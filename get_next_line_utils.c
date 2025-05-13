/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:32:22 by frocha-b          #+#    #+#             */
/*   Updated: 2025/05/13 11:30:14 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int len;

	len = 0;
	if (!str)
		return 0;
	while(str[len])
		len++;
	return (len);
}
	char	*ft_strjoin(char *line, char *buff)
	{
		char	*str;
		int		length;
		int		len_line;
		int		i;
		int		j;

		len_line = 0;
		length = ft_strlen(line) + ft_strlen(buff);
		str = malloc(length + 1);
		if (!str)
			free(line);
			return (NULL);
		i = 0;
		while (i < ft_strlen(line))
		{
			str[i] = line[i];
			i++;
		}
		j = 0;
		while (j < ft_strlen(buff))
		{
			str[i + j] = buff[j];
			j++;
		}
		str[i + j] = '\0';
		return (str);
	}

int	str_srch(char *buff, char c, int bytes_read)
{
	int	i;

	i = 0;
	while (i < bytes_read)
	{
		if (buff[i] == c)
			return (1);
		i++;
	} 
	return (0);
}

void	shift_buffer(char *buff, int bytes_read)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buff[i] != '\n' &&  buff[i] != '\0' && i < bytes_read)
		i++;
	i++;
	while (i + j < bytes_read)
	{
		buff[j] = buff[i + j];
		j++;
	}
	buff[j] = '\0';
}

void	copy_buff(char *buff_segment,char *buff, int bytes_read)
{
	int	i;

	i = 0;
	while (buff[i] && buff[i] != '\n' && i < bytes_read)
	{
		buff_segment[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n' && i < bytes_read)
	{
		buff_segment[i] = '\n';
		i++;
	}
	buff_segment[i] = '\0';
}

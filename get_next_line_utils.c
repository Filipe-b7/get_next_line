/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:32:22 by frocha-b          #+#    #+#             */
/*   Updated: 2025/05/07 17:32:22 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while(str[len])
		len++;
	return (len)
}
char	*ft_strjoin(char *line, char *buff)
{
	char	*str;
	int		length;
	int		i;
	int		j;

	length = ft_strlen(line) + ft_strlen(buff);
	str = malloc(length + 1* sizeof(char));
	if (!str)
		free(line);
		return (NULL);
	while (line[i])
	{
		str[i] = line[i];
		i++;
	}
	while (buff[j])
	{
		str[i + j] = buff[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

int	str_srch(char * buff, char c, int bytes_read)
{
	int	i;

	i = 0;
	while (i < bytes_read)
	{
		if (buff[i] == c)
			return (1);
	} 
	return (0);
}

void	shift_buffer(char *buff, int bytes_read)
{
	while (buff[i] != '\n' && i < bytes_read)
		i++;
	while (buff[i + j])
	{
		buff[j] = buff[i + j];
		j++;
	}
	buff[i + j] = '\0';
}

void	copy_buff(char *buff, int bytes_read)
{
	char	*buff_resized;
	while (buff[i] != '\n' && i < bytes_read)
	{
		buff_resized[i] = buff[i];
		i++;
	}

}
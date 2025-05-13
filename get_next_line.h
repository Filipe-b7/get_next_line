/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:32:28 by frocha-b          #+#    #+#             */
/*   Updated: 2025/05/12 15:28:23 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#define BUFFER_SIZE 42

#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str);
char	*ft_strjoin(char *line, char *buff);
int		str_srch(char * buff, char c, int bytes_read);
void	shift_buffer(char *buff, int bytes_read);
void	copy_buff(char *buff_segment,char *buff, int bytes_read);

#endif
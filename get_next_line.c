/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:19:38 by frocha-b          #+#    #+#             */
/*   Updated: 2025/04/19 17:19:38 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static buff [BUFFER_SIZE + 1];
    int		chars_read;
    char	*stash;
    char	*temp;

    stash = malloc (1);
    stash[0] = '\0';
    while (t_strchr(stash,'\n'))
    {
        chars_read = read(fd, buff, BUFFER_SIZE);
        buff[BUFFER_SIZE] = '\0';
        if (!chars_read) 
        {
                free (stash);
                return ;
        }
        temp = stash;
        stash = ft_strjoin(stash, buff);
        if (!stash)
        {
            free(temp);
            return ;
        }
        free (temp);
    }
}
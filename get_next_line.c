/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:19:38 by frocha-b          #+#    #+#             */
/*   Updated: 2025/04/24 17:11:41 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static char buff [BUFFER_SIZE];
    int         chars_read;
    char	    *stash;
    char	    *temp;
    char        *line;

    if (!fd ||  BUFFER_SIZE <= 0)
        return (NULL);
    if (buff)
    {
        line = ft_strdup(buff);
    }
    stash[0] = '\0';
    while (!ft_strchr(stash,'\n'))
    {
        chars_read = read(fd, buff, BUFFER_SIZE);
        buff[chars_read] = '\0';
        if (!chars_read) 
        {
            free (stash);
            return (NULL);
        }
        temp = stash;
        stash = ft_strjoin(stash, buff);
        if (!stash)
        {
            free(temp);
            return (NULL);
        }
        free (temp);
    }
    line = make_line(stash);
    if (!stash)
        free(stash);
        return ;
    buf = shift_buf(buf);
    return (line);

}
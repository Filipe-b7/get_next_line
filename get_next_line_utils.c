/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:19:41 by frocha-b          #+#    #+#             */
/*   Updated: 2025/04/19 17:19:41 by frocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*string;
	size_t	len;
	size_t	i;
	size_t	j;

	len = ft_strlen(s1) + ft_strlen(s2);
	string = malloc (sizeof (char) * (len + 1));
	if (!string)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[i])
	{
		string[i + j] = s2[j];
		j++;
	}
	string[i + j] = '\0';
	return (string);
}

char	*ft_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s ==(unsigned char) c)
			return (&s);
		s++;
	}
	if (*s == c)
		return (&s);
	return (NULL);
}

char	*make_line(char *stash)
{
	size_t	len;
	char	*line;
	size_t	i;

	len = 0;
	while (stash[len - 1] != '\n')
	{
		len++;
	}
	line = malloc (sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

// problemas a resolver
/*
entender quando chamar outra vez a funcao, 
o que deve ser estatico e o q ela vai ler e
 criar ponteiro para isso talvez
 */

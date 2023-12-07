/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:05:24 by bkwamme           #+#    #+#             */
/*   Updated: 2023/12/07 16:31:04 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	search_line(char *rest, char *line, char *buffer, int fd)
{
	int	i;
	int	li;

	li = ft_strlen(line);
	i = 0;
	read(fd, buffer, BUFFER_SIZE);
	while (buffer[i] != '\0' || )
	{
		line[li] = buffer[i];
		if (buffer[i] == '\n')
			rest = ft_strchr(buffer, '\n');
		i++;
	}
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	int	i;
	int	li;

	if (!fd)
		return (NULL);
	li = 0;
	line = (char *) malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	while (search_line(rest, line, buffer, fd) != 0)
	{

		i = 0;
		while (rest[i] != '\n' && rest[i] != '\0')
		{
			read(fd, buffer, BUFFER_SIZE);
			if (buffer[i] != '\n' && buffer[i] != '\0')
				line[li] = buffer[i];
		li++;
		i++;
		}
	}
}

int main()
{
	int fd = open("blabla", O_RDONLY);
	get_next_line(fd);
	return 0;
}

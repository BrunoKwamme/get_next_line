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

static char	*search_line(char *line, char *buffer, int fd)
{

}

static char	*get_line(char *line, char *buffer, int fd)
{
	read(fd, buffer, BUFFER_SIZE)
	while ()
	{

	}

}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;
	char		buffer[BUFFER_SIZE];
	int	i;

	if (!fd)
		return (NULL);
	if (buffer)
		line = ft_strlcpy(line, rest, ft_strlen(rest));
	while (!)
	{

		i = 0;
		while (rest[i] != '\n' && rest[i] != '\0')
		{
			read(fd, buffer, BUFFER_SIZE);
			if (buffer[i] != '\n' && buffer[i] != '\0')
				line[li] = buffer[i];
		i++;
		}
	}
}

int main()
{
	int fd = open("blabla", O_RDONLY);
	char	*str;
	str = get_next_line(fd);
	while (str != NULL)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	printf("%s", str);
	free(str);
	return 0;
}

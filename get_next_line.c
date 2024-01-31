/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:05:24 by bkwamme           #+#    #+#             */
/*   Updated: 2024/01/31 15:21:48 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *) s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

static char	*search_line(char *line, char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
		return (ft_strjoin(line, buffer));
}

static char	*get_line(int fd)
{
	static char	*buffer;
	char	*line;
	int		i;
	int		x;

	buffer = (char *) malloc((1 + BUFFER_SIZE) * sizeof(char));
	if(!buffer)
		return(NULL);
	if(buffer)
	{
		search_line(line, buffer);
	}
	read(fd, buffer, BUFFER_SIZE);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	ft_strjoin(line, buffer);
	if (buffer[i] == '\n')
	{
		i = 0;
		while (buffer[i] != '\n')
		{
			line[x] = buffer[i];
			x++;
			i++;
		}
		ft_strchr(buffer, '\n');
	}
}

char	*get_next_line(int fd)
{
	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	return (get_line(fd));
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

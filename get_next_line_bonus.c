/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:05:24 by bkwamme           #+#    #+#             */
/*   Updated: 2023/12/07 09:43:38 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}

static char *ft_rest(char *rest)
{
	char	*str;
	char	*temp;

	temp = ft_strchr(rest, '\n');
	if(*temp)
	{
		str = ft_strdup(temp);
		if(!str)
			return (NULL);
		free(rest);
	}
	else
	{
		free(rest);
		return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static ll_manager	*llm;
	gnl_list		*node;
	node = ft_lstfd(fd, llm);
	if (!node)
	{
		llm = (ll_manager  *) malloc (sizeof(ll_manager));
		if (!llm)
			return (NULL);
		llm->fd = fd;
		node = &llm->fd_list;
	}
}

int main()
{
	int fd = open("blabla", O_RDONLY);
	get_next_line(fd);
	return 0;
}

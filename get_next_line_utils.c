/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:07:33 by bkwamme           #+#    #+#             */
/*   Updated: 2024/02/01 18:52:33 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < (size - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str)
		while (str[i] != '\0')
			i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	i = 0;
	if (dst_len >= size)
		return (size + ft_strlen(src));
	while ((dst_len + i) < (size - 1) && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + ft_strlen(src));
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == c)
		return ((char *)&s[i + 1]);
	return (NULL);
}
/*
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		length;

	if (!s1)
		length = (int) ft_strlen(s2) + 1;
	else
		length = (int) ft_strlen(s1) + (int) ft_strlen(s2) + 1;
	str = malloc (sizeof(char) * (length));
	if (!str)
		return (NULL);
	if (s1)
	{
		ft_strlcpy(str, s1, length);
		free(s1);
	}
	ft_strlcat(str, s2, length);
	return (str);
}*/

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		free(s1);
	}
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	if (!*str)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

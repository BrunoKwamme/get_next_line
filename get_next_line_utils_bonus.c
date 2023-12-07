/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:07:33 by bkwamme           #+#    #+#             */
/*   Updated: 2023/12/07 09:43:40 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstadd_back(gnl_list **lst, gnl_list *new)
{
	gnl_list	*node;

	if (lst != NULL)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			node = ft_lstlast(*lst);
			node->next = new;
		}
	}
}

gnl_list	*ft_lstnew(void *content)
{
	gnl_list	*new;

	new = malloc (sizeof(gnl_list));
	if (!new)
		return (NULL);
	new->buffer = content;
	new->next = NULL;
	return (new);
}

gnl_list	*ft_lstlast(gnl_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

gnl_list	ft_lstfd(int fd, ll_manager llm)
{
	if (!llm)
		return (NULL);
	while (llm && llm->fd != fd)
		llm = llm->next;
	return (llm->fd_list);
}

char	*ft_lstnl(gnl_list *lst, char *line, int rest_index)
{
	int	i;
	int	lsti;

	i = rest_index;
	while (lst)
	{
		lsti = 0;
		if (lst->buffer[lsti] != '\n' && lst->buffer[lsti] != '\0')
		{
			line[i] = lst->buffer[lsti];
		}
	}
	line[i] = '\0';
	return (line);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

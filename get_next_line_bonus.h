/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:08:00 by bkwamme           #+#    #+#             */
/*   Updated: 2023/12/07 09:32:35 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>

# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE (1)
# endif
typedef struct linked_list
{
	char			*buffer;
	struct linked_list	*next;
}	gnl_list;

typedef struct linked_list_manager
{
	int				fd;
	gnl_list			fd_list;
	struct linked_list_manager	*next;
}	ll_manager;

char			*ft_strchr(const char *s, int c);
char			*ft_lstnl(gnl_list *lst, char *line, int rest_index);
char			*ft_strdup(const char *s);
void		ft_lstadd_back(gnl_list **lst, gnl_list *new);
size_t		ft_strlen(const char *str);
gnl_list	*ft_lstnew(void *content);
gnl_list	*ft_lstlast(gnl_list *lst);


#endif

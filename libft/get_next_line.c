/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:50:39 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/18 11:48:58 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gnl	*ft_lstlast_gnl(t_gnl *lst)
{
	t_gnl	*aux;

	aux = lst;
	while (lst != NULL)
	{
		aux = lst;
		lst = lst->next;
	}
	return (aux);
}

void	ft_lstclear_gnl(t_gnl **lst, void (*del)(void *))
{
	if (!lst || !del || !(*lst))
		return ;
	ft_lstclear_gnl(&(*lst)->next, del);
	del((*lst)->str_buf);
	free(*lst);
	*lst = NULL;
}

int	init_list(t_gnl **list, int fd)
{
	char	*str;
	int		read_bytes;

	while (!find_new_line(*list))
	{
		str = malloc(BUFFER_SIZE + 1);
		if (!str)
			return (1);
		read_bytes = read(fd, str, BUFFER_SIZE);
		if (read_bytes < 1)
		{
			free(str);
			return (0);
		}
		str[read_bytes] = '\0';
		fill_list(list, str);
	}
	return (0);
}

void	clean_list(t_gnl **list)
{
	t_gnl	*last_node;
	t_gnl	*rest_node;
	char	*str;
	int		i;
	int		j;

	rest_node = malloc(sizeof(t_gnl));
	str = malloc(BUFFER_SIZE + 1);
	if (!str || !rest_node)
	{
		free(rest_node);
		free(str);
		return (ft_lstclear_gnl(list, free));
	}
	last_node = ft_lstlast_gnl(*list);
	i = 0;
	j = 0;
	while (last_node->str_buf[i] && last_node->str_buf[i] != '\n')
		i++;
	while (last_node->str_buf[i] && last_node->str_buf[++i])
		str[j++] = last_node->str_buf[i];
	str[j] = '\0';
	rest_node->str_buf = str;
	rest_node->next = NULL;
	clear_mem(list, rest_node, str);
}

/**
 * The function `get_next_line` reads a line from a file descriptor and
 * returns it as a string.
 * 
 * @param fd The parameter "fd" is an integer representing the file descriptor
 * of the file you want to read from.
 * 
 * @return a pointer to a character, which represents the next line read from
 * the file descriptor specified by `fd`.
 */
char	*get_next_line(int fd)
{
	static t_gnl	*list;
	char			*str;
	int				len_str;
	int				flag;

	if (fd < 0 || read(fd, &str, 0) < 0 || BUFFER_SIZE < 1)
		return (ft_lstclear_gnl(&list, free), NULL);
	flag = init_list(&list, fd);
	if (list == NULL || flag == 1)
		return (ft_lstclear_gnl(&list, free), NULL);
	len_str = count_chars(list);
	str = malloc(len_str + 1);
	if (!str)
		return (ft_lstclear_gnl(&list, free), NULL);
	my_strcpy(str, list);
	clean_list(&list);
	return (str);
}

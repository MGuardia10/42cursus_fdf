/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:50:49 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/13 14:50:51 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	clear_mem(t_gnl **list, t_gnl *rest_node, char *str)
{
	t_gnl	*aux;

	if (*list == NULL)
		return ;
	while (*list)
	{
		aux = (*list)->next;
		free((*list)->str_buf);
		free(*list);
		*list = aux;
	}
	*list = NULL;
	if (rest_node->str_buf[0])
		*list = rest_node;
	else
	{
		free(str);
		free(rest_node);
	}
}

int	count_chars(t_gnl *list)
{
	int	count;
	int	i;

	count = 0;
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
			{
				count++;
				return (count);
			}
			i++;
			count++;
		}
		list = list->next;
	}
	return (count);
}

void	my_strcpy(char *str, t_gnl *list)
{
	int	i;
	int	j;

	j = 0;
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
			{
				str[j] = '\n';
				str[++j] = '\0';
				return ;
			}
			str[j] = list->str_buf[i];
			i++;
			j++;
		}
		list = list->next;
	}
	str[j] = '\0';
}

int	find_new_line(t_gnl *list)
{
	int	i;

	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str_buf[i] && i < BUFFER_SIZE)
		{
			if (list->str_buf[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

void	fill_list(t_gnl **list, char *str)
{
	t_gnl	*last_node;
	t_gnl	*new_node;

	last_node = ft_lstlast_gnl(*list);
	new_node = malloc(sizeof(t_gnl));
	if (new_node == NULL)
	{
		free(str);
		return ;
	}
	if (!last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_buf = str;
	new_node->next = NULL;
}

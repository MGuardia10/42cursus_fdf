/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:38:06 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/10 10:22:55 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * The function `ft_lstiter` iterates through a linked list and applies a given
 * function to each element.
 * 
 * @param lst A pointer to the first node of a linked list.
 * @param f The parameter `f` is a function pointer that points to a function
 * that takes a `void*` parameter and returns `void`.
 * 
 * @return nothing, as indicated by the return type "void".
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

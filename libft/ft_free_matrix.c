/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:52:12 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/18 11:18:17 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The function `ft_free_matrix` frees the memory allocated for a matrix of
 * strings.
 * 
 * @param p The parameter `p` is a pointer to a pointer to a character, which
 * represents a matrix or a 2D array of characters.
 */
void	ft_free_matrix(char **p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:52:12 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/28 09:19:16 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The function `ft_free_matrix` frees the memory allocated for a matrix.
 * 
 * @param p The parameter "p" is a pointer to a pointer. It is assumed to be
 * pointing to the first element of a dynamically allocated matrix (2D array)
 * of pointers. Each element of the matrix is assumed to be a pointer to
 * dynamically allocated memory.
 */
void	ft_free_matrix(void **p)
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

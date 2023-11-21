/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:59:51 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/18 11:17:45 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The function ft_error writes "Error" to the standard error output and exits
 * with a failure status.
 */
void	ft_error(void)
{
	write(STDERR, "Error\n", 6);
	exit(EXIT_FAILURE);
}

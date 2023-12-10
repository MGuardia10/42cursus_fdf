/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:58:45 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/10 20:27:03 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/strings.h"

int	terminate_program(t_all *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	ft_printf(GOOD_BYE);
	exit(EXIT_SUCCESS);
}

void	malloc_err(t_all *data)
{
	if (data->mlx && data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	ft_printf(MALLOC_ERR);
	exit(EXIT_FAILURE);
}

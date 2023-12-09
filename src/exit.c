/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:58:45 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/09 12:13:39 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/strings.h"

int	destroy_window(t_all *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	ft_free_matrix((void **)data->fdf);
	ft_printf(GOOD_BYE);
	exit(EXIT_SUCCESS);
}

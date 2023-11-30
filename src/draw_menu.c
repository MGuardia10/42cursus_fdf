/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:03:20 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/30 17:13:08 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_menu(t_all *data)
{
	int	spc_y;

	spc_y = 30;
	mlx_string_put(data->mlx, data->mlx_win, 50, spc_y, TEXT_COLOR, MENU_TITLE);
	spc_y += 30;
	mlx_string_put(data->mlx, data->mlx_win, 50, spc_y, TEXT_COLOR, MENU_1);
	spc_y += 10;
	mlx_string_put(data->mlx, data->mlx_win, 50, spc_y, TEXT_COLOR, MENU_2);
	spc_y += 10;
	mlx_string_put(data->mlx, data->mlx_win, 50, spc_y, TEXT_COLOR, MENU_3);
	spc_y += 10;
	mlx_string_put(data->mlx, data->mlx_win, 50, spc_y, TEXT_COLOR, MENU_4);
	spc_y += 10;
	mlx_string_put(data->mlx, data->mlx_win, 50, spc_y, TEXT_COLOR, MENU_5);
	spc_y += 10;
	mlx_string_put(data->mlx, data->mlx_win, 50, spc_y, TEXT_COLOR, MENU_6);
	spc_y += 10;
	mlx_string_put(data->mlx, data->mlx_win, 50, spc_y, TEXT_COLOR, MENU_7);
	spc_y += 10;
	mlx_string_put(data->mlx, data->mlx_win, 50, spc_y, TEXT_COLOR, MENU_8);
	spc_y += 10;
	mlx_string_put(data->mlx, data->mlx_win, 50, spc_y, TEXT_COLOR, MENU_9);
}
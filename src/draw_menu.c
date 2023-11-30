/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:03:20 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/30 20:13:33 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	draw_map_info(t_all *data, int x, int *y)
{
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT_COLOR, MAP_INFO);
	*y += 30;
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT_COLOR, MAP_NAME);
	mlx_string_put(data->mlx, data->mlx_win, x + 100, *y, TEXT_COLOR, data->map.name);
	*y += 25;
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT_COLOR, X_MAX);
	mlx_string_put(data->mlx, data->mlx_win, x + 100, *y, TEXT_COLOR, "10");
	*y += 25;
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT_COLOR, Y_MAX);
	mlx_string_put(data->mlx, data->mlx_win, x + 100, *y, TEXT_COLOR, "5000");
	*y += 25;
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT_COLOR, Z_MAX);
	mlx_string_put(data->mlx, data->mlx_win, x + 100, *y, TEXT_COLOR, "400");	
}

static void	draw_controls(t_all *data, int x, int *y)
{
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT_COLOR, CONTROL_INFO);
	*y += 30;
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT_COLOR, PROYECTION);
	if (data->map.proyection == ISO)
		mlx_string_put(data->mlx, data->mlx_win, x + 100, *y, TEXT_COLOR, \
						"Isometric");
	else
		mlx_string_put(data->mlx, data->mlx_win, x + 100, *y, TEXT_COLOR, \
						"Parallel");
	*y += 25;
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT_COLOR, ZOOM);
	mlx_string_put(data->mlx, data->mlx_win, x + 100, *y, TEXT_COLOR, \
						"Zoom in / out");
	*y += 25;
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT_COLOR, MOVE);
	mlx_string_put(data->mlx, data->mlx_win, x + 100, *y, TEXT_COLOR, "Move model");
	*y += 25;
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT_COLOR, ROTATE);
	mlx_string_put(data->mlx, data->mlx_win, x + 100, *y, TEXT_COLOR, "Rotate model");	
}

static void	draw_colors(t_all *data, int x, int *y)
{
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT_COLOR, COLOR_THEMES);
	*y += 30;
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT_COLOR, DEFAULT_THEME);
	mlx_string_put(data->mlx, data->mlx_win, x + 100, *y, TEXT_COLOR, \
						"Default");
	*y += 25;
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT_COLOR, B_AND_W_THEME);
	mlx_string_put(data->mlx, data->mlx_win, x + 100, *y, TEXT_COLOR, \
						"Black & White");
	*y += 25;
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT_COLOR, PARTY_THEME);
	mlx_string_put(data->mlx, data->mlx_win, x + 100, *y, TEXT_COLOR, "Party");
}

void	draw_menu(t_all *data)
{
	int	x;
	int	y;

	// hacer itoa
	x = 30;
	y = 30;
	draw_map_info(data, x, &y);
	y += 50;
	draw_controls(data, x, &y);
	y += 50;
	draw_colors(data, x, &y);
	// mlx_string_put(data->mlx, data->mlx_win, x, y, TEXT_COLOR, CONTROL_INFO);
	// y += 25;
	// mlx_string_put(data->mlx, data->mlx_win, x, y, TEXT_COLOR, PROYECTION);
	// mlx_string_put(data->mlx, data->mlx_win, 30, y, TEXT_COLOR, "Parallel / Isometric");
}
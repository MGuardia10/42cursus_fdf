/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:03:20 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/01 12:11:03 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//proteger bien los mallocs!!!!!!!
static void	draw_map_info2(t_all *data, int x, int *y)
{
	char	*str;

	str = ft_itoa(data->map.max_z);
	if (!str)
		return ;
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT, Z_MAX);
	mlx_string_put(data->mlx, data->mlx_win, x + 90, *y, TEXT, str);
	*y += 25;
	free(str);
	str = ft_itoa(data->map.min_z);
	if (!str)
		return ;
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT, Z_MIN);
	mlx_string_put(data->mlx, data->mlx_win, x + 90, *y, TEXT, str);
	free(str);
}

static void	draw_map_info1(t_all *data, int x, int *y)
{
	char	*str;

	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT, MAP_NAME);
	mlx_string_put(data->mlx, data->mlx_win, x + 90, *y, TEXT, data->map.name);
	*y += 25;
	str = ft_itoa(data->map.max_x);
	if (!str)
		return ;
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT, X_MAX);
	mlx_string_put(data->mlx, data->mlx_win, x + 90, *y, TEXT, str);
	free(str);
	*y += 25;
	str = ft_itoa(data->map.max_y);
	if (!str)
		return ;
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT, Y_MAX);
	mlx_string_put(data->mlx, data->mlx_win, x + 90, *y, TEXT, str);
	free(str);
	*y += 25;
	draw_map_info2(data, x, y);
}

static void	draw_controls(t_all *data, int x, int *y)
{
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT, PROYECTION);
	if (data->map.proyection == ISO)
		mlx_string_put(data->mlx, data->mlx_win, x + 90, *y, TEXT, "Isometric");
	else
		mlx_string_put(data->mlx, data->mlx_win, x + 90, *y, TEXT, "Parallel");
	*y += 25;
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT, ZOOM);
	mlx_string_put(data->mlx, data->mlx_win, x + 90, *y, TEXT, "Zoom in / out");
	*y += 25;
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT, MOVE);
	mlx_string_put(data->mlx, data->mlx_win, x + 90, *y, TEXT, "Move model");
	*y += 25;
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT, ROTATE);
	mlx_string_put(data->mlx, data->mlx_win, x + 90, *y, TEXT, "Rotate model");
}

static void	draw_colors(t_all *data, int x, int *y)
{
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT, DEFAULT_THEME);
	mlx_string_put(data->mlx, data->mlx_win, x + 90, *y, TEXT, \
						"Default");
	*y += 25;
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT, B_AND_W_THEME);
	mlx_string_put(data->mlx, data->mlx_win, x + 90, *y, TEXT, \
						"Black & White");
	*y += 25;
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT, PARTY_THEME);
	mlx_string_put(data->mlx, data->mlx_win, x + 90, *y, TEXT, "Party");
}

void	draw_menu(t_all *data)
{
	int	x;
	int	y;

	x = 30;
	y = 30;
	mlx_string_put(data->mlx, data->mlx_win, x, y, TEXT, MAP_INFO);
	y += 30;
	draw_map_info1(data, x, &y);
	y += 50;
	mlx_string_put(data->mlx, data->mlx_win, x, y, TEXT, CONTROL_INFO);
	y += 30;
	draw_controls(data, x, &y);
	y += 50;
	mlx_string_put(data->mlx, data->mlx_win, x, y, TEXT, COLOR_THEMES);
	y += 30;
	draw_colors(data, x, &y);
}

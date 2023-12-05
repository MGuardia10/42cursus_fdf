/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:03:20 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/05 10:01:13 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//proteger bien los mallocs!!!!!!!
static void	draw_title(t_all *data, int x, int *y)
{
		mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT, TITLE1);
		*y += 25;
		mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT, TITLE2);
		*y += 25;
		mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT, TITLE3);
		*y += 50;
}
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
	mlx_string_put(data->mlx, data->mlx_win, x + 90, *y, TEXT2, data->map.name);
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

static void	draw_proyections(t_all *data, int x, int *y)
{
	if (data->map.proyection == ISO)
	{
		mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT, PROYECTION_1);
		mlx_string_put(data->mlx, data->mlx_win, x + 90, *y, TEXT2, "Isometric");
		*y += 25;
		mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT, PROYECTION_2);
		mlx_string_put(data->mlx, data->mlx_win, x + 90, *y, TEXT, "Parallel");
	}
	else
	{
		mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT, PROYECTION_1);
		mlx_string_put(data->mlx, data->mlx_win, x + 90, *y, TEXT, "Isometric");
		*y += 25;
		mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT, PROYECTION_2);
		mlx_string_put(data->mlx, data->mlx_win, x + 90, *y, TEXT2, "Parallel");
	}
}

void	draw_menu(t_all *data)
{
	int	x;
	int	y;

	x = 30;
	y = 30;
	draw_title(data, x, &y);
	mlx_string_put(data->mlx, data->mlx_win, x, y, TEXT, MAP_INFO);
	y += 30;
	draw_map_info1(data, x, &y);
	y += 60;
	mlx_string_put(data->mlx, data->mlx_win, x, y, TEXT, PROYECTION);
	y += 30;
	draw_proyections(data, x, &y);
	y += 60;
	mlx_string_put(data->mlx, data->mlx_win, x, y, TEXT, COLOR_THEMES);
	y += 30;
	draw_colors(data, x, &y);
	y += 60;
	mlx_string_put(data->mlx, data->mlx_win, x, y, TEXT, CONTROL_INFO);
	y += 30;
	draw_controls(data, x, &y);
}

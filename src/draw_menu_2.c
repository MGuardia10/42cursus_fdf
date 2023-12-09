/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:58:04 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/09 11:05:53 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/strings.h"
#include "../includes/color.h"

void	draw_colors(t_all *data, int x, int *y)
{
	t_theme	color_theme;

	color_theme = data->map.color_theme;
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT, DEFAULT_THEME);
	if (color_theme == DEFAULT)
		mlx_string_put(data->mlx, data->mlx_win, x + 75, *y, TEXT2, "Default");
	else
		mlx_string_put(data->mlx, data->mlx_win, x + 75, *y, TEXT, "Default");
	*y += 25;
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT, INVERT_THEME);
	if (color_theme == INVERT)
		mlx_string_put(data->mlx, data->mlx_win, x + 75, *y, TEXT2, "Invert");
	else
		mlx_string_put(data->mlx, data->mlx_win, x + 75, *y, TEXT, "Invert");
	*y += 25;
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT, BETIS_THEME);
	if (color_theme == LAND)
		mlx_string_put(data->mlx, data->mlx_win, x + 75, *y, TEXT2, "Land");
	else
		mlx_string_put(data->mlx, data->mlx_win, x + 75, *y, TEXT, "Land");
}

void	draw_controls(t_all *data, int x, int *y)
{
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT, ZOOM);
	*y += 25;
	mlx_string_put(data->mlx, data->mlx_win, x + 25, *y, TEXT, ZOOM_1);
	*y += 25;
	mlx_string_put(data->mlx, data->mlx_win, x + 25, *y, TEXT, ZOOM_2);
	*y += 25;
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT, MOVE);
	*y += 25;
	mlx_string_put(data->mlx, data->mlx_win, x + 25, *y, TEXT, MOVE_1);
	*y += 25;
	mlx_string_put(data->mlx, data->mlx_win, x + 25, *y, TEXT, MOVE_2);
}

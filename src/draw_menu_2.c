/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:58:04 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/05 10:42:17 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_colors(t_all *data, int x, int *y)
{
	t_theme	color_theme;

	color_theme = data->map.color_theme;
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT, DEFAULT_THEME);
	if (color_theme == DEFAULT)
		mlx_string_put(data->mlx, data->mlx_win, x + 90, *y, TEXT2, "Default");
	else
		mlx_string_put(data->mlx, data->mlx_win, x + 90, *y, TEXT, "Default");
	*y += 25;
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT, SPAIN_THEME);
	if (color_theme == SPAIN)
		mlx_string_put(data->mlx, data->mlx_win, x + 90, *y, TEXT2, "Spain");
	else
		mlx_string_put(data->mlx, data->mlx_win, x + 90, *y, TEXT, "Spain");
	*y += 25;
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT, PARTY_THEME);
	if (color_theme == PARTY)
		mlx_string_put(data->mlx, data->mlx_win, x + 90, *y, TEXT2, "Party");
	else
		mlx_string_put(data->mlx, data->mlx_win, x + 90, *y, TEXT, "Party");
}

void	draw_controls(t_all *data, int x, int *y)
{
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT, ZOOM);
	mlx_string_put(data->mlx, data->mlx_win, x + 90, *y, TEXT, "Zoom in/out");
	*y += 25;
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT, MOVE);
	mlx_string_put(data->mlx, data->mlx_win, x + 90, *y, TEXT, "Move model");
	*y += 25;
	mlx_string_put(data->mlx, data->mlx_win, x, *y, TEXT, ROTATE);
	mlx_string_put(data->mlx, data->mlx_win, x + 90, *y, TEXT, "Rotate model");
}
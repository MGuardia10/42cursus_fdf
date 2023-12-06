/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_controls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:23:50 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/06 11:35:41 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	zoom(int keycode, t_all *data)
{
	if (keycode == KEY_SUM || keycode == KEY_SUM2 || keycode == SCROLL_DOWN)
	{
		if (data->map.zoom == 100)
			return ;
		if (data->map.zoom == 24 && data->map.max_x > 200)
			return ;
		data->map.zoom += 2;
	}
	if (keycode == KEY_RES || keycode == KEY_RES2 || keycode == SCROLL_UP)
	{
		if (data->map.zoom == 2)
			return ;
		data->map.zoom -= 2;
	}
	draw(data);
}

void	move_model_key(int keycode, t_all *data)
{
	if (keycode == KEY_LEFT)
		data->map.init_x -= 20;
	else if (keycode == KEY_RIGHT)
		data->map.init_x += 20;
	else if (keycode == KEY_UP)
		data->map.init_y -= 20;
	else if (keycode == KEY_DOWN)
		data->map.init_y += 20;
	draw(data);
}

void	change_proyection(int keycode, t_all *data)
{
	if (keycode == KEY_P)
	{
		if (data->map.proyection == PARALLEL)
			return ;
		data->map.proyection = PARALLEL;
	}
	if (keycode == KEY_I)
	{
		if (data->map.proyection == ISO)
			return ;
		data->map.proyection = ISO;
	}
	draw(data);
}

void	change_theme_color(int keycode, t_all *data)
{
	if (keycode == KEY_1 || keycode == KEY_1_SIDE)
	{
		if (data->map.color_theme == DEFAULT)
			return ;
		data->map.color_theme = DEFAULT;
	}
	if (keycode == KEY_2 || keycode == KEY_2_SIDE)
	{
		if (data->map.color_theme == INVERT)
			return ;
		data->map.color_theme = INVERT;
	}
	if (keycode == KEY_3 || keycode == KEY_3_SIDE)
	{
		if (data->map.color_theme == BETIS)
			return ;
		data->map.color_theme = BETIS;
	}
	draw(data);
}

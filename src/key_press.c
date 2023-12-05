/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:10:51 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/05 12:34:01 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_bool	is_key_zoom(int keycode)
{
	return (keycode == KEY_SUM || keycode == KEY_SUM2 || keycode == KEY_RES || \
				keycode == KEY_RES2);
}
void	zoom(int keycode, t_all *data)
{
	if (keycode == KEY_SUM || keycode == KEY_SUM2)
		data->map.zoom += 1;
	if (keycode == KEY_RES || keycode == KEY_RES2)
	{
		if (data->map.zoom == 2)
			return ;
		data->map.zoom -= 1;
	}
	draw(data);
}

t_bool	is_key_move(int keycode)
{
	return (keycode == KEY_LEFT || keycode == KEY_RIGHT || \
			keycode == KEY_UP || keycode == KEY_DOWN);
}

void	move_model(int keycode, t_all *data)
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


t_bool	is_key_proyection(int keycode)
{
	return (keycode == KEY_P || keycode == KEY_I);
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

t_bool	is_key_theme(int keycode)
{
	return (keycode == KEY_1 || keycode == KEY_1_SIDE || keycode == KEY_2 || \
			keycode == KEY_2_SIDE || keycode == KEY_3 || keycode == KEY_3_SIDE);
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
		if (data->map.color_theme == SPAIN)
			return ;
		data->map.color_theme = SPAIN;
	}
	if (keycode == KEY_3 || keycode == KEY_3_SIDE)
	{
		if (data->map.color_theme == PARTY)
			return ;
		data->map.color_theme = PARTY;
	}
	draw(data);
}

int	key_press(int keycode, t_all *data)
{
	if (keycode == KEY_ESC)
		destroy_window(data);
	if (is_key_zoom(keycode) == true)
		zoom(keycode, data);
	if (is_key_move(keycode) == true)
		move_model(keycode, data);
	if (is_key_proyection(keycode) == true)
		change_proyection(keycode, data);
	if (is_key_theme(keycode) == true)
		change_theme_color(keycode, data);
	printf("press --> %d\n", keycode);
	return (0);
}

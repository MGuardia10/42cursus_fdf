/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:10:51 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/07 21:41:19 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/keyboard_keycodes.h"

static t_bool	is_key_zoom(int keycode)
{
	return (keycode == KEY_SUM || keycode == KEY_SUM2 || keycode == KEY_RES || \
				keycode == KEY_RES2);
}

static t_bool	is_key_move(int keycode)
{
	return (keycode == KEY_LEFT || keycode == KEY_RIGHT || \
			keycode == KEY_UP || keycode == KEY_DOWN);
}

static t_bool	is_key_proyection(int keycode)
{
	return (keycode == KEY_P || keycode == KEY_I);
}

static t_bool	is_key_theme(int keycode)
{
	return (keycode == KEY_1 || keycode == KEY_1_SIDE || keycode == KEY_2 || \
			keycode == KEY_2_SIDE || keycode == KEY_3 || keycode == KEY_3_SIDE);
}

int	key_press(int keycode, t_all *data)
{
	if (keycode == KEY_ESC)
		destroy_window(data);
	if (is_key_zoom(keycode) == true)
		zoom(keycode, data);
	if (is_key_move(keycode) == true)
		move_model_key(keycode, data);
	if (is_key_proyection(keycode) == true)
		change_proyection(keycode, data);
	if (is_key_theme(keycode) == true)
		change_theme_color(keycode, data);
	return (0);
}

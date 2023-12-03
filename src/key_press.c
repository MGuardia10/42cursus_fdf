/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:10:51 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/03 19:40:26 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_bool	is_arrow(int keycode)
{
	return (keycode == KEY_LEFT || keycode == KEY_RIGHT || \
			keycode == KEY_UP || keycode == KEY_DOWN);
}

void	move_model(int keycode, t_all *data)
{
	if (keycode == KEY_LEFT)
		data->map.init_x -= 10;
	else if (keycode == KEY_RIGHT)
		data->map.init_x += 10;
	else if (keycode == KEY_UP)
		data->map.init_y -= 10;
	else if (keycode == KEY_DOWN)
		data->map.init_y += 10;
	draw(data);
}

int	key_press(int keycode, t_all *data)
{
	(void)data;
	if (keycode == KEY_ESC)
		destroy_window(data);
	if (is_arrow(keycode) == true)
		move_model(keycode, data);
	printf("press --> %d\n", keycode);
	return (0);
}

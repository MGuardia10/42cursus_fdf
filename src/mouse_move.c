/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:28:28 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/05 21:11:24 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	move_model_mouse(int x, int y, t_all *data)
{
	if (x > data->mouse.mouse_x)
		data->map.init_x = data->map.init_x + x - data->mouse.mouse_x;
	else if (x < data->mouse.mouse_x)
		data->map.init_x = data->map.init_x + x - data->mouse.mouse_x;
	if (y > data->mouse.mouse_y)
		data->map.init_y = data->map.init_y + y - data->mouse.mouse_y;
	else if (y < data->mouse.mouse_y)
		data->map.init_y = data->map.init_y + y - data->mouse.mouse_y;
	data->mouse.mouse_x = x;
	data->mouse.mouse_y = y;
	draw(data);
}

int	mouse_move(int x, int y, t_all *data)
{
	if (data->mouse.left_click == true)
		move_model_mouse(x, y , data);
	return (0);
}

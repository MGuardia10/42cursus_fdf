/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:11:06 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/10 18:59:18 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/mouse_keycodes.h"

static t_bool	is_scroll(int button)
{
	return (button == SCROLL_UP || button == SCROLL_DOWN);
}

static void	set_move_coords(int x, int y, t_all *data)
{
	if (x < 0 || y < 0)
		return ;
	data->mouse.left_click = true;
	data->mouse.mouse_x = x;
	data->mouse.mouse_y = y;
}

int	mouse_press(int button, int x, int y, t_all *data)
{
	if (is_scroll(button) == true)
		zoom(button, data);
	else if (button == LEFT_CLICK)
		set_move_coords(x, y, data);
	return (0);
}

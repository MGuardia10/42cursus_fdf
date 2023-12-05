/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:45:15 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/05 20:48:25 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_background(t_all *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if(x < MENU_WIDTH)
				my_mlx_pixel_put(data, x, y, MENU_COLOR);
			else
				my_mlx_pixel_put(data, x, y, BG_COLOR);
			x++;
		}
		y++;
	}
}

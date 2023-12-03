/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:45:15 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/03 20:52:16 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_background(t_all *data)
{
	int	*image;
	int	i;

	ft_bzero(data->addr, WIDTH * HEIGHT * (data->bits_per_pixel / 8));
	image = (int *)(data->addr);
	i = 0;
	while (i < HEIGHT * WIDTH)
	{
		image[i] = (i % WIDTH < MENU_WIDTH) ? MENU_COLOR : BG_COLOR;
		i++;
	}

	// int	x;
	// int	y;

	// y = 0;
	// while (y < HEIGHT)
	// {
	// 	x = 0;
	// 	while (x < WIDTH)
	// 	{
	// 		if(x < MENU_WIDTH)
	// 			my_mlx_pixel_put(data, x, y, MENU_COLOR);
	// 		else
	// 			my_mlx_pixel_put(data, x, y, BG_COLOR);
	// 		x++;
	// 	}
	// 	y++;
	// }
}


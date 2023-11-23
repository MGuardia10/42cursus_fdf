/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:03:47 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/23 16:24:03 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char **argv)
{
	// void		*mlx;
	// void		*mlx_win;
	t_coords	**fdf;
	// t_data		img;

	// Verify args && create array
	ft_parse_args(argc, argv, fdf);


	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "FDF - mguardia");
	// img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// mlx_loop(mlx);

	
	return (0);
}

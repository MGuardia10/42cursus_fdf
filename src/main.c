/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:03:47 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/27 18:38:49 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// void	create_window(t_all all)
// {
// 	all.mlx = mlx_init();
// 	all.mlx_win = mlx_new_window(all.mlx, WIDTH, HEIGHT, "FDF - mguardia"); // revisar width & height
// 	all.img = mlx_new_image(mlx, WIDTH, HEIGHT);
// 	all.addr = mlx_get_data_addr(all.img, &all.bits_per_pixel, &all.line_length,
// 								&all.endian);
// 	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
// 	mlx_put_image_to_window(all.mlx, all.mlx_win, all.img, 0, 0);
// 	mlx_loop(mlx);
// }

int	main(int argc, char **argv)
{
	t_all		all;

	ft_bzero(&all, sizeof(t_all));
	// Verify args && create array
	ft_parse_args(argc, argv, &all);
	// create_window(all);


	
	return (0);
}

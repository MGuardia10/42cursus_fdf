/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:03:47 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/28 13:02:25 by mguardia         ###   ########.fr       */
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

void	leaks(void)
{
	system("leaks -q fdf");
}

void	print_arr(t_all *all)
{
	int	x;
	int	y;

	y = 0;
	while (y < all->max_height)
	{
		x = 0;
		while (x < all->max_width)
		{
			printf("%3d", all->fdf[y][x].z);
			x++;
		}
		printf("\n"),
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_all		all;

	atexit(leaks);
	ft_bzero(&all, sizeof(t_all));
	ft_parse_args(argc, argv, &all);
	// create_window(all);
	print_arr(&all);
	ft_free_matrix((void **)all.fdf);
	return (0);
}

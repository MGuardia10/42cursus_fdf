/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:03:47 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/28 16:58:04 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	deal_key(int keycode, t_all *all)
{
	(void)all;
	printf("%d\n", keycode);
	return (0);
}
int	deal_mouse(int button, int x, int y, t_all *all)
{
	(void)all;
	(void)x;
	(void)y;
	printf("%d\n", button);
	return (0);
}

void	create_window(t_all all)
{
	all.mlx = mlx_init();
	all.mlx_win = mlx_new_window(all.mlx, WIDTH, HEIGHT, "FDF - mguardia"); // revisar width & height
	all.img = mlx_new_image(all.mlx, WIDTH, HEIGHT);
	all.addr = mlx_get_data_addr(all.img, &all.bits_per_pixel, &all.line_length,
								&all.endian);
	mlx_put_image_to_window(all.mlx, all.mlx_win, all.img, 0, 0);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_key_hook(all.mlx_win, deal_key, &all);
	mlx_mouse_hook(all.mlx_win, deal_mouse, &all);
	mlx_loop(all.mlx);
}

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
	create_window(all);
	// print_arr(&all);
	// ft_free_matrix((void **)all.fdf);
	return (0);
}

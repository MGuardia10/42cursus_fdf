/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:03:47 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/05 12:32:34 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	destroy_window(t_all *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	ft_free_matrix((void **)data->fdf);
	exit(EXIT_SUCCESS);
}

// void	leaks(void)
// {
// 	system("leaks -q fdf");
// }

void	print_arr(t_all *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.max_y)
	{
		x = 0;
		while (x < data->map.max_x)
		{
			printf("%3d", data->fdf[y][x].z);
			x++;
		}
		printf("\n"),
		y++;
	}
}

static void	init_data(t_all *data)
{
	ft_bzero(data, sizeof(t_all));
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, TITLE);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
								&data->line_length, &data->endian);
	data->map.max_z = INT_MIN;
	data->map.min_z = INT_MAX;
	data->map.zoom = 10;
	data->map.proyection = ISO;
	data->map.color_theme = DEFAULT;
}

int	main(int argc, char **argv)
{
	t_all		data;

	// atexit(leaks);
	printf("macro -> %d\n", WHITE);
	printf("macro -> %d\n", RED);
	printf("macro -> %d\n", BG_COLOR);
	printf("macro -> %d\n", MENU_COLOR);
	init_data(&data);
	parse_args(argc, argv, &data);
	// print_arr(&data);
	draw(&data);
	mlx_hook(data.mlx_win, ON_KEYDOWN, 1L<<0, key_press, &data);
	mlx_hook(data.mlx_win, ON_KEYUP, 1L<<1, key_release, &data);
	mlx_hook(data.mlx_win, ON_MOUSEDOWN, 1L<<2, mouse_press, &data);
	mlx_hook(data.mlx_win, ON_MOUSEUP, 1L<<3, mouse_release, &data);
	mlx_hook(data.mlx_win, ON_MOUSEMOVE, 1L<<13, mouse_move, &data);
	mlx_hook(data.mlx_win, ON_DESTROY, 1L << 17, destroy_window, &data);
	mlx_loop(data.mlx);
	return (0);
}

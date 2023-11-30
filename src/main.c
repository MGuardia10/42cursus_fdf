/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:03:47 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/30 09:58:42 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	deal_key(int keycode, t_all *data)
{
	(void)data;
	// codigos
	// - scape --> 53
	// - flecha hacia izq --> 123
	// - flecha hacia drcha --> 124
	// - flecha hacia abajo --> 125
	// - flecha hacia arriba --> 126
	// - w (hacia arriba) --> 13
	// - s (hacia abajo) --> 1
	// - a (hacia izq) --> 0
	// - d (hacia drcha) --> 2
	// - 1 (cambiar colores)--> 18 / 83
	// - 2 (cambiar colores)--> 19 / 84
	// - 3 (cambiar colores)--> 20 / 85
	// - p (cambiar proyeccion (iso/2d)) --> 35
	printf("%d\n", keycode);
	return (0);
}
int	deal_mouse(int button, int x, int y, t_all *data)
{
	(void)data;
	(void)x;
	(void)y;
	// codigos
	// - ruedita hacia arriba --> 5
	// - ruedita hacia abajo -->  4
	printf("%d\n", button);
	return (0);
}

void	leaks(void)
{
	system("leaks -q fdf");
}

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

void	init_data(t_all *data)
{
	ft_bzero(data, sizeof(t_all));
	data->win_width = WIDTH;
	data->win_height = HEIGHT;
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->win_width, data->win_height,
								TITLE);
	data->img = mlx_new_image(data->mlx, data->win_width, data->win_height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, 
								&data->line_length, &data->endian);
	data->map.max_z = INT_MIN;
	data->map.zoom = 20;
	data->map.proyection = ISO;
	data->map.color_theme = DEFAULT;
}

int	main(int argc, char **argv)
{
	t_all		data;

	atexit(leaks);
	init_data(&data);
	ft_parse_args(argc, argv, &data);
	print_arr(&data);
	// ft_free_matrix((void **)data.fdf);

	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_key_hook(data.mlx_win, deal_key, &data);
	mlx_mouse_hook(data.mlx_win, deal_mouse, &data);
	mlx_loop(data.mlx);
	return (0);
}

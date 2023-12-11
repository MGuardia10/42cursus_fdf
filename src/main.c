/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:03:47 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/11 14:14:28 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/strings.h"

// void	leaks(void)
// {
// 	system("leaks -q fdf");
// }
	// atexit(leaks);

static void	init_data(t_all *data)
{
	ft_bzero(data, sizeof(t_all));
	data->mlx = mlx_init();
	if (!data->mlx)
		return (malloc_err(data));
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, TITLE);
	if (!data->mlx_win)
		return (malloc_err(data));
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		return (malloc_err(data));
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
								&data->line_length, &data->endian);
	data->map.max_z = INT_MIN;
	data->map.min_z = INT_MAX;
	data->map.zoom = 10;
	data->map.proyection = ISO;
	data->map.color_theme = DEFAULT;
	data->map.curr_colors = ft_calloc(2, sizeof(t_color));
	if (!data->map.curr_colors)
		return (malloc_err(data));
}

int	main(int argc, char **argv)
{
	t_all		data;

	init_data(&data);
	parse_args(argc, argv, &data);
	ft_printf(LOADING_UI);
	draw(&data);
	mlx_hook(data.mlx_win, ON_MOUSEMOVE, 1L << 13, mouse_move, &data);
	mlx_hook(data.mlx_win, ON_MOUSEDOWN, 1L << 2, mouse_press, &data);
	mlx_hook(data.mlx_win, ON_MOUSEUP, 1L << 3, mouse_release, &data);
	mlx_hook(data.mlx_win, ON_KEYDOWN, 1L << 0, key_press, &data);
	mlx_hook(data.mlx_win, ON_DESTROY, 1L << 17, terminate_program, &data);
	mlx_loop(data.mlx);
	return (0);
}

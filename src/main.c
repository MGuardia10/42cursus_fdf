/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:03:47 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/07 22:03:46 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/strings.h"

int	destroy_window(t_all *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	ft_free_matrix((void **)data->fdf);
	ft_printf(GOOD_BYE);
	exit(EXIT_SUCCESS);
}

// void	leaks(void)
// {
// 	system("leaks -q fdf");
// }

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
	data->map.zoom = 6;
	data->map.proyection = ISO;
	data->map.color_theme = DEFAULT;
	data->map.curr_colors = ft_calloc(2, sizeof(t_color));
}

void	parse_args(int argc, char **argv, t_all *data)
{
	int		i;

	check_args(argc, argv);
	get_dimensions(argv[1], data);
	data->fdf = ft_calloc(data->map.max_y + 1, sizeof(t_point));
	i = 0;
	while (i < data->map.max_y)
	{
		data->fdf[i] = ft_calloc(data->map.max_x + 1, sizeof(t_point));
		i++;
	}
	data->fdf[i] = NULL;
	parse_map(argv[1], data);
	ft_printf(PARSING_OK);
	ft_printf(LOADING_UI);
}

void	draw(t_all *data)
{
	float	coords[2];

	draw_background(data);
	coords[1] = 0;
	while (coords[1] < data->map.max_y)
	{
		coords[0] = 0;
		while (coords[0] < data->map.max_x)
		{
			if (coords[0] < data->map.max_x - 1)
				bresenham(coords, coords[0] + 1, coords[1], data);
			if (coords[1] < data->map.max_y - 1)
				bresenham(coords, coords[0], coords[1] + 1, data);
			coords[0]++;
		}
		coords[1]++;
	}
	put_last_pixel(--coords[0], --coords[1], data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	draw_menu(data);
}

int	main(int argc, char **argv)
{
	t_all		data;

	// atexit(leaks);
	init_data(&data);
	parse_args(argc, argv, &data);
	draw(&data);
	mlx_hook(data.mlx_win, ON_MOUSEMOVE, 1L << 13, mouse_move, &data);
	mlx_hook(data.mlx_win, ON_MOUSEDOWN, 1L << 2, mouse_press, &data);
	mlx_hook(data.mlx_win, ON_MOUSEUP, 1L << 3, mouse_release, &data);
	mlx_hook(data.mlx_win, ON_KEYDOWN, 1L << 0, key_press, &data);
	mlx_hook(data.mlx_win, ON_DESTROY, 1L << 17, destroy_window, &data);
	mlx_loop(data.mlx);
	return (0);
}

/* TODO
	- rotaciones
	- norminette
	- tema betis eje z ?
	- proteger bien los mallocs & leaks
	- ordenar libft
	- .o en archivo a parte
	- poner regla fclean en minilibx
	- silenciar warnings minilibx OK
*/
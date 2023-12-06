/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:06:12 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/06 14:10:40 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	check_args(int argc, char **argv)
{
	if (argc < 2)
		ft_custom_error(ARG_ERR_1);
	else if (argc > 2)
		ft_custom_error(ARG_ERR_2);
	else if (ft_is_format(argv[1], ".fdf") == false)
		ft_custom_error(FORMAT_ERR);
	else if (ft_is_readable(argv[1]) == false)
		ft_custom_error(READ_ERR);
	ft_printf("Map file ✅\n");
	ft_printf("Parsing map...\n");
}

static void	get_dimensions(char *file, t_all *data)
{
	int		fd;
	char	*line;
	char	**split;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return ;
	split = ft_split(line, ' ');
	data->map.max_x = ft_count_words(split);
	ft_free_matrix((void **)split);
	while (line)
	{
		data->map.max_y += 1;
		free(line);
		line = get_next_line(fd);
	}
	data->map.init_x = ((WIDTH / 2 + MENU_WIDTH)) - ((data->map.max_x - data->map.max_y) * sin(0.8) * data->map.zoom);
	data->map.init_y = (HEIGHT / 2) - ((data->map.max_y));
	// printf("max_x -> %d\n", data->map.max_x); (*x - *y) * cos(0.8);
	// printf("max_y -> %d\n", data->map.max_y);
	close(fd);
}

void	get_z_values(int x, int y, int z_value, t_all *data)
{
	data->fdf[y][x].z = z_value;
	if (z_value > data->map.max_z)
		data->map.max_z = z_value;
	if (z_value < data->map.min_z)
		data->map.min_z = z_value;
}

static void	create_matrix(t_all *data, int x, int y, char *z)
{
	char	**split;

	data->fdf[y][x].x = x;
	data->fdf[y][x].y = y;
	split = ft_split(z, ',');
	get_z_values(x , y, ft_atoi(split[0]), data);
	if (split[1])
		data->fdf[y][x].default_color = ft_strtol(split[1], 16);
	else if (data->fdf[y][x].z == 0)
		data->fdf[y][x].default_color = TURQUOISE;
	else if (data->fdf[y][x].z < 0)
		data->fdf[y][x].default_color = YELLOW;
	else
		data->fdf[y][x].default_color = PINK;
	data->fdf[y][x].invert_color = invert_color(data->fdf[y][x].default_color);
	data->fdf[y][x].betis_color = GREEN_BETIS;
	ft_free_matrix((void **)split);
}

static void	parse_map(char *file, t_all *data)
{
	int		fd;
	int		x;
	int		y;
	char	*line;
	char	**split;

	get_map_name(file, data);
	fd = open(file, O_RDONLY);
	y = 0;
	while (y < data->map.max_y)
	{
		x = 0;
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		while (x < data->map.max_x)
		{
			create_matrix(data, x, y, split[x]);
			x++;
		}
		free(line);
		ft_free_matrix((void **)split);
		y++;
	}
	close(fd);
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
	ft_printf("Map parsing ✅\n");
	ft_printf("Loading User Interface...\n");
}

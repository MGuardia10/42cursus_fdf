/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:06:12 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/10 20:52:05 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/strings.h"
#include "../includes/color.h"

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
	ft_printf(MAP_FILE_OK);
	ft_printf(PARSING);
}

static void	get_dimensions(char *file, t_all *data)
{
	int		fd;
	char	*line;
	char	**split;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	split = ft_split(line, ' ');
	if (!line || !split)
		return (malloc_err(data));
	data->map.max_x = ft_count_words(split);
	ft_free_matrix((void **)split);
	while (line)
	{
		data->map.max_y += 1;
		free(line);
		line = get_next_line(fd);
	}
	data->map.init_x = ((WIDTH / 2 + MENU_WIDTH)) - \
					((data->map.max_x / 2) * sin(0.8) * data->map.zoom);
	data->map.init_y = (HEIGHT / 2) - ((data->map.max_y * data->map.zoom) / 2);
	close(fd);
}

static void	set_point_params(t_all *data, int x, int y, char *z)
{
	char	**split;

	split = ft_split(z, ',');
	if (!split)
		return (malloc_err(data));
	get_z_values(x, y, ft_atoi(split[0]), data);
	if (split[1])
		data->fdf[y][x].default_color.rgb = ft_strtol(split[1], 16);
	else if (data->fdf[y][x].z == 0)
		data->fdf[y][x].default_color.rgb = TURQUOISE;
	else if (data->fdf[y][x].z < 0)
		data->fdf[y][x].default_color.rgb = YELLOW;
	else
		data->fdf[y][x].default_color.rgb = PINK;
	set_rgb_color(&data->fdf[y][x].default_color);
	set_invert_color(&data->fdf[y][x].default_color, \
								&data->fdf[y][x].invert_color);
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
	y = -1;
	while (++y < data->map.max_y)
	{
		x = 0;
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		if (!line ||!split)
			return (malloc_err(data));
		while (x < data->map.max_x)
		{
			set_point_params(data, x, y, split[x]);
			x++;
		}
		free(line);
		ft_free_matrix((void **)split);
	}
	close(fd);
}

void	parse_args(int argc, char **argv, t_all *data)
{
	int		x;
	int		y;

	check_args(argc, argv);
	get_dimensions(argv[1], data);
	data->fdf = ft_calloc(data->map.max_y + 1, sizeof(t_point));
	if (!data->fdf)
		return (malloc_err(data));
	y = -1;
	while (++y < data->map.max_y)
	{
		data->fdf[y] = ft_calloc(data->map.max_x + 1, sizeof(t_point));
		if (!data->fdf[y])
			return (malloc_err(data));
	}
	data->fdf[y] = NULL;
	parse_map(argv[1], data);
	y = -1;
	while (++y < data->map.max_y)
	{
		x = 0;
		while (x < data->map.max_x)
			set_land_color(data->map.max_z, &data->fdf[y][x++]);
	}
	ft_printf(PARSING_OK);
}

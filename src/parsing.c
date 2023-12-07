/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:06:12 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/07 14:58:20 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	check_args(int argc, char **argv)
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

void	get_dimensions(char *file, t_all *data)
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
	data->map.init_x = ((WIDTH / 2 + MENU_WIDTH)) - \
					((data->map.max_x / 2) * sin(0.8) * data->map.zoom);
	data->map.init_y = (HEIGHT / 2) - ((data->map.max_y * data->map.zoom) / 2);
	close(fd);
}

static void	get_z_values(int x, int y, int z_value, t_all *data)
{
	data->fdf[y][x].z = z_value;
	if (z_value > data->map.max_z)
		data->map.max_z = z_value;
	if (z_value < data->map.min_z)
		data->map.min_z = z_value;
}

static void	set_point_params(t_all *data, int x, int y, char *z)
{
	char	**split;

	split = ft_split(z, ',');
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
	set_betis_color(data, x, y);
	ft_free_matrix((void **)split);
}

void	parse_map(char *file, t_all *data)
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
			set_point_params(data, x, y, split[x]);
			x++;
		}
		free(line);
		ft_free_matrix((void **)split);
		y++;
	}
	close(fd);
}

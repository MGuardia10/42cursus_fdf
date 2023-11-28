/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:06:12 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/28 11:10:48 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	check_args(int argc, char **argv)
{
	if (argc < 2)
		ft_custom_error("A map is required.\n\n\tUsage: ./fdf <map>\n\n");
	else if (argc > 2)
		ft_custom_error("Only 1 map is required.\n\n\tUsage: ./fdf <map>\n\n");
	else if (check_format(argv[1], ".fdf") == 0)
		ft_custom_error("A map in format *.fdf is required.\n");
	else if (check_is_readable(argv[1]) == 0)
		ft_custom_error("The map cannot be read. Check path.\n");
}

int	ft_count_words(char **split)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (split[i] && ft_isprint(split[i][0]))
	{
		count++;
		i++;
	}
	printf("count --> %d", count);
	return (count);
}

void	get_dimensions(char *file, t_all *all)
{
	int		fd;
	char	*line;
	char	**split;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return ;
	split = ft_split(line, ' ');
	all->max_width = ft_count_words(split);
	ft_free_matrix((void **)split);
	while (line)
	{
		all->max_height += 1;
		free(line);
		line = get_next_line(fd);
	}
	printf("max_width -> %d\n", all->max_width);
	printf("max_height -> %d\n", all->max_height);
	close(fd);
}

void	create_matrix(t_all *all, int x, int y, char *z)
{
	char	**split;

	// coords
	all->fdf[y][x].x = x;
	all->fdf[y][x].y = y;
	split = ft_split(z, ',');
	all->fdf[y][x].z = ft_atoi(split[0]);
	// colors
	if (split[1])
		all->fdf[y][x].color = split[1];
	else
		all->fdf[y][x].color = DEFAULT_COLOR;
	// is last
	if ((all->max_height == (y + 1)) && (all->max_width == (x + 1)))
		all->fdf[y][x].is_last = 1;
	else
		all->fdf[y][x].is_last = 0;
	ft_free_matrix((void **)split);
}

void	parse_map(char *file, t_all *all)
{
	int		fd;
	int		x;
	int		y;
	char	*line;
	char	**split;

	fd = open(file, O_RDONLY);
	y = 0;
	while (y < all->max_height)
	{
		x = 0;
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		while (x < all->max_width)
		{
			create_matrix(all, x, y, split[x]);
			x++;
		}
		free(line);
		ft_free_matrix((void **)split);
		y++;
	}
	close(fd);
}

void	ft_parse_args(int argc, char **argv, t_all *all)
{
	int		i;

	check_args(argc, argv);
	get_dimensions(argv[1], all);
	all->fdf = (t_point **)malloc(sizeof(t_point) * (all->max_height + 1));
	i = 0;
	while (i < all->max_width)
		all->fdf[i++] = (t_point *)malloc(sizeof(t_point) * (all->max_width + 1));
	all->fdf[i] = NULL;
	parse_map(argv[1], all);
}

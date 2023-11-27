/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:06:12 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/27 20:31:52 by mguardia         ###   ########.fr       */
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
	while (split[i])
	{
		count++;
		i++;
	}
	return (count);
}

void	get_dimensions(char *file, t_all *all)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return ;
	all->max_width = ft_count_words(ft_split(line, ' '));
	all->max_height = 1;
	while (line = get_next_line(fd) != NULL)
		all->max_height += 1;
	close(fd);
	// printf("all.width --> %d\n", all->max_width);
	// printf("all.height --> %d", all->max_height);
}

void	ft_parse_args(int argc, char **argv, t_all *all)
{
	t_point	**arr;

	check_args(argc, argv);
	get_dimensions(argv[1], all);
	arr = all->fdf;
	arr = (t_point **)malloc(sizeof(t_point) * (all->max_height + 1));
}

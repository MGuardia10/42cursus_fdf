/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:06:12 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/23 16:36:42 by mguardia         ###   ########.fr       */
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

int	get_height(char *file)
{
	int	fd;
	int	height;

	height = 0;
	fd = open(file, O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
		height++;
	close(fd);
	return (height);
}

int	get_width(char *file)
{
	int		fd;
	int		width;
	char	**split;

	witdh = 0;
	fd = open(file, O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		split = ft_split(line, ' ');
		
		
	}
	close(fd);
	return (height);
}
void	ft_parse_args(int argc, char **argv, t_coords **fdf)
{
	int		fd;
	char	**split;
	int		height;
	int		width;
	// checkear mapa valido
	check_args(argc, argv);
	// leer linea x linea y crear matriz
	//	- leer cols en total para malloc **.
	//  - leer filas para malloc * y inicializar cada struct.
	height = get_height(argv[1]);
	fdf = (t_coords **)malloc(sizeof(t_coords *) * (height + 1));
	width = get_width(argv[1]);
}

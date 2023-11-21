/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:06:12 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/21 16:06:53 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	check_format(char *str, char *format)
{
	int	len_str;
	int	len_format;
	int	i;

	len_str = ft_strlen(str);
	len_format = ft_strlen(format);
	i = 1;
	while (str[len_str - i] && format[len_format - i])
	{
		if (str[len_str - i] != format[len_format - i])
			return (0);
		i++;
	}
	return (1);
}

static int	check_is_readable(char *argv)
{
	int	fd;
	int	flag;

	fd = open(argv, O_RDONLY);
	if (read(fd, 0, 0) < 0)
		flag = 0;
	else
		flag = 1;
	close(fd);
	return (flag);
}

void	ft_parse_args(int argc, char **argv)
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:05:13 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/27 15:31:19 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>

# define WIDTH 1000
# define HEIGHT 1000

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		is_last;
	char	*color;
}			t_point;

typedef struct s_all
{
	int		max_height;
	int		max_width;
	t_point	**fdf;

	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_all;


// Arguments parsing
void	ft_parse_args(int argc, char **argv, t_all *all);

#endif
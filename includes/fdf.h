/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:05:13 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/30 09:57:56 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "keyboard_keycodes.h"
# include "mouse_keycodes.h"
# include "strings.h"
# include "../mlx/mlx.h"
# include <mlx.h>
# include <math.h>

# define WIDTH 1000
# define HEIGHT 1000

# define WHITE "0xFFFFFF"
# define RED "0xFF0000"
# define BLUE "0x0000FF"

typedef enum
{
	ISO,
	PARALLEL
}	t_projection;

typedef enum
{
	DEFAULT,
	PARTY
}	t_theme;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	char	*og_color;
	char	*mod_color;
	t_bool	is_last;
}			t_point;

typedef struct s_map
{
	int				max_x;
	int				max_y;
	int				max_z;

	char			*name;	
	int				zoom;
	t_projection	proyection;
	t_theme			color_theme;
}					t_map;

typedef struct s_all
{
	t_map	map;
	t_point	**fdf;

	int		win_width;
	int		win_height;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_all;


// Arguments parsing
void	ft_parse_args(int argc, char **argv, t_all *data);

// Utils
int		ft_count_words(char **split);
void	get_map_name(char *file, t_all *data);

#endif
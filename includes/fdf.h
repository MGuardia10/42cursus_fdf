/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:05:13 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/01 12:50:23 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "keyboard_keycodes.h"
# include "mouse_keycodes.h"
# include "strings.h"
# include "color.h"
# include "../mlx/mlx.h"
# include <mlx.h>
# include <math.h>

# define WIDTH 1280
# define HEIGHT 720

# define WHITE "0xFFFFFF"
# define RED "0xFF0000"
# define BLUE "0x0000FF"

/* ----------ENUMS--------------- */
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

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};


/* ---------STRUCTS--------------- */
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
	int				min_z;

	char			*name;	
	int				zoom;
	t_projection	proyection;
	t_theme			color_theme;
}					t_map;

typedef struct s_all
{
	t_map	map;
	t_point	**fdf;

	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_all;

/* --------PROTOTYPES------------- */
// Arguments parsing
void	parse_args(int argc, char **argv, t_all *data);

// Event-handler functions
int key_press(int keycode, t_all *data);
int key_release(int keycode, t_all *data);
int mouse_press(int button, int x, int y, t_all *data);
int mouse_release(int button, int x, int y, t_all *data);
int mouse_move(int x, int y, t_all *data);

// Draw functions
void	draw_menu(t_all *data);

// Utils
int		ft_count_words(char **split);
void	get_map_name(char *file, t_all *data);

int	destroy_window(t_all *data);

#endif
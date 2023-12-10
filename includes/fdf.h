/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:05:13 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/10 11:54:35 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"
# include <math.h>

/* ----------MACROS--------------- */
/*--MAC 42--*/
// # define WIDTH			1920
// # define HEIGHT 		1080
// # define MENU_WIDTH		300
/*--portatil--*/
# define WIDTH				1400
# define HEIGHT 			800
# define MENU_WIDTH			300

/* ----------ENUMS--------------- */
typedef enum e_proyection
{
	ISO,
	PARALLEL
}	t_projection;

typedef enum e_theme
{
	DEFAULT,
	INVERT,
	LAND
}	t_theme;

enum
{
	ON_KEYDOWN		= 2,
	ON_KEYUP		= 3,
	ON_MOUSEDOWN	= 4,
	ON_MOUSEUP		= 5,
	ON_MOUSEMOVE	= 6,
	ON_EXPOSE		= 12,
	ON_DESTROY		= 17
};

/* ---------STRUCTS--------------- */
typedef struct s_mouse
{
	int				mouse_x;
	int				mouse_y;
	t_bool			left_click;
}					t_mouse;

typedef struct s_color
{
	int				rgb;
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct s_point
{
	int				z;
	t_color			default_color;
	t_color			invert_color;
	t_color			land_color;
}					t_point;

typedef struct s_map
{
	int				max_x;
	int				max_y;
	int				max_z;
	int				min_z;

	char			*name;
	int				zoom;
	int				init_x;
	int				init_y;
	t_bool			is_line_finish;
	t_color			*curr_colors;
	t_projection	proyection;
	t_theme			color_theme;
}					t_map;

typedef struct s_all
{
	t_mouse			mouse;
	t_point			**fdf;
	t_map			map;

	void			*mlx;
	void			*mlx_win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_all;

/* --------PROTOTYPES------------- */
// parsing
void	parse_args(int argc, char **argv, t_all *data);

// Event-handler functions
int		key_press(int keycode, t_all *data);
int		key_release(int keycode, t_all *data);
int		mouse_press(int button, int x, int y, t_all *data);
int		mouse_release(int button, int x, int y, t_all *data);
int		mouse_move(int x, int y, t_all *data);

// Keypress controls
void	zoom(int keycode, t_all *data);
void	move_model_key(int keycode, t_all *data);
void	change_proyection(int keycode, t_all *data);
void	change_theme_color(int keycode, t_all *data);

// Draw functions
void	draw(t_all *data);
void	draw_menu(t_all *data);
void	draw_colors(t_all *data, int x, int *y);
void	draw_controls(t_all *data, int x, int *y);

// Draw utils
void	my_mlx_pixel_put(t_all *data, int x, int y, int color);
void	set_color(float *fcoords, int x1, int y1, t_all *data);
void	set_zoom(float *fcoords, float *x, float *y, int zoom);
void	isometric(float *x, float *y, t_all *data);
void	put_last_pixel(float x, float y, t_all *data);

// Color functions
void	set_rgb_color(t_color *color);
void	set_invert_color(t_color *def, t_color *invert);
t_color	set_land_color(int max_z, t_point *point);
int		set_gradient(t_color color1, t_color color2, float ratio);
int		add_shade(float transparency, unsigned int color);

// Utils
int		ft_count_words(char **split);
void	get_map_name(char *file, t_all *data);
void	get_z_values(int x, int y, int z_value, t_all *data);
float	get_percentage(int nbr, int min_value, int max_value);
int		ft_max_value(float x, float y);

// exit
int		destroy_window(t_all *data);

#endif
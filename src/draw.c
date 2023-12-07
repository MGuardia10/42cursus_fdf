/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:55:34 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/07 21:21:38 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_properties(float *fcoords, float *x1, float *y1, t_all *data)
{
	set_color(fcoords, (int)*x1, (int)*y1, data);
	set_zoom(fcoords, x1, y1, data->map.zoom);
	set_proyection(fcoords, x1, y1, data);
}

void	print_pixel(float max, float *fcoords, t_color *color, t_all *data)
{
	static float	ratio;
	float			step;
	int				gradient;

	if (data->map.is_line_finish == true)
	{
		ratio = 0;
		data->map.is_line_finish = false;
	}
	gradient = set_gradient(color[0], color[1], ratio);
	step = 1 / max;
	ratio += step;
	if (fcoords[0] + data->map.init_x <= MENU_WIDTH)
		my_mlx_pixel_put(data, fcoords[0] + data->map.init_x, fcoords[1] + \
			data->map.init_y, add_shade(0.9, gradient));
	else
		my_mlx_pixel_put(data, fcoords[0] + data->map.init_x, fcoords[1] + \
			data->map.init_y, gradient);
}

void	bresenham(float *coords, float x1, float y1, t_all *data)
{
	float	*fcoords;
	float	step_x;
	float	step_y;
	int		max;

	fcoords = ft_calloc(2, sizeof(float));
	ft_memcpy(fcoords, coords, 2 * sizeof(float));
	set_properties(fcoords, &x1, &y1, data);
	step_x = x1 - fcoords[0];
	step_y = y1 - fcoords[1];
	max = ft_max_value(fabs(step_x), fabs(step_y));
	step_x /= max;
	step_y /= max;
	while ((int)(fcoords[0] - x1) || (int)(fcoords[1] - y1))
	{
		print_pixel(max, fcoords, data->map.curr_colors, data);
		fcoords[0] += step_x;
		fcoords[1] += step_y;
	}
	data->map.is_line_finish = true;
	free(fcoords);
}

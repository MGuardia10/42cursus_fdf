/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:03:37 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/07 13:05:41 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	add_shade(float transparency, unsigned int color)
{
	unsigned int	t;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	if (transparency > 1)
		transparency = 1;
	else if (transparency < 0)
		transparency = 0;
	t = (unsigned int)(255 * transparency);
	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	return ((t << 24) | (r << 16) | (g << 8) | b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_release.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:12:06 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/07 21:56:38 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/mouse_keycodes.h"

int	mouse_release(int button, int x, int y, t_all *data)
{
	(void)x;
	(void)y;
	if (button == LEFT_CLICK)
		data->mouse.left_click = false;
	return (0);
}

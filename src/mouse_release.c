/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_release.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:12:06 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/01 11:20:09 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	mouse_release(int button, int x, int y, t_all *data)
{
	(void)x;
	(void)y;
	(void)data;
	printf("mouse release --> %d\n", button);
	return (0);
}

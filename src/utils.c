/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:00:01 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/28 13:00:42 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_count_words(char **split)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (split[i] && ft_isprint(split[i][0]))
	{
		count++;
		i++;
	}
	printf("count --> %d\n", count);
	return (count);
}

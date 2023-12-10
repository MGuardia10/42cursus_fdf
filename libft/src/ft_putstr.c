/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:04:08 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/10 10:11:24 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * The ft_putstr function takes a string as input and prints it to the
 * standard output, returning the number of characters printed.
 * 
 * @param str A pointer to a character array (string) that we want to output.
 * 
 * @return the number of characters printed.
 */
int	ft_putstr(char *str)
{
	int	count;

	if (str == NULL)
		str = "(null)";
	count = 0;
	while (str[count])
		count += ft_putchar(str[count]);
	return (count);
}

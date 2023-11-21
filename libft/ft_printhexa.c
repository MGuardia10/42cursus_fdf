/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:41:03 by mguardia          #+#    #+#             */
/*   Updated: 2023/10/23 13:22:56 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printhexa(unsigned int num, int flag)
{
	char	*base;
	int		count;

	if (!flag)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	count = 0;
	if (num < 16)
		count += ft_putchar(base[num]);
	else
	{
		count += ft_printhexa(num / 16, flag);
		count += ft_printhexa(num % 16, flag);
	}
	return (count);
}

int	ft_printhexalong(unsigned long num)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (num < 16)
		count += ft_putchar(base[num]);
	else
	{
		count += ft_printhexalong(num / 16);
		count += ft_printhexalong(num % 16);
	}
	return (count);
}

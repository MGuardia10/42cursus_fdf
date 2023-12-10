/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:15:59 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/10 10:11:12 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putnbr(int n)
{
	long int	num;
	int			count;

	num = n;
	count = 0;
	if (num < 0)
	{
		num *= -1;
		count += ft_putchar('-');
	}
	if (num > 9)
	{
		count += ft_putnbr(num / 10);
		count += ft_putchar((num % 10) + '0');
	}
	else
		count += ft_putchar((num + '0'));
	return (count);
}

int	ft_putnbrunsigned(unsigned int n)
{
	long int	num;
	int			count;

	num = n;
	count = 0;
	if (num > 9)
	{
		count += ft_putnbr(num / 10);
		count += ft_putchar((num % 10) + '0');
	}
	else
		count += ft_putchar((num + '0'));
	return (count);
}

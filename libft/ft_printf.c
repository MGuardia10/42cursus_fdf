/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:23:36 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/18 11:32:27 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	format_printf(char c, va_list ap)
{
	if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_printpointer(va_arg(ap, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_putnbrunsigned(va_arg(ap, unsigned int)));
	else if (c == 'x')
		return (ft_printhexa(va_arg(ap, unsigned int), 0));
	else if (c == 'X')
		return (ft_printhexa(va_arg(ap, unsigned int), 1));
	return (0);
}

/**
 * The ft_printf function takes a string and a variable number of arguments,
 * and prints formatted output based on the format specifiers in the string.
 * 
 * @param str A pointer to a string that contains the format specifier and the
 * text to be printed.
 * 
 * @return an int value, which represents the number of characters printed.
 */
int	ft_printf(char const *str, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += format_printf(*str, ap);
		}
		else
			count += ft_putchar(*str);
		str++;
	}
	va_end(ap);
	return (count);
}

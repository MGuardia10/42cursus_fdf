/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:47:44 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/10 10:11:18 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * The function `ft_putstr_fd` writes a string to a file descriptor.
 * 
 * @param s A pointer to a character array (string) that we want to write to
 * the file descriptor.
 * @param fd The parameter "fd" is an integer representing the file descriptor.
 * It is used to specify the file or output stream where the string "s" will
 * be written to.
 */
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		ft_putchar_fd(s[i++], fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:43:19 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/10 10:09:23 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * The function `ft_isascii` checks if a given character is a valid ASCII
 * character.
 * 
 * @param c The parameter "c" is an integer representing a character.
 * 
 * @return a boolean value indicating whether the given character is an ASCII
 * character or not. It returns 1 if the character is an ASCII character (with
 * ASCII values between 0 and 127), and 0 otherwise.
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

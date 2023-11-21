/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:56:33 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/18 11:30:24 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The function ft_memcpy copies n bytes from the memory area pointed to by src
 * to the memory area pointed to by dst.
 * 
 * @param dst The destination pointer where the copied data will be stored.
 * @param src The `src` parameter is a pointer to the source memory location
 * from where the data will be copied.
 * @param n The parameter `n` represents the number of bytes to be copied from
 * the source memory location (`src`) to the dest memory location (`dst`).
 * 
 * @return a pointer to the destination memory block (dst).
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	if (dst != src)
	{
		while (i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}

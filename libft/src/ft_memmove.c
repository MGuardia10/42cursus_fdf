/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:30:28 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/10 10:10:07 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * The function `ft_memmove` copies a block of memory from source to
 * destination, handling overlapping memory regions correctly.
 * 
 * @param dst The `dst` parameter is a pointer to the destination memory where
 * the copied data will be stored.
 * @param src The `src` parameter is a pointer to the source memory location
 * from where the data will be copied.
 * @param len The parameter "len" represents the number of bytes to be copied
 * from the source memory location to the destination memory location.
 * 
 * @return a void pointer to the destination memory block (dst).
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	const unsigned char	*source;

	if (len == 0 || dst == src)
		return (dst);
	dest = (unsigned char *)dst;
	source = (const unsigned char *)src;
	if (dest > source)
		while (len-- > 0)
			*(dest + len) = *(source + len);
	else
		while (len-- > 0)
			*dest++ = *source++;
	return (dst);
}

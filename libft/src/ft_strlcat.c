/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:59:17 by mguardia          #+#    #+#             */
/*   Updated: 2023/12/10 10:12:27 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * The ft_strlcat function appends a string to another string, ensuring that
 * the resulting string is null-terminated and does not exceed a specified size.
 * 
 * @param dst A pointer to the destination string where the concatenated string
* will be stored.
 * @param src A pointer to the source string that will be concatenated to the
 * destination string.
 * @param dstsize The parameter `dstsize` represents the size of the destination
 * buffer `dst`. It specifies the maximum number of characters that can be
 * written to `dst`, including the null-terminating character.
 * 
 * @return the total length of the string that would have been created if there
 * was enough space in the destination string.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*dstcopy;
	const char	*srccopy;
	size_t		remaining;
	size_t		dstlen;

	dstcopy = dst;
	srccopy = src;
	remaining = dstsize;
	while (remaining-- != 0 && *dstcopy)
		dstcopy++;
	dstlen = dstcopy - dst;
	remaining = dstsize - dstlen;
	if (remaining == 0)
		return (dstlen + ft_strlen(src));
	while (*srccopy)
	{
		if (remaining != 1)
		{
			*dstcopy++ = *srccopy;
			remaining--;
		}
		srccopy++;
	}
	*dstcopy = '\0';
	return (dstlen + (srccopy - src));
}

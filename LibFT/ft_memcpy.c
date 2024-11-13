/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:20:23 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:29:49 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src && n > 0)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

/* Copies 'n' bytes from memory area 'src' to memory area 'dest'.
 *
 * Parameters:
 *  - dest: The destination memory area.
 *  - src: The source memory area.
 *  - n: The number of bytes to copy.
 *
 * Returns:
 *  - A pointer to the destination memory area.
 */
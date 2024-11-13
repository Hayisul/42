/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:05:57 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:30:12 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
	{
		*str = (unsigned char)c;
		str++;
	}
	return (s);
}

/* Writes 'c' to the first 'n' bytes of the memory area 's'.
 *
 * Parameters:
 *  - s: The memory area to be written.
 *  - c: The character to write.
 *  - n: The number of bytes to write.
 *
 * Returns:
 *  - A pointer to the memory area 's'.
 */
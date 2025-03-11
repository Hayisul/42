/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:20:53 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:29:26 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;

	str = (const unsigned char *)s;
	while (n--)
	{
		if (*str == (unsigned char)c)
			return ((void *)str);
		str++;
	}
	return (NULL);
}

/* Locates the first occurrence of 'c' in the first 'n' bytes of the string 's'.
 *
 * Parameters:
 *  - s: The string to be searched.
 *  - c: The character to be located.
 *  - n: The number of bytes to be searched.
 *
 * Returns:
 *  - A pointer to the located byte.
 *  - NULL if 'c' does not occur in the first 'n' bytes.
 */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:46:18 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:46:19 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	len = 0;
	while (src[len])
		len++;
	return (len);
}

/* Copies the string 'src' to 'dest'.
 *
 * Parameters:
 *  - dest: The destination string.
 *  - src: The source string.
 *  - size: The size of the destination buffer.
 *
 * Returns:
 *	- The length of the string
 *  that would have been copied if there was enough space.
 *
 * Behavior:
 *  - The function copies the string 'src' to 'dest'.
 *  - The function will not write more than 'size' bytes to 'dest'.
 *  - The function will always null-terminate 'dest'.
 * 	- The function returns the length of the string
 *  that would have been copied if there was enough space.
 */
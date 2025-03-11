/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:40:05 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:46:25 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	if (!dest && size == 0)
		return (ft_strlen(src));
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (size + src_len);
	i = dest_len;
	j = 0;
	while (src[j] && i < (size - 1))
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest_len + src_len);
}

/* Appends the string 'src' to the end of 'dest'.
 *
 * Parameters:
 *  - dest: The destination string.
 *  - src: The source string.
 *  - size: The size of the destination buffer.
 *
 * Returns:
 *	- The total length of the string
 *  that would have been created if there was enough space.
 *
 * Behavior:
 *  - The function appends the string 'src' to the end of 'dest'.
 *  - The function will not write more than 'size' bytes to 'dest'.
 *  - The function will always null-terminate 'dest'.
 * 	- The function returns the total length of the string
 *  that would have been created if there was enough space.
 */
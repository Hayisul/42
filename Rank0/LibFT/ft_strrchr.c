/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:17:03 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:33:44 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*str;

	str = s;
	while (*str)
		str++;
	if ((unsigned char)c == '\0')
		return ((char *)str);
	while (str-- > s)
		if (*str == (unsigned char)c)
			return ((char *)str);
	return (NULL);
}

/* Locates the last occurrence of 'c' in the string 's'.
 *
 * Parameters:
 *  - s: The string to be searched.
 *  - c: The character to be located.
 *
 * Returns:
 *  - A pointer to the located character.
 *  - NULL if 'c' does not occur in the string.
 *
 * Behavior:
 *  - The function locates the last occurrence of 'c' in 's'.
 *  - The function returns a pointer to the located character.
 */
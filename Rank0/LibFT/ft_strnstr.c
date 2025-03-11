/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:53:50 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:33:36 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;
	size_t	j;

	if (!haystack && len == 0)
		return (NULL);
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && (i + needle_len) <= len)
	{
		j = 0;
		while (needle[j] && needle[j] == haystack[i + j])
			j++;
		if (j == needle_len)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

/* Locates the first occurrence of 'needle' in the string 'haystack'.
 *
 * Parameters:
 *  - haystack: The string to be searched.
 *  - needle: The substring to be located.
 *  - len: The maximum number of characters to search.
 *
 * Returns:
 *  - A pointer to the located substring.
 *  - NULL if 'needle' does not occur in the string.
 *
 * Behavior:
 *  - If 'haystack' is NULL and 'len' is 0, the function returns NULL.
 *  - If 'needle' is an empty string, the function returns 'haystack'.
 *  - The function locates the first occurrence of 'needle' in 'haystack'.
 *  - The function will not search more than 'len' characters.
 */
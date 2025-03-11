/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:33:42 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:45:26 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		str = malloc(1);
		if (str)
			str[0] = '\0';
		return (str);
	}
	if (s_len - start < len)
		len = s_len - start;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

/* Allocates memory for a new string that is a substring of 's'.
 *
 * Parameters:
 *  - s: The string to create the substring from.
 *  - start: The start index of the substring.
 *  - len: The maximum length of the substring.
 *
 * Returns:
 *  - The new string.
 *  - NULL if the allocation fails.
 *
 * Behavior:
 *  - If 's' is NULL, the function returns NULL.
 *  - If 'start' is greater than or equal to the length of 's',
 *  the function returns an empty string.
 *  - If 'len' is greater than the length of the substring,
 *  the function returns a substring of the maximum length.
 *  - The function allocates memory for the new string.
 *  - The function returns the new string.
 */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:04:48 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:33:56 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	len;

	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start] && ft_isinset(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_isinset(s1[end - 1], set))
		end--;
	len = end - start;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start, len + 1);
	str[len] = '\0';
	return (str);
}

/* Allocates memory for a new string that is a copy of 's1' without the characters in 'set'.
 *
 * Parameters:
 *  - s1: The string to be trimmed.
 *  - set: The set of characters to be removed.
 *
 * Returns:
 *  - The new string.
 *  - NULL if the allocation fails.
 *
 * Behavior:
 *  - If 's1' is NULL, the function returns NULL.
 *  - The function calculates the start and end of the new string.
 *  - The function allocates memory for the new string.
 *  - The function copies the characters from 's1' to the new string.
 *  - The function returns a pointer to the new string.
 */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:22:30 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:32:21 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*join;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(s1_len + s2_len + 1);
	if (!str)
		return (NULL);
	join = str;
	while (*s1)
		*join++ = *s1++;
	while (*s2)
		*join++ = *s2++;
	*join = '\0';
	return (str);
}

/* Allocates memory for a new string that is the result of the concatenation of 's1' and 's2'.
 *
 * Parameters:
 *  - s1: The prefix string.
 *  - s2: The suffix string.
 *
 * Returns:
 *  - The new string.
 *  - NULL if the allocation fails.
 *
 * Behavior:
 *  - If both 's1' and 's2' are NULL, the function returns NULL.
 *  - If 's1' is NULL, the function returns a copy of 's2'.
 *  - If 's2' is NULL, the function returns a copy of 's1'.
 *  - The function allocates memory for the new string.
 *  - The function concatenates 's1' and 's2' to the new memory area.
 *  - The function returns a pointer to the new string.
 */
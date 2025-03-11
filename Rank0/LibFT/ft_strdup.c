/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:47:54 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:32:00 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*dup;
	size_t	len;

	len = ft_strlen(s);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	dup = str;
	while (*s)
		*dup++ = *s++;
	*dup = '\0';
	return (str);
}

/* Allocates sufficient memory for a copy of the string 's'.
 *
 * Parameters:
 *  - s: The string to be copied.
 *
 * Returns:
 *  - A pointer to the new string.
 *  - NULL if the allocation fails.
 *
 * Behavior:
 *  - The function allocates memory for a copy of the string 's'.
 *  - The function copies the string 's' to the new memory area.
 *  - The function returns a pointer to the new string.
 */
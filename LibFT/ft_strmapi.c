/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:39:18 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:33:12 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;
	size_t			len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[len] = '\0';
	return (str);
}

/* Applies the function 'f' to each character of the string 's'.
 *
 * Parameters:
 *  - s: The string to iterate over.
 *  - f: The address of the function used to iterate over the string.
 *
 * Returns:
 *  - The new string.
 *  - NULL if the allocation fails.
 *
 * Behavior:
 *  - If 's' or 'f' is NULL, the function returns NULL.
 *  - The function allocates memory for the new string.
 *  - The function applies the function 'f' to each character of the string 's'.
 *  - The function returns the new string.
 */
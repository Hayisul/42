/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:13:28 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:31:38 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_substrcnt(char const *s, char c)
{
	int		in_sub;
	size_t	n;

	in_sub = 0;
	n = 0;
	while (*s)
	{
		if (*s == c)
			in_sub = 0;
		else if (!in_sub)
		{
			in_sub = 1;
			n++;
		}
		s++;
	}
	return (n);
}

static char	*ft_substrdup(char const **s, char c)
{
	char const	*start;
	char		*str;
	size_t		len;

	if (!s || !*s)
		return (NULL);
	start = *s;
	while (**s && **s != c)
		(*s)++;
	len = (size_t)(*s - start);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, start, len);
	str[len] = '\0';
	return (str);
}

static char	**ft_freeall(char **str_arr, size_t n)
{
	while (n > 0)
		free(str_arr[--n]);
	free(str_arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str_arr;
	char	**current;

	if (!s)
		return (NULL);
	str_arr = malloc((ft_substrcnt(s, c) + 1) * sizeof(char *));
	if (!str_arr)
		return (NULL);
	current = str_arr;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			*current = ft_substrdup(&s, c);
			if (!*current)
				return (ft_freeall(str_arr, (size_t)(current - str_arr)));
			current++;
		}
	}
	*current = NULL;
	return (str_arr);
}

/* Splits the string 's' using the character 'c' as a delimiter.
 *
 * Parameters:
 *  - s: The string to split.
 *  - c: The delimiter character.
 *
 * Returns:
 *  - An array of strings obtained by splitting 's'.
 *  - NULL if the allocation fails.
 *
 * Behavior:
 *  - The function allocates memory for an array of strings.
 *  - The array is terminated by a NULL pointer.
 *  - The function returns the array of strings.
 */
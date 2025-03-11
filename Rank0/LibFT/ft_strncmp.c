/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:04:28 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:46:08 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		if (*s1 == '\0' || *s2 == '\0')
			break ;
		s1++;
		s2++;
	}
	return (0);
}

/* Compares the first 'n' characters of 's1' and 's2'.
 *
 * Parameters:
 *  - s1: The first string to be compared.
 *  - s2: The second string to be compared.
 *  - n: The maximum number of characters to compare.
 *
 * Returns:
 *  - An integer less than, equal to,
 *  or greater than zero if the first 'n' characters of 's1' are found,
 *  respectively, to be less than, to match,
 *  or be greater than the first 'n' characters of 's2'.
 *
 * Behavior:
 *  - The function compares the first 'n' characters of 's1' and 's2'.
 *  - The comparison is case-sensitive.
 *  - The function returns an integer less than, equal to,
 *  or greater than zero if the first 'n' characters of 's1' are found,
 *  respectively, to be less than, to match,
 *  or be greater than the first 'n' characters of 's2'.
 */
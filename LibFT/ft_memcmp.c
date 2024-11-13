/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:36:00 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:46:56 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}

/* Compares the first 'n' bytes of the memory areas 's1' and 's2'.
 *
 * Parameters:
 *  - s1: The first memory area to be compared.
 *  - s2: The second memory area to be compared.
 *  - n: The number of bytes to be compared.
 *
 * Returns:
 *  - An integer less than, equal to,
 *  or greater than zero if the first 'n' bytes of 's1' are found,
 *  respectively, to be less than, to match,
 *  or be greater than the first 'n' bytes of 's2'.
 */
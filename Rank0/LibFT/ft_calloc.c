/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:19:46 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:47:44 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	else
		ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/* Allocates memory for an array of 'nmemb' elements of 'size' bytes each.
 *
 * Parameters:
 *  - nmemb: The number of elements.
 *  - size: The size of each element.
 *
 * Returns:
 *  - A pointer to the allocated memory.
 *  - NULL if the allocation fails.
 *
 * Behavior:
 *  - The function checks for integer overflow.
 *  - The function allocates memory for an array of 'nmemb' elements
 *  of 'size' bytes each.
 *  - The function writes zeroes to the allocated memory.
 *  - The function returns a pointer to the allocated memory.
 */
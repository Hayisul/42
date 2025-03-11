/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:49:22 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:33:00 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	const char	*str;

	str = s;
	while (*s)
		s++;
	return (s - str);
}

/* Calculates the length of the string 's'.
 *
 * Parameters:
 *  - s: The string to be measured.
 *
 * Returns:
 *  - The length of the string.
 */
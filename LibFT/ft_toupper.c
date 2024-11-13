/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:15:43 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:34:18 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/* Converts a lowercase letter to uppercase.
 *
 * Parameters:
 *  - c: The character to be converted.
 *
 * Returns:
 *  - The uppercase letter.
 *
 * Behavior:
 *  - If 'c' is a lowercase letter, the function returns the uppercase letter.
 *  - Otherwise, the function returns 'c'.
 */
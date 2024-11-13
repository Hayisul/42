/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:29:47 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:34:10 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

/* Converts an uppercase letter to lowercase.
 *
 * Parameters:
 *  - c: The character to be converted.
 *
 * Returns:
 *  - The lowercase letter.
 *
 * Behavior:
 *  - If 'c' is an uppercase letter, the function returns the lowercase letter.
 *  - Otherwise, the function returns 'c'.
 */
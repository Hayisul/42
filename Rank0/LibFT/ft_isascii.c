/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:33:15 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:28:43 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/* Checks if the character is a 7-bit US-ASCII character.
 *
 * Parameters:
 *  - c: The character to be checked.
 *
 * Returns:
 *  - 1 if the character is a 7-bit US-ASCII character.
 *  - 0 otherwise.
 */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:41:40 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:28:56 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/* Checks if the character is a printable character.
 *
 * Parameters:
 *  - c: The character to be checked.
 *
 * Returns:
 *  - 1 if the character is a printable character.
 *  - 0 otherwise.
 */
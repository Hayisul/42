/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:47:36 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:28:37 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

/* Checks if the character is an alphabetic character.
 *
 * Parameters:
 *  - c: The character to be checked.
 *
 * Returns:
 *  - 1 if the character is an alphabetic character.
 *  - 0 otherwise.
 */
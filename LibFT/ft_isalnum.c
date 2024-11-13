/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:02:20 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:28:31 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0'
			&& c <= '9'))
		return (1);
	return (0);
}

/* Checks if the character is an alphanumeric character.
 *
 * Parameters:
 *  - c: The character to be checked.
 *
 * Returns:
 *  - 1 if the character is an alphanumeric character.
 *  - 0 otherwise.
 */
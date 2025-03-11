/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:00:06 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:28:51 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/* Checks if the character is a digit.
 *
 * Parameters:
 *  - c: The character to be checked.
 *
 * Returns:
 *  - 1 if the character is a digit.
 *  - 0 otherwise.
 */
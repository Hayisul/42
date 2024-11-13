/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:26:17 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:47:53 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return (sign * res);
}

/* Converts the initial portion of the string pointed to by 'nptr' to int.
 *
 * Parameters:
 *  - nptr: The string to be converted.
 *
 * Returns:
 *  - The converted integer.
 *
 * Behavior:
 *  - The function skips white-space characters at the beginning of the string.
 *  - The function converts the string to an integer.
 *  - The function stops the conversion at the first character
 *  that is not a digit.
 *  - The function returns the converted integer.
 */
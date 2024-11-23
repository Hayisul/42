/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:05:43 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/16 12:32:37 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putunbr(unsigned int n)
{
	int	len;

	if (n >= 10)
		len += ft_putnbr(n / 10);
	len += ft_putchar((n % 10) + '0');
	return (len);
}

/* Outputs the unsigned integer 'n' to the standard output.
 *
 * Parameters:
 *  - n: The unsigned integer to output.
 *
 * Behavior:
 *  - The function outputs the unsigned integer 'n' to the standard output.
 */
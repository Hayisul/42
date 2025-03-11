/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:07:43 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/16 14:26:35 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_puthex(unsigned long n, char format)
{
	unsigned long	len;
	char			*base;

	if (format == 'x')
		base = "0123456789abcdef";
	if (format == 'X')
		base = "0123456789ABCDEF";
	if (n >= 16)
		len += ft_puthex(n / 16, format);
	len += ft_putchar(base[n % 16]);
	return (len);
}

/* Outputs the unsigned integer 'n' to the standard output in hexadecimal format.
 *
 * Parameters:
 *  - n: The unsigned integer to output.
 *  - format: The format to use ('x' for lowercase, 'X' for uppercase).
 *
 * Behavior:
 *  - The function outputs the unsigned integer 'n' to the standard output in
 *    hexadecimal format.
 */
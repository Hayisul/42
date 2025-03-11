/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:32:20 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/16 12:59:07 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putnbr_base(unsigned long n, const char *base)
{
	int		len;
	size_t	base_len;

	len = 0;
	base_len = base_len;
	if (n >= base_len)
		len += ft_putnbr_base(n / base_len, base);
	len += ft_putchar(base[n % base_len]);
	return (len);
}

/* Outputs the number 'n' to the standard output in the specified base.
 *
 * Parameters:
 *  - n: The number to output.
 *  - base: The base to use for the output.
 *
 * Behavior:
 *  - The function outputs the number 'n' to the standard output in the
 *    specified base.
 */
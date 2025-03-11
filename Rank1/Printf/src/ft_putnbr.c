/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:36:41 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/16 13:21:15 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putnbr(int n)
{
	int		len;
	long	num;

	len = 0;
	num = n;
	if (num < 0)
	{
		len += ft_putchar('-');
		num = -num;
	}
	if (num >= 10)
		len += ft_putnbr(num / 10);
	len += ft_putchar((num % 10) + '0');
	return (len);
}

/* Outputs the integer 'n' to the given file descriptor 'fd'.
 *
 * Parameters:
 *  - n: The integer to output.
 *  - fd: The file descriptor on which to write.
 *
 * Behavior:
 *  - The function outputs the integer 'n' to the file descriptor 'fd'.
 */
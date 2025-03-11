/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:36:41 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:30:35 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd((nb % 10) + '0', fd);
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
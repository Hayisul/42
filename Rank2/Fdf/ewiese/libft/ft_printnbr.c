/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 07:07:23 by ewiese-m          #+#    #+#             */
/*   Updated: 2024/11/10 12:53:29 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_digit(int num)
{
	int	cur;

	cur = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		cur++;
	while (num != 0)
	{
		num /= 10;
		cur++;
	}
	return (cur);
}

static void	ft_printf_itoa(int n, char *buffer, int buffer_size)
{
	long	nl;
	int		len;

	nl = n;
	len = num_digit(n);
	if (buffer_size <= len)
		return ;
	buffer[len] = '\0';
	if (nl == 0)
	{
		buffer[0] = '0';
		return ;
	}
	if (nl < 0)
		nl = -nl;
	while (nl != 0)
	{
		buffer[--len] = (nl % 10) + '0';
		nl /= 10;
	}
	if (n < 0)
		buffer[0] = '-';
}

int	ft_printnbr(int nbr)
{
	char	buffer[12];

	ft_printf_itoa(nbr, buffer, 12);
	return (ft_printstr(buffer));
}

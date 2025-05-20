/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_unsigned.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:39:48 by ewiese-m          #+#    #+#             */
/*   Updated: 2024/11/10 13:49:50 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	fn_num_len(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int n, char *buffer)
{
	int	len;

	len = fn_num_len(n);
	buffer[len] = '\0';
	if (n == 0)
	{
		buffer[0] = '0';
		return (buffer);
	}
	while (n != 0)
	{
		buffer[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (buffer);
}

int	ft_printnbr_unsigned(unsigned int nbr)
{
	char	buffer[11];

	ft_uitoa(nbr, buffer);
	return (ft_printstr(buffer));
}

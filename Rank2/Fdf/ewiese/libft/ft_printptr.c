/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:00:26 by ewiese-m          #+#    #+#             */
/*   Updated: 2024/11/10 14:43:00 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printnbr_hexp(unsigned long nbr)
{
	const char	*hex;
	int			len;

	len = 0;
	if (nbr == 0)
		return (ft_printchar('0'));
	hex = "0123456789abcdef";
	if (nbr >= 16)
		len += ft_printnbr_hexp(nbr / 16);
	len += ft_printchar(hex[nbr % 16]);
	return (len);
}

int	ft_printptr(unsigned long long ptr)
{
	int	len;

	if (!ptr)
	{
		return (write(1, "(nil)", 5));
	}
	len = 0;
	len += ft_printstr("0x");
	len += ft_printnbr_hexp((unsigned long)ptr);
	return (len);
}

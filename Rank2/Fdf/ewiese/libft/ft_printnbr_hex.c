/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 06:59:32 by ewiese-m          #+#    #+#             */
/*   Updated: 2024/11/10 12:53:27 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printnbr_hex(unsigned long nbr, char flag)
{
	const char	*hex;
	int			len;

	len = 0;
	if (nbr == 0)
		return (ft_printchar('0'));
	if (flag == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (nbr >= 16)
		len += ft_printnbr_hex(nbr / 16, flag);
	len += ft_printchar(hex[nbr % 16]);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:12:28 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/16 13:03:40 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(void *ptr)
{
	int				len;
	unsigned long	addr;

	len = 0;
	addr = (unsigned long)ptr;
	if (!ptr)
		return (write(1, "nil", 3));
	len += ft_putstr("x0");
	len += ft_putnbr_base(addr, "0123456789abcdef");
	return (len);
}

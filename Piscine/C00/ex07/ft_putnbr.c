/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 21:19:53 by rantonia          #+#    #+#             */
/*   Updated: 2024/07/26 21:26:25 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_nbr(char *c, int i)
{
	while (i > 0)
	{
		write(1, &c[i - 1], 1);
		i--;
	}
}

void	ft_putnbr(int nb)
{
	long	nbl;
	char	c[10];
	int		i;

	nbl = nb;
	i = 0;
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nbl < 0)
	{
		nbl = -nbl;
		write(1, "-", 1);
	}
	while (nbl)
	{
		c[i] = (nbl % 10) + '0';
		nbl /= 10;
		i++;
	}
	write_nbr(c, i);
}
/*
int	main(void)
{
	ft_putnbr(42);
	write(1, "\n", 1);
	ft_putnbr(0);
	write(1, "\n", 1);
	ft_putnbr(2147483647);
	write(1, "\n", 1);
	ft_putnbr(-2147483648);
	write(1, "\n", 1);
	return (0);
}
*/

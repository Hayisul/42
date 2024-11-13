/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:10:09 by rantonia          #+#    #+#             */
/*   Updated: 2024/07/29 19:41:33 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_nbr(char *c, int i)
{
	while (i > 0)
	{
		write(1, &c[--i], 1);
	}
}

void	ft_putnbr(int nb)
{
	char	buff[12];
	long	nbl;
	int		i;

	nbl = nb;
	i = 0;
	if (nbl == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nbl < 0)
	{
		nbl *= -1;
		write(1, "-", 1);
	}
	while (nbl)
	{
		buff[i++] = (nbl % 10) + '0';
		nbl /= 10;
	}
	write_nbr(buff, i);
}
/*
int	main(int argc, char **argv)
{
	int	num;
	int	i;
	int	sign;

	num = 0;
	i = 0;
	sign = 1;
	if (argc == 2)
	{
		if (argv[1][i] == '-')
		{
			sign = -1;
			i++;
		}
		while (argv[1][i])
		{
			num = num * 10 + (argv[1][i] - '0');
			i++;
		}
		num *= sign;
		ft_putnbr(num);
	}
	else
	{
		write(1, "Invalid Input", 13);
	}
	return (0);
}
*/

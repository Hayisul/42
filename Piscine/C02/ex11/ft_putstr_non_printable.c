/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:13:07 by rantonia          #+#    #+#             */
/*   Updated: 2024/07/28 19:45:59 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_hexa_con(unsigned char c)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	ft_putchar(hexa[c / 16]);
	ft_putchar(hexa[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		if (c < 32 || c > 126)
		{
			ft_putchar('\\');
			ft_hexa_con(c);
		}
		else
		{
			ft_putchar(c);
		}
		i++;
	}
}
/*
int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		ft_putstr_non_printable(argv[1]);
	}
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:53:03 by rantonia          #+#    #+#             */
/*   Updated: 2024/07/29 19:42:10 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *str)
{
	int	size;

	size = ft_strlen(str);
	write(1, str, size);
}
/*
int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_putstr(argv[1]);
	}
	else
	{
		write(1, "Invalid Input", 13);
	}
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:42:10 by rantonia          #+#    #+#             */
/*   Updated: 2024/07/29 15:51:56 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
/*
int	main(int argc, char **argv)
{
#include <stdio.h>

	if (argc == 2)
	{
		printf("String length: %d\n", ft_strlen(argv[1]));
	}
	else
	{
		printf("Invalid Input");
	}
	return (0);
}
*/

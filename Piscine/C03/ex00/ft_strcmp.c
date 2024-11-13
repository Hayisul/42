/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:50:18 by rantonia          #+#    #+#             */
/*   Updated: 2024/07/28 21:44:19 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
/*
int	main(int argc, char **argv)
{
#include <stdio.h>

	int	value;

	if (argc > 1)
	{
		value = ft_strcmp(argv[1], argv[2]);
		printf("%d\n", value);
	}
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 21:58:34 by rantonia          #+#    #+#             */
/*   Updated: 2024/07/28 22:14:50 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] == s2[i] && s1[i] && s2[i])
	{
		i++;
	}
	if (i == n)
	{
		return (0);
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
		value = ft_strncmp(argv[1], argv[2], 7);
		printf("%d\n", value);
	}
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 22:59:40 by rantonia          #+#    #+#             */
/*   Updated: 2024/07/28 23:16:17 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i])
	{
		i++;
	}
	while (src[j] && j < nb)
	{
		dest[i++] = src[j++];
	}
	dest[i] = '\0';
	return (dest);
}
/*
int	main(int argc, char **argv)
{
#include <stdio.h>
#include <string.h>

	char	dest[50];

	if (argc > 2)
	{
		strncpy(dest, argv[1], sizeof(dest) - 1);
		dest[sizeof(dest) - 1] = '\0';
		ft_strncat(dest, argv[2], 10);
		printf("%s\n", dest);
	}
	else
	{
		printf("Error\n");
	}
	return (0);
}
*/

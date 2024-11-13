/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 22:17:16 by rantonia          #+#    #+#             */
/*   Updated: 2024/07/28 22:57:08 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
	{
		i++;
	}
	while (src[j])
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

	char	*dest;
	char	*src;

	if (argc > 2)
	{
		dest = argv[1];
		src = argv[2];
		ft_strcat(dest, src);
		printf("%s\n", dest);
	}
	else
	{
		printf("Error\n");
	}
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:42:00 by rantonia          #+#    #+#             */
/*   Updated: 2024/07/29 15:08:17 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;
	unsigned int	j;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= dest_len)
	{
		return (size + src_len);
	}
	i = dest_len;
	j = 0;
	while (src[j] && i < size - 1)
	{
		dest[i++] = src[j++];
	}
	if (i < size)
	{
		dest[i] = '\0';
	}
	return (dest_len + src_len);
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
		ft_strlcat(dest, argv[2], 10);
		printf("%s\n", dest);
	}
	else
	{
		printf("Error\n");
	}
	return (0);
}
*/

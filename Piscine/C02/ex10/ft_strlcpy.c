/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:24:49 by rantonia          #+#    #+#             */
/*   Updated: 2024/07/24 20:12:40 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;

	src_len = 0;
	while (src[src_len])
	{
		src_len++;
	}
	if (size == 0)
	{
		return (src_len);
	}
	i = 0;
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
	{
		dest[i] = '\0';
	}
	return (src_len);
}
/*
int	main(void)
{
#include <stdio.h>

	char	dest[1];

	ft_strlcpy(dest, "Hello, World!", 1);
	printf("\nString copy: %s\n\n", dest);
	return (0);
}
*/

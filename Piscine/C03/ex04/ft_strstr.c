/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 23:17:46 by rantonia          #+#    #+#             */
/*   Updated: 2024/07/29 13:40:35 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (*to_find == '\0')
	{
		return (str);
	}
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] && str[i + j] == to_find[j])
		{
			j++;
			if (to_find[j] == '\0')
			{
				return (&str[i]);
			}
		}
		i++;
	}
	return (0);
}
/*
int	main(int argc, char **argv)
{
#include <stdio.h>

	char	*str;
	char	*to_find;
	char	*result;

	if (argc != 3)
	{
		printf("Error\n");
	}
	str = argv[1];
	to_find = argv[2];
	result = ft_strstr(str, to_find);
	if (result != NULL)
	{
		printf("Substring: %s\n", result);
	}
	else
	{
		printf("No substring found\n");
	}
	return (0);
}
*/

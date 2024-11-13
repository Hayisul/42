/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:45:46 by rantonia          #+#    #+#             */
/*   Updated: 2024/07/24 14:03:03 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}
/*
int	main(void)
{
#include <stdio.h>

	char	str[] = "GKFHHVUNGD";
	char	*cap_to_low;

	cap_to_low = ft_strlowcase(str);
	printf("%s\n", cap_to_low);
	return (0);
}
*/

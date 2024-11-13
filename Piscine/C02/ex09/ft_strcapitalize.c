/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:08:58 by rantonia          #+#    #+#             */
/*   Updated: 2024/07/24 18:16:21 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;

	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;
	i = 1;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (!(str[i - 1] >= '0' && str[i - 1] <= '9'))
			{
				if (!(str[i - 1] >= 'A' && str[i - 1] <= 'Z'))
				{
					if (!(str[i - 1] >= 'a' && str[i - 1] <= 'z'))
					{
						str[i] -= 32;
					}
				}
			}
		}
		i++;
	}
	return (str);
}
/*
int	main(void)
{
#include <stdio.h>
	
	char	str[] = "aloRs, tu viens ? 42mots treNte-deux; vinGt+et+un";
	char	*capital;

	capital = ft_strcapitalize(str);
	printf("%s\n", capital);
	return (0);
}
*/

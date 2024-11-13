/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 23:16:33 by rantonia          #+#    #+#             */
/*   Updated: 2024/07/24 00:10:10 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
		}
		i++;
	}
	return (str);
}
/*
int	 main(void)
{
#include <stdio.h>

	char	str[] = "hklasfhgiu";
	char	*low_to_cap;
	
	low_to_cap = ft_strupcase(str);
	printf("%s\n", low_to_cap);
	return (0);
}
*/

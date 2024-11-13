/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:10:09 by rantonia          #+#    #+#             */
/*   Updated: 2024/07/23 13:12:26 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		i++;
	}
	return (i);
}
/*
int	main(void)
{
#include <stdio.h>

	char	*s;
	
	s = "Happy Days!";
	printf("\ns length is: %d\n\n", ft_strlen(s));
	return (0);
}
*/

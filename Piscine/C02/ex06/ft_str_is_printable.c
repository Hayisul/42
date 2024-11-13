/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 23:02:00 by rantonia          #+#    #+#             */
/*   Updated: 2024/07/24 19:30:50 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 32 && str[i] <= 126))
		{
			return (0);
		}
		else
		{
			i++;
		}
	}
	return (1);
}
/*
int	main(void)
{
#include <stdio.h>

	char	str[] = "\t";
	int	input_check;

	input_check = ft_str_is_printable(str);
	printf("%d\n", input_check);
	return (0);
}
*/
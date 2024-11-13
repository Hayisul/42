/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:33:08 by rantonia          #+#    #+#             */
/*   Updated: 2024/07/16 22:44:57 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *a / *b;
	*b = temp % *b;
}
/*
int	main(void)
{
#include <stdio.h>

	int a;
	int b;
	
	a = 3;
	b = 0;
	
	if (b)
	{
		printf("\n%d / %d =", a, b);
		ft_ultimate_div_mod(&a, &b);
		printf(" %d with a remainder of %d\n\n", a, b);
	}
	else
	{
		printf("\nDivision by 0 is undefined\n\n");
	}
	return (0);
}
*/

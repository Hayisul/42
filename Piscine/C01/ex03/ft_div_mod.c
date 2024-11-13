/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:36:34 by rantonia          #+#    #+#             */
/*   Updated: 2024/07/20 19:43:02 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int	main(void)
{
#include <stdio.h>

	int a;
	int b;
	int div;
	int mod;

	a = 12;
	b = -3;
	if (b)
	{
		ft_div_mod(a, b, &div, &mod);
		printf("\n%d / %d = %d with a remainder of %d\n\n", a, b, div, mod);
	}
	else
	{
		printf("\nDivision by zero is indefined.\n\n");
	}
	return (0);
}
*/

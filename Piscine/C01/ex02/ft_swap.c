/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:05:51 by rantonia          #+#    #+#             */
/*   Updated: 2024/07/20 19:37:37 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/*
int	main(void)
{
#include <stdio.h>

	int a = 10;
	int b = 42;

	printf("Before swap:\n");
	printf("a points to: %d\n", a);
	printf("b points to: %d\n", b);
	ft_swap(&a, &b);
	printf("After swap:\n");
	printf("a points to: %d\n", a);
	printf("b points to: %d\n", b);
	return (0);
}
*/

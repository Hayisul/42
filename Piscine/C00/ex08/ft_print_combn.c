/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 21:19:34 by rantonia          #+#    #+#             */
/*   Updated: 2024/07/26 21:19:38 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	initialize_arr(char *arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		arr[i] = i + '0';
		i++;
	}
}

void	increment_comb(char *arr, int n)
{
	int	i;
	int	j;

	i = n - 1;
	while (i >= 0)
	{
		if (arr[i] < '9' - (n - 1 - i))
		{
			arr[i]++;
			j = i + 1;
			while (j < n)
			{
				arr[j] = arr[j - 1] + 1;
				j++;
			}
			break ;
		}
		i--;
	}
}

void	ft_print_combn(int n)
{
	char	arr[10];

	if (n <= 0 || n >= 10)
	{
		write(1, "Error", 6);
		return ;
	}
	initialize_arr(arr, n);
	while (1)
	{
		write(1, arr, n);
		if (arr[0] == '9' - n + 1)
		{
			break ;
		}
		write(1, ", ", 2);
		increment_comb(arr, n);
	}
}
/*
int	main()
{
	ft_print_combn(7);
	return 0;
}
*/

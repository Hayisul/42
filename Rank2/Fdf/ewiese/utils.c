/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewiese-m <ewiese-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:47:16 by ewiese-m          #+#    #+#             */
/*   Updated: 2024/12/18 20:09:52 by ewiese-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free(char **to_free)
{
	int	i;

	i = 0;
	while (to_free[i])
		i++;
	while (i >= 0)
	{
		free(to_free[i]);
		i--;
	}
	free(to_free);
}

void	ft_error_exit(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(-1);
}

void	free_matrix(t_mlx **data)
{
	int	rows;

	rows = (*data)->y;
	if ((*data)->arr == NULL)
		return ;
	while (rows >= 0)
	{
		free((*data)->arr[rows]);
		(*data)->arr[rows] = NULL;
		rows--;
	}
	free((*data)->arr);
}

void	free_color(t_mlx **data)
{
	int	rows;

	rows = (*data)->y;
	if ((*data)->color == NULL)
		return ;
	while (rows >= 0)
	{
		free((*data)->color[rows]);
		(*data)->color[rows] = NULL;
		rows--;
	}
	free((*data)->color);
}

int	get_x(char *line)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_split(line, ' ');
	while (tmp[i] != NULL)
		i++;
	ft_free(tmp);
	return (i);
}

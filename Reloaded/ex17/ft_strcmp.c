/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:56:42 by rantonia          #+#    #+#             */
/*   Updated: 2024/10/19 16:34:34 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	while (s2[j] != '\0')
	{
		j++;
	}
	if (i == j)
	{
		return (0);
	}
	else if (i < j)
	{
		return (-1);
	}
	else
	{
		return (1);
	}
}

/*int main(void)
{
	int result;
	char    str1[] = "Hello World!";
	char    str2[] = "Adios Amigos!";

	result = ft_strcmp(str1, str2);
	if (result == 0)
	{
		printf("'%s' and '%s' are equal in length.\n", str1, str2);
	}
	else if (result < 0)
	{
		printf("'%s' is shorter than '%s'.\n", str1, str2);
	}
	else
	{
		printf("'%s' is longer than '%s'.\n", str1, str2);
	}
	return (0);
}*/
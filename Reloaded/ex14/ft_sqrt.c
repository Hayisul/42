/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:08:44 by rantonia          #+#    #+#             */
/*   Updated: 2024/10/19 14:32:03 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>

int ft_sqrt(int nb)
{
    int i;

    i = 0;
    while (i * i <= nb)
    {
        if (i * i == nb)
        {
            return (i);
        }
        i++;
    }
    return (0);
}

/*int main(int argc, char *argv[])
{
    int num;
    int sqrt;

    if (argc != 2)
    {
        printf("Invalid Input\n");
        return 1;
    }
    num = atoi(argv[1]);
    if (num < 0)
    {
        printf("Square root is not defined for negative numbers.\n");
    }
    else
    {
        sqrt = ft_sqrt(num);
        printf("The Square Root of %d is %d\n", num, sqrt);
    }
    return 0;
}*/
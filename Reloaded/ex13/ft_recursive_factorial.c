/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:39:19 by rantonia          #+#    #+#             */
/*   Updated: 2024/10/19 14:07:50 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>

//n! = n * (n - 1)! = n * (n - 1) * (n - 2) * (n - 3) * ...
int ft_recursive_factorial(int nb)
{
    if (nb == 0 || nb == 1)
    {
        return (1);
    }
    return (nb * ft_recursive_factorial(nb - 1));
    /*ft_recursive_factorial(nb) = nb * (nb - 1) * (nb - 2) * ... * ft_recursive_factorial(1)*/
}

/*int main(int argc, char *argv[])
{
    int num;
    int factorial;

    if (argc != 2)
    {
        printf("Invalid Input\n");
        return 1;
    }
    num = atoi(argv[1]);
    if (num < 0)
    {
        printf("Factorial is not defined for negative numbers.\n");
    }
    else
    {
        factorial = ft_recursive_factorial(num);
        printf("The Factorial of %d is %d\n", num, factorial);
    }
    return 0;
}*/
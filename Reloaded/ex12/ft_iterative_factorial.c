/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:30:00 by rantonia          #+#    #+#             */
/*   Updated: 2024/10/19 14:07:28 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>

//n! = n * (n - 1)! = n * (n - 1) * (n - 2) * (n - 3) * ...
int ft_iterative_factorial(int nb)
{
    int factorial;
    int i;

    factorial = 1;
    i = 1;
    {
        while (i <= nb)
        {
            factorial *= i;
            i++;
        }
        return (factorial);
    }
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
        factorial = ft_iterative_factorial(num);
        printf("The Factorial of %d is %d\n", num, factorial);
    }
    return 0;
}*/
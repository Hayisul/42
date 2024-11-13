/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:53:49 by rantonia          #+#    #+#             */
/*   Updated: 2024/10/17 18:28:57 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void    ft_div_mod(int a, int b, int *div, int *mod)
{
    *div = a / b;
    *mod = a % b;
}

/*int main(void)
{
    int x;
    int y;
    int div; //send its address to ft_div_mod to assign value
    int mod; //send its address to ft_div_mod to assign value

    x = 15;
    y = 10;
    printf("x = %d, y = %d\n", x, y);
    ft_div_mod(x, y, &div, &mod);
    printf("%d / %d = %d with a rimainder of %d\n", x, y, div, mod);
    return 0;
}*/
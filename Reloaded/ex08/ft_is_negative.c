/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:48:29 by rantonia          #+#    #+#             */
/*   Updated: 2024/10/17 17:28:03 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_is_negative(int n)
{
    if (n < 0)
    {
        ft_putchar('N');
    }
    else
    {
        ft_putchar('P');
    }
}

/*int	main(void)
{
    ft_is_negative(7);
    ft_is_negative(-276);
    return 0;
}*/
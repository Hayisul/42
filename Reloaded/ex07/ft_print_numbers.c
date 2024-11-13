/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:48:10 by rantonia          #+#    #+#             */
/*   Updated: 2024/10/15 19:48:12 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

void    ft_print_numbers(void)
{
    char    c;

    c = 48;
    while (c >= 48 && c <= 57)
    {
        write(1, &c, 1);
        c++;
    }
}

/*int main(void)
{
    ft_print_numbers();
    return 0;
}*/
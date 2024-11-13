/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:06:36 by rantonia          #+#    #+#             */
/*   Updated: 2024/10/15 19:35:07 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	c;
	
	c = 97;
	while (c >=97 && c <= 122)
	{
		write(1, &c, 1);
		c++;
	}
}

/*int	main(void)
{
	ft_print_alphabet();
	return 0;
}*/
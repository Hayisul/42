/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:40:39 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/16 13:38:13 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

/* Outputs the character 'c' to the standard output.
 *
 * Parameters:
 *  - c: The character to output.
 *
 * Returns:
 *  - The number of bytes written (always 1).
 */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:49:49 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/16 12:52:30 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putstr(const char *s)
{
	int	len;

	if (!s)
		s = "(null)";
	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
	return (len);
}

/* Outputs the string 's' to the standard output.
 *
 * Parameters:
 *  - s: The string to output.
 *
 * Behavior:
 *  - If 's' is NULL, the function outputs "(null)".
 *  - The function outputs the string 's' to the standard output.
 */
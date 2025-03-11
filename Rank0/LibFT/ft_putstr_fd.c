/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:49:49 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:30:40 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		ft_putchar_fd(*s++, fd);
}

/* Outputs the string 's' to the given file descriptor 'fd'.
 *
 * Parameters:
 *  - s: The string to output.
 *  - fd: The file descriptor on which to write.
 *
 * Behavior:
 *  - If 's' is NULL, the function does nothing.
 *  - The function outputs the string 's' to the file descriptor 'fd'.
 */
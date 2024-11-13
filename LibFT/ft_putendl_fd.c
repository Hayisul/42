/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:28:53 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:30:27 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		ft_putchar_fd(*s++, fd);
	ft_putchar_fd('\n', fd);
}

/* Outputs the string 's' to the given file descriptor 'fd' followed by a newline.
 *
 * Parameters:
 *  - s: The string to output.
 *  - fd: The file descriptor on which to write.
 *
 * Behavior:
 *  - If 's' is NULL, the function does nothing.
 *  - The function outputs the string 's' to the file descriptor 'fd'.
 *  - The function then outputs a newline character.
 */
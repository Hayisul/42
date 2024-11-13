/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:40:39 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/13 20:30:19 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* Outputs the character 'c' to the given file descriptor 'fd'.
 *
 * Parameters:
 *  - c: The character to output.
 *  - fd: The file descriptor on which to write.
 */
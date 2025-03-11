/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:25:41 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/16 14:38:50 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parse(const char **format, va_list args)
{
	int	len;

	len = 0;
	if (**format == 'c')
		len += ft_putchar(va_arg(args, char));
	else if (**format == 's')
		len += ft_putstr(va_arg(args, const char *));
	else if (**format == 'p')
		len += ft_putptr(va_arg(args, void *));
	else if (**format == 'd' || **format == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (**format == 'u')
		len += ft_putunbr(va_arg(args, unsigned int));
	else if (**format == 'x' || **format == 'X')
		len += ft_puthex(va_arg(args, unsigned long), **format);
	else if (**format == '%')
		len += ft_putchar('%');
	else
	{
		len += ft_putchar('%');
		len += ft_putchar(**format);
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len += ft_parse(&format, args);
		}
		else
			len += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (len);
}

/* Outputs the formatted string to the standard output.
 *
 * Parameters:
 *  - format: The format string to output.
 *  - ...: The arguments to replace the format specifiers.
 *
 * Behavior:
 *  - The function outputs the formatted string to the standard output.
 *  - The format string can contain format specifiers that are replaced by the
 *    arguments provided.
 *  - The format specifiers are introduced by the '%' character and are followed
 *    by a conversion specifier.
 *  - The conversion specifier can be one of the following:
 *     - 'c': Outputs a character.
 *     - 's': Outputs a string.
 *     - 'p': Outputs a pointer.
 *     - 'd' or 'i': Outputs a decimal integer.
 *     - 'u': Outputs an unsigned decimal integer.
 *     - 'x': Outputs an unsigned integer in hexadecimal format (lowercase).
 *     - 'X': Outputs an unsigned integer in hexadecimal format (uppercase).
 *     - '%': Outputs a '%' character.
 *  - The function returns the number of characters outputted.
 */
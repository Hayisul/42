/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantonia <rantonia@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:34:46 by rantonia          #+#    #+#             */
/*   Updated: 2024/11/16 12:59:15 by rantonia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

/* Function Prototype */
int		ft_printf(const char *format, ...);

/* Utility Functions */
int		ft_putchar(char c);
int		ft_putstr(const char *s);
int		ft_putnbr(int n);
int		ft_putunbr(unsigned int n);
int		ft_puthex(unsigned long n, char format);
int		ft_putptr(void *ptr);
int		ft_putnbr_base(unsigned long n, const char *base);
size_t	ft_strlen(const char *s);

#endif
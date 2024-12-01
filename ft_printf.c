/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:10:40 by toto              #+#    #+#             */
/*   Updated: 2024/12/01 00:21:25 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	size_t	i;
	va_list	arguments;

	va_start(arguments, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i+1] == 's')
				print_string(va_arg(arguments, char *));
			else if (format[i+1] == 'c')
				print_char(va_arg(arguments, int));
			else if (format[i+1] == 'd')
				print_nbr(va_arg(arguments, int));
			else if (format[i+1] == 'i')
				print_nbr(va_arg(arguments, int));
			else if (format[i+1] == 'x')
				print_hex(va_arg(arguments, unsigned long));
			else if (format[i+1] == 'X')
				print_hex_upper(va_arg(arguments, unsigned long));
			else if (format[i+1] == '%')
				print_char('%');
			else if (format[i+1] == 'p')
			{
				print_string("0x");
				print_hex(va_arg(arguments, unsigned long));
			}
			else if (format[i+1] == 'u')
				print_unsigned(va_arg(arguments, long));
			i++;
		}
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	return (0);
}

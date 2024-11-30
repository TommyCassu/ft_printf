/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:10:40 by toto              #+#    #+#             */
/*   Updated: 2024/11/11 01:08:29 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"

int	print_string(char *str)
{
	ft_putstr_fd(str, 1);
	return (0);
}

int	print_char(char c)
{
	write(1, &c, 1);
	return (0);
}
int	print_nbr(int nbr)
{
	ft_putnbr_fd(nbr, 1);
	return (0);
}

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
			if (format[i + 1] == '-')
				flags
			i++;
		}
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	return (0);
}


int	main()
{
	printf("je m'appelle |%-10d|\n", 42);
	ft_printf("je m'appelle %-10d\n", 42);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:10:40 by toto              #+#    #+#             */
/*   Updated: 2024/11/30 23:43:39 by toto             ###   ########.fr       */
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


void	print_hex(unsigned long nb)
{
	char	*hex = "0123456789abcdef";

	if (nb > 16)
		print_hex(nb / 16);
	ft_putchar_fd(hex[nb % 16], 1);
}
void	print_hex_upper(unsigned long nb)
{
	char	*hex = "0123456789ABCDEF";

	if (nb > 16)
		print_hex(nb / 16);
	ft_putchar_fd(hex[nb % 16], 1);
}

void	ft_putnbr_fdd(long n, int fd)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr_fd((nbr / 10), fd);
		ft_putchar_fd((nbr % 10 + '0'), fd);
	}
	else
		ft_putchar_fd(nbr + '0', fd);
}
void	print_unsigned(long nb)
{
	if (nb < 0)
	{
		ft_putnbr_fdd((4294967296  - (-nb)), 1);
	
	}
	ft_putnbr_fdd(nb, 1);
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

int main() {
    char c = 'Z';
    char *s = "Hello, World!";
    void *p = (void *)0xABCDEF12;
    int d = -42;
    int i = 42;
    unsigned int u = 3000000000;
    unsigned int x = 0xDEADBEEF;
    unsigned int X = 0xCAFEBABE;

    printf("Test: %%c=%c, %%s=%s, %%p=%p, %%d=%d, %%i=%i, %%u=%u, %%x=%x, %%X=%X, %%%%=%%\n",
           c, s, p, d, i, u, x, X);
	ft_printf("Test: %%c=%c, %%s=%s, %%p=%p, %%d=%d, %%i=%i, %%u=%u, %%x=%x, %%X=%X, %%%%=%%\n",
           c, s, p, d, i, u, x, X);
    return 0;
}

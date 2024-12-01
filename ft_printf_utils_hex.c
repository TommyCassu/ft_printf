/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 23:44:39 by toto              #+#    #+#             */
/*   Updated: 2024/12/01 00:18:23 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include "./includes/libft.h"

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
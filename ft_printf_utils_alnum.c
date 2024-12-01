/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_alnum.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 23:44:39 by toto              #+#    #+#             */
/*   Updated: 2024/12/01 00:21:30 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include "./includes/libft.h"

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

void	print_unsigned(long nb)
{
	if (nb < 0)
	{
		ft_putnbr_fdd((4294967296  - (-nb)), 1);
	
	}
	ft_putnbr_fdd(nb, 1);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
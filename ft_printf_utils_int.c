/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 23:44:39 by toto              #+#    #+#             */
/*   Updated: 2024/12/03 02:47:51 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include "./includes/libft.h"

int	ft_countdigit(int nb)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		sign = 1;
		nb *= -1;
	}
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i + sign);
}
int	print_nbr(int nbr, size_t *compteur)
{
	(*compteur) += ft_countdigit(nbr);
	ft_putnbr_fd(nbr, 1);
	return (0);
}

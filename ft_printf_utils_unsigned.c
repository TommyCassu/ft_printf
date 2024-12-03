/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_unsigned.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 23:44:39 by toto              #+#    #+#             */
/*   Updated: 2024/12/03 22:43:55 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include "./includes/libft.h"

/* Count the number of digit */
int	ft_countdigit_unsigned(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

/* Write %u a unsigned int */
void	print_unsigned(unsigned int nb, size_t *compteur)
{
	int		len;
	char	*digit;

	if (nb == 0)
	{
		ft_putchar_fd('0', 1);
		(*compteur)++;
		return ;
	}
	len = ft_countdigit_unsigned(nb);
	(*compteur) += len;
	digit = ft_calloc(len + 1, sizeof(char));
	while (len)
	{
		len--;
		digit[len] = (nb % 10) + '0';
		nb /= 10;
	}
	ft_putstr_fd(digit, 1);
	free(digit);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 23:44:39 by toto              #+#    #+#             */
/*   Updated: 2024/12/03 14:28:14 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include "./includes/libft.h"

int	ft_countdigit_hex(unsigned long long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 16;
		i++;
	}
	return (i);
}


void	print_address(unsigned long long nb, size_t *compteur)
{
	int		len;
	char	*digit;
	char	*hex;

	hex = "0123456789abcdef";	
	if (nb == 0)
	{
		ft_putstr_fd("(nil)", 1);
		(*compteur)+= 5;
		return ;
	}
	ft_putstr_fd("0x", 1);
	len = ft_countdigit_hex(nb);
	(*compteur)+= len + 1;
	digit = ft_calloc(len + 1, sizeof(char));
	while (len)
	{
		len--;
		digit[len] = hex[nb % 16];
		nb /= 16;
	}
	ft_putstr_fd(digit, 1);
	(*compteur)++;
	free(digit);
}

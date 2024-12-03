/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_unsigned.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 23:44:39 by toto              #+#    #+#             */
/*   Updated: 2024/12/03 14:37:50 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include "./includes/libft.h"

int	ft_countdigit_unsigned(unsigned long nb)
{
	printf("%ld\n", nb);
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

void	print_unsigned(int nb, size_t *compteur)
{
	int		len;
	char	*digit;
	char	*hex;

	hex = "0123456789";	
	if (nb == 0)
	{
		ft_putstr_fd("(nil)", 1);
		(*compteur)+= 5;
		return ;
	}
	len = ft_countdigit_unsigned(nb);
	(*compteur)+= len + 1;
	digit = ft_calloc(len + 1, sizeof(char));
	while (len)
	{
		len--;
		digit[len] = hex[nb % 10];
		nb /= 10;
	}
	ft_putstr_fd(digit, 1);
	(*compteur)++;
	free(digit);
}
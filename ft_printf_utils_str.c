/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 23:44:39 by toto              #+#    #+#             */
/*   Updated: 2024/12/03 02:48:15 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include "./includes/libft.h"

int	print_string(char *str, size_t *compteur)
{
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	(*compteur) += ft_strlen(str);
	return (0);
}

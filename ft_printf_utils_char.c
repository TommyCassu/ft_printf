/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:27:22 by toto              #+#    #+#             */
/*   Updated: 2024/12/03 22:42:13 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include "./includes/libft.h"

/* Write a charactere */
int	print_char(char c, size_t *compteur)
{
	write(1, &c, 1);
	(*compteur)++;
	return (0);
}

/* Write %x hexadecimal base in lowercase*/

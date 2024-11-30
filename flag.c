/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:02:38 by toto              #+#    #+#             */
/*   Updated: 2024/11/11 01:07:46 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int ft_flags(const char format, size_t i)
{
	size_t k;
	int size;

	k = 0;
	size = ft_atoi(format + (i + 1)));
	while (size > i)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
	return (i);
}
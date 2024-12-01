/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:01:36 by toto              #+#    #+#             */
/*   Updated: 2024/12/01 00:21:36 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>

int	print_string(char *str);
int	print_char(char c);
int	print_nbr(int nbr);
void	print_unsigned(long nb);

void	print_hex(unsigned long nb);
void	print_hex_upper(unsigned long nb);
void	ft_putnbr_fdd(long n, int fd);
void	ft_putchar_fd(char c, int fd);
int	ft_printf(const char *format, ...);

#endif
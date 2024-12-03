/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:01:36 by toto              #+#    #+#             */
/*   Updated: 2024/12/03 03:00:45 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>

int	print_string(char *str, size_t *compteur);
int	print_char(char c, size_t *compteur);
int	print_nbr(int nbr, size_t *compteur);
void	print_hex(void *nb, size_t *compteur);
void	print_hex_upper(void *nb, size_t *compteur);
void	ft_putchar_fd(char c, int fd);
int	ft_printf(const char *format, ...);

#endif
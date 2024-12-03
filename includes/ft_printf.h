/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:01:36 by toto              #+#    #+#             */
/*   Updated: 2024/12/03 22:35:57 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
int		print_string(char *str, size_t *compteur);
int		print_char(char c, size_t *compteur);
int		print_nbr(int nbr, size_t *compteur);
void	print_address(unsigned long long nb, size_t *compteur);
void	print_hex(unsigned int nb, size_t *compteur);
void	print_hex_upper(unsigned int nb, size_t *compteur);
void	print_unsigned(unsigned int nb, size_t *compteur);
//void	print_hex(unsigned long nb, size_t *compteur);

#endif
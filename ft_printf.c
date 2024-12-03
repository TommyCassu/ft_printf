/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:10:40 by toto              #+#    #+#             */
/*   Updated: 2024/12/03 03:11:52 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parsing_flags(va_list arguments, char *format, size_t *compteur, size_t *i)
{
	if (format[*i+1] == 'c')
		print_char(va_arg(arguments, int), compteur);
	else if (format[*i+1] == 's')
		print_string(va_arg(arguments, char *), compteur);
	else if (format[*i+1] == 'd' || format[*i+1] == 'i')
		print_nbr(va_arg(arguments, int), compteur);
	else if (format[*i+1] == '%')
		print_char('%', compteur);
	(*i)++;
	compteur++;
}
int	ft_printf(char const *format, ...)
{
	va_list	arguments;
	size_t	i;
	size_t	compteur;
	
	va_start(arguments, format);
	i = 0;
	compteur = 0;
	while (format[i] != '\0')
	{
		
		if (format[i] == '%')
		{
			parsing_flags(arguments, (char *)format, &compteur, &i);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			compteur++;
		}
		i++;
	}
	return (compteur);
}

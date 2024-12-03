/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:10:40 by toto              #+#    #+#             */
/*   Updated: 2024/12/03 22:45:12 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./includes/libft.h"

/* Check if there is a match with a specification to write the correct result */
void	parsing_flags(va_list arguments, char *format,
			size_t *compteur, size_t *i)
{
	if (format[*i + 1] == 'c')
		print_char(va_arg(arguments, int), compteur);
	else if (format[*i + 1] == 's')
		print_string(va_arg(arguments, char *), compteur);
	else if (format[*i + 1] == 'd' || format[*i + 1] == 'i')
		print_nbr(va_arg(arguments, int), compteur);
	else if (format[*i + 1] == '%')
		print_char('%', compteur);
	else if (format[*i + 1] == 'p')
		print_address((va_arg(arguments, unsigned long long)), compteur);
	else if (format[*i + 1] == 'x')
		print_hex((va_arg(arguments, unsigned int)), compteur);
	else if (format[*i + 1] == 'X')
		print_hex_upper((va_arg(arguments, unsigned int)), compteur);
	else if (format[*i + 1] == 'u')
		print_unsigned((va_arg(arguments, unsigned int)), compteur);
	(*i)++;
	compteur++;
}

/* Main function to fetch all the string and params */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:59:18 by toto              #+#    #+#             */
/*   Updated: 2024/11/10 22:16:45 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_countword(const char *str, char c)
{
	int	i;
	int	inword;
	int	nbword;

	i = 0;
	inword = 0;
	nbword = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			inword = 0;
		else if (str[i] != c && inword == 0)
		{
			inword = 1;
			nbword++;
		}
		i++;
	}
	return (nbword);
}

char	*ft_strcpy(const char *src, char *dest, int debut, int fin)
{
	int	i;

	i = 0;
	while (debut <= fin)
	{
		dest[i] = src[debut];
		i++;
		debut++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_set_string(const char *str, char **result, char c)
{
	int		i;
	int		debut;
	int		fin;
	int		actualword;
	char	*word;

	i = 0;
	actualword = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		debut = i;
		while (str[i] != c && str[i] != '\0')
			i++;
		fin = i - 1;
		if (actualword < ft_countword(str, c))
		{
			word = (char *)malloc(sizeof(char) * (fin - debut + 1) + 1);
			result[actualword] = ft_strcpy(str, word, debut, fin);
			actualword++;
		}
	}
	result[actualword] = 0;
}

char	**ft_split(char const *str, char c)
{
	char	**result;

	result = (char **)malloc(sizeof(char *) * (ft_countword(str, c) + 1));
	ft_set_string(str, result, c);
	return (result);
}
/*
int	main(void)
{
	char	str[] = " toto va al plage a    ";
    
    char **result;
    result = ft_split(str);
    int i;
    i = 0;
    while(result[i] != 0)
    {
        printf("[%s]\n", result[i]);
        free(result[i]);
        i++;
    }
    free(result);
}
*/
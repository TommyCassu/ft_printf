/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:32:22 by tcassu            #+#    #+#             */
/*   Updated: 2024/11/11 00:11:49 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include <unistd.h>
#include "libft.h"

#define OK "\033[0;32mOK\033[0m"
#define KO "\033[0;31mKO\033[0m"


void test_ft_isalpha()
{
    printf("\nft_isalpha:");
    
	printf(" [%s]", (ft_isalpha('z') > 1)? OK : KO);
	printf(" [%s]", (ft_isalpha('a') > 1) ? OK : KO);
	printf(" [%s]", (ft_isalpha('9') == 0) ? OK : KO);
	printf(" [%s]", (ft_isalpha('A') > 1) ? OK : KO);
}

void test_ft_isdigit()
{
    printf("\nft_isdigit:");
    
    printf(" [%s]", (ft_isdigit('H') == 0)? OK : KO);
	printf(" [%s]", (ft_isdigit(' ') == 0)? OK : KO);
	printf(" [%s]", (ft_isdigit('0') > 0) ? OK : KO);
	printf(" [%s]", (ft_isdigit('9') > 0) ? OK : KO);
	printf(" [%s]", (ft_isdigit('!') == 0) ? OK : KO);
}

void test_ft_isalnum()
{
    printf("\nft_isalnum:");
    
    printf(" [%s]", (ft_isalnum('H') > 0)? OK : KO);
	printf(" [%s]", (ft_isalnum('0') > 0) ? OK : KO);
	printf(" [%s]", (ft_isalnum('9') > 0) ? OK : KO);
	printf(" [%s]", (ft_isalnum(47) == 0) ? OK : KO);
}

void test_ft_isascii()
{
    printf("\nft_isascii:");
    
    printf(" [%s]", (ft_isascii('H') == 1)? OK : KO);
	printf(" [%s]", (ft_isascii(128) == 0) ? OK : KO);
	printf(" [%s]", (ft_isascii(56) == 1) ? OK : KO);
	printf(" [%s]", (ft_isascii(0) == 1) ? OK : KO);
}

void test_ft_isprint()
{
    printf("\nft_isprint:");
    
    printf(" [%s]", (ft_isprint(31) == 0)? OK : KO);
	printf(" [%s]", (ft_isprint(32) > 0) ? OK : KO);
	printf(" [%s]", (ft_isprint(127) == 0) ? OK : KO);
	printf(" [%s]", (ft_isprint(126) > 0) ? OK : KO);
}

void test_ft_strlen()
{
    printf("\nft_strlen: ");
    char	s1[] = "Toto";
	char	s2[] = "toto va a la plage";
	char	s3[] = "\n";
	char	s4[] = "";
	
    printf(" [%s]", (ft_strlen(s1) == strlen(s1))? OK : KO);
	printf(" [%s]", (ft_strlen(s2) == strlen(s2)) ? OK : KO);
	printf(" [%s]", (ft_strlen(s3) == strlen(s3)) ? OK : KO);
	printf(" [%s]", (ft_strlen(s4) == strlen(s4)) ? OK : KO);
}

void test_ft_memset()
{
    char str1[20] = "Hello, World!";
    char str2[20] = "Hello, World!";
    char empty1[1] = "";
    char empty2[1] = "";
	
	printf("\nft_memset: ");
	
    printf(" [%s]", (memcmp(ft_memset(str1, '*', 5), memset(str2, '*', 5), sizeof(str1)) == 0) ? OK : KO);
	printf(" [%s]", (memcmp(ft_memset(str1, 'A', sizeof(str1)), memset(str2, 'A', sizeof(str2)), sizeof(str1)) == 0) ? OK : KO);
    printf(" [%s]", (memcmp(ft_memset(str1, '\0', sizeof(str1)), memset(str2, '\0', sizeof(str2)), sizeof(str1)) == 0) ? OK : KO);
    printf(" [%s]", (memcmp(ft_memset(empty1, 'A', sizeof("")) , memset(empty2, 'A', sizeof("")) , sizeof("")) ==0 )? OK : KO);
}

void test_ft_bzero()
{
    char str1[20] = "Hello, World!";
    char str2[20] = "Hello, World!";
    char empty1[20] = "";
    char empty2[20] = "";

    printf("\nft_bzero:  ");
    
    ft_bzero(str1, 5);
    bzero(str2, 5);
    printf(" [%s]", (memcmp(str1, str2, 20) == 0) ? OK : KO);
    
    ft_bzero(str1 + 7, 3);
    bzero(str2 + 7, 3);
    printf(" [%s]", (memcmp(str1, str2, 20) == 0) ? OK : KO);
    
    ft_bzero(str1, (0));
    bzero(str2, (0));
    printf(" [%s]", (memcmp(str1, str2, 20) == 0) ? OK : KO);
    
    ft_bzero(str1, 20);
    bzero(str2, 20);
    printf(" [%s]", (memcmp(empty1, empty2, 20) == 0) ? OK : KO);
}
void test_ft_memcpy()
{
    char src[20] = "Hello, World!";
	char src2[20] = "";
	char dest[23] = "_____________________";
	
	printf("\nft_memcpy: ");
	
    printf(" [%s]", (memcmp(ft_memcpy(dest, src, 0), memcpy(dest, src, 0), sizeof(src)) == 0) ? OK : KO);
	printf(" [%s]", (memcmp(ft_memcpy(dest, src, 2), memcpy(dest, src, 0), sizeof(src)) == 0) ? OK : KO);
    printf(" [%s]", (memcmp(ft_memcpy(dest, src, strlen(src)), memcpy(dest, src, strlen(src)), sizeof(src)) == 0) ? OK : KO);
    printf(" [%s]", (memcmp(ft_memcpy(dest, src2, 0), memcpy(dest, src2, 0), sizeof(src)) ==0 )? OK : KO);
}
void test_ft_memmove()
{
    // Test 1: Déplacement normal
    char str1[] = "Hello, World!";
    char str2[] = "Hello, World!";
    printf("\nft_memmove:");
    ft_memmove(str1 + 7, str1 + 5, 6); // Déplace " World" à "World!"
    memmove(str2 + 7, str2 + 5, 6);     // Même opération avec memmove
    printf(" [%s]", strcmp(str1, str2) == 0 ? OK : KO);
    // Réinitialiser les chaînes pour le prochain test
    strcpy(str1, "Hello, World!");
    strcpy(str2, "Hello, World!");
    // Test 2: Chevauchement (source < destination)
    ft_memmove(str1 + 5, str1 + 7, 6); // Déplace " World" à partir de l'index 5
    memmove(str2 + 5, str2 + 7, 6);     // Même opération avec memmove
    printf(" [%s]", strcmp(str1, str2) == 0 ? OK : KO);
    // Réinitialiser les chaînes pour le prochain test
    strcpy(str1, "Hello, World!");
    strcpy(str2, "Hello, World!");
    // Test 3: Chevauchement (destination < source)
    ft_memmove(str1 + 7, str1 + 5, 6); // Déplace " World" à partir de l'index 5
    memmove(str2 + 7, str2 + 5, 6);     // Même opération avec memmove
    printf(" [%s]", strcmp(str1, str2) == 0 ? OK : KO);
    // Test 4: Taille zéro
    char zero_test1[] = "No change";
    char zero_test2[] = "No change";
    ft_memmove(zero_test1, zero_test2, 0); // Ne doit rien changer
    printf(" [%s]", strcmp(zero_test1, zero_test2) == 0 ? OK : KO);
}
void test_ft_strlcat()
{
    char dest[20];
    const char *src = "World!";
    size_t result;

    printf("\nft_strlcat:");

    // Test 1: Concaténation normale
    strcpy(dest, "Hello ");
    result = ft_strlcat(dest, src, sizeof(dest));
    printf(" [%s]", (result == 12 && strcmp(dest, "Hello World!") == 0) ? OK : KO);

    // Test 2: Destination trop petite
    strcpy(dest, "Hello ");
    result = ft_strlcat(dest, src, 10);
    printf(" [%s]", (result == 12 && strcmp(dest, "Hello Wor") == 0) ? OK : KO);

    // Test 3: Source vide
    strcpy(dest, "Hello ");
    result = ft_strlcat(dest, "", sizeof(dest));
    printf(" [%s]", (result == 6 && strcmp(dest, "Hello ") == 0) ? OK : KO);

    // Test 4: Taille zéro
    strcpy(dest, "Hello ");
    result = ft_strlcat(dest, src, 0);
    printf(" [%s]", (result == 6 && strcmp(dest, "Hello ") == 0) ? OK : KO);
}

void test_ft_strlcpy()
{
    char dest[20];
    const char *src = "Hello, World!";
    size_t result;

    printf("\nft_strlcpy:");
    // Test 1: Copie normale
    result = ft_strlcpy(dest, src, sizeof(dest));
    printf(" [%s]", (result == 13 && strcmp(dest, src) == 0) ? OK : KO);
    // Test 2: Destination trop petite
    result = ft_strlcpy(dest, src, 7);
    printf(" [%s]", (result == 13 && strcmp(dest, "Hello,") == 0) ? OK : KO);
    // Test 3: Taille zéro
    dest[0] = 'A';
    result = ft_strlcpy(dest, src, 0);
    printf(" [%s]", (result == 13 && dest[0] == 'A') ? OK : KO);
    // Test 4: Source vide
    result = ft_strlcpy(dest, "", sizeof(dest));
    printf(" [%s]", (result == 0 && dest[0] == '\0') ? OK : KO);
}
void test_ft_toupper()
{
    printf("\nft_toupper:");
	
    printf(" [%s]", (ft_toupper('c') == 'C')? OK : KO);
	printf(" [%s]", (ft_toupper('E') == 'E') ? OK : KO);
	printf(" [%s]", (ft_toupper('!') == '!') ? OK : KO);
	printf(" [%s]", (ft_toupper('1') == '1') ? OK : KO);
	printf(" [%s]", (ft_toupper('\n') == '\n') ? OK : KO);
}

void test_ft_tolower()
{
    printf("\nft_tolower:");
	
    printf(" [%s]", (ft_tolower('z') == 'z')? OK : KO);
	printf(" [%s]", (ft_tolower('A') == 'a') ? OK : KO);
	printf(" [%s]", (ft_tolower('!') == '!') ? OK : KO);
	printf(" [%s]", (ft_tolower('1') == '1') ? OK : KO);
	printf(" [%s]", (ft_tolower('\n') == '\n') ? OK : KO);
}

void test_ft_strchr()
{
    const char str1[20] = "Hello, World!";
    //const char str2[20] = "Hello, World!";
	printf("\nft_strchr: ");
	
    printf(" [%s]", (ft_strchr(str1, 'W') == strchr(str1, 'W'))? OK : KO);
	printf(" [%s]", (ft_strchr(str1, 'H') == strchr(str1, 'H'))? OK : KO);
	printf(" [%s]", (ft_strchr(str1, 'd') == strchr(str1, 'd'))? OK : KO);
	printf(" [%s]", (ft_strchr(str1, '!') == strchr(str1, '!'))? OK : KO);
}

void test_ft_strrchr()
{
    const char str1[20] = "Hello, World!";
    //const char str2[20] = "Hello, World!";
	printf("\nft_strrchr:");
	
    printf(" [%s]", (ft_strrchr(str1, 'o') == strrchr(str1, 'o'))? OK : KO);
	printf(" [%s]", (ft_strrchr(str1, 'H') == strrchr(str1, 'H'))? OK : KO);
	printf(" [%s]", (ft_strrchr(str1, 'd') == strrchr(str1, 'd'))? OK : KO);
	printf(" [%s]", (ft_strrchr(str1, '!') == strrchr(str1, '!'))? OK : KO);
}

void test_ft_strncmp()
{
    printf("\nft_strncmp:");
    printf(" [%s]", (ft_strncmp("Hello", "Hello", 4) == strncmp("Hello", "Hello", 4)) ? OK : KO);
    printf(" [%s]", (ft_strncmp("Hello", "Hellx", 5) < 0 && strncmp("Hello", "Hellx", 5) < 0) ? OK : KO);
    printf(" [%s]", (ft_strncmp("Hellx", "Hello", 5) > 0 && strncmp("Hellx", "Hello", 5) > 0) ? OK : KO);
    printf(" [%s]", (ft_strncmp("", "", 0) == strncmp("", "", 0)) ? OK : KO);
}

void test_ft_memchr()
{
    const char str[20] = "Hello, World!";
    //const char str2[20] = "Hello, World!";
	printf("\nft_memchr: ");
	
    printf(" [%s]", (ft_memchr(str, 'o', strlen(str)) == memchr(str, 'o', strlen(str))) ? OK : KO);
    printf(" [%s]", (ft_memchr(str, 'z', strlen(str)) == memchr(str, 'z', strlen(str))) ? OK : KO);
    printf(" [%s]", (ft_memchr(str, 'H', strlen(str)) == memchr(str, 'H', strlen(str))) ? OK : KO);
    printf(" [%s]", (ft_memchr(str, '\0', strlen(str)) == memchr(str, '\0', strlen(str))) ? OK : KO);
}

void test_ft_memcmp()
{
    printf("\nft_memcmp: ");
    
    printf(" [%s]", (ft_memcmp("Hello", "Hello", 5) == memcmp("Hello", "Hello", 5)) ? OK : KO);
    printf(" [%s]", (ft_memcmp("Hello", "Hellx", 5) < 0 && memcmp("Hello", "Hellx", 5) < 0) ? OK : KO);
    printf(" [%s]", (ft_memcmp("Hello", "Hel", 4) > 0 && memcmp("Hello", "Hel", 4) > 0) ? OK : KO);
    printf(" [%s]", (ft_memcmp("", "", 0) == memcmp("", "", 0)) ? OK : KO);
}

void test_ft_strnstr()
{
    const char r1[20] = "Hello, World!";
	const char r2[20] = "o";
	const char r3[20] = "ell";
	const char r4[20] = "d!";
	const char r5[20] = "";

	printf("\nft_strnstr:");
    printf(" [%s]", (ft_memcmp(ft_strnstr(r1, r2, ft_strlen(r1)), "o, World!", 10) == 0 )? OK : KO);
	printf(" [%s]", (ft_memcmp(ft_strnstr(r1, r3, ft_strlen(r1)), "ello, World!", 13) == 0 )? OK : KO);
	printf(" [%s]", (ft_memcmp(ft_strnstr(r1, r4, ft_strlen(r1)), "d!", 3) == 0 )? OK : KO);
	printf(" [%s]", (ft_memcmp(ft_strnstr(r1, r5, ft_strlen(r1)), "Hello, World!", 14) == 0 )? OK : KO);
}

void test_ft_atoi()
{
	char	test1[] = " -123abc";
	char	test2[] = "2147483647";
	char	test3[] = "-2147483648";
	char	test4[] = "   +42";
    printf("\nft_atoi:   ");
    
	printf(" [%s]", (ft_atoi(test1) == atoi(test1)) ? OK : KO);
	printf(" [%s]", (ft_atoi(test2) == atoi(test2)) ? OK : KO);
	printf(" [%s]", (ft_atoi(test3) == atoi(test3)) ? OK : KO);
	printf(" [%s]", (ft_atoi(test4) == atoi(test4)) ? OK : KO);
}
void test_ft_calloc()
{
    int *arr;
    int i, test_ok;

    printf("\nft_calloc: ");

    // Test 1: Allocation normale
    arr = (int *)ft_calloc(5, sizeof(int));
    if (arr == NULL)
    {
        printf(" [%s]", KO);
    }
    else
    {
        test_ok = 1;
        for (i = 0; i < 5; i++)
        {
            if (arr[i] != 0)
            {
                test_ok = 0;
                break;
            }
        }
        printf(" [%s]", test_ok ? OK : KO);
        free(arr);
    }
}

void test_ft_strdup()
{
	char	test1[] = "to";
	char	test2[] = "1231!@#4932 324wrswer";
	char	test3[] = "'[];{}]][123waqwe]]'";
	char	test4[] = "";
	
    printf("\nft_strdup: ");
    
	printf(" [%s]", (ft_memcmp(ft_strdup(test1), strdup(test1), 3) == 0) ? OK : KO);
	printf(" [%s]", (ft_memcmp(ft_strdup(test2), strdup(test2), 23) == 0) ? OK : KO);
	printf(" [%s]", (ft_memcmp(ft_strdup(test3), strdup(test3), 22) == 0) ? OK : KO);
	printf(" [%s]", (ft_memcmp(ft_strdup(test4), strdup(test4), 2) == 0) ? OK : KO);
}

void test_ft_itoa()
{
	int	str = -2147483648;
	int	str1 = 2147483647;
	int	str2 = 0;
	int	str3 = 42;
	
    printf("\nft_itoa:   ");

	printf(" [%s]", (ft_memcmp(ft_itoa(str), "-2147483648", 11) == 0) ? OK : KO);
	printf(" [%s]", (ft_memcmp(ft_itoa(str1), "2147483647", 10) == 0) ? OK : KO);
	printf(" [%s]", (ft_memcmp(ft_itoa(str2), "0", 1) == 0) ? OK : KO);
	printf(" [%s]", (ft_memcmp(ft_itoa(str3), "42", 2) == 0) ? OK : KO);
}

void test_ft_strtrim()
{
	char	test1[] = "abcdefghij";
	char	test2[] = "    abcde     ";
	char	test3[] = "               ";
	char	test4[] = "";
	
    printf("\nft_strtrim:");
    
	printf(" [%s]", (ft_memcmp(ft_strtrim(test1, "aj"), "bcdefghi", 9) == 0) ? OK : KO);
	printf(" [%s]", (ft_memcmp(ft_strtrim(test2, " "), "abcde", 6) == 0) ? OK : KO);
	printf(" [%s]", (ft_memcmp(ft_strtrim(test3, " "), "", 1) == 0) ? OK : KO);
	printf(" [%s]", (ft_memcmp(ft_strtrim(test4, ""), "", 1) == 0) ? OK : KO);
}

void test_ft_strjoin()
{
	char	test1[] = "A ";
	char	test2[] = "";
	char	test3[] = "12345678";
	char	test4[] = "";
	
    printf("\nft_strjoin:");
    
	printf(" [%s]", (ft_memcmp(ft_strjoin(test1, "cat is not a dog"), "A cat is not a dog", 19) == 0) ? OK : KO);
	printf(" [%s]", (ft_memcmp(ft_strjoin(test2, "A cat is not a dog"), "A cat is not a dog", 18) == 0) ? OK : KO);
	printf(" [%s]", (ft_memcmp(ft_strjoin(test3, "12345678"), "1234567812345678", 17) == 0) ? OK : KO);
	printf(" [%s]", (ft_memcmp(ft_strjoin(test4, ""), "", 1) == 0) ? OK : KO);
}

void test_ft_substr()
{
	char	test1[] = "A cat is not a dog.";
	
	
    printf("\nft_substr: ");
    
	printf(" [%s]", (ft_memcmp(ft_substr(test1, 2, 3), "cat", 4) == 0) ? OK : KO);
	printf(" [%s]", (ft_memcmp(ft_substr(test1, 0, 5), "A cat", 5) == 0) ? OK : KO);
	printf(" [%s]", (ft_memcmp(ft_substr(test1, 0, ft_strlen(test1)), "A cat is not a dog.", 19) == 0) ? OK : KO);
	printf(" [%s]", (ft_memcmp(ft_substr(test1, 2, 0), "", 1) == 0) ? OK : KO);
}

char to_upper(unsigned int i, char c)
{
    (void)i;
    if (c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}

void test_ft_strmapi()
{
    printf("\nft_strmapi:");
    
	char	str[] = "abc";

	printf(" [%s]\n", (ft_memcmp(ft_strmapi(str, to_upper), "ABC", 4) == 0) ? OK : KO);
}

void to_upperv(unsigned int i, char *c)
{
    (void)i;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 'a' + 'A';
}

void test_ft_striteri()
{
	char	str[] = "abc";
	char	str1[] = "123abc";
	char	str2[] = "!@#$abc";
	char	str3[] = ";./,abc";
	
    printf("\nft_striteri:");
    
	ft_striteri(str, to_upperv);
	ft_striteri(str1, to_upperv);
	ft_striteri(str2, to_upperv);
	ft_striteri(str3, to_upperv);

	printf("[%s] ", (ft_memcmp(str, "ABC", 4) == 0) ? OK : KO);
	printf("[%s] ", (ft_memcmp(str1, "123ABC", 7) == 0) ? OK : KO);
	printf("[%s] ", (ft_memcmp(str2, "!@#$ABC", 8) == 0) ? OK : KO);
	printf("[%s] ", (ft_memcmp(str3, ";./,ABC", 8) == 0) ? OK : KO);
}
void test_ft_split()
{
    char **result;
    int i;

    printf("\nft_split:  ");

    // Test 1: Séparation normale
    result = ft_split("hello world", ' ');
    if (result[0] && strcmp(result[0], "hello") == 0 && strcmp(result[1], "world") == 0 && result[2] == NULL)
        printf(" [%s]", OK);
    else
        printf(" [%s]", KO);
    
    // Libération de la mémoire
    i = 0;
    while (result[i])
        free(result[i++]);
    free(result);

    // Test 2: Plusieurs délimiteurs consécutifs
    result = ft_split("  hello   world  ", ' ');
    if (result[0] && strcmp(result[0], "hello") == 0 && strcmp(result[1], "world") == 0 && result[2] == NULL)
        printf(" [%s]", OK);
    else
        printf(" [%s]", KO);
    
    // Libération de la mémoire
    i = 0;
    while (result[i])
        free(result[i++]);
    free(result);

    // Test 3: Chaîne vide
    result = ft_split("", ' ');
    if (result[0] == NULL)
        printf(" [%s]", OK);
    else
        printf(" [%s]", KO);
    
    free(result);

    // Test 4: Aucun délimiteur
    result = ft_split("hello", ' ');
    if (result[0] && strcmp(result[0], "hello") == 0 && result[1] == NULL)
        printf(" [%s]", OK);
    else
        printf(" [%s]", KO);
    
    // Libération de la mémoire
    free(result[0]);
    free(result);
}

void test_ft_putendl_fd()
{
    
    
	ft_putendl_fd("ft_putendl_fd:   [\033[0;32mOK\033[0m]", 1);
	
}

void test_ft_putstr_fd()
{
    
	ft_putstr_fd("\nft_putstr_fd:    [\033[0;32mOK\033[0m]", 1);
	
}

void test_ft_putchar_fd()
{
    
	char	*str;

	str = "ft_putchar_fd:   [\033[0;32mOK\033[0m]";
	while (*str)
		ft_putchar_fd(*str++, 2);
	
}
void test_ft_putnbr_fd()
{
    int fd;
    char buffer[100];
    // Ouvrir un fichier temporaire pour les tests
    fd = open("test_putnbr.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        printf("Erreur lors de l'ouverture du fichier de test\n");
        return;
    }
    // Tester différents nombres
    ft_putnbr_fd(0, fd);
	write(fd, "\n", 1);
    ft_putnbr_fd(42, fd);
    write(fd, "\n", 1);
    ft_putnbr_fd(-42, fd);
    write(fd, "\n", 1);
    ft_putnbr_fd(INT_MAX, fd);
    write(fd, "\n", 1);
    ft_putnbr_fd(INT_MIN, fd);
    write(fd, "\n", 1);
    // Fermer le fichier
    close(fd);
    // Lire le contenu du fichier
    fd = open("test_putnbr.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Erreur lors de la lecture du fichier de test\n");
        return;
    }
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read > 0)
        buffer[bytes_read] = '\0';
    else
        printf("Erreur lors de la lecture du fichier ou fichier vide\n");
    close(fd);
    // Vérifier le résultat
    const char *expected = "0\n42\n-42\n2147483647\n-2147483648\n";
    if (strcmp(buffer, expected) == 0)
    {
        printf("\nft_putnbr_fd:    [\033[0;32mOK\033[0m]\n");
    }
    else
    {
        printf("\nft_putnbr_fd:    [\033[0;31mKO\033[0m]\n");
    }
    
    // Supprimer le fichier temporaire
    unlink("test_putnbr.txt");
}
int main()
{
	test_ft_isalpha();
	test_ft_isdigit();
	test_ft_isalnum();
	test_ft_isascii();
	test_ft_isprint();
	test_ft_strlen();
	test_ft_memset();
	test_ft_bzero();
	test_ft_memcpy();
	test_ft_memmove();
	test_ft_strlcpy();
	test_ft_strlcat();
	test_ft_toupper();
	test_ft_tolower();
	test_ft_strchr();
	test_ft_strrchr();
	test_ft_strncmp();
	test_ft_memchr();
	test_ft_memcmp();
	test_ft_strnstr();
	test_ft_atoi();
	
	test_ft_calloc();
	test_ft_strdup();
	
	test_ft_substr();
	test_ft_strjoin();
	test_ft_strtrim();
	test_ft_split();
	test_ft_itoa();
	test_ft_striteri();
	test_ft_strmapi();
	
	test_ft_putchar_fd();
	test_ft_putstr_fd();
	test_ft_putnbr_fd();
	test_ft_putendl_fd();
	

	//test_ft_lstnew();
	//test_ft_lstadd_front();
	//test_ft_lstsize();
	//test_ft_lstlast();
	//test_ft_lstadd_back();
	//test_ft_lstdelone();
	//test_ft_lstclear();
	//test_ft_lstiter();
	//test_ft_lstmap();

}

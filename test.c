/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 22:40:15 by anraymon          #+#    #+#             */
/*   Updated: 2023/08/08 22:40:15 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <string.h>// memset | bzero | strcmp
#include <stdio.h>// printf

void	t_memset()
{
	char ft_s[50] = "";
	char s[50] = "";

	ft_memset(ft_s, '4', 50);
	memset(s, '4', 50);
	if (strncmp(ft_s, s, 50) == 0)
		printf("OK\n");
	else
		printf("KO -> ft_memset\n");

	if (ft_memset(NULL, '4', 50) == NULL)// Function de base segfault
		printf("OK\n");
	else
		printf("KO -> ft_memset\n");
}

void	t_bzero()
{
	char ft_s[50] = "";
	int i;

	memset( ft_s, '4', 50);
	ft_bzero(ft_s, 50);
	if (ft_s != NULL)
		printf("OK\n");
	else
		printf("KO -> ft_bzero\n");

	i = 0;
	while (i < 50 && i >= 0)
	{
		if (ft_s[i++] != 0)
			i = -1;
	}
	if (i == -1)
		printf("KO -> f_bzero\n");
	else
		printf("OK\n");
	
	memset( ft_s, '4', 50);
	ft_bzero(ft_s, 25);
	i = 0;
	while (i < 50 && i >= 0)
	{
		if (ft_s[i++] != 0)
			i = -1;
	}
	if (i == -1)
		printf("OK\n");
	else
		printf("KO -> ft_bzero\n");
}

void	t_memcpy()
{
	char ft_dest[] = "La libft c'est un vrai p'tit plaisir.word\0";
	char ft_src[] = "drow.risialp tit'p iarv nu tse'c tfbil aL\0";
	char diff[] = "drow.risialp tit'p iarv nu tse'c tfbil aL\0";

	ft_memcpy(ft_dest, ft_src, 42);
	if (strncmp(ft_dest, diff, 42) == 0)
		printf("OK\n");
	else
		printf("KO -> ft_memcpy\n");

	if (ft_memcpy(NULL, ft_src, 42) == NULL)// Function de base segfault
		printf("OK\n");
	else
		printf("KO -> ft_memcpy\n");
}

void	t_memccpy()
{
	char ft_dest[] = "La libft c'est un vrai p'tit plaisir.word\0";
	char ft_src[] = "drow.risialp tit'p iarv nu tse'c tfbil aL\0";
	char diff[] = "drow.risialp tit'p iarvp'tit plaisir.word\0";

	ft_memccpy(ft_dest, ft_src, 'v', 42);
	if (strncmp(ft_dest, diff, 42) == 0)
		printf("OK\n");
	else
		printf("KO -> ft_memccpy\n");

	if (ft_memccpy(NULL, ft_src, 'p', 42) == NULL)// Function de base segfault
		printf("OK\n");
	else
		printf("KO -> ft_memccpy\n");

	if (ft_memccpy(ft_dest, ft_src, 'z', 42) == NULL)// Function de base segfault
		printf("OK\n");
	else
		printf("KO -> ft_memccpy\n");
}

void	t_memmove()
{
	//char ft_dest[90] = "La libft c'est un vrai p'tit plaisir, comme un bon gateau.";
	char ft_dest[] = "Start stop\0";
	char diff[] = "artrt stop\0";

	ft_memmove(ft_dest, ft_dest + 2, 3);
	if (strncmp(ft_dest, diff, 10) == 0)
		printf("OK\n");
	else
		printf("KO -> ft_memmove\n");

	if (ft_memmove(NULL, ft_dest + 2, 3) == NULL)// Function de base segfault
		printf("OK\n");
	else
		printf("KO -> ft_memmove\n");
}

void	t_memchr()
{
	char ft_dest[] = "Start stop\0";

	if (ft_memchr(ft_dest, 'o', 10) == ft_dest + 8)
		printf("OK\n");
	else
		printf("KO -> ft_memchr\n");

	if (ft_memchr("", 'o', 10) == NULL)
		printf("OK\n");
	else
		printf("KO -> ft_memchr\n");
}

void	t_memcmp()
{
	char s1[] = "Start stop\0";
	char s2[] = "Stop start\0";

	if (ft_memcmp(s1, s1, 10) == 0)
		printf("OK\n");
	else
		printf("KO -> ft_memcmp\n");

	if (ft_memcmp(s1, s2, 10) < 0)
		printf("OK\n");
	else
		printf("KO -> ft_memcmp\n");

	if (ft_memcmp(s1, s2, 0) == 0)
		printf("OK\n");
	else
		printf("KO -> ft_memcmp\n");

}

void	t_strlen()
{
	char s[] = "Start stop\0";

	if (ft_strlen("") == 0)
		printf("OK\n");
	else
		printf("KO -> ft_strlen\n");

	if (ft_strlen(s) == 10)
		printf("OK\n");
	else
		printf("KO -> ft_strlen\n");
}

void	t_isalpha()
{
	if (ft_isalpha('z') == 1)
		printf("OK\n");
	else
		printf("KO -> ft_isalpha\n");

	if (ft_isalpha('4') == 0)
		printf("OK\n");
	else
		printf("KO -> ft_isalpha\n");
}

void	t_isdigit()
{
	if (ft_isdigit('4') == 1)
		printf("OK\n");
	else
		printf("KO -> ft_isdigit\n");

	if (ft_isdigit('z') == 0)
		printf("OK\n");
	else
		printf("KO -> ft_isdigit\n");
}

void	t_isalnum()
{
	if (ft_isalnum('4') == 1)
		printf("OK\n");
	else
		printf("KO -> ft_isalnum\n");

	if (ft_isalnum('z') == 1)
		printf("OK\n");
	else
		printf("KO -> ft_isalnum\n");

	if (ft_isalnum('.') == 0)
		printf("OK\n");
	else
		printf("KO -> ft_isalnum\n");
}

void	t_isascii()
{
	if (ft_isascii(127) == 1)
		printf("OK\n");
	else
		printf("KO -> ft_isascii\n");

	if (ft_isascii(0) == 1)
		printf("OK\n");
	else
		printf("KO -> ft_isascii\n");

	if (ft_isascii(129) == 0)
		printf("OK\n");
	else
		printf("KO -> ft_isascii\n");
}

void	t_isprint()
{
	if (ft_isprint(126) == 1)
		printf("OK\n");
	else
		printf("KO -> ft_isprint\n");

	if (ft_isprint(32) == 1)
		printf("OK\n");
	else
		printf("KO -> ft_isprint\n");

	if (ft_isprint(129) == 0)
		printf("OK\n");
	else
		printf("KO -> ft_isprint\n");
}

void	t_toupper()
{
	if (ft_toupper('a') == 'A')
		printf("OK\n");
	else
		printf("KO -> ft_toupper\n");

	if (ft_toupper('z') == 'Z')
		printf("OK\n");
	else
		printf("KO -> ft_toupper\n");

	if (ft_toupper(126) == 126)
		printf("OK\n");
	else
		printf("KO -> ft_toupper\n");
}

void	t_tolower()
{
	if (ft_tolower('A') == 'a')
		printf("OK\n");
	else
		printf("KO -> ft_tolower\n");

	if (ft_tolower('Z') == 'z')
		printf("OK\n");
	else
		printf("KO -> ft_tolower\n");

	if (ft_tolower(126) == 126)
		printf("OK\n");
	else
		printf("KO -> ft_tolower\n");
}

void	t_strchr()
{
	char ft_test[] = "La libft c'est un vrai p'tit plaisir.word\0";

	if (strcmp(ft_strchr(ft_test, '.'), ".word") == 0)
		printf("OK\n");
	else
		printf("KO -> ft_strchr\n");

	if (strcmp(ft_strchr(ft_test, '.'), ".wor") == 1)
		printf("OK\n");
	else
		printf("KO -> ft_strchr\n");
}

void	t_strrchr()
{
	char ft_test[] = "La libft c'est un vrai p'tit plaisir.word\0";

	if (strcmp(ft_strrchr(ft_test, 'i'), "ir.word") == 0)
		printf("OK\n");
	else
		printf("KO -> ft_strrchr\n");

	if (strcmp(ft_strrchr(ft_test, 'i'), "ir.wor") == 1)
		printf("OK\n");
	else
		printf("KO -> ft_strrchr\n");
}

int main()
{
	printf("\n====== Start test Libft ======\n");
	t_memset();
	printf("------------------------------\n");
	t_bzero();
	printf("------------------------------\n");
	t_memcpy();
	printf("------------------------------\n");
	t_memccpy();
	printf("------------------------------\n");
	t_memmove();
	printf("------------------------------\n");
	t_memchr();
	printf("------------------------------\n");
	t_memcmp();
	printf("------------------------------\n");
	t_strlen();
	printf("------------------------------\n");
	t_isalpha();
	printf("------------------------------\n");
	t_isdigit();
	printf("------------------------------\n");
	t_isalnum();
	printf("------------------------------\n");
	t_isascii();
	printf("------------------------------\n");
	t_isprint();
	printf("------------------------------\n");
	t_toupper();
	printf("------------------------------\n");
	t_tolower();
	printf("------------------------------\n");
	t_strchr();
	printf("------------------------------\n");
	t_strrchr();
	printf("========== finished ==========\n");
}
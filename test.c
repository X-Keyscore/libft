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

/*
- memset() -
Elle remplit les n premiers octets de la zone mémoire pointée par s avec l'octet c.
Elle renvoie un pointeur sur la zone mémoire s.
*/

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

/*
- bzero() -
Elle met à 0 (octets contenant « \0 ») les n premiers octets du bloc pointé par s.
*/

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

/*
- memcpy() -
Elle copie n octets depuis la zone mémoire src vers la zone mémoire dest.
Les deux zones ne doivent pas se chevaucher. Si c'est le cas, utilisez plutôt memmove(3).
Elle renvoie un pointeur sur dest.
*/

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

/*
- memccpy() -
elle copie au plus n octets de la zone mémoire src vers la zone mémoire dest, s'arrêtant dès qu'elle rencontre le caractère c.
Elle renvoie un pointeur sur le caractère immédiatement après c dans la zone dest, ou NULL si c n'a pas été trouvé dans les n premiers caractères de src.
*/

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

/*
- memmove() -
Elle copie n octets depuis la zone mémoire src vers la zone mémoire dest.
Les deux zones peuvent se chevaucher : la copie se passe comme si les octets de src étaient d'abord copiés dans une zone temporaire qui ne chevauche ni src ni dest,
et les octets sont ensuite copiés de la zone temporaire vers dest.
Elle renvoie un pointeur sur dest.  
*/

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

/*
- memchr() -
Elle examine les n premiers octets de la zone mémoire pointée par s à la recherche du caractère c.
Le premier octet correspondant à c (interprété comme un unsigned char) arrête l'opération.
Elle renvoie un pointeur sur l'octet correspondant, ou NULL si le caractère n'est pas présent dans la zone de mémoire concernée.
*/

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

/*
- _memcmp() -
Elle compare les n premiers octets des zones mémoire s1 et s2.
Elle renvoie un entier inférieur, égal, ou supérieur à zéro, si s1 est respectivement inférieure, égale ou supérieur à s2.
*/

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

/*
- strlen() -
La len du mouton.
*/

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

/*
- isalpha() -
vérifie un caractère alphabétique.
Les valeurs renvoyées sont différentes de zéro si le caractère c appartient à la classe testée, et une valeur nulle sinon.
*/

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

/*
- isdigit() -
Recherche un chiffre.
Les valeurs renvoyées sont différentes de zéro si le caractère c appartient à la classe testée, et une valeur nulle sinon.
*/

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

/*
- isalnum() -
Recherche un caractère alphanumérique.
Les valeurs renvoyées sont différentes de zéro si le caractère c appartient à la classe testée, et une valeur nulle sinon.
*/

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

/*
- isascii() -
Vérifie si c est une valeur de caractère non signée de 7 bits qui correspond au jeu de caractères ASCII.
Les valeurs renvoyées sont différentes de zéro si le caractère c appartient à la classe testée, et une valeur nulle sinon.
*/

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

/*
- isprint() -
vérifie tout caractère imprimable, y compris l'espace.
Les valeurs renvoyées sont différentes de zéro si le caractère c appartient à la classe testée, et une valeur nulle sinon.
*/

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

/*
- toupper() -
Convertit la lettre c en majuscule, si possible.
La valeur renvoyée est celle de la lettre convertie, ou c si la conversion n'a pas été possible.
*/

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

/*
- tolower() -
Convertit la lettre c en minuscule, si possible.
La valeur renvoyée est celle de la lettre convertie, ou c si la conversion n'a pas été possible.
*/

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

/*
- strrchr() -
Elle renvoie un pointeur sur la première occurrence du caractère c dans la chaîne s.
*/

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

/*
- strrchr() -
Elle renvoie un pointeur sur la dernière occurrence du caractère c dans la chaîne s.
*/

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

/*
- strncmp() -
Compare que les n (au plus) premiers caractères de s1 et s2.
Elle renvoie un entier négatif, nul, ou positif, si s1 est respectivement inférieure, égale ou supérieure à s2.
*/

void	t_strncmp()
{
	char ft_str[] = "La libft c'est un vrai p'tit plaisir.word\0";
	char ft_cmp[] = "La libft c'est un vrai p'tit plaisir\0";

	if (ft_strncmp(ft_str, ft_cmp, 22) == 0)
		printf("OK\n");
	else
		printf("KO -> ft_strncmp\n");

	if (ft_strncmp(ft_str, ft_cmp, 41) == 46)
		printf("OK\n");
	else
		printf("KO -> ft_strncmp\n");

	if (ft_strncmp(ft_str, ft_cmp, 0) == 0)
		printf("OK\n");
	else
		printf("KO -> ft_strncmp\n");

	if (ft_strncmp(ft_cmp, ft_str, 41) == -46)
		printf("OK\n");
	else
		printf("KO -> ft_strncmp\n");
}

/*
- strlcpy() -
Copie une chaînes de caractères.
Elle renvoie la longueur totale de la chaîne qu'elles a essayé de créer cela signifie la longueur de src.
*/

void	t_strlcpy()
{
	char ft_dest[42];
	char ft_src[] = "La libft c'est un vrai p'tit plaisir.word\0";

	if (ft_strlcpy(ft_dest, ft_src, 41) == 41)
		printf("OK\n");
	else
		printf("KO -> ft_strlcpy\n");

	if (ft_strlcpy(ft_dest, ft_src, 0) == 41)
		printf("OK\n");
	else
		printf("KO -> ft_strlcpy\n");

	if (ft_strlcpy(ft_dest, ft_src, 50) == 41)
		printf("OK\n");
	else
		printf("KO -> ft_strlcpy\n");
}

/*
- strlcpy() -
Concaténent une chaînes de caractères.
Elle renvoie la longueur initiale de dst plus la longueur de src.
*/

void	t_strlcat()
{
	char ft_dest[83] = "La libft c'est un vrai p'tit plaisir.word\0";;
	char ft_src[42] = "La libft c'est un vrai p'tit plaisir.word\0";

	if (ft_strlcat(ft_dest, ft_src, 41) == 82)
		printf("OK\n");
	else
		printf("KO -> ft_strlcpy\n");

	if (ft_strlcat(ft_dest, ft_src, 20) == 61)
		printf("OK\n");
	else
		printf("KO -> ft_strlcpy\n");

	if (ft_strlcpy(ft_dest, ft_src, 0) == 41)
		printf("OK\n");
	else
		printf("KO -> ft_strlcpy\n");
}

/*
- strnstr() -
Rechercher la première sous-chaîne dans une chaîne de longueur limitée.
Si little est une chaîne vide, big est renvoyé, si little n'apparaît nulle part dans big, NULL est renvoyé,
sinon un pointeur vers le premier caractère de la première occurrence de little est renvoyé.
*/

void	t_strnstr()
{
	char ft_big[] = "La libft c'est un vrai p'tit plaisir.word\0";
	char ft_little[] = "un vrai p'tit plaisir\0";
	char diff[] = "un vrai p'tit plaisir.word\0";

	if (ft_strnstr(ft_big, ft_little, 10) == 0)
		printf("OK\n");
	else
		printf("KO -> ft_strnstr\n");

	if (ft_strnstr(ft_big, ft_little, 0) == 0)
		printf("OK\n");
	else
		printf("KO -> ft_strnstr\n");

	if (strcmp(ft_strnstr(ft_big, ft_little, 42), ft_big) == 1)
		printf("OK\n");
	else
		printf("KO -> ft_strnstr\n");

	if (strcmp(ft_strnstr(ft_big, ft_little, 42), diff) == 0)
		printf("OK\n");
	else
		printf("KO -> ft_strnstr\n");
}

/*
- atoi() -
Elle convertie le début d'une chaîne pointée par nptr en entier de type int.
Le résultat de la conversion.
*/

void	t_atoi()
{
	if (ft_atoi("42") == 42)
		printf("OK\n");
	else
		printf("KO -> ft_atoi\n");

	if (ft_atoi("42t 	fg \t\v\f\n\r fg ") == 42)
		printf("OK\n");
	else
		printf("KO -> ft_atoi\n");

	if (ft_atoi("test42t 	fg \t\v\f\n\r fg ") == 0)
		printf("OK\n");
	else
		printf("KO -> ft_atoi\n");
}

/*
- calloc() -
Elle alloue la mémoire nécessaire pour un tableau de nmemb éléments de size octets, et renvoie un pointeur vers la mémoire allouée.
Cette zone est remplie avec des zéros. Si nmemb ou si size est nulle, calloc renvoie soit NULL ou un unique pointeur qui pourra être passé ultérieurement à free() avec succès.
*/

void	t_calloc()
{
	char *dest;

	dest = ft_calloc(10, 2);
	dest[9] = 42;
	if (dest[9] == 42)
		printf("OK\n");
	else
		printf("KO -> ft_calloc\n");
	free(dest);
}

/*
- strdup() -
elle renvoie un pointeur sur une nouvelle chaîne de caractères qui est dupliquée depuis s.
La mémoire occupée par cette nouvelle chaîne est obtenue en appelant malloc(3), et peut (doit) donc être libérée avec free(3). 
*/

void	t_strdup()
{
	char str[] = "La libft c'est un vrai p'tit plaisir.word\0";
	char diff[] = "La libft c'est un vrai p'tit plaisir.word\0";
	char *dest;

	dest = ft_strdup(str);
	if (strcmp(dest, diff) == 0)
		printf("OK\n");
	else
		printf("KO -> ft_strdup\n");
	free(dest);
}

/*
- substr() -
Alloue (avec malloc(3)) et retourne une chaine de caractères issue de la chaine donnée en argument.
Cette nouvelle chaine commence à l’index ’start’ et a pour taille maximale ’len’.
Elle renvoie un pointeur sur une nouvelle chaîne de caractères qui est dupliquée depuis s. NULL si l’allocation échoue.
*/

void	t_substr()
{
	char str[] = "La libft c'est un vrai p'tit plaisir.word\0";
	char diff[] = "un vrai p'tit plaisir\0";
	char *dest;

	dest = ft_substr(str, 15, 21);
	if (strcmp(dest, diff) == 0)
		printf("OK\n");
	else
		printf("KO -> ft_substr\n");
	dest = ft_substr(str, 0, 0);
	if (strcmp(dest, "") == 0)
		printf("OK\n");
	else
		printf("KO -> ft_substr\n");
	free(dest);
}

/*
- strjoin() -
Alloue (avec malloc(3)) et retourne une chaine de caractères issue de la chaine donnée en argument.
Cette nouvelle chaine commence à l’index ’start’ et a pour taille maximale ’len’.
Elle renvoie un pointeur sur une nouvelle chaîne de caractères qui est dupliquée depuis s. NULL si l’allocation échoue.
*/

void	t_strjoin()
{
	char str1[] = "La libft c'est un vrai p'tit plaisir.word\0";
	char diff1[] = "La libft c'est un vrai p'tit plaisir.wordLa libft c'est un vrai p'tit plaisir.word\0";
	char str2[] = "La libft c'est un vrai p'tit plaisir.word\0";
	char *dest;

	dest = ft_strjoin(str1, str2);
	if (strcmp(dest, diff1) == 0)
		printf("OK\n");
	else
		printf("KO -> ft_strjoin\n");
	dest = ft_strjoin("", "");
	if (strcmp(dest, "") == 0)
		printf("OK\n");
	else
		printf("KO -> ft_strjoin\n");
	free(dest);
}

/*
- strtrim() -
Alloue (avec malloc(3)) et retourne une copie de la chaine de caractères donnée en argument, sans les
caractères spécifiés dans le set donné en argument au début et à la fin de la chaine de caractères.
Elle renvoie une chaine de caractères trimmée. NULL si l’allocation échoue.
*/

void	t_strtrim()
{

	char str[] = "La libft c'est un vrai p'tit plaisir.word\0";
	char diff[] = "a libft c'est un vrai p'tit plaisi\0";
	char *dest;

	dest = ft_strtrim(str, "L.word");
	if (strcmp(dest, diff) == 0)
		printf("OK\n");
	else
		printf("KO -> ft_strtrim\n");
	dest = ft_strjoin("", "");
	if (strcmp(ft_substr(dest, 0, 0), "") == 0)
		printf("OK\n");
	else
		printf("KO -> ft_strtrim\n");
	free(dest);
}

/*
- split() -
Alloue (avec malloc(3)) et retourne un tableau de chaines de caracteres obtenu en séparant s à
l’aide du caractère c, utilisé comme délimiteur. Le tableau doit être terminé par NULL.
Elle renvoie le tableau de nouvelles chaines de caractères, résultant du découpage. NULL si l’allocation échoue.
*/

void t_split()
{
	char str[] = "  lfi  lr rn \0";
	char diff1_0[] = "lfi\0";
	char diff1_1[] = "lr\0";
	char diff1_2[] = "rn\0";
	char **dest;

	dest = ft_split(str, ' ');
	if (strcmp(dest[0], diff1_0) == 0)
		printf("OK\n");
	else
		printf("KO -> ft_split\n");
	if (strcmp(dest[1], diff1_1) == 0)
		printf("OK\n");
	else
		printf("KO -> ft_split\n");
	if (strcmp(dest[2], diff1_2) == 0)
		printf("OK\n");
	else
		printf("KO -> ft_split\n");
	free(dest);
}

/*
- itoa() -
Alloue (avec malloc(3)) et retourne une chaîne de caractères représentant l’entier ’n’ reçu en argument.
Les nombres négatifs doivent être gérés.
Elle renvoie une chaîne de caractères représentant l’entier. NULL si l’allocation échoue.
*/

void t_itoa()
{
	char *dest;

	dest = ft_itoa(10);
	if (strcmp(dest, "10") == 0)
		printf("OK\n");
	else
		printf("KO -> ft_itoa\n");
	free(dest);
	dest = ft_itoa(-10);
	if (strcmp(dest, "-10") == 0)
		printf("OK\n");
	else
		printf("KO -> ft_itoa\n");
	free(dest);
	dest = ft_itoa(0);
	if (strcmp(dest, "0") == 0)
		printf("OK\n");
	else
		printf("KO -> ft_itoa\n");
	free(dest);
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
	printf("------------------------------\n");
	t_strncmp();
	printf("------------------------------\n");
	t_strlcpy();
	printf("------------------------------\n");
	t_strlcat();
	printf("------------------------------\n");
	t_strnstr();
	printf("------------------------------\n");
	t_atoi();
	printf("------------------------------\n");
	t_calloc();
	printf("------------------------------\n");
	t_strdup();
	printf("------------------------------\n");
	t_substr();
	printf("------------------------------\n");
	t_strjoin();
	printf("------------------------------\n");
	t_strtrim();
	printf("------------------------------\n");
	t_split();
		printf("------------------------------\n");
	t_itoa();
	printf("========== finished ==========\n");
}
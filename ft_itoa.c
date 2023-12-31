/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:22:15 by anraymon          #+#    #+#             */
/*   Updated: 2023/11/03 05:08:20 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_alloc(long long n)
{
	size_t	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n >= 10)
	{
		count++;
		n /= 10;
	}
	count++;
	return (count);
}

static void	ft_convert_n(long long n, char *str, size_t alloc)
{
	str[alloc--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n >= 10)
	{
		str[alloc--] = "0123456789"[n % 10];
		n /= 10;
	}
	str[alloc] = "0123456789"[n % 10];
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	alloc;

	n = (long long)n;
	alloc = ft_count_alloc(n);
	str = (char *)malloc(sizeof(*str) * (alloc + 1));
	if (!str)
		return (NULL);
	ft_convert_n(n, str, alloc);
	return (str);
}

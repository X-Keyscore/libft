/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 23:07:45 by anraymon          #+#    #+#             */
/*   Updated: 2023/08/10 23:07:45 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && s1 && s2 && *(unsigned char*)(s1 + i) == *(unsigned char*)(s2 + i))
		i++;

	if (*(unsigned char*)(s1 + i) - *(unsigned char*)(s2 + i) == 0)
		return (0);
	else if (*(unsigned char*)(s1 + i) - *(unsigned char*)(s2 + i) < 0)
		return (-1);
	return (1);
}
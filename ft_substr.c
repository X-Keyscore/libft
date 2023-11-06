/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 02:24:51 by anraymon          #+#    #+#             */
/*   Updated: 2023/11/03 04:35:46 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	alloc;
	char	*str;

	if (ft_strlen(s) < start)
		alloc = 0;
	else if (ft_strlen(s) < start + len)
		alloc = ft_strlen(s) - start;
	else
		alloc = len;
	str = (char *)malloc(alloc + 1 * sizeof(*s));
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	while (i < ft_strlen(s) && j < len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}

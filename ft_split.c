/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:09:35 by anraymon          #+#    #+#             */
/*   Updated: 2023/11/06 22:31:18 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_alloc(char const *str, char c)
{
	size_t	alloc;
	size_t	boolean;

	alloc = 0;
	boolean = 0;
	while (*str)
	{
		if (*str != c && !boolean)
		{
			boolean = 1;
			alloc++;
		}
		else if (*str == c)
			boolean = 0;
		str++;
	}
	return (alloc);
}

static char	**alloc_string(char const *s, char c, char **split, size_t s_len)
{
	size_t	i;
	size_t	split_i;
	size_t	len;

	i = 0;
	split_i = 0;
	len = 0;
	while (i < s_len + 1 && s_len > 0)
	{
		if (s[i] == c || !s[i])
		{
			if (len > 0)
			{
				split[split_i] = (char *)ft_calloc(len + 1, sizeof(char));
				if (split[split_i])
					ft_strlcpy(split[split_i], &s[i - len], len + 1);
				len = 0;
				split_i++;
			}
		}
		else
			len++;
		i++;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	size_t	alloc;
	size_t	s_len;
	char	**split;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (!s)
		return (NULL);
	alloc = count_alloc(s, c);
	split = (char **)ft_calloc(sizeof(char *), alloc + 1);
	if (!split)
		return (NULL);
	split = alloc_string(s, c, split, s_len);
	split[alloc] = NULL;
	return (split);
}

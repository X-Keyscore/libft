/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:09:35 by anraymon          #+#    #+#             */
/*   Updated: 2023/10/31 18:09:35 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	ft_free_alloc(char	**array, size_t arr_i)
{
	while (arr_i)
	{
		free(array[arr_i--]);
	}
}

static size_t	ft_count_alloc(char const *s, char c)
{
	size_t	i;
	size_t	alloc;
	int		boolean;

	i = 0;
	alloc = 0;
	boolean = 0;
	while (s[i])
	{
		if (s[i] != c && boolean == 0)
			boolean = 1;
		else if (s[i] == c && boolean)
		{
			alloc++;
			boolean = 0;
		}
		i++;
	}
	if (boolean)
		alloc++;
	return (alloc);
}

static void	ft_spliter(char	**array, char const *s, char c)
{
	int		boolean;
	size_t	i;
	size_t	arr_i;
	size_t	start;
	size_t	len;

	boolean = 0;
	arr_i = 0;
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != c && boolean == 0)
		{
			boolean = 1;
			start = i;
			len = 0;
		}
		else if (s[i] == c && boolean)
		{
			array[arr_i++] = ft_substr(s, start, len);
			if (!array[arr_i - 1])
			{
				ft_free_alloc(array, arr_i);
				return ;
			}
			start = 0;
			boolean = 0;
		}
		if (boolean)
			len++;
		i++;
	}
	if (boolean)
		array[arr_i++] = ft_substr(s, start, len);
	if (!array[arr_i - 1])
	{
		ft_free_alloc(array, arr_i);
		return ;
	}
	array[arr_i] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	alloc;

	alloc = ft_count_alloc(s, c);
	printf("\nlen = %ld", alloc);
	if (!alloc)
		return (NULL);
	array = malloc(sizeof(char *) * (alloc + 1));
	if (!array)
		return (NULL);
	ft_spliter(array, s, c);
	return (array);
}

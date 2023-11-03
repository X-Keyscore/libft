/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:09:35 by anraymon          #+#    #+#             */
/*   Updated: 2023/11/03 05:20:56 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_alloc(const char *str, char c)
{
	int	i;
	int	bool;

	i = 0;
	bool = 0;
	while (*str)
	{
		if (*str != c && bool == 0)
		{
			bool = 1;
			i++;
		}
		else if (*str == c)
			bool = 0;
		str++;
	}
	return (i);
}

static char	*ft_strdup_p2p(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static void	ft_splitter(char **array, char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;

	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			array[j++] = ft_strdup_p2p(s, index, i);
			index = -1;
		}
		i++;
	}
	array[j] = '\0';
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = malloc(sizeof(char *) * ft_count_alloc(s, c) + 1);
	if (!array)
		return (NULL);
	ft_splitter(array, s, c);
	return (array);
}

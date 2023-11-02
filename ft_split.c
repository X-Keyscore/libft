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

static size_t	ft_count_alloc(char const *s, char c)
{
	size_t	i;
	size_t	len;
	int		boolean;

	i = 0;
	len = 0;
	boolean = 0;
	while (s[i])
	{
		if (s[i] != c && boolean == 0)
		{
			len++;
			boolean = 1;
		}
		else if (s[i] == c && boolean)
			boolean = 0;
		if (boolean)
			len++;
		i++;
	}
	return (len);
}

static char	*ft_strdup_p2p(char const *s, size_t start_index, size_t end_index)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(*s) * (end_index - start_index) + 1);
	if (!str)
		return (NULL);
	i = start_index;
	j = 0;
	while (s[i] && i <= end_index)
	{
		str[j++] = s[i++];
	}
	str[j] = 0;
	return (str);
}

static void	ft_spliter(char	**array, char const *s, char c)
{
	int		boolean;
	size_t	i;
	size_t	arr_i;
	size_t	start_s;

	boolean = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && boolean == 0)
		{
			boolean = 1;
			start_s = i;
		}
		else if (s[i] == c && boolean)
		{
			array[arr_i++] = ft_strdup_p2p(s, start_s, i - 1);
			start_s = 0;
			boolean = 0;
		}
		i++;
	}
	if (boolean)
		array[arr_i] = ft_strdup_p2p(s, start_s, i - 1);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	len;

	len = ft_count_alloc(s, c);
	if (!len)
		return (NULL);
	array = malloc(sizeof(char *) * (len));
	if (!array)
		return (NULL);
	ft_spliter(array, s, c);
	return (array);
}

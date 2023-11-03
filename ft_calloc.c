/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 01:54:40 by anraymon          #+#    #+#             */
/*   Updated: 2023/11/03 22:49:39 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	g_size;
	void	*dst;

	g_size = size * nmemb;
	dst = malloc(g_size);
	if (!dst)
		return (0);
	ft_memset(dst, 0, g_size);
	return (dst);
}

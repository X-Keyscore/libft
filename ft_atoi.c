/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:13:20 by anraymon          #+#    #+#             */
/*   Updated: 2023/10/30 22:13:20 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	res;

	if (!nptr)
		return (0);
	i = 0;
	while (nptr[i] == '\r' || nptr[i] == '\v' || nptr[i] == '\n'
		|| nptr[i] == '\f' || nptr[i] == '\t' || nptr[i] == ' ')
		i++;
	neg = 0;
	if (nptr[i] != '-')
		neg = 1;
	if (neg == -1 || nptr[i] == '+')
		i++;
	res = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		res = (res * 10) + (nptr[i++] - '0');
	return (res * neg);
}

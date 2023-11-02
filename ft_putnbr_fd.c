/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anraymon <anraymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 02:39:11 by anraymon          #+#    #+#             */
/*   Updated: 2023/11/02 02:39:11 by anraymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*base;
	int		len_base;

	base = "0123456789";
	len_base = ft_strlen(base);
	if (n >= len_base)
	{
		ft_putnbr_fd(n / len_base, fd);
		write(1, &base[n % len_base], fd);
	}
	else if (n < 0)
	{
		n = n * -1;
		write(1, "-", fd);
		ft_putnbr_fd(n, fd);
	}
	else
		write(1, &base[n % len_base], fd);
}

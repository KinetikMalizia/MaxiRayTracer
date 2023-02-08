/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:54:14 by nnemeth           #+#    #+#             */
/*   Updated: 2022/05/25 16:43:46 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hex_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

static void	ft_put_hex(unsigned int n, const char flag)
{
	if (n >= 16)
	{
		ft_put_hex(n / 16, flag);
		ft_put_hex(n % 16, flag);
	}
	else
	{
		if (n <= 9)
		{
			ft_putchar_fd((n + '0'), 1);
		}
		else
		{
			if (flag == 'x')
				ft_putchar_fd((n - 10 + 'a'), 1);
			if (flag == 'X')
				ft_putchar_fd((n - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex(unsigned int n, const char flag)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(n, flag);
	return (ft_hex_len(n));
}

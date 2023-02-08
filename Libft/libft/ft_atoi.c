/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:13:15 by nnemeth           #+#    #+#             */
/*   Updated: 2023/01/25 18:49:03 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(unsigned char c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ' || c == ',');
}

int	ft_atoi(const char *str)
{
	long long	nbr;
	int			i;
	int			is_negative;
	int			res;

	i = 0;
	is_negative = 1;
	nbr = 0;
	while (ft_isspace(str[i]))
	{
		i++;
		res = 0;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				is_negative = -1;
			i++;
		}
		while (ft_isdigit(str[i]))
		{
			nbr = (nbr * 10) + (int) str[i] - '0';
			res = (res * 10) + (int) str[i] - '0';
			i++;
		}
		printf("str in atoi: %s\n", str);
		res = nbr * is_negative;
		printf("res: %d\n", res);
	}
	return (res);
}


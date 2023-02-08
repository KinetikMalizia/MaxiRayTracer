/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:31:12 by nnemeth           #+#    #+#             */
/*   Updated: 2023/01/26 16:09:50 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

int	new_atoi(char *str)
{
	int			i;
	long long	nbr;
	int			res;
	int			is_negative;

	i = 0;
	nbr = 0;
	is_negative = 1;
	res = 0;
	while (ft_isspace(str[i]) == 0)
	{
		i++;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				is_negative = -1;
			i++;
		}
		while (ft_isdigit(str[i]))
		{
			res = (res * 10) + (int) str[i] - '0';
			i++;
		}
		res = nbr * is_negative;
	}
	return (res);
}

int	ft_isspace(unsigned char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ' || c == ',')
		return (0);
	return (1);
}

double	my_atof(const char *str, double	b)
{
	double		res;
	double		deci;
	int			i;
	int			a;
	int			neg;

	i = 0;
	res = 0.;
	deci = 1.;
	neg = 1;
	a = 0;
	while (ft_isspace(str[i]) == 1 && str[i])
	{
		while (ft_isdigit(str[i]))
		{
			res = (res * 10) + ((int) str[i] - '0');
			i++;
		}
		if (str[i] == '.')
			i++;
		while (ft_isdigit(str[i]) && str[i])
		{
			res = res * 10 + ((int) str[i] - '0');
			a -= 1;
			i++;
		}
		if (str[i] == 'e' || str[i] == 'E')
		{
			i++;
			if (str[i] == '-')
			{
				neg = -1;
				i++;
			}
			while (ft_isdigit(str[i]) && str[i])
			{
				b = b * 10 + (int) str[i] - '0';
				i++;
			}
			a = b * neg;
		}
		else
			b = 0;
		i++;
	}
	while (a > 0)
	{
		deci *= 10;
		a--;
	}
	while (a < 0)
	{
		deci /= 10;
		a++;
	}
	return (neg * res * deci);
}

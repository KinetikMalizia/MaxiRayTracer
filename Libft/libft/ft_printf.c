/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:53:59 by nnemeth           #+#    #+#             */
/*   Updated: 2022/05/25 16:44:12 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_flag(va_list args, const char flag)
{
	int	print;

	print = 0;
	if (flag == 'c')
		print += ft_print_char(va_arg(args, int));
	else if (flag == 's')
		print += ft_printstr(va_arg(args, char *));
	else if (flag == 'p')
		print += ft_print_ptr(va_arg(args, long));
	else if (flag == 'd' || flag == 'i')
		print += ft_print_int(va_arg(args, int));
	else if (flag == 'u')
		print += ft_print_unsignedint(va_arg(args, unsigned int));
	else if (flag == 'x' || flag == 'X')
		print += ft_print_hex(va_arg(args, unsigned int), flag);
	else if (flag == '%')
		print += write (1, "%", 1);
	return (print);
}

int	ft_printf(const char *flag, ...)
{
	int		i;
	int		print;
	va_list	args;

	i = 0;
	print = 0;
	va_start(args, flag);
	while (flag[i])
	{
		if (flag[i] == '%')
		{
			print += ft_flag(args, flag[i + 1]);
			i++;
		}
		else
			print += ft_print_char(flag[i]);
		i++;
	}
	va_end(args);
	return (print);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:11:04 by nnemeth           #+#    #+#             */
/*   Updated: 2022/05/25 16:43:49 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_int(int c)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(c);
	len = ft_printstr(num);
	free(num);
	return (len);
}

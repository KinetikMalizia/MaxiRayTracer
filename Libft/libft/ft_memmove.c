/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:32:51 by nnemeth           #+#    #+#             */
/*   Updated: 2021/11/27 11:00:20 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h> 

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	if (dst == src)
		return (dst);
	if (src < dst)
	{
		i = (int) len;
		while (i > 0)
		{
			i--;
			((char *)dst)[i] = ((char *)src)[i];
		}
	}
	else
	{
		i = 0;
		while (i < (int) len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}

// int main ()
// {
//    char dest[] = "mostannoying";
//    const char src[]  = "newstring";

//    printf("memmove dest = %s, src = %s\n", dest, src);
//    ft_memmove(dest, src, 8);
//    printf("memmove dest = %s, src = %s\n", dest, src);

//    return(0);
// }

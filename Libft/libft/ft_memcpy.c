/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:16:50 by nnemeth           #+#    #+#             */
/*   Updated: 2021/11/13 10:56:31 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h> 

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char			*dest;
	const char		*source;

	i = 0;
	dest = (char *) dst;
	source = (const char *) src;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}
/*int main ()
{
  size_t len = 0;
  char src[10] = "";
  char dst[10] = "";
  
	printf("%s\n", ft_memcpy(dst,src,len));
	printf("%s", memcpy(dst,src,len));
}*/

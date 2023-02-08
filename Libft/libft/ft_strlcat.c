/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:15:39 by nnemeth           #+#    #+#             */
/*   Updated: 2022/11/29 14:29:23 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <string.h>
#include <stdio.h>

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(dst) >= dstsize)
		return (ft_strlen(src) + dstsize);
	while (dst[j])
		j++;
	while (src[i] && (i + j) < (dstsize - 1))
	{
		dst[i + j] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	return (ft_strlen(&src[i]) + ft_strlen(dst));
}

/*int main()
{
	char first[] = "this is ";
	char last[] = "a potentially long string";

	int r;
	int size = 16;
	char buffer[size];

	strcpy(buffer,first);
	r = ft_strlcat(buffer,last,size);
	puts(buffer);
	printf("Value returned: %d\n",r);

	if(r > size)
	puts("string truncated");
	else
	puts("string was fully copied");
	return(0);	

	char dst[10] = "whta ";
	char src[10] = "up";

	printf("%zu\n", ft_strlcat(dst, src, 4));
	printf("%lu\n", strlcat(dst, src, 4));
	}*/

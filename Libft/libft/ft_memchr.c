/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:03:57 by nnemeth           #+#    #+#             */
/*   Updated: 2021/11/05 14:36:27 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h> 

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	char			*string;

	i = 0;
	string = (char *)s;
	while (i < n)
	{
		if (string[i] == (char) c)
			return (&string[i]);
		i++;
	}
	return (0);
}
/*int main ()
{
	char s[20] = "/|\x12\xff\x09\0\x42\042\0\42|\\";

	printf("%s\n", ft_memchr(s,'\0', 12));
	printf("%s", memchr(s, '\0', 12));
}*/

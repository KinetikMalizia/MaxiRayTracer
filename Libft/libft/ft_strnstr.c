/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 11:53:12 by nnemeth           #+#    #+#             */
/*   Updated: 2022/11/29 14:29:50 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*ft_strnstr(char *big, char *small, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = -1;
	size = ft_strlen(small);
	if (!(size))
		return ((char *) big);
	while (big[++i] && i < len)
	{	
		j = 0;
		while (small[j] == big[i + j] && (i + j < len))
		{
			if (j == size - 1)
				return ((char *)(big + i));
			j++;
		}
	}
	return (NULL);
}

// int main ()
// {
// 	char* s1 = "see FF your FF return FF now FF";
// 	char* s2 = "FF";
// 	size_t size = -1;

// 	printf("%s\n", ft_strnstr(s1,s2,size));
// 	printf("%s", strnstr(s1,s2,size));
// }

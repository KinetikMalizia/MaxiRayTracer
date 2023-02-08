/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:16:05 by nnemeth           #+#    #+#             */
/*   Updated: 2022/11/29 14:32:55 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	int		i;
	char	*str;

	str = (char *) s;
	i = ft_strlen(s) - 1;
	if (!str)
		return (NULL);
	if (c == 0 || !c)
		return (str + i + 1);
	while (i >= 0 && str[i])
	{
		if ((char) str[i] == (char) c)
			return ((char *) &str[i]);
		i--;
	}
	return (NULL);
}
/*int main () 
{
   const char str[] = "bonjour"; 
   char *p, *p2;

   p = strrchr(str, 's'); 
   printf("String starting from last occurrence of is: %s\n", p);

   p2 = ft_strrchr(str, 's'); 
   printf("String starting from last occurrence of is: %s\n", p2);

   return 0;
}*/
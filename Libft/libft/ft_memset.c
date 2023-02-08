/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:15:25 by nnemeth           #+#    #+#             */
/*   Updated: 2021/11/05 13:05:28 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h> 

void	*ft_memset(void *b, unsigned char c, int len)
{
	int		i;
	char	*string;

	i = 0;
	string = b;
	while (i < len)
	{
		string[i] = c;
		i++;
	}
	b = string;
	return (b);
}
/*int main () 
{
   char str[50];

   strcpy(str,"This is string.h library function");
   puts(str);

   ft_memset(str,'$',7);
   puts(str);
   
   return(0);
}*/

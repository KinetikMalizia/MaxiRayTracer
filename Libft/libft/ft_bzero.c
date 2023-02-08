/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:16:57 by nnemeth           #+#    #+#             */
/*   Updated: 2021/11/12 16:41:30 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <strings.h> 

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*string;

	i = 0;
	string = s;
	while (i < n)
	{
		string[i] = '\0';
		i++;
	}
}
/*int main () 
{
   char str[50];

   strcpy(str,"This is string.h library function");
   puts(str);
   ft_bzero(str,3);
   puts(str);
}*/

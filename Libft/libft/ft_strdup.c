/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:42:18 by nnemeth           #+#    #+#             */
/*   Updated: 2022/11/29 14:32:25 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h> 

char	*ft_strdup(char *s1)
{
	char		*store;
	size_t		i;

	store = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	i = 0;
	if (!s1)
		return (0);
	if (!store)
		return (0);
	while (s1[i])
	{
		store[i] = s1[i];
		i++;
	}
	store[i] = '\0';
	return (store);
}
/*int main()
{
    char source[] = "";
    char* target = ft_strdup(source);
    printf("%s", target);
    return 0;
}*/

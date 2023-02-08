/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:48:30 by nnemeth           #+#    #+#             */
/*   Updated: 2022/11/29 14:30:17 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	index;

	if (!s)
		return (0);
	i = 0;
	if (len > ft_strlen(s))
		index = (size_t)ft_strlen(s);
	else
		index = len;
	new = (char *)ft_calloc((index + 1), sizeof(*new));
	if (!new)
		return (0);
	while (start < ft_strlen(s) && i < index)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = 0;
	return (new);
}
/*int main()
{
    char src[] = "substr";
    int m = 2;
    int n = 3;
    char* dest = ft_substr(src, m, n);
    printf("%s\n", dest);
}*/

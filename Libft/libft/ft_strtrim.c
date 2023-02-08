/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:18:32 by nnemeth           #+#    #+#             */
/*   Updated: 2022/11/30 15:57:54 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set(char *s1, char *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!set)
		return (0);
	while (set[j])
	{
		printf("set: %c\n", set[j]);
		if (set[j] == s1[i])
		{
			printf("hello\n");
			return (1);
		}
		else
			j++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	size_t		start;
	size_t		end;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_set((char *)&s1[start], set) == 1 && s1[start])
		start++;
	while (ft_set((char *)&s1[end], set) == 1 && end > 0)
		end--;
	return (ft_substr(s1, start, end - start + 1));
}

/*int main(void)
{
    char src[] = "   xxx   xxx";
    char dest[] = " x";

	char *ptr;

	printf("SRC: address de :[%p]\n", src);
	printf("SRC: le resultat :[%s]\n", src);
	
	ptr = ft_strtrim(src, dest);

	printf("SRC: address de :[%p]\n", src);
	printf("SRC: le resultat :[%s]\n", src);
	
	printf("PTR: address de :[%p]\n", ptr);
	printf("PTR: le resultat :[%s]\n", ptr);

	
	// printf("%s", strtrim(src, dest));
    
}*/
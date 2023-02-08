/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:38:18 by nnemeth           #+#    #+#             */
/*   Updated: 2022/11/29 14:31:35 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char *str, char c)
{
	int	flag;
	int	count;

	flag = 0;
	count = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (*str == c)
			flag = 0;
		str++;
	}
	return (count);
}

static char	*ft_cutoff(char *str, int start, int end)
{
	int		i;
	char	*new;

	i = 0;
	new = malloc((end - start + 1) * sizeof(char));
	if (!new)
		return (0);
	while (start < end)
		new[i++] = str[start++];
	new[i] = '\0';
	return (new);
}

char	**ft_split(char *s, char c)
{
	size_t	i;
	size_t	j;
	char	**tmp;
	int		start;

	if (!s)
		return (0);
	tmp = malloc((ft_count(s, c) + 1) * sizeof(*tmp));
	if (!tmp)
		return (0);
	i = -1;
	j = 0;
	start = -1;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == (size_t)ft_strlen(s)) && start >= 0)
		{
			tmp[j++] = ft_cutoff(s, start, i);
			start = -1;
		}
	}	
	tmp[j] = 0;
	return (tmp);
}

// int	main(void)
// {
// 	char	*str[] = "Geeks-for-Geeks";
// 	char	c = '-';

// 	printf("%s\n", ft_split(str, c));
// }
// tmp[j] = 0;
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:17:46 by nnemeth           #+#    #+#             */
/*   Updated: 2021/11/27 15:51:04 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list			*list;

	list = malloc(sizeof(*list));
	if (!list)
	{
		return (0);
	}
	list->content = content;
	list->next = NULL;
	return (list);
}

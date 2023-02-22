/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:35:23 by nnemeth           #+#    #+#             */
/*   Updated: 2023/02/21 15:46:49 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

int	close_window(t_rays *rays)
{
	free(rays->map);
	exit(0);
	return (0);
}

int	escape(int keycode, t_rays *rays)
{
	if (keycode == KEY_ESC)
	{
		free(rays);
		exit(0);
	}
	return (0);
}

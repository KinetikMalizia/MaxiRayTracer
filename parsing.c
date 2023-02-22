/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:41:36 by nnemeth           #+#    #+#             */
/*   Updated: 2023/02/21 16:26:33 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	get_info(t_rays *rays)
{
	int	i;
	// int	y;

	i = 0;
	while (rays->map[i])
	{
		// y = 0;
		if (rays->map[i][0] == 'A')
			get_lightning(rays, &rays->map[i][1]);
		else if (rays->map[i][0] == 'C')
			get_camera(rays, &rays->map[i][1]);
		// else if (rays->map[i][0] == 'L')
		// 	get_light(rays, &rays->map[i][0]);
		// else if (rays->map[i][0] == 'pl')
		// 	get_plane(rays, &rays->map[i][0]);
		// else if (rays->map[i][0] == 'sp')
		// 	get_sphere(rays, &rays->map[i][0]);
		// else if (rays->map[i][0] == 'cy')
		// 	get_cylinder(rays, &rays->map[i][0]);
		i++;
	}
}

void	get_lightning(t_rays *rays, char *light)
{
	int		i;
	int		pos;
	char	*tmp;
	double	b;

	i = 1;
	pos = 1;
	b = 0;
	while (light[i])
	{
		if (light[i] == ' ')
		{
			if ((rays->a_light_ratio) == 0)
			{
				tmp = ft_substr(light, pos, i);
				rays->a_light_ratio = my_atof(tmp, b);
			}
			// else
			// 	rays->a_light_color = new_atoi((&light[i]));
			pos = i;
		}
		i++;
	}
}

void	get_camera(t_rays *rays, char *cam)
{
	int		i;
	int		pos;
	char	*tmp;

	i = 0;
	pos = 0;
	while (cam[i])
	{
		if (cam[i] == ',')
		{
			tmp = ft_substr(cam, pos, i);
			// printf("tmp': %s\n", tmp);
			if (rays->cam.cam.x == 0)
				rays->cam.cam.x = new_atoi(tmp);
			else if (rays->cam.cam.y == 0)
				rays->cam.cam.y = new_atoi(tmp);
			else
				rays->cam.cam.z = new_atoi(tmp);
			pos = (i + 1);
		}	
		i++;
	}
}

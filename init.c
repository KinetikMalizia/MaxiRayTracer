/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:14:48 by nnemeth           #+#    #+#             */
/*   Updated: 2023/02/22 16:18:57 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	ft_init_window(t_rays *rays)
{
	rays->mlx_ptr = mlx_init();
	rays->win_ptr = mlx_new_window(rays->mlx_ptr, W, H, "MiniRT");
	rays->img = mlx_new_image(rays->mlx_ptr, W, H);
	rays->addr = mlx_get_data_addr(rays->img, &rays->bits_per_pixel,
			&rays->line_length, &rays->endian);
}

void	set_scene(t_rays *rays)
{
	int		bckclr;

	bckclr = 0.28 * (rays->win_i + 1);
	bckclr += ((1 - bckclr) * color((0.5/255), (0.7 / 255), (1 / 255)) - (bckclr * color((1/255), (1/255), (1/255))));
	my_mlx_pixel_put(rays, rays->win_y, (H - rays->win_i - 1),
		ray_color(bckclr, 135, 206, 235));
	rays->ray_orig.x = rays->cam.pos.x;
	rays->ray_orig.y = rays->cam.pos.y;
	rays->ray_orig.z = rays->cam.pos.z;
	rays->ray_dir.x = ((float)rays->win_y - W / 2);
	rays->ray_dir.y = ((float)rays->win_i - H / 2);
	rays->ray_dir.z = -W / (2 * tan(rays->cam.cam_fov / 2));
	normalize(rays->ray_dir);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:31:27 by nnemeth           #+#    #+#             */
/*   Updated: 2023/02/08 12:58:42 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	load_scene(t_rays *rays)
{
	int		hit;

	rays->win_i = 0;
	hit = FALSE;
	ft_init_window(rays);
	while (rays->win_i < H)
	{
		rays->win_y = 0;
		while (rays->win_y < W)
		{
			set_scene(rays);
			hit = inter_sphere(rays);
			if (hit == TRUE)
			{
				get_light(rays);
				my_mlx_pixel_put(rays, rays->win_y, rays->win_i,
					color(251, 227, 95));
			}
			rays->win_y++;
		}
		rays->win_i++;
	}
	mlx_put_image_to_window(rays->mlx_ptr, rays->win_ptr, rays->img, 0, 0);
}

void	get_light(t_rays *rays)
{
	double		dot_light;
	t_vector	minus;
	t_vector	tmp;

	minus = ft_minus(rays->light.light_point, rays->light.p);
	normalize(minus);
	dot_light = dot(minus, rays->light.n);
	tmp = dot_light / minus;
	rays->light.intens_pixel = rays->light.l_bright * tmp;
}

void	my_mlx_pixel_put(t_rays *rays, int x, int y, int color)
{
	char	*dst;

	dst = rays->addr + (y * rays->line_length + x * (rays->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	color(double r, double g, double b)
{
	return ((int)r << 16 | (int)g << 8 |(int)b);
}

int	ray_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_init_window(t_rays *rays)
{
	rays->mlx_ptr = mlx_init();
	rays->win_ptr = mlx_new_window(rays->mlx_ptr, W, H, "MiniRT");
	rays->img = mlx_new_image(rays->mlx_ptr, W, H);
	rays->addr = mlx_get_data_addr(rays->img, &rays->bits_per_pixel,
			&rays->line_length, &rays->endian);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:31:27 by nnemeth           #+#    #+#             */
/*   Updated: 2023/02/22 11:01:05 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

void	load_scene(t_rays *rays)
{
	int		hit;
	int		hit2;

	rays->win_i = 0;
	hit = FALSE;
	ft_init_window(rays);
	while (rays->win_i < H)
	{
		rays->win_y = 0;
		while (rays->win_y < W)
		{
			set_scene(rays);
			hit = inter_plane(rays);
			hit2 = inter_sphere(rays);
			if (hit == TRUE || hit2 == TRUE)
			{
				// rays->light.n = get_light(rays);
				rays->light.n = add_amb(rays);
				my_mlx_pixel_put(rays, rays->win_y, rays->win_i,
					color(100, 0, 70));
				my_mlx_pixel_put(rays, rays->win_y, (H - rays->win_i - 1),
					color((ft_max((rays->light.n.x))), ft_max(((rays->light.n.y))), ft_max((rays->light.n.z))));
				// my_mlx_pixel_put(rays, rays->win_y, (H - rays->win_i - 1),
				// 	color((ft_max(rays->light.intens_pixel.x)),
				// 		(ft_max(rays->light.intens_pixel.y)),
				// 		(ft_max(rays->light.intens_pixel.z))));
			}
			rays->win_y++;
		}
		rays->win_i++;
	}
	mlx_put_image_to_window(rays->mlx_ptr, rays->win_ptr, rays->img, 0, 0);
}

t_vector	add_amb(t_rays *rays)
{
	rays->light.n.x *= (rays->a_light_color.col_r \
	* rays->a_light_ratio);
	rays->light.n.y *= (rays->a_light_color.col_g \
	* rays->a_light_ratio);
	rays->light.n.z *= (rays->a_light_color.col_b \
	* rays->a_light_ratio);
	return (rays->light.n);
}

// t_vector	get_light(t_rays *rays)
// {
// 	double		dot_light;
// 	t_vector	minus_tmp;
// 	t_vector	change;
// 	t_vector	ray_light;
// 	int			shadow;

// 	change.x = 1;
// 	change.y = 1;
// 	change.z = 1;
// 	minus_tmp = normalize(minus(rays->light.light_dir, rays->light.p));
// 	dot_light = getnorm(minus_tmp);
// 	ray_light = ft_plus(rays->light.p, ft_mult(0.01, rays->light.n));
// 	shadow = inter_sphere(rays);
// 	if (shadow && rays->t * rays->t < dot_light)
// 		rays->light.n = add_values(0, 0, 0);
// 	// rays->light.intens_pixel = ft_mult((rays->light.l_bright \
// 	// 	* ft_max(dot(minus_tmp, rays->light.n)) / dot_light), rays->light.albedo);
// 	// rays->light.intens_pixel = normalize(rays->light.intens_pixel);
// 	// rays->light.intens_pixel = ft_mult_vec(rays->light.albedo, rays->light.intens_pixel);
// 	return (rays->light.n);
// }

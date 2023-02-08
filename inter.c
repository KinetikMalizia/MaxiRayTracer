/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:21:40 by nnemeth           #+#    #+#             */
/*   Updated: 2023/02/08 12:41:24 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

int	inter_sphere(t_rays *rays)
{
	float		a;
	float		b;
	float		c;
	float		delta;
	t_vector	oc;
	double		t;

	oc = minus(rays->ray_orig, rays->sphere.sph_cord);
	a = getnorm(rays->ray_dir);
	b = 2 * (dot(oc, rays->ray_dir));
	c = dot(oc, oc) - (rays->sphere.sphere_rad * rays->sphere.sphere_rad);
	delta = (b * b) - (4 * a * c);
	if (delta < 0)
		return (FALSE);
	rays->t1 = (-b - sqrtf(delta)) / (2);
	rays->t2 = (-b + sqrtf(delta)) / (2);
	if (rays->t2 < 0)
		return (FALSE);
	if (rays->t1 > 0)
		t = rays->t1;
	else
		t = rays->t2;
	rays->light.p = (rays->ray_orig) + (t * rays->ray_dir);
	rays->light.n = (rays->light.p * (normalize(rays->sphere.sph_cord)));
	return (FALSE);
}

void	set_scene(t_rays *rays)
{
	int		bckclr;

	bckclr = 0.28 * (rays->win_i + 1);
	bckclr += ((1 - bckclr) * color(0.5, 0.7, 1) - (bckclr * color(1, 1, 1)));
	my_mlx_pixel_put(rays, rays->win_y, rays->win_i,
		ray_color(bckclr, 135, 206, 235));
	rays->ray_orig.x = rays->cam.pos.x;
	rays->ray_orig.y = rays->cam.pos.y;
	rays->ray_orig.z = rays->cam.pos.z;
	rays->ray_dir.x = ((float)rays->win_y - W / 2);
	rays->ray_dir.y = ((float)rays->win_i - W / 2);
	rays->ray_dir.z = -W / (2 * tan(rays->cam.cam_fov / 2));
	normalize(rays->ray_dir);
}
// P[t] = A + tb
//A = ray origin as in camera coordinates
//b = ray direction
//P = 3d position along a line

// 1) calculate the ray from the eye to the pixel 
// 2) determine which objects the ray intersects
// 3) compute a color for that intersection point 

// https://www.google.com/search?q=rendering+a+sphere+in+c+language&oq=rendering+a+sphere+in+c+&aqs=chrome.3.69i57j33i160l3.9737j1j7&sourceid=chrome&ie=UTF-8#fpstate=ive&vld=cid:86a89d49,vid:v9vndyfk2U8
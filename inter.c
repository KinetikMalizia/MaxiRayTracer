/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:21:40 by nnemeth           #+#    #+#             */
/*   Updated: 2023/02/22 10:59:29 by nnemeth          ###   ########.fr       */
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
	float 		d;
	t_vector	color;

	color.x = 1;
	color.y = 0;
	color.z = 0;
	oc = minus(rays->ray_orig, rays->sphere.sph_cord);
	a = dot(rays->ray_dir, rays->ray_dir);
	b = 2.0f * (dot(oc, rays->ray_dir));
	c = dot(oc, oc) - (rays->sphere.sphere_rad * rays->sphere.sphere_rad);
	delta = (b * b) - (4 * a * c);
	if (delta < 0)
		return (FALSE);
	rays->t1 = (-b + sqrt(delta)) / (2 * a);
	rays->t2 = (-b - sqrt(delta)) / (2 * a);
	if (rays->t1 < 0)
		return (FALSE);
	if (rays->t2 > 0)
		rays->t = rays->t2;
	else
		rays->t = rays->t1;
	rays->light.p = (ft_plus((rays->ray_orig), ft_mult(rays->t, rays->ray_dir)));
	rays->light.n = normalize((minus(rays->light.p, rays->sphere.sph_cord)));
	rays->light.light_dir = normalize(rays->light.light_dir);
	d = (dot(rays->light.n, ft_mult(-1, rays->light.light_dir)));
	rays->light.n = ft_mult(d, color);
	return (TRUE);
}

//www.google.com/search?q=rendering+a+sphere+in+c+language&oq=
//rendering+a+sphere+in+c+&aqs=chrome.3.69i57j33i160l3.9737j1j7&sourceid=chrome&
//ie=UTF-8#fpstate=ive&vld=cid:86a89d49,vid:v9vndyfk2U8

int	inter_plane(t_rays *rays)
{
	float		denom;
	t_vector	oc;
	float		t;
	// float 		d;	
	rays->plan.plan_orient = normalize(rays->plan.plan_orient);
	rays->plan.plan_pos = normalize(rays->plan.plan_pos);
	denom = dot(rays->ray_dir, rays->plan.plan_orient);
	oc = minus(rays->plan.plan_pos, rays->ray_orig);
	t = dot(oc, rays->plan.plan_orient) / denom;
	if (t >= 0.0)
	{
		// printf("%f\n", t);
		rays->light.p = (ft_plus((rays->ray_orig), ft_mult(rays->t, rays->ray_dir)));
		rays->light.n = rays->plan.plan_orient;
		// d = (dot(rays->light.n, ft_mult(-1, rays->light.light_dir)));
		// rays->light.n = ft_mult(d, rays->light.albedo);
		normalize((minus(rays->light.p, rays->plan.plan_orient)));
		return (TRUE);
	}
	return (FALSE);
}

// int	routine_inter(t_rays *rays)
// {
	
// }
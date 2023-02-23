/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:21:40 by nnemeth           #+#    #+#             */
/*   Updated: 2023/02/23 13:56:01 by fmalizia         ###   ########.ch       */
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
	if (rays->t2 > rays->t)
		return (FALSE);
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
	rays->plan.plan_orient = normalize(rays->plan.plan_orient);
	// rays->plan.plan_pos = normalize(rays->plan.plan_pos);
	denom = dot(rays->ray_dir, rays->plan.plan_orient);
	oc = minus(rays->ray_orig, rays->plan.plan_pos);
	t = (-1 * dot(oc, rays->plan.plan_orient)) / denom;
	if (t < 0)
		return (FALSE);
	if (t < rays->t)
		rays->t = t;
	else
		return(FALSE);
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

int	inter_cylinder(t_rays *rays)
{
	float		a;
	float		b;
	float		c;
	float		delta;
	float		m;
	float		d;
	float		t_tmp;
	t_vector	vm;
	t_vector	oc;

	oc = minus(rays->ray_orig, rays->cyl.cyl_cord);
	rays->cyl.cyl_vec = normalize(rays->cyl.cyl_vec);
	a = dot(rays->ray_dir, rays->ray_dir) - powf(dot(rays->ray_dir, rays->cyl.cyl_vec), 2);
	b = 2.0f * (dot(rays->ray_dir, oc) - (dot(rays->ray_dir, rays->cyl.cyl_vec) * dot(oc, rays->cyl.cyl_vec)));
	c = dot(oc, oc) - powf(dot(oc, rays->cyl.cyl_vec), 2) - powf(rays->cyl.dia / 2, 2);
	delta = (b * b) - (4 * a * c);
	if (delta < 0)
		return (FALSE);
	rays->t1 = (-b + sqrt(delta)) / (2 * a);
	rays->t2 = (-b - sqrt(delta)) / (2 * a);
	t_tmp = rays->t;
	if (rays->t2 > rays->t)
		return (FALSE);
	if (rays->t2 > 0)
		rays->t = rays->t2;
	else
		rays->t = rays->t1;
	rays->light.p = (ft_plus((rays->ray_orig), ft_mult(rays->t, rays->ray_dir)));
	m = (dot(rays->ray_dir, rays->cyl.cyl_vec) * rays->t) + dot(oc, rays->cyl.cyl_vec);
	if (m < 0 || m > rays->cyl.height)
	{
		rays->t = t_tmp;
		return (FALSE);
	}
	vm = ft_mult(m, rays->cyl.cyl_vec);
	rays->light.n =	normalize(minus(minus(rays->light.p, rays->cyl.cyl_cord), vm));
	rays->light.light_dir = normalize(rays->light.light_dir);
	d = (dot(rays->light.n, ft_mult(-1, rays->light.light_dir)));
	rays->light.n = ft_mult(d, rays->cyl.cyl_clr);
	return(TRUE);
}

// int	routine_inter(t_rays *rays)
// {
	
// }
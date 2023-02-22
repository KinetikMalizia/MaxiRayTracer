/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:03:39 by nnemeth           #+#    #+#             */
/*   Updated: 2023/02/21 16:09:56 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

double	getnorm(t_vector vector)
{
	return (vector.x * vector.x + vector.y * vector.y
		+ vector.z * vector.z);
}

t_vector	normalize(t_vector vector)
{
	float	norm;

	norm = sqrt(getnorm(vector));
	vector.x /= norm;
	vector.y /= norm;
	vector.z /= norm;
	return (vector);
}

double	dot(t_vector ray_dir, t_vector ray_o)
{
	return (ray_dir.x * ray_o.x + ray_dir.y * ray_o.y
		+ ray_dir.z * ray_o.z);
}

t_vector	minus(t_vector origin, t_vector position)
{
	t_vector	new;

	new.x = origin.x - position.x;
	new.y = origin.y - position.y;
	new.z = origin.z - position.z;
	return (new);
}

void	reverse_vector(t_vector *vec)
{
	vec->x *= -1;
	vec->y *= -1;
	vec->z *= -1;
}

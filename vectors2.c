/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikki <nikki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:58:16 by nnemeth           #+#    #+#             */
/*   Updated: 2023/02/18 12:10:07 by nikki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

t_vector	ft_mult(double t, t_vector v1)
{
	t_vector	new;

	new.x = t * v1.x;
	new.y = t * v1.y;
	new.z = t * v1.z;
	return (new);
}

double	ft_mult2(t_vector v2, t_vector v1)
{
	return (v2.x * v1.x + v2.y * v1.y + v2.z * v1.z);
}

t_vector	ft_plus(t_vector origin, t_vector position)
{
	t_vector	new;

	new.x = origin.x + position.x;
	new.y = origin.y + position.y;
	new.z = origin.z + position.z;
	return (new);
}

double	ft_max(double clr)
{
	if (clr > 255)
		clr = 255;
	if (clr < 0)
		clr = 0;
	return (clr);
}

t_vector	ft_divide(t_vector v1, double a)
{
	t_vector	new;

	new.x = v1.x / a;
	new.y = v1.y / a;
	new.z = v1.z / a;
	return (new);
}

t_vector	ft_mult_vec(t_vector v1, t_vector v2)
{
	t_vector	new;

	new.x = v1.x * v2.x;
	new.y = v1.y * v2.y;
	new.z = v1.z * v2.z;
	return (new);
}

t_vector	add_values(double x, double y, double z)
{
	t_vector new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}
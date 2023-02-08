/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:41:30 by nnemeth           #+#    #+#             */
/*   Updated: 2023/02/08 12:58:18 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <string.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "minilibx/mlx.h"
# include "Libft/libft/libft.h"

# define BUFFER_SIZE 42
# define KEY_ESC 53
# define IMG_WIDTH 1024
# define IMG_HEIGHT 1024
# define TRUE 1
# define FALSE 0

# define H 800
# define W 800

typedef struct S_coord
{
	float	x;	
	float	y;
	float	z;
}	t_coord;

typedef struct S_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef struct S_color
{
	int		col_r;
	int		col_g;
	double	col_b;
}	t_color;

typedef struct S_plane
{
	t_vector	plan;
	t_coord		plane;
	t_color		plan_col;
}	t_plane;

typedef struct S_cam
{
	t_coord		cam;
	t_vector	pos;
	t_color		col;
	float		cam_fov;
}	t_cam;

typedef struct S_sphere
{
	t_vector	sph_cord;
	float		sphere_dia;
	float		sphere_rad;
	int			sphere_color;
}	t_sphere;

typedef struct S_light
{
	t_vector	light_point;
	t_vector	p;
	t_vector	n;
	t_color		light_clr;
	double		l_bright;
	t_vector	intens_pixel;
}	t_light;

typedef struct S_cyl
{
	t_vector	cyl_vec;
	t_color		cyl_clr;
	t_coord		cyl_cord;
	double		dia;
	double		height;
}	t_cyl;

typedef struct S_rays
{
	double		a_light_ratio;
	t_color		a_light_color;
	t_cam		cam;
	t_light		light;
	t_sphere	sphere;
	t_plane		plan;
	t_cyl		cyl;
	double		t1;
	double		t2;
	t_vector	ray_dir;
	t_vector	ray_orig;		
	int			win_i;
	int			win_y;
	char		**map;
	void		*img;
	void		*mlx_ptr;
	void		*win_ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_rays;

// parsing of the .rt doc

t_rays		*init_struct(void);
char		*get_next_line(int fd);
void		check_args(char *argv);
int			read_doc(t_rays *rays, char *arg);
void		get_info(t_rays *rays);
void		get_lightning(t_rays *rays, char *light);
int			new_atoi(char *str);
int			ft_isspace(unsigned char c);
double		my_atof(const char *str, double b);
void		get_camera(t_rays *rays, char *cam);

// set the scene

void		load_scene(t_rays *rays);
int			end_game(t_rays *rays);
void		load_scene(t_rays *rays);
void		my_mlx_pixel_put(t_rays *rays, int x, int y, int color);
int			color(double r, double g, double b);
int			ray_color(int t, int r, int g, int b);
int			inter_sphere(t_rays *rays);
double		getnorm(t_vector vector);
void		normalize(t_vector vector);
void		set_scene(t_rays *rays);
double		dot(t_vector ray_dir, t_vector ray_o);
t_vector	minus(t_vector origin, t_vector position);
void		ft_init_window(t_rays *rays);
void		get_light(t_rays *rays);
t_vector	ft_minus(t_vector v1, t_vector v2);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:41:30 by nnemeth           #+#    #+#             */
/*   Updated: 2023/02/23 13:44:28 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <string.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <ctype.h>
# include "minilibx/mlx.h"
# include "Libft/libft/libft.h"

# define BUFFER_SIZE 42
# define KEY_ESC 53
# define IMG_WIDTH 1024
# define IMG_HEIGHT 1024
# define TRUE 1
# define FALSE 0
# define KEY_ESC 53

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
	double	col_r;
	double	col_g;
	double	col_b;
}	t_color;

typedef struct S_plane
{
	t_vector	plan_orient;
	t_vector	plan_pos;
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
	t_vector	light_dir;
	t_vector	shadow_ray;
	t_vector	p;
	t_vector	n;
	t_color		light_clr;
	float		l_bright;
	t_vector	intens_pixel;
	t_vector	albedo;
}	t_light;

typedef struct S_cyl
{
	t_vector	cyl_vec;
	t_vector	cyl_clr;
	t_vector	cyl_cord;
	double		dia;
	double		height;
}	t_cyl;

typedef struct S_rays
{
	double		a_light_ratio;
	t_color		a_light_color;
	t_light		l_shadow;
	t_cam		cam;
	t_light		light;
	t_sphere	sphere;
	t_plane		plan;
	t_cyl		cyl;
	float		t;
	float		t1;
	float		t2;
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
int			close_window(t_rays *rays);
int			escape(int keycode, t_rays *rays);
void		load_scene(t_rays *rays);
void		my_mlx_pixel_put(t_rays *rays, int x, int y, int color);
int			color(double r, double g, double b);
int			ray_color(int t, int r, int g, int b);
int			inter_sphere(t_rays *rays);
double		getnorm(t_vector vector);
t_vector	normalize(t_vector vector);
void		set_scene(t_rays *rays);
double		dot(t_vector ray_dir, t_vector ray_o);
t_vector	minus(t_vector origin, t_vector position);
void		ft_init_window(t_rays *rays);
t_vector	get_light(t_rays *rays);
t_vector	ft_minus(t_vector v1, t_vector v2);
t_vector	ft_mult(double t, t_vector v1);
double		ft_mult2(t_vector v2, t_vector v1);
t_vector	ft_plus(t_vector origin, t_vector position);
double		ft_max(double clr);
t_vector	ft_divide(t_vector v1, double a);
int			color2(double r, double g, double b);
t_vector	ft_mult_vec(t_vector v1, t_vector v2);
int			inter_plane(t_rays *rays);
t_vector	add_amb(t_rays *rays);
t_vector	add_values(double x, double y, double z);
void		reverse_vector(t_vector *vec);
int			inter_cylinder(t_rays *rays);


//---------------------//
/*

char		*readfile(char *filename); //read all the file and return it as a big str
char		**split_string(const char *str, char sep); //take a string, split the elements every <sep> and return all the elements as a tab
void		convert_tab(char **tab, t_data *data); //take a tab that contains string, split them and save them in a struct.
void		print_tab(char **tab); //print a tab
int			ft_stoi(char *str); //convert str to int
float		ft_strtof(const char* str); //convert str to float
int 		ft_strinstr(const char* str, const char* substr);//check if there is a specified str in another str
void		free_tab(char **tab);//free a tab
char 		*ft_strcpy(char *dest, char *src, size_t dest_size);
char 		*ft_strncpy(char *dest, const char *src, size_t n);
char 		*ft_realloc(char *org, int n_size);
int			contains_alpha(char* str);

#define BUFSIZE 1024

typedef struct s_color
{
	double	col_r;
	double	col_g;
	double	col_b;
}	t_color;

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef struct s_form
{
	char		*type;
	t_vector	coord;
	t_color		color;
	t_vector	orient;
	float		sphere_rad;
	float		cyl_dia;
	float		cyl_height;
	struct s_form *next;
}	t_form;

typedef struct s_cam
{
	t_vector 	coord;
	t_vector 	orient;
	int			fov;
}	t_cam;

typedef struct s_light
{
	char			type;
	t_vector		coord;
	t_color			color;
	float 			ratio;
	struct s_light 	*next;
}	t_light;

typedef struct s_data
{
	int 	element;
	t_form	object;
	t_cam	camera;
	t_light	light;
}	t_data;

*/

#endif
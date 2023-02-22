/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:41:42 by nnemeth           #+#    #+#             */
/*   Updated: 2023/02/21 16:25:26 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

t_rays	*init_struct(void)
{
	t_rays	*rays;

	rays = malloc(sizeof(t_rays) + 1);
	rays->a_light_ratio = 0.7;
	rays->a_light_color.col_b = 0.8;
	rays->a_light_color.col_g = 0.8;
	rays->a_light_color.col_r = 0.8;
	rays->map = NULL;
	rays->sphere.sph_cord.x = 0;
	rays->sphere.sph_cord.y = 0;
	rays->sphere.sph_cord.z = -30;
	rays->sphere.sphere_dia = 12.6;
	rays->sphere.sphere_rad = 5.5;
	rays->cam.pos.x = 0;
	rays->cam.pos.y = 0;
	rays->cam.pos.z = 1;
	// rays->cam.cam.x = 0;
	// rays->cam.cam.y = 30;
	// rays->cam.cam.z = 20;
	rays->cam.cam_fov = 45 * (M_PI / 180);
	rays->light.light_point.x = 10;
	rays->light.light_point.y = 20;
	rays->light.light_point.z = -40;
	rays->light.light_dir.x = 2.8;
	rays->light.light_dir.y = 1.9;
	rays->light.light_dir.z = -1.5;
	rays->light.l_bright = 3.5;
	rays->light.albedo.x = 1;
	rays->light.albedo.y = 0;
	rays->light.albedo.z = 1;
	rays->plan.plan_orient.x = 0;
	rays->plan.plan_orient.y = 0;
	rays->plan.plan_orient.z = -1;
	rays->plan.plan_pos.x = 0;
	rays->plan.plan_pos.y = 10;
	rays->plan.plan_pos.z = -20;
	return (rays);
}

void	check_args(char *arg)
{
	if (!strchr(arg, '.'))
	{
		printf("%s\n", "Invalid file!");
		exit(1);
	}
	if (ft_strncmp((ft_strrchr(arg, '.')), ".rt", 4))
	{
		printf("%s\n", "Invalid extension!");
		exit(1);
	}
}

int	read_doc(t_rays *rays, char *arg)
{
	char	*line;	
	char	*comb;
	int		fd;

	fd = open(arg, O_RDONLY);
	comb = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		comb = ft_strjoin(comb, line);
		free(line);
	}
	rays->map = ft_split(comb, '\n');
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	t_rays	*rays;

	if (argc == 2)
	{
		rays = init_struct();
		check_args(argv[1]);
		read_doc(rays, argv[1]);
		get_info(rays);
		load_scene(rays);
		mlx_key_hook(rays->win_ptr, escape, rays);
		mlx_hook(rays->win_ptr, 17, 0, close_window, rays);
		mlx_loop(rays->mlx_ptr);
		mlx_destroy_window(rays->mlx_ptr, rays->win_ptr);
	}
	else
	{
		printf("You have the launch the program with an .rt file\n");
		return (0);
	}
	return (0);
}

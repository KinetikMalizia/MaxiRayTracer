/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:41:42 by nnemeth           #+#    #+#             */
/*   Updated: 2023/02/08 12:23:22 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

t_rays	*init_struct(void)
{
	t_rays	*rays;

	rays = malloc(sizeof(t_rays) + 1);
	rays->a_light_ratio = 0;
	rays->cam.cam_fov = 0;
	rays->plan.plan.x = 0;
	rays->sphere.sphere_color = 0;
	rays->map = NULL;
	rays->sphere.sph_cord.x = 0;
	rays->sphere.sph_cord.y = 0;
	rays->sphere.sph_cord.z = 20.6;
	rays->sphere.sphere_dia = 12.6;
	rays->sphere.sphere_rad = 6.3;
	rays->cam.pos.x = 0;
	rays->cam.pos.y = 0;
	rays->cam.pos.z = 1;
	rays->cam.cam.x = 0;
	rays->cam.cam.y = 30;
	rays->cam.cam.z = 20;
	rays->cam.cam_fov = 60 * (M_PI / 180);
	rays->light.light_point.x = 0;
	rays->light.light_point.y = 0;
	rays->light.light_point.z = 20.6;
	rays->light.l_bright = 0.6;
	rays->light.intens_pixel = 0;
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
		mlx_hook(rays->win_ptr, 17, 0, end_game, rays);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 15:10:46 by juthomas          #+#    #+#             */
/*   Updated: 2017/10/16 22:56:50 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main_1(t_wolf *wolf, char **argv)
{
	if ((wolf->mlx = (t_win*)malloc(sizeof(*wolf->mlx))) == NULL)
		return (-1);
	if ((wolf->cast = (t_cast*)malloc(sizeof(*wolf->cast))) == NULL)
		return (-1);
	if ((wolf->ground = (t_ground*)malloc(sizeof(*wolf->ground))) == NULL)
		return (-1);
	if ((wolf->key = (t_key*)malloc(sizeof(*wolf->key))) == NULL)
		return (-1);
	if ((wolf->ammo = (t_tex*)malloc(sizeof(*wolf->ammo))) == NULL)
		return (-1);
	if (malloc_theme_1(wolf))
		return (-1);
	if (malloc_menu_1(wolf))
		return (-1);
	setup_key(wolf);
	wolf->cast->plan_x = 0;
	wolf->cast->plan_y = 0.66;
	wolf->sky_x = 0;
	if (is_true_map(argv, wolf) == 0)
	{
		ft_putstr_fd("Map Error\n", 2);
		exit(-1);
	}
	return (0);
}

void	main_2(t_wolf *wolf)
{
	wolf->cast->dir_x = -1;
	wolf->cast->dir_y = 0;
	wolf->mlx->mlx = mlx_init();
	wolf->mlx->win = mlx_new_window(wolf->mlx->mlx, X_WIN, Y_WIN,
			"WOLFENSTEIN Mamene");
	wolf->mlx->img = mlx_new_image(wolf->mlx->mlx, X_WIN, Y_WIN);
	wolf->mlx->addr = mlx_get_data_addr(wolf->mlx->img, &wolf->mlx->bpp,
			&wolf->mlx->sizeline, &wolf->mlx->endian);
	wolf->dyke = wolf->theme->t1_wall;
	wolf->floor = wolf->theme->t1_floor;
	wolf->cloud = wolf->theme->t1_roof;
	wolf->sun = wolf->theme->t1_sun;
}

void	help(void)
{
	ft_putstr_fd("Usage : \"./wolf3d [Map.wlf]\"\n", 2);
	ft_putstr_fd("        You can use the map generator\n", 2);
	ft_putstr_fd("        to create a map\n", 2);
	ft_putstr_fd("        Ex : \"./gen_map/map_gen 30 30 30\"\n", 2);
}

int		main(int argc, char **argv)
{
	t_wolf	*wolf;

	wolf = 0;
	if (argc == 2)
	{
		if ((wolf = (t_wolf*)malloc(sizeof(*wolf))) == NULL)
			return (-1);
		if (main_1(wolf, argv) == -1)
			return (-1);
		main_2(wolf);
		xpm_to_img(wolf);
		mlx_hook(wolf->mlx->win, 17, (1L << 17), eteindre, NULL);
		mlx_hook(wolf->mlx->win, 2, (1L << 0), press_key, wolf);
		mlx_hook(wolf->mlx->win, 3, (1L << 1), release_key, wolf);
		mlx_loop_hook(wolf->mlx->mlx, infinity_loop, wolf);
		mlx_put_image_to_window(wolf->mlx->mlx, wolf->mlx->win,
				wolf->mlx->img, 0, 0);
		mlx_loop(wolf->mlx->mlx);
		system("killall afplay");
	}
	else
		help();
	return (0);
}

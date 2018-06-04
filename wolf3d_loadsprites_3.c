/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_loadsprites_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 23:35:59 by juthomas          #+#    #+#             */
/*   Updated: 2017/10/11 23:37:12 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		theme_to_xpm_theme_img_3(t_theme *theme, t_win *win)
{
	if (!(theme->t4_floor->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/textures/theme_4_floor.xpm",
					&theme->t4_floor->x, &theme->t4_floor->y)))
		return (1);
	if (!(theme->t4_roof->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/textures/theme_4_roof.xpm",
					&theme->t4_roof->x, &theme->t4_roof->y)))
		return (1);
	if (!(theme->t4_wall->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/textures/theme_4_wall.xpm",
					&theme->t4_wall->x, &theme->t4_wall->y)))
		return (1);
	if (!(theme->t4_sun->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/textures/theme_4_sun.xpm",
					&theme->t4_sun->x, &theme->t4_sun->y)))
		return (1);
	if (!(theme->t5_floor->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/textures/theme_5_floor.xpm",
					&theme->t5_floor->x, &theme->t5_floor->y)))
		return (1);
	if (!(theme->t5_roof->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/textures/theme_5_roof.xpm",
					&theme->t5_roof->x, &theme->t5_roof->y)))
		return (1);
	return (0);
}

int		theme_to_xpm_theme_img(t_theme *theme, t_win *win)
{
	if (theme_to_xpm_theme_img_1(theme, win))
		return (1);
	if (theme_to_xpm_theme_img_2(theme, win))
		return (1);
	if (theme_to_xpm_theme_img_3(theme, win))
		return (1);
	if (!(theme->t5_wall->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/textures/theme_5_wall.xpm",
					&theme->t5_wall->x, &theme->t5_wall->y)))
		return (1);
	if (!(theme->t5_sun->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/textures/theme_5_sun.xpm",
					&theme->t5_sun->x, &theme->t5_sun->y)))
		return (1);
	return (0);
}

void	theme_to_xpm_theme_addr_1(t_theme *theme)
{
	theme->t1_floor->addr = mlx_get_data_addr(theme->t1_floor->img,
			&theme->t1_floor->bpp, &theme->t1_floor->sizeline,
			&theme->t1_floor->endian);
	theme->t1_roof->addr = mlx_get_data_addr(theme->t1_roof->img,
			&theme->t1_roof->bpp, &theme->t1_roof->sizeline,
			&theme->t1_roof->endian);
	theme->t1_wall->addr = mlx_get_data_addr(theme->t1_wall->img,
			&theme->t1_wall->bpp, &theme->t1_wall->sizeline,
			&theme->t1_wall->endian);
	theme->t1_sun->addr = mlx_get_data_addr(theme->t1_sun->img,
			&theme->t1_sun->bpp, &theme->t1_sun->sizeline,
			&theme->t1_sun->endian);
	theme->t2_floor->addr = mlx_get_data_addr(theme->t2_floor->img,
			&theme->t2_floor->bpp, &theme->t2_floor->sizeline,
			&theme->t2_floor->endian);
	theme->t2_roof->addr = mlx_get_data_addr(theme->t2_roof->img,
			&theme->t2_roof->bpp, &theme->t2_roof->sizeline,
			&theme->t2_roof->endian);
	theme->t2_wall->addr = mlx_get_data_addr(theme->t2_wall->img,
			&theme->t2_wall->bpp, &theme->t2_wall->sizeline,
			&theme->t2_wall->endian);
	theme->t2_sun->addr = mlx_get_data_addr(theme->t2_sun->img,
			&theme->t2_sun->bpp, &theme->t2_sun->sizeline,
			&theme->t2_sun->endian);
}

void	theme_to_xpm_theme_addr_2(t_theme *theme)
{
	theme->t3_floor->addr = mlx_get_data_addr(theme->t3_floor->img,
			&theme->t3_floor->bpp, &theme->t3_floor->sizeline,
			&theme->t3_floor->endian);
	theme->t3_roof->addr = mlx_get_data_addr(theme->t3_roof->img,
			&theme->t3_roof->bpp, &theme->t3_roof->sizeline,
			&theme->t3_roof->endian);
	theme->t3_wall->addr = mlx_get_data_addr(theme->t3_wall->img,
			&theme->t3_wall->bpp, &theme->t3_wall->sizeline,
			&theme->t3_wall->endian);
	theme->t3_sun->addr = mlx_get_data_addr(theme->t3_sun->img,
			&theme->t3_sun->bpp, &theme->t3_sun->sizeline,
			&theme->t3_sun->endian);
	theme->t4_floor->addr = mlx_get_data_addr(theme->t4_floor->img,
			&theme->t4_floor->bpp, &theme->t4_floor->sizeline,
			&theme->t4_floor->endian);
	theme->t4_roof->addr = mlx_get_data_addr(theme->t4_roof->img,
			&theme->t4_roof->bpp, &theme->t4_roof->sizeline,
			&theme->t4_roof->endian);
	theme->t4_wall->addr = mlx_get_data_addr(theme->t4_wall->img,
			&theme->t4_wall->bpp, &theme->t4_wall->sizeline,
			&theme->t4_wall->endian);
	theme->t4_sun->addr = mlx_get_data_addr(theme->t4_sun->img,
			&theme->t4_sun->bpp, &theme->t4_sun->sizeline,
			&theme->t4_sun->endian);
}

void	theme_to_xpm_theme_addr(t_theme *theme)
{
	theme_to_xpm_theme_addr_1(theme);
	theme_to_xpm_theme_addr_2(theme);
	theme->t5_floor->addr = mlx_get_data_addr(theme->t5_floor->img,
			&theme->t5_floor->bpp, &theme->t5_floor->sizeline,
			&theme->t5_floor->endian);
	theme->t5_roof->addr = mlx_get_data_addr(theme->t5_roof->img,
			&theme->t5_roof->bpp, &theme->t5_roof->sizeline,
			&theme->t5_roof->endian);
	theme->t5_wall->addr = mlx_get_data_addr(theme->t5_wall->img,
			&theme->t5_wall->bpp, &theme->t5_wall->sizeline,
			&theme->t5_wall->endian);
	theme->t5_sun->addr = mlx_get_data_addr(theme->t5_sun->img,
			&theme->t5_sun->bpp, &theme->t5_sun->sizeline,
			&theme->t5_sun->endian);
}

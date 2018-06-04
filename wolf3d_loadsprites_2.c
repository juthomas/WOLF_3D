/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_loadsprites_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 23:33:17 by juthomas          #+#    #+#             */
/*   Updated: 2017/10/12 02:03:49 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	menu_to_xpm_theme_addr_2(t_menu *menu)
{
	menu->t_3_g_1->addr = mlx_get_data_addr(menu->t_3_g_1->img,
			&menu->t_3_g_1->bpp, &menu->t_3_g_1->sizeline,
			&menu->t_3_g_1->endian);
	menu->t_3_g_1_f->addr = mlx_get_data_addr(menu->t_3_g_1_f->img,
			&menu->t_3_g_1_f->bpp, &menu->t_3_g_1_f->sizeline,
			&menu->t_3_g_1_f->endian);
	menu->t_3_g_2->addr = mlx_get_data_addr(menu->t_3_g_2->img,
			&menu->t_3_g_2->bpp, &menu->t_3_g_2->sizeline,
			&menu->t_3_g_2->endian);
	menu->t_3_g_2_f->addr = mlx_get_data_addr(menu->t_3_g_2_f->img,
			&menu->t_3_g_2_f->bpp, &menu->t_3_g_2_f->sizeline,
			&menu->t_3_g_2_f->endian);
	menu->t_4_g_1->addr = mlx_get_data_addr(menu->t_4_g_1->img,
			&menu->t_4_g_1->bpp, &menu->t_4_g_1->sizeline,
			&menu->t_4_g_1->endian);
	menu->t_4_g_1_f->addr = mlx_get_data_addr(menu->t_4_g_1_f->img,
			&menu->t_4_g_1_f->bpp, &menu->t_4_g_1_f->sizeline,
			&menu->t_4_g_1_f->endian);
	menu->t_4_g_2->addr = mlx_get_data_addr(menu->t_4_g_2->img,
			&menu->t_4_g_2->bpp, &menu->t_4_g_2->sizeline,
			&menu->t_4_g_2->endian);
	menu->t_4_g_2_f->addr = mlx_get_data_addr(menu->t_4_g_2_f->img,
			&menu->t_4_g_2_f->bpp, &menu->t_4_g_2_f->sizeline,
			&menu->t_4_g_2_f->endian);
}

void	menu_to_xpm_theme_addr(t_menu *menu)
{
	menu_to_xpm_theme_addr_1(menu);
	menu_to_xpm_theme_addr_2(menu);
	menu->t_5_g_1->addr = mlx_get_data_addr(menu->t_5_g_1->img,
			&menu->t_5_g_1->bpp, &menu->t_5_g_1->sizeline,
			&menu->t_5_g_1->endian);
	menu->t_5_g_1_f->addr = mlx_get_data_addr(menu->t_5_g_1_f->img,
			&menu->t_5_g_1_f->bpp, &menu->t_5_g_1_f->sizeline,
			&menu->t_5_g_1_f->endian);
	menu->t_5_g_2->addr = mlx_get_data_addr(menu->t_5_g_2->img,
			&menu->t_5_g_2->bpp, &menu->t_5_g_2->sizeline,
			&menu->t_5_g_2->endian);
	menu->t_5_g_2_f->addr = mlx_get_data_addr(menu->t_5_g_2_f->img,
			&menu->t_5_g_2_f->bpp, &menu->t_5_g_2_f->sizeline,
			&menu->t_5_g_2_f->endian);
}

void	menu_to_xpm(t_wolf *wolf)
{
	t_menu	*menu;
	t_win	*win;

	win = wolf->mlx;
	menu = wolf->menu;
	if (menu_to_xpm_theme_img(menu, win))
		exit(-1);
	menu_to_xpm_theme_addr(menu);
}

int		theme_to_xpm_theme_img_1(t_theme *theme, t_win *win)
{
	if (!(theme->t1_floor->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/textures/theme_1_floor.xpm",
					&theme->t1_floor->x, &theme->t1_floor->y)))
		return (1);
	if (!(theme->t1_roof->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/textures/theme_1_roof.xpm",
					&theme->t1_roof->x, &theme->t1_roof->y)))
		return (1);
	if (!(theme->t1_wall->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/textures/theme_1_wall.xpm",
					&theme->t1_wall->x, &theme->t1_wall->y)))
		return (1);
	if (!(theme->t1_sun->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/textures/theme_1_sun.xpm",
					&theme->t1_sun->x, &theme->t1_sun->y)))
		return (1);
	if (!(theme->t2_floor->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/textures/theme_2_floor.xpm",
					&theme->t2_floor->x, &theme->t2_floor->y)))
		return (1);
	if (!(theme->t2_roof->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/textures/theme_2_roof.xpm",
					&theme->t2_roof->x, &theme->t2_roof->y)))
		return (1);
	return (0);
}

int		theme_to_xpm_theme_img_2(t_theme *theme, t_win *win)
{
	if (!(theme->t2_wall->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/textures/theme_2_wall.xpm",
					&theme->t2_wall->x, &theme->t2_wall->y)))
		return (1);
	if (!(theme->t2_sun->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/textures/theme_2_sun.xpm",
					&theme->t2_sun->x, &theme->t2_sun->y)))
		return (1);
	if (!(theme->t3_floor->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/textures/theme_3_floor.xpm",
					&theme->t3_floor->x, &theme->t3_floor->y)))
		return (1);
	if (!(theme->t3_roof->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/textures/theme_3_roof.xpm",
					&theme->t3_roof->x, &theme->t3_roof->y)))
		return (1);
	if (!(theme->t3_wall->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/textures/theme_3_wall.xpm",
					&theme->t3_wall->x, &theme->t3_wall->y)))
		return (1);
	if (!(theme->t3_sun->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/textures/theme_3_sun.xpm",
					&theme->t3_sun->x, &theme->t3_sun->y)))
		return (1);
	return (0);
}

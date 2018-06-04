/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_loadsprites_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 23:28:27 by juthomas          #+#    #+#             */
/*   Updated: 2017/10/12 02:03:22 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		menu_to_xpm_theme_img_1(t_menu *menu, t_win *win)
{
	if (!(menu->t_1_g_1->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/interface/theme_1_gun_1.xpm",
					&menu->t_1_g_1->x, &menu->t_1_g_1->y)))
		return (1);
	if (!(menu->t_1_g_1_f->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/interface/theme_1_gun_1_f.xpm",
					&menu->t_1_g_1_f->x, &menu->t_1_g_1_f->y)))
		return (1);
	if (!(menu->t_1_g_2->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/interface/theme_1_gun_2.xpm",
					&menu->t_1_g_2->x, &menu->t_1_g_2->y)))
		return (1);
	if (!(menu->t_1_g_2_f->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/interface/theme_1_gun_2_f.xpm",
					&menu->t_1_g_2_f->x, &menu->t_1_g_2_f->y)))
		return (1);
	if (!(menu->t_2_g_1->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/interface/theme_2_gun_1.xpm",
					&menu->t_2_g_1->x, &menu->t_2_g_1->y)))
		return (1);
	if (!(menu->t_2_g_1_f->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/interface/theme_2_gun_1_f.xpm",
					&menu->t_2_g_1_f->x, &menu->t_2_g_1_f->y)))
		return (1);
	return (0);
}

int		menu_to_xpm_theme_img_2(t_menu *menu, t_win *win)
{
	if (!(menu->t_2_g_2->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/interface/theme_2_gun_2.xpm",
					&menu->t_2_g_2->x, &menu->t_2_g_2->y)))
		return (1);
	if (!(menu->t_2_g_2_f->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/interface/theme_2_gun_2_f.xpm",
					&menu->t_2_g_2_f->x, &menu->t_2_g_2_f->y)))
		return (1);
	if (!(menu->t_3_g_1->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/interface/theme_3_gun_1.xpm",
					&menu->t_3_g_1->x, &menu->t_3_g_1->y)))
		return (1);
	if (!(menu->t_3_g_1_f->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/interface/theme_3_gun_1_f.xpm",
					&menu->t_3_g_1_f->x, &menu->t_3_g_1_f->y)))
		return (1);
	if (!(menu->t_3_g_2->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/interface/theme_3_gun_2.xpm",
					&menu->t_3_g_2->x, &menu->t_3_g_2->y)))
		return (1);
	if (!(menu->t_3_g_2_f->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/interface/theme_3_gun_2_f.xpm",
					&menu->t_3_g_2_f->x, &menu->t_3_g_2_f->y)))
		return (1);
	return (0);
}

int		menu_to_xpm_theme_img_3(t_menu *menu, t_win *win)
{
	if (!(menu->t_4_g_1->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/interface/theme_4_gun_1.xpm",
					&menu->t_4_g_1->x, &menu->t_4_g_1->y)))
		return (1);
	if (!(menu->t_4_g_1_f->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/interface/theme_4_gun_1_f.xpm",
					&menu->t_4_g_1_f->x, &menu->t_4_g_1_f->y)))
		return (1);
	if (!(menu->t_4_g_2->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/interface/theme_4_gun_2.xpm",
					&menu->t_4_g_2->x, &menu->t_4_g_2->y)))
		return (1);
	if (!(menu->t_4_g_2_f->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/interface/theme_4_gun_2_f.xpm",
					&menu->t_4_g_2_f->x, &menu->t_4_g_2_f->y)))
		return (1);
	if (!(menu->t_5_g_1->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/interface/theme_5_gun_1.xpm",
					&menu->t_5_g_1->x, &menu->t_5_g_1->y)))
		return (1);
	if (!(menu->t_5_g_1_f->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/interface/theme_5_gun_1_f.xpm",
					&menu->t_5_g_1_f->x, &menu->t_5_g_1_f->y)))
		return (1);
	return (0);
}

int		menu_to_xpm_theme_img(t_menu *menu, t_win *win)
{
	if (menu_to_xpm_theme_img_1(menu, win))
		return (1);
	if (menu_to_xpm_theme_img_2(menu, win))
		return (1);
	if (menu_to_xpm_theme_img_3(menu, win))
		return (1);
	if (!(menu->t_5_g_2->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/interface/theme_5_gun_2.xpm",
					&menu->t_5_g_2->x, &menu->t_5_g_2->y)))
		return (1);
	if (!(menu->t_5_g_2_f->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/interface/theme_5_gun_2_f.xpm",
					&menu->t_5_g_2_f->x, &menu->t_5_g_2_f->y)))
		return (1);
	return (0);
}

void	menu_to_xpm_theme_addr_1(t_menu *menu)
{
	menu->t_1_g_1->addr = mlx_get_data_addr(menu->t_1_g_1->img,
			&menu->t_1_g_1->bpp, &menu->t_1_g_1->sizeline,
			&menu->t_1_g_1->endian);
	menu->t_1_g_1_f->addr = mlx_get_data_addr(menu->t_1_g_1_f->img,
			&menu->t_1_g_1_f->bpp, &menu->t_1_g_1_f->sizeline,
			&menu->t_1_g_1_f->endian);
	menu->t_1_g_2->addr = mlx_get_data_addr(menu->t_1_g_2->img,
			&menu->t_1_g_2->bpp, &menu->t_1_g_2->sizeline,
			&menu->t_1_g_2->endian);
	menu->t_1_g_2_f->addr = mlx_get_data_addr(menu->t_1_g_2_f->img,
			&menu->t_1_g_2_f->bpp, &menu->t_1_g_2_f->sizeline,
			&menu->t_1_g_2_f->endian);
	menu->t_2_g_1->addr = mlx_get_data_addr(menu->t_2_g_1->img,
			&menu->t_2_g_1->bpp, &menu->t_2_g_1->sizeline,
			&menu->t_2_g_1->endian);
	menu->t_2_g_1_f->addr = mlx_get_data_addr(menu->t_2_g_1_f->img,
			&menu->t_2_g_1_f->bpp, &menu->t_2_g_1_f->sizeline,
			&menu->t_2_g_1_f->endian);
	menu->t_2_g_2->addr = mlx_get_data_addr(menu->t_2_g_2->img,
			&menu->t_2_g_2->bpp, &menu->t_2_g_2->sizeline,
			&menu->t_2_g_2->endian);
	menu->t_2_g_2_f->addr = mlx_get_data_addr(menu->t_2_g_2_f->img,
			&menu->t_2_g_2_f->bpp, &menu->t_2_g_2_f->sizeline,
			&menu->t_2_g_2_f->endian);
}

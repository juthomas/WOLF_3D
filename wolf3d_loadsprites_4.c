/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_loadsprites_4.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 23:37:33 by juthomas          #+#    #+#             */
/*   Updated: 2017/10/11 23:39:30 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	theme_to_xpm(t_wolf *wolf)
{
	t_theme	*theme;
	t_win	*win;

	win = wolf->mlx;
	theme = wolf->theme;
	if (theme_to_xpm_theme_img(theme, win))
		exit(-1);
	theme_to_xpm_theme_addr(theme);
}

void	xpm_to_img(t_wolf *wolf)
{
	t_win *win;

	win = wolf->mlx;
	wolf->face_x = 42;
	wolf->face_y = 43;
	if (!(wolf->ammo->img = mlx_xpm_file_to_image(win->mlx,
					"./ress/xpm/ammo.xpm", &wolf->ammo->x, &wolf->ammo->y)))
		exit(-1);
	wolf->ammo->addr = mlx_get_data_addr(wolf->ammo->img,
			&wolf->ammo->bpp, &wolf->ammo->sizeline,
			&wolf->ammo->endian);
	theme_to_xpm(wolf);
	menu_to_xpm(wolf);
}

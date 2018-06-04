/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_img_rd_wr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 23:43:34 by juthomas          #+#    #+#             */
/*   Updated: 2017/10/12 01:57:01 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

unsigned int	get_img_color_xpm_tex(int x, int y, t_tex *tex)
{
	unsigned int	color;

	color = 0;
	if (x < tex->x && y < tex->y && x >= 0 && y >= 0)
	{
		color = tex->addr[(y * tex->sizeline + x * tex->bpp / 8)];
		color += tex->addr[(y * tex->sizeline + x *
				tex->bpp / 8) + 1] * 256;
		color += tex->addr[(y * tex->sizeline + x *
				tex->bpp / 8) + 2] * 256 * 256;
	}
	return (color);
}

void			img_add_px(t_win *mlx, unsigned int color, int x, int y)
{
	if (x < X_WIN && y < Y_WIN && x >= 0 && y >= 0)
	{
		mlx->addr[(y * mlx->sizeline + x * mlx->bpp / 8)] = color;
		mlx->addr[(y * mlx->sizeline + x * mlx->bpp / 8) + 1] = color >> 8;
		mlx->addr[(y * mlx->sizeline + x * mlx->bpp / 8) + 2] = color >> 16;
	}
}

void			img_add_px_2(t_tex *tex, unsigned int color, int x, int y)
{
	if (x < X_WIN && y < Y_WIN && x >= 0 && y >= 0)
	{
		tex->addr[(y * tex->sizeline + x * tex->bpp / 8)] = color;
		tex->addr[(y * tex->sizeline + x * tex->bpp / 8) + 1] = color >> 8;
		tex->addr[(y * tex->sizeline + x * tex->bpp / 8) + 2] = color >> 16;
	}
}

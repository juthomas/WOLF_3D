/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_raycasting_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 00:37:58 by juthomas          #+#    #+#             */
/*   Updated: 2017/10/12 02:07:25 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		put_vertical_line(int x, t_cast *cast, t_wolf *wolf, t_win *mlx)
{
	int				y;
	unsigned int	color;
	int				shadow;

	if (cast->witch_side == 0 && cast->raydir_x > 0)
		shadow = 100;
	else if (cast->witch_side == 0 && cast->raydir_x < 0)
		shadow = 50;
	else if (cast->witch_side == 1 && cast->raydir_y > 0)
		shadow = 75;
	else
		shadow = 45;
	cast->text_fx = (int)(cast->text_x * wolf->dyke->x);
	cast->text_fx = wolf->dyke->x - cast->text_fx - 1;
	y = cast->draw_str;
	while (y < cast->draw_end)
	{
		cast->text_fy = (y * 2 - Y_WIN + cast->hght_wall) *
			(wolf->dyke->y / 2) / cast->hght_wall;
		color = get_img_color_xpm_tex(cast->text_fx, cast->text_fy, wolf->dyke);
		color = color_fade(color, shadow);
		img_add_px(mlx, color, X_WIN - x - 1, y);
		y++;
	}
}

double		get_angle(double x, double y)
{
	if (x < 0 && y >= 0)
		return ((-x + 0.66 - y) / 1.33 * 0.25);
	else if (x < 0 && y < 0)
		return ((0.66 + x - y) / 1.33 * 0.25 + 0.25);
	else if (x >= 0 && y < 0)
		return ((x + 0.66 + y) / 1.33 * 0.25 + 0.5);
	else if (x >= 0 && y >= 0)
		return ((0.66 - x + y) / 1.33 * 0.25 + 0.75);
	return (0);
}

double		apply_roof_2(double r_sun)
{
	if (r_sun < 0)
		r_sun = 1.0 + r_sun;
	r_sun = r_sun - (int)r_sun;
	return (r_sun);
}

void		apply_roof(int x, t_wolf *wolf, t_cast *cast)
{
	int				y;
	double			rap;
	unsigned int	color;
	double			r_sun;

	rap = -cast->camera_x * 0.09 + get_angle(cast->plan_x, cast->plan_y);
	r_sun = rap;
	rap = rap + (float)((float)wolf->sky_x / wolf->key->rot);
	if (rap < 0)
		rap = 1.0 + rap;
	y = 0;
	rap = rap - (int)(rap);
	r_sun = apply_roof_2(r_sun);
	while (y < cast->draw_str)
	{
		if (0x000000 != get_img_color_xpm_tex(r_sun * (float)wolf->sun->x,
					(float)y / (float)Y_WIN * (float)wolf->sun->y, wolf->sun))
			color = get_img_color_xpm_tex(r_sun * (float)wolf->sun->x,
					(float)y / (float)Y_WIN * (float)wolf->sun->y, wolf->sun);
		else
			color = get_img_color_xpm_tex(rap * (float)wolf->cloud->x,
				(float)y / (float)Y_WIN * (float)wolf->cloud->y, wolf->cloud);
		img_add_px(wolf->mlx, color, X_WIN - x - 1, y);
		y++;
	}
}

void		apply_floor_1(t_ground *ground, t_cast *cast)
{
	ground->range_wall = cast->wall_len;
	ground->range_player = 0;
	ground->current_range = 0;
	if (cast->witch_side == 0 && cast->raydir_x > 0)
	{
		ground->f_wall_x = cast->map_x;
		ground->f_wall_y = cast->map_y + cast->text_x;
	}
	else if (cast->witch_side == 0 && cast->raydir_x < 0)
	{
		ground->f_wall_x = cast->map_x + 1;
		ground->f_wall_y = cast->map_y + cast->text_x;
	}
	else if (cast->witch_side == 1 && cast->raydir_y > 0)
	{
		ground->f_wall_x = cast->map_x + cast->text_x;
		ground->f_wall_y = cast->map_y;
	}
	else
	{
		ground->f_wall_x = cast->map_x + cast->text_x;
		ground->f_wall_y = cast->map_y + 1;
	}
}

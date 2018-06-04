/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_raycasting_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 00:43:26 by juthomas          #+#    #+#             */
/*   Updated: 2017/10/12 02:08:28 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	apply_floor(int x, t_wolf *wolf, t_cast *cast)
{
	t_ground		*ground;
	t_tex			*floor;
	int				y;
	unsigned int	color;

	floor = wolf->floor;
	ground = wolf->ground;
	apply_floor_1(ground, cast);
	y = cast->draw_end;
	while (y < Y_WIN - 200)
	{
		ground->current_range = (double)Y_WIN / (2.0 * (double)y -
				(double)Y_WIN);
		ground->weight = (ground->current_range - ground->range_player) /
			(ground->range_wall - ground->range_player);
		ground->current_x = ground->weight * ground->f_wall_x +
			(1.0 - ground->weight) * wolf->x_player;
		ground->current_y = ground->weight * ground->f_wall_y +
			(1.0 - ground->weight) * wolf->y_player;
		ground->text_x = (int)(ground->current_x * floor->x) % floor->x;
		ground->text_y = (int)(ground->current_y * floor->y) % floor->y;
		color = get_img_color_xpm_tex(ground->text_x, ground->text_y, floor);
		img_add_px(wolf->mlx, color, X_WIN - x - 1, y);
		y++;
	}
}

void	true_raycast_1(t_wolf *wolf, t_cast *cast, int x)
{
	cast->camera_x = 2 * x / (double)X_WIN - 1;
	cast->raydir_x = cast->dir_x + cast->plan_x * cast->camera_x;
	cast->raydir_y = cast->dir_y + cast->plan_y * cast->camera_x;
	cast->map_x = (int)wolf->x_player;
	cast->map_y = (int)wolf->y_player;
	cast->rngwall2_x = sqrt(1 + (cast->raydir_y * cast->raydir_y)
			/ (cast->raydir_x * cast->raydir_x));
	cast->rngwall2_y = sqrt(1 + (cast->raydir_x * cast->raydir_x)
			/ (cast->raydir_y * cast->raydir_y));
	cast->touch = 0;
}

void	true_raycast_2(t_wolf *wolf, t_cast *cast)
{
	if (cast->raydir_x < 0)
	{
		cast->step_x = -1;
		cast->rngwall_x = (wolf->x_player - cast->map_x) * cast->rngwall2_x;
	}
	else
	{
		cast->step_x = 1;
		cast->rngwall_x = (cast->map_x + 1.0 - wolf->x_player) *
			cast->rngwall2_x;
	}
	if (cast->raydir_y < 0)
	{
		cast->step_y = -1;
		cast->rngwall_y = (wolf->y_player - cast->map_y) * cast->rngwall2_y;
	}
	else
	{
		cast->step_y = 1;
		cast->rngwall_y = (cast->map_y + 1.0 - wolf->y_player) *
			cast->rngwall2_y;
	}
}

void	true_raycast_3(t_wolf *wolf, t_cast *cast)
{
	while (cast->touch == 0)
	{
		if (cast->rngwall_x < cast->rngwall_y)
		{
			cast->rngwall_x += cast->rngwall2_x;
			cast->map_x += cast->step_x;
			cast->witch_side = 0;
		}
		else
		{
			cast->rngwall_y += cast->rngwall2_y;
			cast->map_y += cast->step_y;
			cast->witch_side = 1;
		}
		if (wolf->map[cast->map_y][cast->map_x] != wolf->blank)
			cast->touch = 1;
	}
	if (cast->witch_side == 0)
		cast->wall_len = fabs((cast->map_x - wolf->x_player
					+ (1 - cast->step_x) / 2) / cast->raydir_x);
	else
		cast->wall_len = fabs((cast->map_y - wolf->y_player
					+ (1 - cast->step_y) / 2) / cast->raydir_y);
	cast->hght_wall = abs((int)(Y_WIN / cast->wall_len));
	cast->draw_str = -cast->hght_wall / 2 + Y_WIN / 2;
}

void	true_raycast_4(t_wolf *wolf, t_cast *cast, int x, t_win *mlx)
{
	if (cast->draw_str < 0)
		cast->draw_str = 0;
	cast->draw_end = cast->hght_wall / 2 + Y_WIN / 2;
	if (cast->draw_end >= Y_WIN - 200)
		cast->draw_end = Y_WIN - 200;
	if (wolf->map[cast->map_y][cast->map_x] == wolf->block)
		cast->color = 0xFF0000;
	else
		cast->color = 0x00FF00;
	if (cast->witch_side == 0 && wolf->map[cast->map_y]
			[cast->map_x] == wolf->block)
		cast->color = 0xA00000;
	else if (cast->witch_side == 0)
		cast->color = 0x00A000;
	if (cast->witch_side == 1)
		cast->text_x = wolf->x_player + ((cast->map_y - wolf->y_player +
					(1 - cast->step_y) / 2) / cast->raydir_y) * cast->raydir_x;
	else
		cast->text_x = wolf->y_player + ((cast->map_x - wolf->x_player +
					(1 - cast->step_x) / 2) / cast->raydir_x) * cast->raydir_y;
	cast->text_x = cast->text_x - (int)cast->text_x;
	put_vertical_line(x, cast, wolf, mlx);
	apply_floor(x, wolf, cast);
	apply_roof(x, wolf, cast);
}

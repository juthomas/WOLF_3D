/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_key_analyst_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 00:59:59 by juthomas          #+#    #+#             */
/*   Updated: 2017/10/12 01:59:56 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	which_key_2_1(t_cast *cast)
{
	cast->last_dir_x = cast->dir_x;
	cast->dir_x = cast->dir_x * cos(+0.1) - cast->dir_y * sin(+0.1);
	cast->dir_y = cast->last_dir_x * sin(+0.1) + cast->dir_y * cos(+0.1);
	cast->last_plan_x = cast->plan_x;
	cast->plan_x = cast->plan_x * cos(+0.1) - cast->plan_y * sin(+0.1);
	cast->plan_y = cast->last_plan_x * sin(+0.1) + cast->plan_y * cos(+0.1);
}

int		which_key_2(int keycode, t_wolf *wolf)
{
	t_cast	*cast;

	cast = wolf->cast;
	if (keycode == 123)
	{
		cast->last_dir_x = cast->dir_x;
		cast->dir_x = cast->dir_x * cos(-0.1) -
			cast->dir_y * sin(-0.1);
		cast->dir_y = cast->last_dir_x * sin(-0.1) +
			cast->dir_y * cos(-0.1);
		cast->last_plan_x = cast->plan_x;
		cast->plan_x = cast->plan_x * cos(-0.1) - cast->plan_y * sin(-0.1);
		cast->plan_y = cast->last_plan_x *
			sin(-0.1) + cast->plan_y * cos(-0.1);
	}
	else if (keycode == 124)
		which_key_2_1(cast);
	true_raycast(wolf, wolf->mlx);
	mlx_put_image_to_window(wolf->mlx->mlx, wolf->mlx->win,
			wolf->mlx->img, 0, 0);
	mlx_put_image_to_window(wolf->mlx->mlx, wolf->mlx->win,
			wolf->interface->img, 0, 0);
	return (0);
}

void	which_key_42(t_cast *cast, int keycode)
{
	if (keycode == keycode_ch(123))
	{
		cast->last_dir_x = cast->dir_x;
		cast->dir_x = cast->dir_x * cos(-ROT_SP) - cast->dir_y * sin(-ROT_SP);
		cast->dir_y = cast->last_dir_x *
			sin(-ROT_SP) + cast->dir_y * cos(-ROT_SP);
		cast->last_plan_x = cast->plan_x;
		cast->plan_x = cast->plan_x *
			cos(-ROT_SP) - cast->plan_y * sin(-ROT_SP);
		cast->plan_y = cast->last_plan_x *
			sin(-ROT_SP) + cast->plan_y * cos(-ROT_SP);
	}
	else if (keycode == keycode_ch(124))
	{
		cast->last_dir_x = cast->dir_x;
		cast->dir_x = cast->dir_x * cos(+ROT_SP) -
			cast->dir_y * sin(+ROT_SP);
		cast->dir_y = cast->last_dir_x * sin(+ROT_SP) +
			cast->dir_y * cos(+ROT_SP);
		cast->last_plan_x = cast->plan_x;
		cast->plan_x = cast->plan_x * cos(+ROT_SP) -
			cast->plan_y * sin(+ROT_SP);
		cast->plan_y = cast->last_plan_x * sin(+ROT_SP) + cast->plan_y *
			cos(+ROT_SP);
	}
}

int		which_key(int keycode, t_wolf *wolf)
{
	t_cast	*cast;

	cast = wolf->cast;
	if (keycode == keycode_ch(126))
	{
		if (cast->dir_y > 0)
			if (wolf->map[(int)(wolf->y_player + (cast->dir_y * 0.1))]
					[(int)(wolf->x_player)] == '.')
				wolf->y_player += cast->dir_y * 0.1;
		if (wolf->map[(int)(wolf->y_player)][(int)(wolf->x_player +
					(cast->dir_x * 0.1))] == '.')
			wolf->x_player += cast->dir_x * 0.1;
	}
	else if (keycode == keycode_ch(125))
	{
		if (wolf->map[(int)(wolf->y_player - (cast->dir_y * 0.1))]
				[(int)(wolf->x_player)] == '.')
			wolf->y_player -= cast->dir_y * 0.1;
		if (wolf->map[(int)(wolf->y_player)][(int)(wolf->x_player
					- (cast->dir_x * 0.1))] == '.')
			wolf->x_player -= cast->dir_x * 0.1;
	}
	else
		which_key_42(cast, keycode);
	return (0);
}

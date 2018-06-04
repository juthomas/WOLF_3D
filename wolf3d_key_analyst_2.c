/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_key_analyst_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 01:02:09 by juthomas          #+#    #+#             */
/*   Updated: 2017/10/12 02:01:07 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double	move_player_1(t_wolf *wolf, t_cast *cast, double nobug, t_key *key)
{
	if (key->up == 1)
	{
		nobug = cast->dir_y > 0 ? 0.1 : -0.1;
		if (wolf->map[(int)(wolf->y_player + (nobug + cast->dir_y * 0.1))]
				[(int)(wolf->x_player)] == '.')
			wolf->y_player += cast->dir_y * 0.1;
		nobug = cast->dir_x > 0 ? 0.1 : -0.1;
		if (wolf->map[(int)(wolf->y_player)]
				[(int)(wolf->x_player + (nobug + cast->dir_x * 0.1))] == '.')
			wolf->x_player += cast->dir_x * 0.1;
	}
	else if (key->down == 1)
	{
		nobug = cast->dir_y > 0 ? 0.1 : -0.1;
		if (wolf->map[(int)(wolf->y_player - (nobug + cast->dir_y * 0.1))]
				[(int)(wolf->x_player)] == '.')
			wolf->y_player -= cast->dir_y * 0.1;
		nobug = cast->dir_x > 0 ? 0.1 : -0.1;
		if (wolf->map[(int)(wolf->y_player)]
				[(int)(wolf->x_player - (nobug + cast->dir_x * 0.1))] == '.')
			wolf->x_player -= cast->dir_x * 0.1;
	}
	return (nobug);
}

void	move_player_2(t_cast *cast, t_key *key)
{
	if (key->left == 1)
	{
		cast->last_dir_x = cast->dir_x;
		cast->dir_x = cast->dir_x * cos(-ROT_SP) -
			cast->dir_y * sin(-ROT_SP);
		cast->dir_y = cast->last_dir_x * sin(-ROT_SP) +
			cast->dir_y * cos(-ROT_SP);
		cast->last_plan_x = cast->plan_x;
		cast->plan_x = cast->plan_x * cos(-ROT_SP) -
			cast->plan_y * sin(-ROT_SP);
		cast->plan_y = cast->last_plan_x * sin(-ROT_SP) +
			cast->plan_y * cos(-ROT_SP);
	}
	else if (key->right == 1)
	{
		cast->last_dir_x = cast->dir_x;
		cast->dir_x = cast->dir_x * cos(+ROT_SP) -
			cast->dir_y * sin(+ROT_SP);
		cast->dir_y = cast->last_dir_x * sin(+ROT_SP) +
			cast->dir_y * cos(+ROT_SP);
		cast->last_plan_x = cast->plan_x;
		cast->plan_x = cast->plan_x * cos(ROT_SP) - cast->plan_y * sin(ROT_SP);
		cast->plan_y = cast->last_plan_x * sin(+ROT_SP) +
			cast->plan_y * cos(+ROT_SP);
	}
}

void	move_player(t_wolf *wolf)
{
	t_key	*key;
	t_cast	*cast;
	double	nobug;

	nobug = 0;
	key = wolf->key;
	cast = wolf->cast;
	nobug = move_player_1(wolf, cast, nobug, key);
	move_player_2(cast, key);
}

void	modif_interface(t_wolf *wolf, t_key *key)
{
	if (key->theme == 1 && key->weap == 1)
		wolf->interface = wolf->menu->t_1_g_1;
	else if (key->theme == 1 && key->weap == 2)
		wolf->interface = wolf->menu->t_1_g_2;
	else if (key->theme == 2 && key->weap == 1)
		wolf->interface = wolf->menu->t_2_g_1;
	else if (key->theme == 2 && key->weap == 2)
		wolf->interface = wolf->menu->t_2_g_2;
	else if (key->theme == 3 && key->weap == 1)
		wolf->interface = wolf->menu->t_3_g_1;
	else if (key->theme == 3 && key->weap == 2)
		wolf->interface = wolf->menu->t_3_g_2;
	else if (key->theme == 4 && key->weap == 1)
		wolf->interface = wolf->menu->t_4_g_1;
	else if (key->theme == 4 && key->weap == 2)
		wolf->interface = wolf->menu->t_4_g_2;
	else if (key->theme == 5 && key->weap == 1)
		wolf->interface = wolf->menu->t_5_g_1;
	else if (key->theme == 5 && key->weap == 2)
		wolf->interface = wolf->menu->t_5_g_2;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_key_analyst_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 01:03:44 by juthomas          #+#    #+#             */
/*   Updated: 2017/10/16 23:27:50 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	modif_theme_1(t_wolf *wolf, t_key *key)
{
	if (key->theme == 3)
	{
		wolf->dyke = wolf->theme->t3_wall;
		wolf->floor = wolf->theme->t3_floor;
		wolf->cloud = wolf->theme->t3_roof;
		wolf->sun = wolf->theme->t3_sun;
		wolf->key->rot = 50;
	}
	else if (key->theme == 4)
	{
		wolf->dyke = wolf->theme->t4_wall;
		wolf->floor = wolf->theme->t4_floor;
		wolf->cloud = wolf->theme->t4_roof;
		wolf->sun = wolf->theme->t4_sun;
		wolf->key->rot = 5000;
	}
	else if (key->theme == 5)
	{
		wolf->dyke = wolf->theme->t5_wall;
		wolf->floor = wolf->theme->t5_floor;
		wolf->cloud = wolf->theme->t5_roof;
		wolf->sun = wolf->theme->t5_sun;
	}
}

void	modif_theme(t_wolf *wolf, t_key *key)
{
	if (key->theme == 1)
	{
		wolf->dyke = wolf->theme->t1_wall;
		wolf->floor = wolf->theme->t1_floor;
		wolf->cloud = wolf->theme->t1_roof;
		wolf->sun = wolf->theme->t1_sun;
		wolf->key->rot = 5000;
	}
	else if (key->theme == 2)
	{
		wolf->dyke = wolf->theme->t2_wall;
		wolf->floor = wolf->theme->t2_floor;
		wolf->cloud = wolf->theme->t2_roof;
		wolf->sun = wolf->theme->t2_sun;
	}
	else
		modif_theme_1(wolf, key);
}

void	press_key_1(int keycode, t_key *key)
{
	if (keycode == keycode_ch(126))
		key->up = 1;
	else if (keycode == keycode_ch(125))
		key->down = 1;
	else if (keycode == keycode_ch(123))
		key->left = 1;
	else if (keycode == keycode_ch(124))
		key->right = 1;
	else if (keycode == keycode_ch(4))
		key->help = 1;
	else if (keycode == keycode_ch(53))
		eteindre();
}

void	press_key_2(int keycode, t_key *key, t_wolf *wolf)
{
	if (keycode == keycode_ch(8))
		key->weap = (key->weap > 1) ? 1 : key->weap + 1;
	if (keycode == keycode_ch(3))
	{
		key->theme = (key->theme > 4) ? 1 : key->theme + 1;
		modif_theme(wolf, key);
	}
	if (keycode == keycode_ch(49) && key->fire_key == 0 &&
		((key->weap == 1 && key->ammo1 > 0) ||
			(key->weap == 2 && key->ammo2 > 0)))
	{
		key->fire_key = 1;
		key->wait = -3;
		key->fire = (key->fire == 0) ? 1 : 0;
		if (key->weap == 1)
			system("afplay ress/mp3/weap1.mp3&");
		else
			system("afplay ress/mp3/weap2.mp3&");
		key->ammo1 = (key->weap == 1) ? key->ammo1 - 1 : key->ammo1;
		key->ammo2 = (key->weap == 2) ? key->ammo2 - 1 : key->ammo2;
	}
}

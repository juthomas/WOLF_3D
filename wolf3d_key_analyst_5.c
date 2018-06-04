/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_key_analyst_5.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 01:07:20 by juthomas          #+#    #+#             */
/*   Updated: 2017/10/12 02:03:07 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	infinity_loop_1(t_wolf *wolf, t_key *key)
{
	wolf->sky_x++;
	move_player(wolf);
	wolf->key->wait = (wolf->key->wait > 2) ? 0 : wolf->key->wait + 1;
	if (wolf->key->fire_key == 1 && wolf->key->wait == 2 &&
	((key->weap == 1 && key->ammo1 > 0) || (key->weap == 2 && key->ammo2 > 0)))
	{
		if (key->weap == 1)
			system("afplay ress/mp3/weap1.mp3&");
		else
			system("afplay ress/mp3/weap2.mp3&");
		key->fire = (key->fire == 0) ? 1 : 0;
		key->ammo1 = (key->weap == 1) ? key->ammo1 - 1 : key->ammo1;
		key->ammo2 = (key->weap == 2) ? key->ammo2 - 1 : key->ammo2;
	}
	if (wolf->key->fire == 1)
		modif_interface_ammo(wolf, wolf->key);
	else
		modif_interface(wolf, wolf->key);
	wolf->key->fire = 0;
	if (wolf->sky_x / 100000 == 1)
		wolf->sky_x = 0;
	true_raycast(wolf, wolf->mlx);
	mlx_put_image_to_window(wolf->mlx->mlx, wolf->mlx->win,
			wolf->mlx->img, 0, 0);
}

int		infinity_loop(t_wolf *wolf)
{
	t_key *key;

	key = wolf->key;
	infinity_loop_1(wolf, key);
	wiew_mini_map(wolf, wolf->interface);
	mlx_put_image_to_window(wolf->mlx->mlx, wolf->mlx->win,
			wolf->interface->img, 0, 0);
	apply_ammo(wolf, (wolf->key->weap == 1) ?
			wolf->key->ammo1 : wolf->key->ammo2);
	if (wolf->key->help == 1)
	{
		print_help(wolf, 10, 10, "Help : Arrows to move");
		print_help(wolf, 10, 30, "       Space to fire");
		print_help(wolf, 10, 50, "       C to change weapon");
		print_help(wolf, 10, 70, "       R to reload");
		print_help(wolf, 10, 90, "       F to change theme");
	}
	return (0);
}

void	setup_key(t_wolf *wolf)
{
	wolf->key->wait = 0;
	wolf->key->up = 0;
	wolf->key->down = 0;
	wolf->key->left = 0;
	wolf->key->right = 0;
	wolf->key->theme = 1;
	wolf->key->fire = 0;
	wolf->key->weap = 1;
	wolf->key->help = 0;
	wolf->key->ammo1 = 10;
	wolf->key->ammo2 = 22;
	wolf->key->rot = 5000;
}

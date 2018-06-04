/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_key_analyst_4.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 01:05:20 by juthomas          #+#    #+#             */
/*   Updated: 2017/10/16 23:24:59 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		press_key(int keycode, t_wolf *wolf)
{
	t_key	*key;

	key = wolf->key;
	press_key_1(keycode, key);
	if (keycode == keycode_ch(8) || keycode == keycode_ch(3)
			|| keycode == keycode_ch(49) || keycode == keycode_ch(15))
	{
		press_key_2(keycode, key, wolf);
		if (keycode == keycode_ch(15))
		{
			system("afplay ress/mp3/reload.mp3&");
			key->ammo1 = (key->weap == 1) ? 10 : key->ammo1;
			key->ammo2 = (key->weap == 2) ? 22 : key->ammo2;
		}
		modif_interface(wolf, key);
	}
	return (1);
}

int		release_key(int keycode, t_wolf *wolf)
{
	t_key	*key;

	key = wolf->key;
	if (keycode == keycode_ch(126))
		key->up = 0;
	else if (keycode == keycode_ch(125))
		key->down = 0;
	else if (keycode == keycode_ch(123))
		key->left = 0;
	else if (keycode == keycode_ch(124))
		key->right = 0;
	else if (keycode == keycode_ch(49))
		key->fire_key = 0;
	else if (keycode == keycode_ch(4))
		key->help = 0;
	return (1);
}

void	apply_ammo(t_wolf *wolf, int ammo)
{
	int		x;
	int		i;

	i = 0;
	x = 200;
	while (i < ammo)
	{
		mlx_put_image_to_window(wolf->mlx->mlx, wolf->mlx->win,
				wolf->ammo->img, x, 80);
		x += 12;
		i++;
	}
}

void	modif_interface_ammo(t_wolf *wolf, t_key *key)
{
	if (key->theme == 1 && key->weap == 1)
		wolf->interface = wolf->menu->t_1_g_1_f;
	if (key->theme == 1 && key->weap == 2)
		wolf->interface = wolf->menu->t_1_g_2_f;
	if (key->theme == 2 && key->weap == 1)
		wolf->interface = wolf->menu->t_2_g_1_f;
	if (key->theme == 2 && key->weap == 2)
		wolf->interface = wolf->menu->t_2_g_2_f;
	if (key->theme == 3 && key->weap == 1)
		wolf->interface = wolf->menu->t_3_g_1_f;
	if (key->theme == 3 && key->weap == 2)
		wolf->interface = wolf->menu->t_3_g_2_f;
	if (key->theme == 4 && key->weap == 1)
		wolf->interface = wolf->menu->t_4_g_1_f;
	if (key->theme == 4 && key->weap == 2)
		wolf->interface = wolf->menu->t_4_g_2_f;
	if (key->theme == 5 && key->weap == 1)
		wolf->interface = wolf->menu->t_5_g_1_f;
	if (key->theme == 5 && key->weap == 2)
		wolf->interface = wolf->menu->t_5_g_2_f;
}

void	print_help(t_wolf *wolf, int x, int y, char *msg)
{
	mlx_string_put(wolf->mlx->mlx, wolf->mlx->win, x - 1, y, 0x333333, msg);
	mlx_string_put(wolf->mlx->mlx, wolf->mlx->win, x + 1, y, 0x333333, msg);
	mlx_string_put(wolf->mlx->mlx, wolf->mlx->win, x, y - 1, 0x333333, msg);
	mlx_string_put(wolf->mlx->mlx, wolf->mlx->win, x, y + 1, 0x333333, msg);
	mlx_string_put(wolf->mlx->mlx, wolf->mlx->win, x, y, 0xFFFFFF, msg);
}

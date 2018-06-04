/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 00:47:44 by juthomas          #+#    #+#             */
/*   Updated: 2017/10/12 02:05:21 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	malloc_map_intra(t_wolf *wolf)
{
	int		y;

	y = 0;
	if ((wolf->map = (char**)malloc(sizeof(char*) * (wolf->y_max + 1))) == NULL)
		exit(-1);
	while (y < wolf->y_max)
	{
		if ((wolf->map[y] = (char*)malloc(wolf->x_max + 1)) == NULL)
			exit(-1);
		y++;
	}
}

void	ft_minimap_x_y(t_wolf *wolf, int *x_mini, int *y_mini)
{
	if (wolf->x_max <= wolf->y_max)
	{
		*y_mini = S_MINI;
		*x_mini = ((wolf->x_max * S_MINI) / wolf->y_max);
	}
	else
	{
		*y_mini = ((wolf->y_max * S_MINI) / wolf->x_max);
		*x_mini = S_MINI;
	}
}

void	str_map_intra(char *str, t_wolf *wolf, int y)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		if (str[i] == wolf->blank || str[i] == wolf->wall
				|| str[i] == wolf->block || str[i] == 'P')
		{
			if (str[i] == 'P')
			{
				wolf->x_player = x + 0.5;
				wolf->y_player = y + 0.5;
				wolf->map[y][x] = wolf->blank;
			}
			else
				wolf->map[y][x] = str[i];
			x++;
		}
		i++;
	}
	wolf->map[y][x] = '\0';
}

void	wiew_mini_map_1(t_wolf *wolf, t_tex *tex, int x[2], int y[2])
{
	if (ft_produit_en_x(y[1], wolf->y_max, y[0]) == (int)(wolf->y_player)
			&& ft_produit_en_x(x[1], wolf->x_max, x[0])
			== (int)(wolf->x_player))
		img_add_px_2(tex, 0xFF0000, x[0] + 1035, y[0] + 630);
	else if (wolf->map[ft_produit_en_x(y[1], wolf->y_max, y[0])]
			[ft_produit_en_x(x[1], wolf->x_max, x[0])] == wolf->wall)
		img_add_px_2(tex, 0x202020, x[0] + 1035, y[0] + 630);
	else if (wolf->map[ft_produit_en_x(y[1], wolf->y_max, y[0])]
			[ft_produit_en_x(x[1], wolf->x_max, x[0])] == wolf->block)
		img_add_px_2(tex, 0x505050, x[0] + 1035, y[0] + 630);
	else if (wolf->map[ft_produit_en_x(y[1], wolf->y_max, y[0])]
			[ft_produit_en_x(x[1], wolf->x_max, x[0])] == wolf->blank)
		img_add_px_2(tex, 0xC0C0C0, x[0] + 1035, y[0] + 630);
	x[0]++;
}

void	wiew_mini_map(t_wolf *wolf, t_tex *tex)
{
	int		x[2];
	int		y[2];

	y[0] = 0;
	x[0] = 0;
	ft_minimap_x_y(wolf, &x[1], &y[1]);
	while (y[0] < y[1])
	{
		while (x[0] < x[1])
			wiew_mini_map_1(wolf, tex, x, y);
		y[0]++;
		x[0] = 0;
	}
}

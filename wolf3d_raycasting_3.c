/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_raycasting_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 00:45:14 by juthomas          #+#    #+#             */
/*   Updated: 2017/10/12 00:46:03 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	true_raycast(t_wolf *wolf, t_win *mlx)
{
	int		x;
	t_cast	*cast;

	x = 0;
	cast = wolf->cast;
	while (x < X_WIN)
	{
		true_raycast_1(wolf, cast, x);
		true_raycast_2(wolf, cast);
		true_raycast_3(wolf, cast);
		true_raycast_4(wolf, cast, x, mlx);
		x++;
	}
}

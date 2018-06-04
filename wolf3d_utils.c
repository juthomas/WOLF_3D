/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 01:11:14 by juthomas          #+#    #+#             */
/*   Updated: 2017/10/12 02:30:16 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				ft_produit_en_x(int max1, int max2, int i1)
{
	return (i1 * max2 / max1);
}

int				close_and_free_1(int fd, char *str, int ret)
{
	close(fd);
	free(str);
	return (ret);
}

unsigned int	color_fade(unsigned int color, int percent)
{
	char	r;
	char	g;
	char	b;

	r = (char)((float)(color / 256 / 256 % 256) *
			(float)((float)percent / 100.0));
	g = (char)((float)(color / 256 % 256) * (float)((float)percent / 100.0));
	b = (char)((float)(color % 256) * (float)((float)percent / 100.0));
	return ((unsigned int)(r * 256 * 256 + g * 256 + b));
}

int				eteindre(void)
{
	system("killall afplay");
	exit(0);
	return (0);
}

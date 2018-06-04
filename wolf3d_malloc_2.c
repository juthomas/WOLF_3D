/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_malloc_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 01:33:56 by juthomas          #+#    #+#             */
/*   Updated: 2017/10/16 22:43:22 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		malloc_theme_3(t_wolf *wolf)
{
	t_theme	*theme;

	theme = wolf->theme;
	if ((theme->t4_sun = (t_tex*)malloc(sizeof(*theme->t4_sun))) == NULL)
		return (1);
	if ((theme->t5_floor = (t_tex*)malloc(sizeof(*theme->t5_floor))) == NULL)
		return (1);
	if ((theme->t5_wall = (t_tex*)malloc(sizeof(*theme->t5_wall))) == NULL)
		return (1);
	if ((theme->t5_roof = (t_tex*)malloc(sizeof(*theme->t5_roof))) == NULL)
		return (1);
	if ((theme->t5_sun = (t_tex*)malloc(sizeof(*theme->t5_sun))) == NULL)
		return (1);
	return (0);
}

int		malloc_theme_2(t_wolf *wolf)
{
	t_theme	*theme;

	theme = wolf->theme;
	if ((theme->t3_floor = (t_tex*)malloc(sizeof(*theme->t3_floor))) == NULL)
		return (1);
	if ((theme->t3_wall = (t_tex*)malloc(sizeof(*theme->t3_wall))) == NULL)
		return (1);
	if ((theme->t3_roof = (t_tex*)malloc(sizeof(*theme->t3_roof))) == NULL)
		return (1);
	if ((theme->t3_sun = (t_tex*)malloc(sizeof(*theme->t3_sun))) == NULL)
		return (1);
	if ((theme->t4_floor = (t_tex*)malloc(sizeof(*theme->t4_floor))) == NULL)
		return (1);
	if ((theme->t4_wall = (t_tex*)malloc(sizeof(*theme->t4_wall))) == NULL)
		return (1);
	if ((theme->t4_roof = (t_tex*)malloc(sizeof(*theme->t4_roof))) == NULL)
		return (1);
	if (malloc_theme_3(wolf))
		return (1);
	return (0);
}

int		malloc_theme_1(t_wolf *wolf)
{
	t_theme	*theme;

	if ((wolf->theme = (t_theme*)malloc(sizeof(*wolf->theme))) == NULL)
		return (1);
	theme = wolf->theme;
	if ((theme->t1_floor = (t_tex*)malloc(sizeof(*theme->t1_floor))) == NULL)
		return (1);
	if ((theme->t1_wall = (t_tex*)malloc(sizeof(*theme->t1_wall))) == NULL)
		return (1);
	if ((theme->t1_roof = (t_tex*)malloc(sizeof(*theme->t1_roof))) == NULL)
		return (1);
	if ((theme->t1_sun = (t_tex*)malloc(sizeof(*theme->t1_sun))) == NULL)
		return (1);
	if ((theme->t2_floor = (t_tex*)malloc(sizeof(*theme->t2_floor))) == NULL)
		return (1);
	if ((theme->t2_wall = (t_tex*)malloc(sizeof(*theme->t2_wall))) == NULL)
		return (1);
	if ((theme->t2_roof = (t_tex*)malloc(sizeof(*theme->t2_roof))) == NULL)
		return (1);
	if ((theme->t2_sun = (t_tex*)malloc(sizeof(*theme->t2_roof))) == NULL)
		return (1);
	if (malloc_theme_2(wolf))
		return (1);
	return (0);
}

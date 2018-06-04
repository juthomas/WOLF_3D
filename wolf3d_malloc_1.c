/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_malloc_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 01:18:15 by juthomas          #+#    #+#             */
/*   Updated: 2017/10/12 01:33:45 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		malloc_menu_3(t_wolf *wolf)
{
	t_menu	*menu;

	menu = wolf->menu;
	if ((menu->t_5_g_1 = (t_tex*)malloc(sizeof(*menu->t_5_g_1))) == NULL)
		return (1);
	if ((menu->t_5_g_1_f = (t_tex*)malloc(sizeof(*menu->t_5_g_1_f))) == NULL)
		return (1);
	if ((menu->t_5_g_2 = (t_tex*)malloc(sizeof(*menu->t_5_g_2))) == NULL)
		return (1);
	if ((menu->t_5_g_2_f = (t_tex*)malloc(sizeof(*menu->t_5_g_2_f))) == NULL)
		return (1);
	return (0);
}

int		malloc_menu_2(t_wolf *wolf)
{
	t_menu	*menu;

	menu = wolf->menu;
	if ((menu->t_3_g_1 = (t_tex*)malloc(sizeof(*menu->t_3_g_1))) == NULL)
		return (1);
	if ((menu->t_3_g_1_f = (t_tex*)malloc(sizeof(*menu->t_3_g_1_f))) == NULL)
		return (1);
	if ((menu->t_3_g_2 = (t_tex*)malloc(sizeof(*menu->t_3_g_2))) == NULL)
		return (1);
	if ((menu->t_3_g_2_f = (t_tex*)malloc(sizeof(*menu->t_3_g_2_f))) == NULL)
		return (1);
	if ((menu->t_4_g_1 = (t_tex*)malloc(sizeof(*menu->t_4_g_1))) == NULL)
		return (1);
	if ((menu->t_4_g_1_f = (t_tex*)malloc(sizeof(*menu->t_4_g_1_f))) == NULL)
		return (1);
	if ((menu->t_4_g_2 = (t_tex*)malloc(sizeof(*menu->t_4_g_2))) == NULL)
		return (1);
	if ((menu->t_4_g_2_f = (t_tex*)malloc(sizeof(*menu->t_4_g_2_f))) == NULL)
		return (1);
	if (malloc_menu_3(wolf))
		return (1);
	return (0);
}

int		malloc_menu_1(t_wolf *wolf)
{
	t_menu	*menu;

	if ((wolf->menu = (t_menu*)malloc(sizeof(*wolf->menu))) == NULL)
		return (1);
	menu = wolf->menu;
	if ((menu->t_1_g_1 = (t_tex*)malloc(sizeof(*menu->t_1_g_1))) == NULL)
		return (1);
	if ((menu->t_1_g_1_f = (t_tex*)malloc(sizeof(*menu->t_1_g_1_f))) == NULL)
		return (1);
	if ((menu->t_1_g_2 = (t_tex*)malloc(sizeof(*menu->t_1_g_2))) == NULL)
		return (1);
	if ((menu->t_1_g_2_f = (t_tex*)malloc(sizeof(*menu->t_1_g_2_f))) == NULL)
		return (1);
	if ((menu->t_2_g_1 = (t_tex*)malloc(sizeof(*menu->t_2_g_1))) == NULL)
		return (1);
	if ((menu->t_2_g_1_f = (t_tex*)malloc(sizeof(*menu->t_2_g_1_f))) == NULL)
		return (1);
	if ((menu->t_2_g_2 = (t_tex*)malloc(sizeof(*menu->t_2_g_2))) == NULL)
		return (1);
	if ((menu->t_2_g_2_f = (t_tex*)malloc(sizeof(*menu->t_2_g_2_f))) == NULL)
		return (1);
	if (malloc_menu_2(wolf))
		return (1);
	return (0);
}

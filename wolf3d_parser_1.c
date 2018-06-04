/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_parser_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 00:51:19 by juthomas          #+#    #+#             */
/*   Updated: 2017/10/16 22:48:01 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

char	first_line(int fd, t_wolf *wolf)
{
	char	str[20];
	char	tmp;
	int		i;

	i = 0;
	tmp = 'y';
	while (tmp != '\n' && tmp != '\0' && (read(fd, &tmp, 1)))
	{
		str[i++] = tmp;
		if (i > 10)
			return (1);
	}
	if (i < 4)
		return (1);
	i--;
	wolf->block = str[--i];
	wolf->wall = str[--i];
	wolf->blank = str[--i];
	wolf->y_max = ft_atoi(str);
	if (str[--i] < '0' || str[i] > '9')
		return (1);
	return (0);
}

int		is_true_first_line(char *line, t_wolf *wolf, int fd)
{
	int	i;

	i = 0;
	wolf->x_max = 0;
	while (line[i] != '\0')
	{
		if (((line[i] != wolf->wall && i % 2 == 0)
					|| (line[i] != ' ' && i % 2 == 1)))
			return (close_and_free_1(fd, line, 0));
		if (line[i] == wolf->wall)
			wolf->x_max++;
		i++;
	}
	if (i % 2 == 0)
		return (close_and_free_1(fd, line, 0));
	return (1);
}

int		is_true_middle(char *line, t_wolf *wolf, int fd, int *nb_play)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if ((((line[i] != wolf->block && line[i] != wolf->blank
				&& line[i] != 'P' && (i != 0 ||
					(i == 0 && line[i] != wolf->wall))
				&& (i != wolf->x_max * 2 - 2 || (i == wolf->x_max * 2 - 2
				&& line[i] != wolf->wall))) && i % 2 == 0)
				|| (line[i] != ' ' && i % 2 == 1)))
			return (close_and_free_1(fd, line, 0));
		if (line[i] == 'P')
			*nb_play = *nb_play + 1;
		i++;
	}
	if (i % 2 == 0)
		return (close_and_free_1(fd, line, 0));
	return (1);
}

int		is_true_last(char *line, t_wolf *wolf, int fd)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (((line[i] != wolf->wall && i % 2 == 0)
					|| (line[i] != ' ' && i % 2 == 1)))
			return (close_and_free_1(fd, line, 0));
		i++;
	}
	if (i % 2 == 0)
		return (close_and_free_1(fd, line, 0));
	return (1);
}

char	is_true_map_1(t_wolf *wolf, char *line, int fd, int y_and_nb_play[2])
{
	if (y_and_nb_play[0] == 0)
	{
		if (is_true_first_line(line, wolf, fd) == 0)
			return (0);
		malloc_map_intra(wolf);
		str_map_intra(line, wolf, y_and_nb_play[0]);
	}
	else if (y_and_nb_play[0] < wolf->y_max - 1)
	{
		if (is_true_middle(line, wolf, fd, &y_and_nb_play[1]) == 0)
			return (0);
		str_map_intra(line, wolf, y_and_nb_play[0]);
	}
	else
	{
		if (is_true_last(line, wolf, fd) == 0)
			return (0);
		str_map_intra(line, wolf, y_and_nb_play[0]);
	}
	free(line);
	return (1);
}

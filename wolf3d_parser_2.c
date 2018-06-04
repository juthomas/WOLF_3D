/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_parser_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 00:53:15 by juthomas          #+#    #+#             */
/*   Updated: 2017/10/16 22:45:18 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

char	is_true_map(char **argv, t_wolf *wolf)
{
	int		fd;
	char	*line;
	int		y_and_nb_play[2];

	y_and_nb_play[1] = 0;
	if ((fd = open(argv[1], O_RDONLY)) <= 0)
		exit(-1);
	if (first_line(fd, wolf))
		return (0);
	y_and_nb_play[0] = 0;
	while (1 == get_next_line(fd, &line))
	{
		if (is_true_map_1(wolf, line, fd, y_and_nb_play) == 0)
			return (0);
		y_and_nb_play[0]++;
	}
	if (y_and_nb_play[1] != 1)
		return (close_and_free_1(fd, line, 0));
	return (close_and_free_1(fd, line, 1));
}

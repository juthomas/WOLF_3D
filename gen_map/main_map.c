/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 15:58:49 by juthomas          #+#    #+#             */
/*   Updated: 2017/10/17 01:37:05 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../gnl/libft/libft.h"

int		setup_rand(void)
{
	unsigned int	seed;
	int				fd;

	if ((fd = open("/dev/random", O_RDONLY)) == -1)
		return (0);
	if ((read(fd, &seed, sizeof(seed))) == -1)
		return (0);
	srand(seed);
	close(fd);
	return (1);
}

void	while_of_the_death(int x, int y, int den, int fd)
{
	int		tx;
	int		ty;

	ty = -1;
	while (++ty < y)
	{
		tx = 0;
		while (tx < x)
		{
			if (tx == x / 2 && ty == y / 2)
				ft_putchar_fd('P', fd);
			else if (ty == 0 || ty == y - 1 || tx == 0 || tx == x - 1)
				ft_putchar_fd('O', fd);
			else if (den > rand() % 100)
				ft_putchar_fd('X', fd);
			else
				ft_putchar_fd('.', fd);
			if (tx != x - 1)
				ft_putchar_fd(' ', fd);
			tx++;
		}
		ft_putchar_fd('\n', fd);
	}
}

void	creat_map(int x, int y, int den)
{
	int		fd;
	char	*lines;

	unlink("map.wlf");
	fd = open("map.wlf", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	ft_putstr_fd(lines = ft_itoa(y), fd);
	ft_putstr_fd(".OX\n", fd);
	while_of_the_death(x, y, den, fd);
	free(lines);
	close(fd);
	ft_putstr_fd("Done\nfile created : map.wlf\n", 1);
}

char	is_only_numbers(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		i++;
	return ((i < 5 && str[i] == '\0' && i > 0) ? 1 : 0);
}

int		main(int argc, char **argv)
{
	int				x;
	int				y;
	int				den;

	if (setup_rand() == 0)
		return (0);
	if (argc == 4)
	{
		if (is_only_numbers(argv[1]) && is_only_numbers(argv[2])
			&& is_only_numbers(argv[3]))
		{
			x = ft_atoi(argv[1]);
			y = ft_atoi(argv[2]);
			den = ft_atoi(argv[3]);
			creat_map(x, y, den);
		}
		else
		{
			ft_putstr_fd("Usage : \"./map_gen [X] [Y] [Density]\"\n", 2);
			ft_putstr_fd("Replace with numbers lul\n", 2);
		}
	}
	else
		ft_putstr_fd("Usage : \"./map_gen [X] [Y] [Density]\"\n", 2);
}

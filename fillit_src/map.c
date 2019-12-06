/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phakakos <phakakos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:48:31 by phakakos          #+#    #+#             */
/*   Updated: 2019/12/06 13:40:02 by phakakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	map_undo(char **map, char c, char rep)
{
	int i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] == c)
			map[0][i] = rep;
		i++;
	}
}

static int	map_space(char *map, t_tetrimino *current)
{
	int blocks;
	int dot;
	int i;
	int len;
	int llen;

	dot = 0;
	blocks = 0;
	i = -1;
	len = ft_strlen(map) - 1;
	llen = ft_strclen(map, '\n');
	while (current)
	{
		current = current->next;
		blocks++;
	}
	while (++i < len)
		if (map[i] == '.' && check_spot(map, i, llen, len) > 0)
			dot++;
	return (blocks * 4 > dot ? 0 : 1);
}

static int	map_place(char *map, t_tetrimino *block, int y, int size)
{
	int i;
	int z;
	int map_s;

	i = 0;
	size++;
	map_s = ft_strlen(map) - 1;
	if (y + block->arr[3] / 4 * size + block->arr[i] % 4 - 4 > map_s)
		return (0);
	while (i < 4)
	{
		z = block->arr[i] / 4 * size + block->arr[i] % 4 - 4;
		if ((y + z) >= 0 &&map[y + z] == '.')
			map[y + z] = block->c;
		else
		{
			map_undo(&map, block->c, '.');
			return (0);
		}
		i++;
	}
	return (1);
}

static int	map_print(char *map)
{
system("clear");
	ft_putstr(map);
	ft_strdel(&map);
	exit(0);
	return (1);
}

#include <unistd.h>

int			map_solve(t_tetrimino *current, int size, char *map, int i)
{
	size = size == 0 ? block_amount(current) : size;
	map = !map ? map = make_map(size * 4) : map;
	while (map[i] && map_space(map, current))
	{
		if (map_place(map, current, i, ft_strclen(map, '\n')))
		{
//system("clear");
//ft_putstr(map);
//usleep(1000);
			if (!current->next)
				return (map_print(map));
			if (!map_solve(current->next, size, map, 0))
				map_undo(&map, current->c, '.');
				//{ return (map_solve(current, size, map, i + 1)); }
		}
			i++;
		//else
		//	return (map_solve(current, size, map, i + 1));
	}
	if (!ft_strchr(map, 'A'))
	{
//system("clear");
//ft_putstr(map);
//ft_putnbr(size);
//usleep(20000);
		ft_strdel(&map);
		return (map_solve(current, size + 1, NULL, 0));
	}
	return (0);
}

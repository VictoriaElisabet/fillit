/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phakakos <phakakos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:48:31 by phakakos          #+#    #+#             */
/*   Updated: 2019/12/05 15:43:30 by vgrankul         ###   ########.fr       */
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

static int	map_space(char *map, t_tetrimino *current, int i)
{
	int blocks;
	int dot;

	dot = 0;
	blocks = 0;
	while (current)
	{
		current = current->next;
		blocks++;
	}
	while (map[i])
	{
		if (map[i] == '.')
			dot++;
		i++;
	}
	if (blocks * 4 > dot)
		return (0);
	else
		return (1);
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
	//	if (block->arr[i] < 4 && map[y + block->arr[i]] == '.')
	//		map[y + block->arr[i]] = block->c;
		z = block->arr[i] / 4 * size + block->arr[i] % 4 - 4;
		if (map[y + z] == '.')
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
	if (size == 0)
		size = block_amount(current);
	if (!map)
		map = make_map(size);
system("clear");
ft_putstr(map);
usleep(100000);
	if (map_space(map, current, 0))
	{
		if (map_place(map, current, i, size))
		{
			if (!current->next)
				return (map_print(map));
			if (!map_solve(current->next, size, map, 0))
			{
				map_undo(&map, current->c, '.');
				return (map_solve(current, size, map, i + 1));
			}
		}
		else
			return (map_solve(current, size, map, i + 1));
	}
	else if (!ft_strchr(map, 'A'))
	{
		ft_strdel(&map);
		return (map_solve(current, size + 1, NULL, 0));
	}
	return (0);
}

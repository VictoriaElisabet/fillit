/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phakakos <phakakos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:48:31 by phakakos          #+#    #+#             */
/*   Updated: 2019/12/09 13:33:08 by phakakos         ###   ########.fr       */
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

static int	map_space(char *map, t_tetrimino *current, int len, int llen)
{
	int blocks;
	int dot;
	int i;

	dot = 0;
	blocks = 0;
	i = -1;
	len--;
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

static int	map_place(char *map, t_tetrimino *block, int y, int map_s)
{
	int i;
	int z;
	int len_s;

	i = 3;
	len_s = ft_strclen(map, '\n') + 1;
	if (y + block->arr[i] / 4 * len_s + block->arr[i] % 4 - 4 > map_s ||
			y + block->arr[0] / 4 * len_s + block->arr[0] % 4 - 4 < 0)
		return (0);
	while (i >= 0)
	{
		z = block->arr[i] / 4 * len_s + block->arr[i] % 4 - 4;
		if (map[y + z] == '.')
			map[y + z] = block->c;
		else
		{
			if (i < 3)
				map_undo(&map, block->c, '.');
			return (0);
		}
		i--;
	}
	return (1);
}

static int	map_print(char *map)
{
	ft_putstr(map);
	ft_strdel(&map);
	exit(0);
	return (1);
}

int			map_solve(t_tetrimino *current, int size, char *map, int i)
{
	int len;
	int llen;

	size = size == 0 ? block_amount(current) : size;
	map = !map ? make_map(size * 4, current) : map;
	len = ft_strlen(map);
	llen = ft_strclen(map, '\n');
	while (map[i] && map_space(map, current, len, llen))
	{
		if (map_place(map, current, i, len))
		{
			if (!current->next)
				return (map_print(map));
			if (!map_solve(current->next, size, map, 0))
				map_undo(&map, current->c, '.');
		}
		i++;
	}
	if (!ft_strchr(map, 'A'))
	{
		ft_strdel(&map);
		return (map_solve(current, size + 1, NULL, 0));
	}
	return (0);
}

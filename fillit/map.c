/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phakakos <phakakos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 18:33:42 by phakakos          #+#    #+#             */
/*   Updated: 2019/12/04 12:50:46 by vgrankul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int block_amount(t_tetrimino *start)
{
	int total;

	if (!start)
		return (0);
	while (start->next)
		start = start->next;
	total = start->c - 'A' + 1;
	return (total);
}

static char	*make_map(int size)
{
	char	*map;
	int		total;
	int		i;

	total = size * (size + 1) + 1;
	if (!(map = ft_strnew(total)))
		print_error(-3);
	ft_memset(map, '.', total - 1);
	i = size;
	while (i < (size * (size + 1)))
	{
		map[i] = '\n';
		i += size + 1;
	}
	return (map);
}

static void map_undo(char **map, char c, char rep)
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

	blocks = 0;
	dot = 0;
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
		return (0);
}

static int	map_place(t_tetrimino *block, char *map, int y, int size)
{
	int i;
	int map_s;

	i = 0;
	size++;
	map_s = ft_strlen(map) - 1;
	if (y + block->arr[3] / 4 * size + block->arr[i] % 4 - 4 > map_s)
		return (0);
	while (i < 4)
	{
		if (map[y + block->arr[i] / 4 * size + block->arr[i] % 4 - 4] == '.')
			map[y + block->arr[i] / 4 * size + block->arr[i] % 4 - 4] = block->c;
		else
		{
			map_undo(&map, block->c, '.');
			return (0);
		}
		i++;
	}
	return (1);
}

/*
 * first call with *start, 0, NULL, 0
 */

int		map_solve(t_tetrimino *current, int size, char *map, int i)
{
	if (size == 0)
		size = block_amount(current);
	if (!map)
		map = make_map(size);
	if (map_space(map, current, i))
	{
		if (map_place(current, map, i, size))
		{
			if (!current->next)
			{
				ft_putstr(map);
				ft_strdel(&map);
				return (1);
			}
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phakakos <phakakos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 18:33:42 by phakakos          #+#    #+#             */
/*   Updated: 2019/12/03 13:45:50 by phakakos         ###   ########.fr       */
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

static char	make_map(int size)
{
	char	*map;
	int		total;
	int		i;

	total = size * (size + 1) + 1;
	if (!(map = ft_strnew(total)))
		error(-3);
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

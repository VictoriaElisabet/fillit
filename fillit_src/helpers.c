/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phakakos <phakakos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:44:47 by phakakos          #+#    #+#             */
/*   Updated: 2019/12/05 12:37:58 by phakakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	block_del(t_tetrimino *start)
{
	t_tetrimino	*next;

	if (start)
	{
		next = start->next;
		free(start);
		block_del(next);
	}
}

int		block_amount(t_tetrimino *start)
{
	int total;

	if (!start)
		return (0);
	while (start->next)
		start = start->next;
	total = start->c - 'A' + 1;
	return (total);
}

char	*make_map(int size)
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

int		check_tetri(t_tetrimino *block)
{
	int	conn;
	int i;
	int y;

	i = 0;
	conn = 0;
	while (i < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (y == i)
			{
				y++;
				continue ;
			}
			conn += block->arr[i] - 4 == block->arr[y] ? 1 : 0;
			conn += block->arr[i] - 1 == block->arr[y] ? 1 : 0;
			conn += block->arr[i] + 1 == block->arr[y] ? 1 : 0;
			conn += block->arr[i] + 4 == block->arr[y] ? 1 : 0;
			y++;
		}
		i++;
	}
	return ((conn == 6) || (conn == 8) ? 1 : 0);
}

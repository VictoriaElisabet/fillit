/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phakakos <phakakos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:44:47 by phakakos          #+#    #+#             */
/*   Updated: 2019/12/04 17:48:06 by phakakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	block_del(t_tetrimino *start)
{
	t_tetrimino	next;

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

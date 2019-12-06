/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phakakos <phakakos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:44:47 by phakakos          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/12/06 13:45:01 by phakakos         ###   ########.fr       */
=======
/*   Updated: 2019/12/06 13:16:42 by vgrankul         ###   ########.fr       */
>>>>>>> b246f8aca422a90dfb5ba03b2ccef65d0fb7b730
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

int		check_spot(char *map, int i, int llen, int len)
{
	int	free;

	free = 4;
	if (i - llen >= 0 && map[i - llen] != '.')
		free--;
	if (i - 1 >= 0 && map[i - 1] != '.')
		free--;
	if (i + 1 < len && map[i + 1] != '.')
		free--;
	if (i + llen < len && map[i + llen] != '.')
		free--;
	return (free);
}

char	*make_map(int size)
{
	char	*map;
	int		total;
	int		i;

	total = 1;
	while (size > total * total)
		total++;
	size = total;
	total = size * (size + 1) + 1;
	if (!(map = ft_strnew(total)))
		print_error(-3);
	ft_memset(map, '.', total - 1);
	i = size;
	while (i < total)
	{
		map[i] = '\n';
		i += size + 1;
	}
	return (map);
}

void	check_tetri(int arr[26][4])
{
	int	conn;
	int i;
	int y;
	int k;

	k = -1;
	while (++k < 26 && arr[k][0] != -1 && !(conn = 0))
	{
		i = -1;
		while (++i < 4)
		{
			y = -1;
			while (++y < 4)
			{
				conn += arr[k][i] - 4 == arr[k][y] ? 1 : 0;
				conn += (arr[k][i] - 1 == arr[k][y]) && (arr[k][i] % 4 != 0) ? 1 : 0;
				conn += (arr[k][i] + 1 == arr[k][y]) && (arr[k][i] % 4 != 3) ? 1 : 0;
				conn += arr[k][i] + 4 == arr[k][y] ? 1 : 0;
			}
		}
		if (conn != 6 && conn != 8)
			print_error(-1);
	}
}

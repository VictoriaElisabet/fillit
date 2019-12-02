/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phakakos <phakakos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 18:33:42 by phakakos          #+#    #+#             */
/*   Updated: 2019/12/02 19:11:45 by phakakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int map_size(t_tetrimino *start)
{
	int rtn;
	int total;

	if (!start)
		return (0);
	while (start->next)
		start = start->next;
	total = start->c - 'A' + 1;
	total = total * 4;
	rtn = 4;
	while (1)
	{
		if (rtn * rtn > total)
			return (rtn * rtn);
		rtn++;
	}
}



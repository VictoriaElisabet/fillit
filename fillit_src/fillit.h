/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phakakos <phakakos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:55:37 by phakakos          #+#    #+#             */
/*   Updated: 2019/12/04 12:57:11 by phakakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft.h"

typedef strutct	s_tetrimino
{
	char	c;
	void	*next;
	int		arr[4];
}				t_tetrimino

void	print_error(int i);
int		map_solve(t_tetrimino *current, int size, char *map, int i);

#endif

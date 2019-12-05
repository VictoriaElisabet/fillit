/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phakakos <phakakos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:47:56 by phakakos          #+#    #+#             */
/*   Updated: 2019/12/05 13:58:47 by vgrankul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_tetrimino
{
	char	c;
	void	*next;
	int		arr[4];
}				t_tetrimino;

void			print_error(int i);
void			block_del(t_tetrimino *start);
int				map_solve(t_tetrimino *current, int size, char *map, int i);
int				block_amount(t_tetrimino *start);
char			*make_map(int size);

#endif

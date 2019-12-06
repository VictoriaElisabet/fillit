/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrankul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 13:59:37 by vgrankul          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/12/06 13:40:22 by phakakos         ###   ########.fr       */
=======
/*   Updated: 2019/12/06 13:22:12 by vgrankul         ###   ########.fr       */
>>>>>>> b246f8aca422a90dfb5ba03b2ccef65d0fb7b730
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
void			check_file(int fd);
void			check_tetri(int arr[26][4]);
void			check_tetrimino_characters(char **str);
void			check_coordinates(char **s);
void			create_list(int a[26][4]);

char			*make_map(int size);
char			*join_lines(char *str, char **line);

int				map_solve(t_tetrimino *current, int size, char *map, int i);
int				block_amount(t_tetrimino *start);
<<<<<<< HEAD
char			*make_map(int size);
void			check_tetri(int arr[26][4]);
int				check_spot(char *map, int i, int llen, int len);
=======
int				check_spot(char *map, int i);
int				check_line(char *line);
>>>>>>> b246f8aca422a90dfb5ba03b2ccef65d0fb7b730

#endif

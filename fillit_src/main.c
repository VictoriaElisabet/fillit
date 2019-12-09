/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phakakos <phakakos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:19:44 by vgrankul          #+#    #+#             */
/*   Updated: 2019/12/09 13:31:28 by phakakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print_error(int i, t_tetrimino *start, char **s)
{
	t_tetrimino	*curr;

	curr = start;
	if (i == -1 || i == -3)
	{
		ft_putstr("error\n");
		if (curr)
			block_del(start);
		if (s)
			ft_strarrdel(s);
	}
	else if (i == -2)
		ft_putstr("usage: fillit input_file\n");
	exit(8);
}

static char	*join_lines(char *str, char *line, char **s)
{
	char *tmp;

	tmp = ft_strjoin(str, line);
	ft_strdel(&str);
	ft_strdel(&line);
	if (!tmp)
		print_error(-3, NULL, s);
	return (tmp);
}

void		check_file(int fd)
{
	char		*line;
	static int	i;
	int			j;
	char		*str;
	static char *s[27];

	j = 0;
	str = NULL;
	while (j < 4)
	{
		j++;
		if (get_next_line(fd, &line) != 1 || check_line(line) == -1)
			print_error(-1, NULL, s);
		str = join_lines(str, line, s);
		if (j == 4)
			s[i++] = str;
	}
	if (i < 26 && (j = get_next_line(fd, &line)) > 0)
		ft_strlen(line) == 0 ? check_file(fd) : print_error(-1, NULL, s);
	else if (i > 26 || j == -1)
		print_error(-1, NULL, s);
	check_tetrimino_characters(s);
	check_coordinates(s);
}

int			main(int argc, char **argv)
{
	int fd;

	if (argc < 2 || argc > 2)
		print_error(-2, NULL, NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error(-1, NULL, NULL);
	check_file(fd);
	return (0);
}

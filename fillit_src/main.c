/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phakakos <phakakos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:19:44 by vgrankul          #+#    #+#             */
/*   Updated: 2019/12/09 10:54:48 by vgrankul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print_error(int i)
{
	if (i == -1)
		ft_putstr("error\n");
	else if (i == -2)
		ft_putstr("usage: fillit input_file\n");
	else if (i == -3)
		ft_putstr("error\n");
	exit(0);
}

static char	*join_lines(char *str, char *line)
{
	char *tmp;

	if (!(tmp = ft_strjoin(str, line)))
		print_error(-3);
	ft_strdel(&str);
	ft_strdel(&line);
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
			print_error(-1);
		str = join_lines(str, line);
		if (j == 4)
			s[i++] = str;
	}
	if (i < 26 && (j = get_next_line(fd, &line)) > 0)
		ft_strlen(line) == 0 ? check_file(fd) : print_error(-1);
	else if (i > 26 || j == -1)
		print_error(-1);
	check_tetrimino_characters(s);
	check_coordinates(s);
}

int			main(int argc, char **argv)
{
	int fd;

	if (argc < 2 || argc > 2)
		print_error(-2);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error(-1);
	check_file(fd);
	return (0);
}

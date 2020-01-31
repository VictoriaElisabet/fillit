/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrankul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:17:12 by vgrankul          #+#    #+#             */
/*   Updated: 2019/12/11 18:13:35 by vgrankul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	fix_coordinates(int arr[26][4])
{
	int i;
	int l;
	int p;

	i = -1;
	while (++i < 26 && arr[i][0] != -1)
	{
		while (arr[i][0] > 3)
		{
			l = -1;
			while (++l < 4)
				arr[i][l] -= 4;
		}
		p = 3;
		while (p != 0 && (l = -1))
		{
			while (++l < 4)
				p = arr[i][l] % 4 == 0 ? 0 : p;
			if (p != 0 && !(l = 0))
				while (l < 4)
					l += (arr[i][l] -= 1) ? 1 : 1;
		}
	}
}

void		check_coordinates(char **s)
{
	int arr[26][4];
	int i;
	int j;
	int k;
	int l;

	i = -1;
	k = 0;
	while (s[++i] && !(l = 0))
	{
		j = -1;
		while (s[i][++j] != '\0')
		{
			if (s[i][j] == '#')
				l += (arr[k][l] = j) ? 1 : 1;
		}
		k++;
		ft_strdel(&s[i]);
	}
	ft_strdel(s);
	if (k < 26)
		arr[k][0] = -1;
	fix_coordinates(arr);
	check_tetri(arr);
	create_list(arr);
}

void		check_tetrimino_characters(char **str)
{
	int i;
	int j;
	int count;

	i = 0;
	while (str[i] != NULL)
	{
		j = 0;
		count = 0;
		while (str[i][j] != '\0')
		{
			if (str[i][j] == '#')
				count++;
			j++;
		}
		if (count != 4)
			print_error(-1, NULL, str);
		i++;
	}
}

int			check_line(char *line)
{
	int i;

	i = 0;
	if (!line)
		return (-1);
	if (ft_strlen(line) != 4)
	{
		ft_strdel(&line);
		return (-1);
	}
	while (line[i] != '\0')
	{
		if (line[i] != '.' && line[i] != '#')
		{
			ft_strdel(&line);
			return (-1);
		}
		i++;
	}
	return (1);
}

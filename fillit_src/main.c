/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phakakos <phakakos@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:19:44 by vgrankul          #+#    #+#             */
/*   Updated: 2019/12/05 18:29:22 by phakakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	print_error(int i)
{
	if (i == -1)
		ft_puterr("error");
	else if (i == -2 )
		ft_putstr("usage: fillit input_file");
	else if (i == -3)
		ft_puterr("error: allocation failed");
	exit(0);
}

t_tetrimino	*create(char c, int a[4])
{
	int j;

	j = 0;
	t_tetrimino *new = (t_tetrimino*)malloc(sizeof(t_tetrimino));
	if (!new)
		print_error(-3);
	while (j < 4)
	{
		new->arr[j] = a[j];
		j++;
	}
	new->c = c;
	new->next = NULL;
	return (new);
}

void	append(t_tetrimino **head, int a[4], char c)
{
	t_tetrimino *cursor;

	cursor = *head;
	while (cursor->next != NULL)
		cursor = cursor->next;
	t_tetrimino *new;
	new = create(c, a);
	cursor->next = new;
}

void	create_list(int a[26][4])
{
	int i;
	char c;
	t_tetrimino *head;

	c = 65;
	i = 0;
	head = NULL;
	while (a[i][0] != -1)
	{		
		if (!head)
			head = create(c, a[i]);
		else
			append (&head, a[i], c + i);
		i++;
	}
	map_solve(head, 0, NULL, 0);
}

int	check_line(char *line)
{
	int i;

	i = 0;
	if (!line)
		return (-1);
	if (ft_strlen(line) > 4 || ft_strlen(line) < 4)
		return (-1);
	while (line[i] != '\0')
	{
		if (line[i] != '.' && line[i] != '#')
			return (-1);
		i++;
	}
	return(1);
}

void	fix_coordinates(int arr[26][4])
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

void	check_coordinates(char **s)
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
//		free(s[i]);
		k++;
	}
	ft_strdel(s);
	if (k < 26)
		arr[k][0] = -1;
	fix_coordinates(arr);
	check_tetri(arr);
	create_list(arr);
}
/*
int	check_blocks(char **str)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while(str[i] != NULL)
	{
		j = 0;
		count = 0;
		while(str[i][j] != '\0')
		{
			if(str[i][j + 1] == '#')
				count++;
			else if (str[i][j - 1] == '#')
				count++;
			else if(str[i][j - 4] == '#')
			   count++;
			else if	(str[i][j + 4] == '#')
				count++;
			if (count > 1)
				return (1);
			j++;
		}
		i++;
	}
	return (-1);	
}

void	check_tetrimino(char **str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != NULL)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (str[i][j] == '#')
			{
				if (str[i][j + 1] == '#' || str[i][j - 1] == '#' || str[i][j + 4] == '#' || str[i][j - 4] == '#')
				{
					if(check_blocks(str) == -1)
						print_error(-1);
				}
				else
					print_error(-1);
			}
			j++;
		}
		i++;
	}
}
*/
void	check_tetrimino_characters(char **str)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i] != NULL)
	{
		j = 0;
		count = 0;
		while (str[i][j] != '\0')
		{
		if (str[i][j] == '#')
			count++;	
		if (count > 4 && count < 4)
			 print_error(-1);
		j++;
		}
		i++;
	}
	//check_tetrimino(str);
}
char	*join_lines(char *str, char **line)
{
	char *tmp;

	if (!(tmp = ft_strjoin(str, *line)))
		print_error(-3);
	ft_strdel(&str);
	str = tmp;
	ft_strdel(line);
	return (str);
}

void	check_file(int fd)
{
	char *line;
	static int i;
	int j;
	char *str;
	static char *s[27];

	j = 0;
	str = NULL;
	while(j < 4)
	{
		j++;
		if (get_next_line(fd, &line) != 1 || check_line(line) == -1)
			print_error(-1);
		str = join_lines(str, &line);
		if (j == 4)
		{
			str = ((s[i++] = str)) ? NULL : NULL;
//			printf("%s %d\n", s[i - 1], i);
		}
	}
	if (i < 26 && get_next_line(fd, &line) > 0)
			ft_strlen(line) == 0 ? check_file(fd) : print_error(-1);
	else if (i > 26)
		print_error(-1);
	check_tetrimino_characters(s);	
	check_coordinates(s);
}

int	main(int argc, char **argv)
{
	int fd;
	
	if (argc < 2 || argc > 2)
		print_error(-2);
	fd = open(argv[1], O_RDONLY);
	check_file(fd);
	return(0);
}

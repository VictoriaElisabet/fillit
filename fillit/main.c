/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrankul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:19:44 by vgrankul          #+#    #+#             */
/*   Updated: 2019/11/29 17:00:10 by phakakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	print_error(int i)
{
	if (i == -1)
		write(2, "error", 5);
	else if (i == -2 )
		write(1, "usage: fillit input_file", 24);
	else if (i == -3)
		write(2, "error: allocation failed", 24);
	exit(0);
}

tetrimino	*create(char c, int a[4])
{
	int j;

	j = 0;
	t_tetrimino *new = (tetrimino*)malloc(sizeof(tetrimino));
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

void	append(tetrimino *head, int a[4], char c)
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
	tetrimino *head;

	c = 65;
	i = 0;
	head = NULL;
	while (a[i][0] != -1)
	{		
		if (!head)
			head = create(c, a[i]);
		else
			append (head, a[i], c + i);
		i++;
	}
}

int	check_line(char *line)
{
	int i;

	i = 0;
	if (ft_strlen(line) > 4)
		return (-1);
	while (line[i] != '\0')
	{
		if (line[i] != '.' && line[i] != '#')
			return (-1);
		i++;
	}
	return(1);
}
void	check_coordinates(char **s)
{
	int arr[26][4];
	int i;
	int j;
	int k;
	int l;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	while (s[i])
	{
		j = 0;
		l = 0;
		while (s[i][j] != '\0')
		{
			if (s[i][j] == '#')
			{
				arr[k][l] = j;
				l++;
			}
			j++;
		}
		i++;
		k++;
	}
	arr[k][0] = -1;
	create_list(arr);
}
/*void	check_tetromino(char **str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '.' && str[i] != '#')
		{
			ft_strdel(&str);
			print_error(-1);
		}
		if (str[i] == '#')
			count++;
		if (count > 4 && count < 4)
			print_error(-1);
		i++;
	}
	//check_coordinates(str);
}*/

void	check_file(int fd)
{
	char *line;
	int i;
	int j;
	int k;
	char *str;
	char *tmp;
	char *s[27];

	i = 0;
	j = 0;
	k = 0;
	str = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		j++;
		if(check_line(line) == -1)
			print_error(-1);
		if (str == NULL)
			if (!(str = ft_strnew(0)))
				print_error(-3);
		if (!(tmp = ft_strjoin(str, line)))
			print_error(-3);
		free(str);
		str = tmp;
		if (j == 4)
		{
			if (!(s[i] = ft_strsub(str, 0, ft_strlen(str))))
				print_error(-3);
			ft_strdel(&str);
			j = 0;
			i++;
		}
		if (ft_strlen(line) == 0)
		{
			j = 0;
			k++;
		}
		if (k > 1)
			print_error(-1);
		free(line);
	}
	if (get_next_line(fd, &line) == -1)
		print_error(-1);
	//check_tetromino(s);
	check_coordinates(s);
}

int	main(int argc, char **argv)
{
	int fd;
	
	if (argc < 2 || argc > 2)
		print_error(-2);
	fd = open(argv[1], O_RDONLY);
	check_file(fd);
	close(fd);
	return(0);
}

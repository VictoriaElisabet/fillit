/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrankul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 12:59:48 by vgrankul          #+#    #+#             */
/*   Updated: 2019/12/06 13:35:42 by vgrankul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	t_tetrimino	*create(char c, int a[4])
{
	int			j;
	t_tetrimino *new;

	j = 0;
	new = (t_tetrimino*)malloc(sizeof(t_tetrimino));
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

static	void		append(t_tetrimino **head, int a[4], char c)
{
	t_tetrimino *cursor;
	t_tetrimino *new;

	cursor = *head;
	while (cursor->next != NULL)
		cursor = cursor->next;
	new = create(c, a);
	cursor->next = new;
}

void				create_list(int a[26][4])
{
	int			i;
	char		c;
	t_tetrimino *head;

	c = 65;
	i = 0;
	head = NULL;
	while (a[i][0] != -1)
	{
		if (!head)
			head = create(c, a[i]);
		else
			append(&head, a[i], c + i);
		i++;
	}
	map_solve(head, 0, NULL, 0);
}

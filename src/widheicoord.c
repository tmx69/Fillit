/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widheicoord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:08:20 by jritchie          #+#    #+#             */
/*   Updated: 2019/01/15 16:42:39 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_min(int *arr)
{
	int i;
	int y;

	i = 0;
	y = 4;
	while (i < 4)
	{
		if (y > arr[i])
			y = arr[i];
		i++;
	}
	return (y);
}

int		get_max(int *arr)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (i < 4)
	{
		if (x < arr[i])
			x = arr[i];
		i++;
	}
	return (x);
}

void	ft_coordinate(t_tetr *head)
{
	int row;
	int column;
	int hash;

	row = -1;
	hash = 0;
	while (++row < 4)
	{
		column = -1;
		while (++column < 4)
		{
			if (head->array[row][column] == '#')
			{
				head->x[hash] = row % 4;
				head->y[hash] = column % 4;
				hash++;
			}
		}
	}
}

t_tetr	*ft_wid_hei_coord(t_tetr *head)
{
	char	a;
	int		d[2];
	int		i;
	t_tetr	*begin;

	begin = head;
	a = 'A';
	while (head != NULL)
	{
		ft_coordinate(head);
		d[0] = get_min(head->x);
		d[1] = get_min(head->y);
		head->height = get_max(head->x) - d[0] + 1;
		head->width = get_max(head->y) - d[1] + 1;
		i = -1;
		while (++i < 4)
		{
			head->x[i] = head->x[i] - d[0];
			head->y[i] = head->y[i] - d[1];
		}
		head->letter = a++;
		head->letter > 'Z' ? ft_error() : 0;
		head = head->next;
	}
	return (begin);
}

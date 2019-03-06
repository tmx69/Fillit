/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:19:11 by jritchie          #+#    #+#             */
/*   Updated: 2019/01/15 14:22:23 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_place_tetr(t_tetr *tetra, char **map, int i, int j)
{
	int b;

	b = 0;
	while (b < 4)
	{
		map[tetra->x[b] + i][tetra->y[b] + j] = tetra->letter;
		b++;
	}
}

char	**ft_remove_tetr(t_tetr *tetra, char **map, int i, int j)
{
	int b;

	b = 0;
	while (b < 4)
	{
		map[tetra->x[b] + i][tetra->y[b] + j] = '.';
		b++;
	}
	return (map);
}

int		ft_check(t_tetr *tetra, char **map, int i, int j)
{
	int b;

	b = 0;
	while (b < 4)
	{
		if (map[tetra->x[b] + i][tetra->y[b] + j] != '.')
			return (0);
		b++;
	}
	return (1);
}

int		ft_tetris2(t_tetr *tet, char **map, int mapsize)
{
	int i;
	int j;

	i = 0;
	while ((tet->height) + i <= mapsize)
	{
		j = 0;
		while ((tet->width) + j <= mapsize)
		{
			if (ft_check(tet, map, i, j) == 1)
			{
				ft_place_tetr(tet, map, i, j);
				if (tet->next == NULL || ft_tetris2(tet->next, map, mapsize))
					return (1);
				else
					ft_remove_tetr(tet, map, i, j);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_tetris(t_tetr *tetra)
{
	int		i;
	int		size;
	t_tetr	*head;
	char	**map;

	i = 0;
	head = NULL;
	head = tetra;
	size = (tetra->height > tetra->width ? tetra->height : tetra->width);
	map = ft_create_map(tetra, size);
	while (!ft_tetris2(tetra, map, size))
	{
		ft_freemap(map, size);
		map = ft_create_map(tetra, size += 1);
		tetra = head;
	}
	ft_print_tetris(map, tetra->map_size);
}

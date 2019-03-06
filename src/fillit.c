/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 16:50:43 by jritchie          #+#    #+#             */
/*   Updated: 2019/01/16 11:05:25 by jritchie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_print_tetris(char **map, int size)
{
	int row;

	row = 0;
	while (row < size)
	{
		ft_putstr(map[row]);
		write(1, "\n", 1);
		row++;
	}
}

char		**ft_create_map(t_tetr *tetra, int size)
{
	char	**map;
	int		i;

	i = 0;
	tetra->map_size = size;
	map = (char **)malloc(sizeof(char *) * size + 1);
	while (i < size)
	{
		map[i] = ft_memset(ft_strnew(size), '.', size);
		i++;
	}
	return (map);
}

char		**ft_freemap(char **map, int size)
{
	size -= 1;
	while (size > 0)
	{
		ft_strdel(&map[size]);
		size--;
	}
	free(map);
	map = NULL;
	return (map);
}

int			main(int argc, char **argv)
{
	int			fd;
	t_tetr		*tetra;

	tetra = ft_listnew();
	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
	{
		write(1, "usage: ./fillit input_file\n", 28);
		exit(0);
	}
	if (fd < 0)
		ft_error();
	if (!(tetra = start_valid(fd, tetra)))
		ft_error();
	ft_tetris(tetra);
	return (0);
}
